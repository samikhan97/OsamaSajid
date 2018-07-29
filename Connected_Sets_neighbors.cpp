#include<iostream>
using namespace std;

struct pixel
{
int row;
int col;
};
void connectedneighbours(struct pixel s,double T,unsigned char**img,int width,int height,int *M,struct pixel c[4])
{
	int s1=s.row;
	int s2=s.col;
	int index=0;
	int sf=img[s1][s2];
	int f=0;
	int r=0;
	for(int i=0;i<4;i++)
	{
		if(i=0)
		{
			if(s1-1>=0)
			{
				r=img[s1-1][s2];
				f=sf-r;
				if(f>=0)
				{
					if(f<=T)
					{
                      (*M)++;
					  c[index].col=s2;
					  c[index].row=s1-1;
					  index++;

					}
				}
				else
				{
					f=-f;
					if(f<=T)
					{
                      (*M)++;
					  c[index].col=s2;
					  c[index].row=s1-1;
					  index++;

					}
				}
			}
		}
		else if(i==1)
		{
			if(s1+1<height)
			{
				r=img[s1+1][s2];
				f=sf-r;
				if(f>=0)
				{
					if(f<=T)
					{
                      (*M)++;
					  c[index].col=s2;
					  c[index].row=s1+1;
					  index++;

					}
				}
				else
				{
					f=-f;
					if(f<=T)
					{
                      (*M)++;
					  c[index].col=s2;
					  c[index].row=s1+1;
					  index++;

					}
				}
			}
		}
		else if(i==2)
		{
			if(s2-1>=0)
			{
				r=img[s1][s2-1];
				f=sf-r;
				if(f>=0)
				{
					if(f<=T)
					{
                      (*M)++;
					  c[index].col=s2-1;
					  c[index].row=s1;
					  index++;

					}
				}
				else
				{
					f=-f;
					if(f<=T)
					{
                      (*M)++;
					  c[index].col=s2-1;
					  c[index].row=s1;
					  index++;

					}
				}
			}
		}
		else if(i==3)
		{
			if(s2+1<width)
			{
				r=img[s1][s2+1];
				f=sf-r;
				if(f>=0)
				{
					if(f<=T)
					{
                      (*M)++;
					  c[index].col=s2+1;
					  c[index].row=s1;
					  index++;

					}
				}
				else
				{
					f=-f;
					if(f<=T)
					{
                      (*M)++;
					  c[index].col=s2+1;
					  c[index].row=s1;
					  index++;

					}
				}
			}
		}		  
	}
}
void connectedset(struct pixel s,double T,unsigned char**img,int width,int height,int classlabel,unsigned int**seg,int *numconpixels)
{
	struct pixel B[4];
	connectedneighbours(s,T,img,width,height,numconpixels,B);
	for(int i=0;i<*numconpixels;i++)
	{
	   seg[B[i].row][B[i].col]=classlabel;
	}
}
int main()
{
	
	system("pause");
}
