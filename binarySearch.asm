[org 0x0100]	

	mov cx,0xffff
	mov dx,0		; stores index in dx
	mov bx,0		; starting index
	mov di,[length]		; ending index
loop1:	mov si,di
	sub si,bx
	shr si,1	;
	add si,bx
	cmp word[search_array+si],bin_search
	jb larger
	cmp word[search_array+si],bin_search
	jg smaller
	

larger:
	mov di,si
	jmp loop1

smaller: 
	cmp word[search_array+si],bin_search
	jnz found
	mov bx,si
	jmp loop1

found:
	
mov cx,si
	
					
	
	
	
	








mov ax,0x4c00
int 0x21

search_array: dw 0x1,0x3,0x4,0x5,0x6,0x8
bin_search:   dw 0x4 
length:       dw 0x6	
