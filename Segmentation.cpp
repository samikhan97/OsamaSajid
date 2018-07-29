#include "defs.h"

int main () 
{
	
	int argc;
	char **argv;
	
	
	FILE *fp;
	struct TIFF_img my_image;
	struct pixel pxl;
	int number_connected, segment_label;
	double threshold;

	
	
	
	if (argc != 4) error(argv[0]);

	/* we have 1 segment at the beginning */
	segment_label = 1;

	
	
	/* open image file */
	if ((fp = fopen(argv[1], "rb")) == NULL) 
	{
		
		
				fprintf(stderr, "cannot open file %s\n", argv[1]);
				exit(1);
		
		
	}

	
	
	/* read image */
	if (read_TIFF(fp, &my_image)) 
	{
		
		
				fprintf(stderr, "error reading file %s\n", argv[1]);
				exit(1);
		
		
	}

	
	
	
	
	/* close image file */
	fclose(fp);

	
	
	
	/* check the type of image data */
	if (my_image.TIFF_type != 'g') 
	{
		
		
				fprintf(stderr, "error:  image must be grayscale\n");
				exit(1);
		
		
	}

	
	
	
	
	/* get the other parameters */
	sscanf(argv[2], "%lf", &threshold);

	
	
	
	unsigned int **seg = (unsigned int **)get_img(my_image.width, my_image.height,sizeof(unsigned int));

    
	
	
	/* make sure all elements are 0 */
    for ( int i = 0; i < my_image.height; i++) 
	{
		
		
		for ( int j = 0; j < my_image.width; j++) 
		{
			
			
					seg[i][j] = 0;
		
		
		}
	
	
	}

	
	
	
	
	
	
    /* go through the image */
	for (int i = 0; i < my_image.height; i++) 
	{
		
		
		for (int j = 0; j < my_image.width; j++) 
		{
			
			
					if (seg[i][j] == 0) 
					{
						
						
								pxl.row = i;
								pxl.column = j;
								
								
							ConnectedSet(pxl, threshold, my_image.mono, my_image.width,my_image.height, segment_label, seg, &number_connected); // starts connecting the pixels in a link list based on the threshold value
							
							
					if (number_connected > 100) 
				{
					
					
                    /* new label created after 100 connected sets */
					segment_label++;
					
					
				} 
				
					else 
				{
					
					
					/* otherwise, back to 0 */
					ConnectedSet(pxl, threshold, my_image.mono, my_image.width,my_image.height, 1, seg, &number_connected);
				
				}
				
			}
		}
	}


	
	
	printf("Number of regions generated for %lf is %d\n", threshold, segment_label - 1);

	
	
	
	
	for (int i = 0; i < my_image.height; i++) 
	{
		
		
				for ( int j = 0; j < my_image.width; j++) 
			{
			
			
								my_image.mono[i][j] = seg[i][j];
		
		
			}
		
		
	}

	
	
	
	
	free_img((void *)seg);

	
	
	
	
	
	/* open output image file */
	if ((fp = fopen(argv[3], "wb")) == NULL) 
	{
		
		
				fprintf(stderr, "cannot open file output.tif\n");
				exit(1);
		
		
	}

	
	
	
	
	/* write output image */
	if(write_TIFF(fp, &my_image)) 
	{
		
		
				fprintf(stderr, "error writing TIFF file %s\n", argv[3]);
				exit(1);
		
		
	}

	
	
	
	
	
	
	/* close color image file */
	fclose(fp);

	
	
	
	/* de-allocate space which was used for the images */
	free_TIFF(&(my_image));

	return(0);
}

