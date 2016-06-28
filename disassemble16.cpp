#include<stdio.h>
#include<string.h>


static char* getregister(char arg0);
static char* getrm(char arg0);
static char* getregisteral(char arg0);
static char* getrmal(char arg0);
static char* getrm2(char arg0);

void disassemble16( char* arg0 ) {

	int pos = 0;
	unsigned char* data = (unsigned char*)arg0;

begin:
	printf("%04x      ", pos);
	switch (data[pos]) {
	case 0x06:
		printf("%02x    push es\n", data[pos]);
		pos++;
		goto begin;
	case 0x07:
		printf("%02x    pop es\n", data[pos]);
		pos++;
		goto begin;
	case 0x0f:
		/* 0x84 */
		if (data[pos + 1] == 0x85) {
			printf("%02x%02x%02x%02x    jz +0x%02x%02x\n",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3],
				data[pos + 3], data[pos + 2]
				);
			pos += 4;
			goto begin;
		}
		/* 0x85 */
		if ( data[pos+1] == 0x85 ) {
			printf("%02x%02x%02x%02x    jnz +0x%02x%02x\n",
				data[pos], data[pos+1], data[pos+2], data[pos+3],
				data[pos+3], data[pos+2]
				);
			pos += 4;
			goto begin;
		}
		goto r;
	case 0x1e:
		printf("%02x    push ds\n", data[pos]);
		pos++;
		goto begin;
	case 0x1f:
		printf("%02x    pop ds\n", data[pos]);
		pos++;
		goto begin;
	case 0x24:
		printf("%02x%02x    and al,0x%02x\n", 
			data[pos],data[pos+1],data[pos+1]
			);
		pos+=2;
		goto begin;
	case 0x31:
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			printf("%02x%02x    xor %s,%s\n",
				data[pos], data[pos + 1],
				getregister(data[pos + 1]), getrm(data[pos + 1])
			);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x3c:
		printf("%02x%02x    cmp al,0x%02x\n",
			data[pos], data[pos + 1], data[pos + 1]
		);
		pos += 2;
		goto begin;
	case 0x40:
		printf("%02x    inc ax\n", data[pos]);
		pos++;
		goto begin;
	case 0x41:
		printf("%02x    inc cx\n", data[pos]);
		pos++;
		goto begin;
	case 0x42:
		printf("%02x    inc dx\n", data[pos]);
		pos++;
		goto begin;
	case 0x43:
		printf("%02x    inc bx\n", data[pos]);
		pos++;
		goto begin;
	case 0x44:
		printf("%02x    inc sp\n", data[pos]);
		pos++;
		goto begin;
	case 0x45:
		printf("%02x    inc bp\n", data[pos]);
		pos++;
		goto begin;
	case 0x46:
		printf("%02x    inc si\n", data[pos]);
		pos++;
		goto begin;
	case 0x47:
		printf("%02x    inc di\n", data[pos]);
		pos++;
		goto begin;
	case 0x48:
		printf("%02x    dec ax\n", data[pos]);
		pos++;
		goto begin;
	case 0x49:
		printf("%02x    dec cx\n", data[pos]);
		pos++;
		goto begin;
	case 0x4a:
		printf("%02x    dec dx\n", data[pos]);
		pos++;
		goto begin;
	case 0x4b:
		printf("%02x    dec bx\n", data[pos]);
		pos++;
		goto begin;
	case 0x4c:
		printf("%02x    dec sp\n", data[pos]);
		pos++;
		goto begin;
	case 0x4d:
		printf("%02x    dec bp\n", data[pos]);
		pos++;
		goto begin;
	case 0x4e:
		printf("%02x    dec si\n", data[pos]);
		pos++;
		goto begin;
	case 0x4f:
		printf("%02x    dec di\n", data[pos]);
		pos++;
		goto begin;
	case 0x50:
		printf("%02x    push ax\n", data[pos]);
		pos++;
		goto begin;
	case 0x51:
		printf("%02x    push cx\n", data[pos]);
		pos++;
		goto begin;
	case 0x52:
		printf("%02x    push dx\n", data[pos]);
		pos++;
		goto begin;
	case 0x53:
		printf("%02x    push bx\n",data[pos]);
		pos++;
		goto begin;
	case 0x54:
		printf("%02x    push sp\n", data[pos]);
		pos++;
		goto begin;
	case 0x55:
		printf("%02x    push bp\n", data[pos]);
		pos++;
		goto begin;
	case 0x56:
		printf("%02x    push si\n", data[pos]);
		pos++;
		goto begin;
	case 0x57:
		printf("%02x    push di\n", data[pos]);
		pos++;
		goto begin;
	case 0x58:
		printf("%02x    pop ax\n", data[pos]);
		pos++;
		goto begin;
	case 0x59:
		printf("%02x    pop cx\n", data[pos]);
		pos++;
		goto begin;
	case 0x5a:
		printf("%02x    pop dx\n", data[pos]);
		pos++;
		goto begin;
	case 0x5b:
		printf("%02x    pop bx\n", data[pos]);
		pos++;
		goto begin;
	case 0x5c:
		printf("%02x    pop sp\n", data[pos]);
		pos++;
		goto begin;
	case 0x5d:
		printf("%02x    pop bp\n", data[pos]);
		pos++;
		goto begin;
	case 0x5e:
		printf("%02x    pop si\n", data[pos]);
		pos++;
		goto begin;
	case 0x5f:
		printf("%02x    pop di\n", data[pos]);
		pos++;
		goto begin;
	case 0x60:
		printf("%02x    pushaw\n", data[pos]);
		pos++;
		goto begin;
	case 0x61:
		printf("%02x    popaw\n", data[pos]);
		pos++;
		goto begin;
	case 0x66:
		printf("%02x    66\n", data[pos]);
		pos++;
		goto begin;
	case 0x74:
		printf("%02x%02x    jz +0x%02x\n",
			data[pos], data[pos + 1], data[pos + 1]
		);
		pos += 2;
		goto begin;
	case 0x75:
		printf("%02x%02x    jnz +0x%02x\n",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x76:
		printf("%02x%02x    jbe +0x%02x\n",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x77:
		printf("%02x%02x    ja +0x%02x\n",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x78:
		printf("%02x%02x    js +0x%02x\n",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x79:
		printf("%02x%02x    jns +0x%02x\n",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x7a:
		printf("%02x%02x    jp +0x%02x\n",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x7b:
		printf("%02x%02x    jnp +0x%02x\n",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x7c:
		printf("%02x%02x    jl +0x%02x\n",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x7d:
		printf("%02x%02x    jge +0x%02x\n",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x7e:
		printf("%02x%02x    jle +0x%02x\n",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x7f:
		printf("%02x%02x    jg +0x%02x\n",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x80:
		/* 00_000_??? */
		if ((data[pos + 1] & 0xf8) == 0x00) {
			printf("%02x%02x%02x    add byte[%s],0x%02x\n",
				data[pos], data[pos + 1], data[pos + 2],
				getrm(data[pos + 1]), data[pos + 2]
				);
			pos += 3;
			goto begin;
		}
		goto begin;
	case 0x83:
		/* 11_000_??? */
		if ((data[pos + 1] & 0xf8) == 0xc0) {
			printf("%02x%02x%02x    add %s,0x%02x\n", 
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0x84:
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			printf("%02x%02x    test %s,%s\n",
				data[pos], data[pos + 1],
				getregisteral(data[pos + 1]), getrmal(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x88:
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			printf("%02x%02x%02x    mov [%s+0x%02x],%s\n",
				data[pos], data[pos + 1], data[pos + 2],
				getrm2(data[pos + 1]), data[pos + 2],
				getregisteral(data[pos + 1])
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			printf("%02x%02x    mov %s,%s\n",
				data[pos], data[pos + 1],
				getrmal(data[pos + 1]), getregisteral(data[pos + 1])
			);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x89:
		/* 01_???_110 */
		if ((data[pos + 1] & 0xc7) == 0x46) {
			printf("%02x%02x%02x    mov word ss:[bp+0x%02x],%s\n",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 2], getregister(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			printf("%02x%02x    mov %s,%s\n", 
				data[pos],data[pos+1],
				getrm(data[pos+1]),getregister(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x8a:
		/* 00_???_110 */
		if ((data[pos + 1] & 0xc7) == 0x06) {
			printf("%02x%02x%02x%02x    mov %s,ds:0x%02x%02x\n",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3],
				getregisteral(data[pos + 1]),
				data[pos + 3], data[pos + 2]
				);
			pos += 4;
			goto begin;
		}
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			printf("%02x%02x    mov %s,[%s]\n",
				data[pos], data[pos + 1],
				getregisteral(data[pos + 1]), getrm2(data[pos+1])
				);
			pos += 2;
			goto begin;
		}

		/* 01_???_110 */
		if ((data[pos + 1] & 0xc7) == 0x46) {
			printf("%02x%02x%02x    mov %s,word ss:[bp+0x%02x]\n",
				data[pos], data[pos + 1], data[pos + 2], 
				getregisteral(data[pos + 1]),data[pos + 2]
				);
			pos += 3;
			goto begin;
		}

		goto r;
	case 0x8b:
		/* 01_???_110 */
		if ((data[pos + 1] & 0xc7) == 0x46) {
			printf("%02x%02x%02x    mov %s,word ss:[bp+0x%02x]\n",
				data[pos], data[pos + 1], data[pos + 2],
				getregister(data[pos + 1]), data[pos + 2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0x8c:
		/* 11_001_??? */
		if ((data[pos + 1] & 0xf8) == 0xc8) {
			printf("%02x%02x    mov %s,cs\n",
				data[pos], data[pos + 1],
				getrm(data[pos + 1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x8d:
		/* 01_???_110 */
		if ((data[pos + 1] & 0xc7) == 0x46) {
			printf("%02x%02x%02x    lea %s,word ss:[bp+0x%02x]\n",
				data[pos], data[pos + 1], data[pos + 2], 
				getregister(data[pos + 1]),data[pos + 2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0x8e:
		/* 0x5e */
		if (data[pos+1]==0x5e) {
			printf("%02x%02x%02x    mov ds,word ss:[bp+0x%02x]\n",
				data[pos],data[pos+1],data[pos+2],data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0xa4:
		printf("%02x    movsb\n", data[pos]);
		pos++;
		goto begin;
	case 0xaa:
		printf("%02x    stosb\n", data[pos]);
		pos++;
		goto begin;
	case 0xb0:
		printf("%02x%02x    mov al,0x%02x\n",
			data[pos], data[pos + 1], data[pos + 1]
		);
		pos += 2;
		goto begin;
	case 0xb1:
		printf("%02x%02x    mov cl,0x%02x\n",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xb2:
		printf("%02x%02x    mov dl,0x%02x\n",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xb3:
		printf("%02x%02x    mov bl,0x%02x\n",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xb4:
		printf("%02x%02x    mov ah,0x%02x\n",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xb5:
		printf("%02x%02x    mov ch,0x%02x\n",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xb6:
		printf("%02x%02x    mov dh,0x%02x\n",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xb7:
		printf("%02x%02x    mov bh,0x%02x\n",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xb8:
		printf("%02x%02x%02x    mov ax,0x%02x%02x\n",
			data[pos], data[pos + 1], data[pos + 2],
			data[pos + 2], data[pos + 1]
		);
		pos += 3;
		goto begin;
	case 0xb9:
		printf("%02x%02x%02x    mov cx,0x%02x%02x\n",
			data[pos], data[pos + 1], data[pos + 2],
			data[pos + 2], data[pos + 1]
			);
		pos += 3;
		goto begin;
	case 0xba:
		printf("%02x%02x%02x    mov dx,0x%02x%02x\n",
			data[pos], data[pos + 1], data[pos + 2],
			data[pos + 2], data[pos + 1]
			);
		pos += 3;
		goto begin;
	case 0xbb:
		printf("%02x%02x%02x    mov bx,0x%02x%02x\n",
			data[pos], data[pos + 1], data[pos + 2],
			data[pos + 2], data[pos + 1]
			);
		pos += 3;
		goto begin;
	case 0xbc:
		printf("%02x%02x%02x    mov sp,0x%02x%02x\n",
			data[pos], data[pos + 1], data[pos + 2],
			data[pos + 2], data[pos + 1]
			);
		pos += 3;
		goto begin;
	case 0xbd:
		printf("%02x%02x%02x    mov bp,0x%02x%02x\n",
			data[pos], data[pos + 1], data[pos + 2],
			data[pos + 2], data[pos + 1]
			);
		pos += 3;
		goto begin;
	case 0xbe:
		printf("%02x%02x%02x    mov si,0x%02x%02x\n",
			data[pos], data[pos + 1], data[pos + 2],
			data[pos + 2], data[pos + 1]
			);
		pos += 3;
		goto begin;
	case 0xbf:
		printf("%02x%02x%02x    mov di,0x%02x%02x\n",
			data[pos], data[pos + 1], data[pos + 2],
			data[pos + 2], data[pos + 1]
			);
		pos += 3;
		goto begin;
	case 0xc3:
		printf("%02x    ret\n", data[pos]);
		pos++;
		goto begin;
	case 0xc4:
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			printf("%02x%02x%02x    les %s,[%s+0x%02x]\n",
				data[pos], data[pos + 1], data[pos + 2],
				getregister(data[pos + 1]),getrm2(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0xc5:
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			printf("%02x%02x%02x    lds %s,[%s+0x%02x]\n",
				data[pos], data[pos + 1], data[pos + 2],
				getregister(data[pos + 1]), getrm2(data[pos + 1]), data[pos + 2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0xe3:
		printf("%02x%02x    jcxz +0x%02x\n",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xe4:
		printf("%02x%02x    in al,0x%02x\n",
			data[pos], data[pos + 1], data[pos + 1]
		);
		pos += 2;
		goto begin;
	case 0xe6:
		printf("%02x%02x    out 0x%02x,al\n",
			data[pos], data[pos + 1], data[pos + 1]
		);
		pos += 2;
		goto begin;
	case 0xe8:
		printf("%02x%02x%02x    call 0x%02x%02x\n", 
			data[pos],data[pos+1],data[pos+2],
			data[pos+2],data[pos+1]
			);
		pos += 3;
		goto begin;
	case 0xe9:
		printf("%02x%02x%02x    jmp +0x%02x%02x\n",
			data[pos], data[pos + 1], data[pos + 2],
			data[pos + 2], data[pos + 1]
			);
		pos += 3;
		goto begin;
	case 0xea:
		printf("%02x%02x%02x%02x%02x    jmpf 0x%02x%02x:%02x%02x\n",
			data[pos], data[pos + 1], data[pos + 2],
			data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 2]
		);
		pos += 5;
		goto begin;
	case 0xf3:
		printf("%02x    rep\n", data[pos]);
		pos++;
		goto begin;
	case 0xfa:
		printf("%02x    cli\n", data[pos]);
		pos++;
		goto begin;
	case 0xfb:
		printf("%02x    sti\n", data[pos]);
		pos++;
		goto begin;
	case 0xfc:
		printf("%02x    cld\n", data[pos]);
		pos++;
		goto begin;
	case 0xfd:
		printf("%02x    std\n", data[pos]);
		pos++;
		goto begin;
	default:
		goto r;
	}

r:
	printf("it over : %02x%02x\n", data[pos], data[pos + 1]);
	return;
}


static char* getrmal(char arg0) {
	switch ((arg0 & 0x7))
	{
	case 0x00:
		return "al";
	case 0x01:
		return "cl";
	case 0x02:
		return "dl";
	case 0x03:
		return "bl";
	case 0x04:
		return "ah";
	case 0x05:
		return "ch";
	case 0x06:
		return "dh";
	case 0x07:
		return "bh";
	default:
		return "unknown";
	}
}

static char* getrm(char arg0) {
	switch ((arg0 & 0x7))
	{
	case 0x00:
		return "ax";
	case 0x01:
		return "cx";
	case 0x02:
		return "dx";
	case 0x03:
		return "bx";
	case 0x04:
		return "sp";
	case 0x05:
		return "bp";
	case 0x06:
		return "si";
	case 0x07:
		return "di";
	default:
		return "unknown";
	}
}

static char* getrm2(char arg0) {
	switch ((arg0 & 0x7))
	{
	case 0x00:
		return "bx+si";
	case 0x01:
		return "bx+di";
	case 0x02:
		return "bp+si";
	case 0x03:
		return "bp+di";
	case 0x04:
		return "si";
	case 0x05:
		return "di";
	case 0x06:
		return "bp";
	case 0x07:
		return "bx";
	default:
		return "unknown";
	}
}

static char* getregisteral(char arg0) {
	switch ((arg0 & 0x38))
	{
	case 0x00:
		return "al";
	case 0x08:
		return "cl";
	case 0x10:
		return "dl";
	case 0x18:
		return "bl";
	case 0x20:
		return "ah";
	case 0x28:
		return "ch";
	case 0x30:
		return "dh";
	case 0x38:
		return "bh";
	default:
		return "unknown";
	}
}

static char* getregister(char arg0) {
	switch ((arg0 & 0x38))
	{
	case 0x00:
		return "ax";
	case 0x08:
		return "cx";
	case 0x10:
		return "dx";
	case 0x18:
		return "bx";
	case 0x20:
		return "sp";
	case 0x28:
		return "bp";
	case 0x30:
		return "si";
	case 0x38:
		return "di";
	default:
		return "unknown";
	}
}




