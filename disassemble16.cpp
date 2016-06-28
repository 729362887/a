#include<stdio.h>
#include<string.h>


static char* getregister(char arg0);
static char* getrm(char arg0);
static char* getregisteral(char arg0);
static char* getrmal(char arg0);
static char* getrm2(char arg0);

static char buffer[0x40];

char* disassemble16(char* arg0, int* arg1) {

	unsigned char* data = (unsigned char*)arg0;
	int pos = 0;

	/* clear buffer */
	memset(buffer, 0, sizeof(buffer));

	switch (data[pos]) {
	case 0x03:
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			snprintf(buffer, sizeof(buffer), "%02x%02x    add %s,[%s]",
				data[pos], data[pos + 1],
				getregister(data[pos + 1]), getrm2(data[pos + 1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x06:
		snprintf(buffer, sizeof(buffer), "%02x    push es", data[pos]);
		pos++;
		goto begin;
	case 0x07:
		snprintf(buffer, sizeof(buffer), "%02x    pop es", data[pos]);
		pos++;
		goto begin;
	case 0x0f:
		/* 0x84 */
		if (data[pos + 1] == 0x85) {
			snprintf(buffer, sizeof(buffer), "%02x%02x%02x%02x    jz +0x%02x%02x",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3],
				data[pos + 3], data[pos + 2]
				);
			pos += 4;
			goto begin;
		}
		/* 0x85 */
		if (data[pos + 1] == 0x85) {
			snprintf(buffer, sizeof(buffer), "%02x%02x%02x%02x    jnz +0x%02x%02x",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3],
				data[pos + 3], data[pos + 2]
				);
			pos += 4;
			goto begin;
		}
		goto r;
	case 0x13:
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer, sizeof(buffer), "%02x%02x%02x    adc %s,[%s+0x%02x]",
				data[pos], data[pos + 1], data[pos + 2],
				getregister(data[pos + 1]), getrm2(data[pos + 1]), data[pos + 2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0x1e:
		snprintf(buffer, sizeof(buffer), "%02x    push ds", data[pos]);
		pos++;
		goto begin;
	case 0x1f:
		snprintf(buffer, sizeof(buffer), "%02x    pop ds", data[pos]);
		pos++;
		goto begin;
	case 0x23:
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			snprintf(buffer, sizeof(buffer), "%02x%02x    and %s,[%s]",
				data[pos], data[pos + 1],
				getregister(data[pos + 1]), getrm2(data[pos + 1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer, sizeof(buffer), "%02x%02x%02x    and %s,[%s]",
				data[pos], data[pos + 1], data[pos + 2],
				getregister(data[pos + 1]), getrm2(data[pos + 1]), data[pos + 2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0x24:
		snprintf(buffer, sizeof(buffer), "%02x%02x    and al,0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x25:
		snprintf(buffer, sizeof(buffer), "%02x%02x%02x    and ax,0x%02x%02x",
			data[pos], data[pos + 1], data[pos + 2],
			data[pos + 2], data[pos + 1]
			);
		pos += 3;
		goto begin;
	case 0x31:
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			snprintf(buffer, sizeof(buffer), "%02x%02x    xor %s,%s",
				data[pos], data[pos + 1],
				getregister(data[pos + 1]), getrm(data[pos + 1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x36:
		snprintf(buffer, sizeof(buffer), "%02x    ss", data[pos]);
		pos++;
		goto begin;
	case 0x3c:
		snprintf(buffer, sizeof(buffer), "%02x%02x    cmp al,0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x40:
		snprintf(buffer, sizeof(buffer), "%02x    inc ax", data[pos]);
		pos++;
		goto begin;
	case 0x41:
		snprintf(buffer, sizeof(buffer), "%02x    inc cx", data[pos]);
		pos++;
		goto begin;
	case 0x42:
		snprintf(buffer, sizeof(buffer), "%02x    inc dx", data[pos]);
		pos++;
		goto begin;
	case 0x43:
		snprintf(buffer, sizeof(buffer), "%02x    inc bx", data[pos]);
		pos++;
		goto begin;
	case 0x44:
		snprintf(buffer, sizeof(buffer), "%02x    inc sp", data[pos]);
		pos++;
		goto begin;
	case 0x45:
		snprintf(buffer, sizeof(buffer), "%02x    inc bp", data[pos]);
		pos++;
		goto begin;
	case 0x46:
		snprintf(buffer, sizeof(buffer), "%02x    inc si", data[pos]);
		pos++;
		goto begin;
	case 0x47:
		snprintf(buffer, sizeof(buffer), "%02x    inc di", data[pos]);
		pos++;
		goto begin;
	case 0x48:
		snprintf(buffer, sizeof(buffer), "%02x    dec ax", data[pos]);
		pos++;
		goto begin;
	case 0x49:
		snprintf(buffer, sizeof(buffer), "%02x    dec cx", data[pos]);
		pos++;
		goto begin;
	case 0x4a:
		snprintf(buffer, sizeof(buffer), "%02x    dec dx", data[pos]);
		pos++;
		goto begin;
	case 0x4b:
		snprintf(buffer, sizeof(buffer), "%02x    dec bx", data[pos]);
		pos++;
		goto begin;
	case 0x4c:
		snprintf(buffer, sizeof(buffer), "%02x    dec sp", data[pos]);
		pos++;
		goto begin;
	case 0x4d:
		snprintf(buffer, sizeof(buffer), "%02x    dec bp", data[pos]);
		pos++;
		goto begin;
	case 0x4e:
		snprintf(buffer, sizeof(buffer), "%02x    dec si", data[pos]);
		pos++;
		goto begin;
	case 0x4f:
		snprintf(buffer, sizeof(buffer), "%02x    dec di", data[pos]);
		pos++;
		goto begin;
	case 0x50:
		snprintf(buffer, sizeof(buffer), "%02x    push ax", data[pos]);
		pos++;
		goto begin;
	case 0x51:
		snprintf(buffer, sizeof(buffer), "%02x    push cx", data[pos]);
		pos++;
		goto begin;
	case 0x52:
		snprintf(buffer, sizeof(buffer), "%02x    push dx", data[pos]);
		pos++;
		goto begin;
	case 0x53:
		snprintf(buffer, sizeof(buffer), "%02x    push bx", data[pos]);
		pos++;
		goto begin;
	case 0x54:
		snprintf(buffer, sizeof(buffer), "%02x    push sp", data[pos]);
		pos++;
		goto begin;
	case 0x55:
		snprintf(buffer, sizeof(buffer), "%02x    push bp", data[pos]);
		pos++;
		goto begin;
	case 0x56:
		snprintf(buffer, sizeof(buffer), "%02x    push si", data[pos]);
		pos++;
		goto begin;
	case 0x57:
		snprintf(buffer, sizeof(buffer), "%02x    push di", data[pos]);
		pos++;
		goto begin;
	case 0x58:
		snprintf(buffer, sizeof(buffer), "%02x    pop ax", data[pos]);
		pos++;
		goto begin;
	case 0x59:
		snprintf(buffer, sizeof(buffer), "%02x    pop cx", data[pos]);
		pos++;
		goto begin;
	case 0x5a:
		snprintf(buffer, sizeof(buffer), "%02x    pop dx", data[pos]);
		pos++;
		goto begin;
	case 0x5b:
		snprintf(buffer, sizeof(buffer), "%02x    pop bx", data[pos]);
		pos++;
		goto begin;
	case 0x5c:
		snprintf(buffer, sizeof(buffer), "%02x    pop sp", data[pos]);
		pos++;
		goto begin;
	case 0x5d:
		snprintf(buffer, sizeof(buffer), "%02x    pop bp", data[pos]);
		pos++;
		goto begin;
	case 0x5e:
		snprintf(buffer, sizeof(buffer), "%02x    pop si", data[pos]);
		pos++;
		goto begin;
	case 0x5f:
		snprintf(buffer, sizeof(buffer), "%02x    pop di", data[pos]);
		pos++;
		goto begin;
	case 0x60:
		snprintf(buffer, sizeof(buffer), "%02x    pushaw", data[pos]);
		pos++;
		goto begin;
	case 0x61:
		snprintf(buffer, sizeof(buffer), "%02x    popaw", data[pos]);
		pos++;
		goto begin;
	case 0x66:
		goto begin;
	case 0x74:
		snprintf(buffer, sizeof(buffer), "%02x%02x    jz +0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x75:
		snprintf(buffer, sizeof(buffer), "%02x%02x    jnz +0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x76:
		snprintf(buffer, sizeof(buffer), "%02x%02x    jbe +0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x77:
		snprintf(buffer, sizeof(buffer), "%02x%02x    ja +0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x78:
		snprintf(buffer, sizeof(buffer), "%02x%02x    js +0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x79:
		snprintf(buffer, sizeof(buffer), "%02x%02x    jns +0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x7a:
		snprintf(buffer, sizeof(buffer), "%02x%02x    jp +0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x7b:
		snprintf(buffer, sizeof(buffer), "%02x%02x    jnp +0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x7c:
		snprintf(buffer, sizeof(buffer), "%02x%02x    jl +0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x7d:
		snprintf(buffer, sizeof(buffer), "%02x%02x    jge +0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x7e:
		snprintf(buffer, sizeof(buffer), "%02x%02x    jle +0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x7f:
		snprintf(buffer, sizeof(buffer), "%02x%02x    jg +0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x80:
		/* 00_000_??? */
		if ((data[pos + 1] & 0xf8) == 0x00) {
			snprintf(buffer, sizeof(buffer), "%02x%02x%02x    add byte[%s],0x%02x",
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
			snprintf(buffer, sizeof(buffer), "%02x%02x%02x    add %s,0x%02x",
				data[pos], data[pos + 1], data[pos + 2],
				getrm(data[pos + 1]), data[pos + 2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0x84:
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			snprintf(buffer, sizeof(buffer), "%02x%02x    test %s,%s",
				data[pos], data[pos + 1],
				getregisteral(data[pos + 1]), getrmal(data[pos + 1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x88:
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer, sizeof(buffer), "%02x%02x%02x    mov [%s+0x%02x],%s",
				data[pos], data[pos + 1], data[pos + 2],
				getrm2(data[pos + 1]), data[pos + 2],
				getregisteral(data[pos + 1])
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			snprintf(buffer, sizeof(buffer), "%02x%02x    mov %s,%s",
				data[pos], data[pos + 1],
				getrmal(data[pos + 1]), getregisteral(data[pos + 1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x89:
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			snprintf(buffer, sizeof(buffer), "%02x%02x    mov [%s],%s",
				data[pos], data[pos + 1],
				getrm2(data[pos + 1]), getregister(data[pos + 1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_110 */
		if ((data[pos + 1] & 0xc7) == 0x46) {
			snprintf(buffer, sizeof(buffer), "%02x%02x%02x    mov word ss:[bp+0x%02x],%s",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 2], getregister(data[pos + 1])
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			snprintf(buffer, sizeof(buffer), "%02x%02x    mov %s,%s",
				data[pos], data[pos + 1],
				getrm(data[pos + 1]), getregister(data[pos + 1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x8a:
		/* 00_???_110 */
		if ((data[pos + 1] & 0xc7) == 0x06) {
			snprintf(buffer, sizeof(buffer), "%02x%02x%02x%02x    mov %s,ds:0x%02x%02x",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3],
				getregisteral(data[pos + 1]),
				data[pos + 3], data[pos + 2]
				);
			pos += 4;
			goto begin;
		}
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			snprintf(buffer, sizeof(buffer), "%02x%02x    mov %s,[%s]",
				data[pos], data[pos + 1],
				getregisteral(data[pos + 1]), getrm2(data[pos + 1])
				);
			pos += 2;
			goto begin;
		}

		/* 01_???_110 */
		if ((data[pos + 1] & 0xc7) == 0x46) {
			snprintf(buffer, sizeof(buffer), "%02x%02x%02x    mov %s,word ss:[bp+0x%02x]",
				data[pos], data[pos + 1], data[pos + 2],
				getregisteral(data[pos + 1]), data[pos + 2]
				);
			pos += 3;
			goto begin;
		}

		goto r;
	case 0x8b:
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			snprintf(buffer, sizeof(buffer), "%02x%02x    mov %s,[%s]",
				data[pos], data[pos + 1],
				getregister(data[pos + 1]), getrm2(data[pos + 1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_110 */
		if ((data[pos + 1] & 0xc7) == 0x46) {
			snprintf(buffer, sizeof(buffer), "%02x%02x%02x    mov %s,word ss:[bp+0x%02x]",
				data[pos], data[pos + 1], data[pos + 2],
				getregister(data[pos + 1]), data[pos + 2]
				);
			pos += 3;
			goto begin;
		}
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer, sizeof(buffer), "%02x%02x%02x    mov %s,[%s+0x%02x]",
				data[pos], data[pos + 1], data[pos + 2],
				getregister(data[pos + 1]), getrm2(data[pos + 1]), data[pos + 2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0x8c:
		/* 11_001_??? */
		if ((data[pos + 1] & 0xf8) == 0xc8) {
			snprintf(buffer, sizeof(buffer), "%02x%02x    mov %s,cs",
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
			snprintf(buffer, sizeof(buffer), "%02x%02x%02x    lea %s,word ss:[bp+0x%02x]",
				data[pos], data[pos + 1], data[pos + 2],
				getregister(data[pos + 1]), data[pos + 2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0x8e:
		/* 0x5e */
		if (data[pos + 1] == 0x5e) {
			snprintf(buffer, sizeof(buffer), "%02x%02x%02x    mov ds,word ss:[bp+0x%02x]",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0xa4:
		snprintf(buffer, sizeof(buffer), "%02x    movsb", data[pos]);
		pos++;
		goto begin;
	case 0xa5:
		snprintf(buffer, sizeof(buffer), "%02x    movsd", data[pos]);
		pos++;
		goto begin;
	case 0xaa:
		snprintf(buffer, sizeof(buffer), "%02x    stosb", data[pos]);
		pos++;
		goto begin;
	case 0xb0:
		snprintf(buffer, sizeof(buffer), "%02x%02x    mov al,0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xb1:
		snprintf(buffer, sizeof(buffer), "%02x%02x    mov cl,0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xb2:
		snprintf(buffer, sizeof(buffer), "%02x%02x    mov dl,0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xb3:
		snprintf(buffer, sizeof(buffer), "%02x%02x    mov bl,0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xb4:
		snprintf(buffer, sizeof(buffer), "%02x%02x    mov ah,0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xb5:
		snprintf(buffer, sizeof(buffer), "%02x%02x    mov ch,0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xb6:
		snprintf(buffer, sizeof(buffer), "%02x%02x    mov dh,0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xb7:
		snprintf(buffer, sizeof(buffer), "%02x%02x    mov bh,0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xb8:
		snprintf(buffer, sizeof(buffer), "%02x%02x%02x    mov ax,0x%02x%02x",
			data[pos], data[pos + 1], data[pos + 2],
			data[pos + 2], data[pos + 1]
			);
		pos += 3;
		goto begin;
	case 0xb9:
		snprintf(buffer, sizeof(buffer), "%02x%02x%02x    mov cx,0x%02x%02x",
			data[pos], data[pos + 1], data[pos + 2],
			data[pos + 2], data[pos + 1]
			);
		pos += 3;
		goto begin;
	case 0xba:
		snprintf(buffer, sizeof(buffer), "%02x%02x%02x    mov dx,0x%02x%02x",
			data[pos], data[pos + 1], data[pos + 2],
			data[pos + 2], data[pos + 1]
			);
		pos += 3;
		goto begin;
	case 0xbb:
		snprintf(buffer, sizeof(buffer), "%02x%02x%02x    mov bx,0x%02x%02x",
			data[pos], data[pos + 1], data[pos + 2],
			data[pos + 2], data[pos + 1]
			);
		pos += 3;
		goto begin;
	case 0xbc:
		snprintf(buffer, sizeof(buffer), "%02x%02x%02x    mov sp,0x%02x%02x",
			data[pos], data[pos + 1], data[pos + 2],
			data[pos + 2], data[pos + 1]
			);
		pos += 3;
		goto begin;
	case 0xbd:
		snprintf(buffer, sizeof(buffer), "%02x%02x%02x    mov bp,0x%02x%02x",
			data[pos], data[pos + 1], data[pos + 2],
			data[pos + 2], data[pos + 1]
			);
		pos += 3;
		goto begin;
	case 0xbe:
		snprintf(buffer, sizeof(buffer), "%02x%02x%02x    mov si,0x%02x%02x",
			data[pos], data[pos + 1], data[pos + 2],
			data[pos + 2], data[pos + 1]
			);
		pos += 3;
		goto begin;
	case 0xbf:
		snprintf(buffer, sizeof(buffer), "%02x%02x%02x    mov di,0x%02x%02x",
			data[pos], data[pos + 1], data[pos + 2],
			data[pos + 2], data[pos + 1]
			);
		pos += 3;
		goto begin;
	case 0xc3:
		snprintf(buffer, sizeof(buffer), "%02x    ret", data[pos]);
		pos++;
		goto begin;
	case 0xc4:
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer, sizeof(buffer), "%02x%02x%02x    les %s,[%s+0x%02x]",
				data[pos], data[pos + 1], data[pos + 2],
				getregister(data[pos + 1]), getrm2(data[pos + 1]), data[pos + 2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0xc5:
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer, sizeof(buffer), "%02x%02x%02x    lds %s,[%s+0x%02x]",
				data[pos], data[pos + 1], data[pos + 2],
				getregister(data[pos + 1]), getrm2(data[pos + 1]), data[pos + 2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0xe3:
		snprintf(buffer, sizeof(buffer), "%02x%02x    jcxz +0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xe4:
		snprintf(buffer, sizeof(buffer), "%02x%02x    in al,0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xe6:
		snprintf(buffer, sizeof(buffer), "%02x%02x    out 0x%02x,al",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xe8:
		snprintf(buffer, sizeof(buffer), "%02x%02x%02x    call 0x%02x%02x",
			data[pos], data[pos + 1], data[pos + 2],
			data[pos + 2], data[pos + 1]
			);
		pos += 3;
		goto begin;
	case 0xe9:
		snprintf(buffer, sizeof(buffer), "%02x%02x%02x    jmp +0x%02x%02x",
			data[pos], data[pos + 1], data[pos + 2],
			data[pos + 2], data[pos + 1]
			);
		pos += 3;
		goto begin;
	case 0xea:
		snprintf(buffer, sizeof(buffer), "%02x%02x%02x%02x%02x    jmpf 0x%02x%02x:%02x%02x",
			data[pos], data[pos + 1], data[pos + 2],
			data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 2]
			);
		pos += 5;
		goto begin;
	case 0xf3:
		snprintf(buffer, sizeof(buffer), "%02x    rep", data[pos]);
		pos++;
		goto begin;
	case 0xfa:
		snprintf(buffer, sizeof(buffer), "%02x    cli", data[pos]);
		pos++;
		goto begin;
	case 0xfb:
		snprintf(buffer, sizeof(buffer), "%02x    sti", data[pos]);
		pos++;
		goto begin;
	case 0xfc:
		snprintf(buffer, sizeof(buffer), "%02x    cld", data[pos]);
		pos++;
		goto begin;
	case 0xfd:
		snprintf(buffer, sizeof(buffer), "%02x    std", data[pos]);
		pos++;
		goto begin;
	default:
		goto r;
	}

begin:
r:
	*arg1 = pos;
	return buffer;
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




