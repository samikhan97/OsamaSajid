[org 0x0100]

mov ax,[n1]
mov dx,[n2]

cmp dx,ax
jbe noswap

mov bx,ax
mov ax,dx
mov dx,bx
	
noswap:
	mov cl,1
	
l1:
	mov ax,[n1]
	DIV cl
	cmp ah,0
	jne NotTrue
	

	mov ax,[n2]
	DIV cl
	cmp ah,0
	jne NotTrue
	
	mov [hcf],cx
	
NotTrue:

	add cl,1
	cmp cl,dl
	jne l1



mov ax, 0x4c00 ; terminate program
int 0x21

n1: dw 0x0008
n2: dw 0x0004
hcf: dw 0x0000
