#include<stdio.h>
#include<string.h>

static char* getregister(char arg0);
static char* getrm(char arg0);
static char* getregisteral(char arg0);
static char* getrmal(char arg0);
static char* getsib8(char arg0, char arg1);
static char* getsib32(char arg0, char arg1, char arg2, char arg3, char arg4);

void disassemble(char* arg0) {

	int pos = 0;
	unsigned char* data = (unsigned char*)arg0;

begin:
	printf("%04x      ", pos);
	switch (data[pos])
	{
	case 0x00:
		/* 00_???_??? */
		if ( ( data[pos+1] & 0xc0 ) == 0x00 ) {
			printf("%02x%02x    add byte [%s],%s(al)\n",
				data[pos],data[pos+1],getrm(data[pos+1]),getregister(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_100 */
		if ((data[pos + 1] & 0x47) == 0x44) {
			printf("%02x%02x%02x%02x    add byte %s,%s\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getsib8(data[pos+2],data[pos+3]),getregisteral(data[pos+1])
				);
			pos += 4;
			goto begin;
		}
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			printf("%02x%02x%02x    add byte [%s+0x%02x],%s\n",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2],getregisteral(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
		/* 10_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x80) {
			printf("%02x%02x%02x%02x%02x%02x      add byte [%s+0x%02x%02x%02x%02x],%s\n",
				data[pos],data[pos+1],data[pos+2],
				data[pos+3],data[pos+4],data[pos+5],
				getrm(data[pos+1]),data[pos+5],data[pos+4],data[pos+3],data[pos+2],
				getregisteral(data[pos+1])
				);
			pos += 6;
			goto begin;
		}
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			printf("%02x%02x    add %s,%s\n",
				data[pos],data[pos+1],
				getrmal(data[pos + 1]),getregisteral(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x01:
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			printf("%02x%02x%02x    add dword [%s+0x%02x],%s\n",
				data[pos], data[pos + 1], data[pos + 2],
				getrm(data[pos + 1]), data[pos + 2], getregister(data[pos + 1])
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0x02:
		/* 01_???_100 */
		if ( (data[pos+1] & 0xc7) ==0x44 ) {
			printf("%02x%02x%02x%02x    add %s,byte %s\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getregisteral(data[pos+1]),getsib8(data[pos+2],data[pos+3])
				);
			pos += 4;
			goto begin;
		}
		goto r;
	case 0x03:
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			printf("%02x%02x%02x    add %s,[%s+0x%02x]\n",
				data[pos],data[pos+1],data[pos+2],
				getregister(data[pos+1]),getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			printf("%02x%02x    add %s,%s\n", 
				data[pos],data[pos+1],
				getregister(data[pos+1]),getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x04:
		printf("%02x%02x    add al,0x%02x\n", data[pos], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x05:
		printf("%02x%02x%02x%02x%02x    add eax,0x%02x%02x%02x%02x\n", 
			data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],
			data[pos+4],data[pos+3],data[pos+2],data[pos+1]
			);
		pos += 5;
		goto begin;
	case 0x06:
		printf("%02x    push es\n", data[pos]);
		pos++;
		goto begin;
	case 0x08:
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			printf("%02x%02x    or %s,%s\n", data[pos], data[pos + 1],
				getregisteral(data[pos + 1]), getrmal(data[pos + 1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x0b:
		/* 11_???_??? */
		if ( (data[pos+1] & 0xc0) == 0xc0 ) {
			printf("%02x%02x    or %s,%s\n", data[pos],data[pos+1],
				getregister(data[pos+1]),getrm(data[pos+1])
			);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x0c:
		printf("%02x%02x    or al,0x%02x\n",
			data[pos],data[pos+1],data[pos+1]
			);
		pos += 2;
		goto begin;
	case 0x0d:
		printf("%02x%02x%02x%02x%02x    or eax,0x%02x%02x%02x%02x\n",
			data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],
			data[pos+4],data[pos+3],data[pos+2],data[pos+1]
			);
		pos += 5;
		goto begin;
	case 0x0e:
		printf("%02x    push cs\n", data[pos]);
		pos++;
		goto begin;
	case 0x0f:
		if (data[pos + 1] == 0x80) {
			printf("%02x%02x%02x%02x%02x%02x    jo +0x%02x%02x%02x%02x\n",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		if (data[pos + 1] == 0x81) {
			printf("%02x%02x%02x%02x%02x%02x    jno +0x%02x%02x%02x%02x\n",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		if (data[pos + 1] == 0x82) {
			printf("%02x%02x%02x%02x%02x%02x    jb +0x%02x%02x%02x%02x\n",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		if (data[pos + 1] == 0x83) {
			printf("%02x%02x%02x%02x%02x%02x    jae +0x%02x%02x%02x%02x\n",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		if (data[pos + 1] == 0x84) {
			printf("%02x%02x%02x%02x%02x%02x    je +0x%02x%02x%02x%02x\n",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		if ( data[pos+1] == 0x85 ) {
			printf("%02x%02x%02x%02x%02x%02x    jne +0x%02x%02x%02x%02x\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],data[pos+5],
				data[pos+5],data[pos+4],data[pos+3],data[pos+2]
				);
			pos += 6;
			goto begin;
		}
		if (data[pos + 1] == 0x86) {
			printf("%02x%02x%02x%02x%02x%02x    jbe +0x%02x%02x%02x%02x\n",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		if (data[pos + 1] == 0x87) {
			printf("%02x%02x%02x%02x%02x%02x    ja +0x%02x%02x%02x%02x\n",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		if (data[pos + 1] == 0x88) {
			printf("%02x%02x%02x%02x%02x%02x    js +0x%02x%02x%02x%02x\n",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		if (data[pos + 1] == 0x89) {
			printf("%02x%02x%02x%02x%02x%02x    jns +0x%02x%02x%02x%02x\n",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		if (data[pos + 1] == 0x8a) {
			printf("%02x%02x%02x%02x%02x%02x    jp +0x%02x%02x%02x%02x\n",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		if (data[pos + 1] == 0x8b) {
			printf("%02x%02x%02x%02x%02x%02x    jnp +0x%02x%02x%02x%02x\n",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		if (data[pos + 1] == 0x8c) {
			printf("%02x%02x%02x%02x%02x%02x    jl +0x%02x%02x%02x%02x\n",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		if (data[pos + 1] == 0x8d) {
			printf("%02x%02x%02x%02x%02x%02x    jge +0x%02x%02x%02x%02x\n",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		if (data[pos + 1] == 0x8e) {
			printf("%02x%02x%02x%02x%02x%02x    jle +0x%02x%02x%02x%02x\n",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		if (data[pos + 1] == 0x8f) {
			printf("%02x%02x%02x%02x%02x%02x    jg +0x%02x%02x%02x%02x\n",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		/* 0xa0 */
		if (data[pos+1] == 0xa0) {
			printf("%02x%02x    push fs\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xa8 */
		if (data[pos + 1] == 0xa8) {
			printf("%02x%02x    push gs\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xaf */
		if (data[pos + 1] == 0xaf) {
			/* 11_???_??? */
			if ( (data[pos+2] & 0xc0) == 0xc0 ) {
				printf("%02x%02x%02x   imul %s,%s\n",
					data[pos],data[pos+1],data[pos+2],
					getregister(data[pos+2]),getrm(data[pos+2])
					);
				pos += 3;
				goto begin;
			}
			printf("%02x%02x%02x%02x    imul %s,dword [%s+0x%02x]\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getregister(data[pos+2]),getrm(data[pos+2]),data[pos+3]
				);
			pos += 4;
			goto begin;
		}
		/* 0xb6 */
		if (data[pos + 1] == 0xb6) {
			/* 01_???_??? */
			if ((data[pos + 2] & 0xc0) == 0x40) {
				printf("%02x%02x%02x%02x    movzx %s,byte [%s+0x%02x]\n",
					data[pos],data[pos+1],data[pos+2],data[pos+3],
					getregister(data[pos+2]),getrm(data[pos+2]),data[pos+3]
					);
				pos += 4;
				goto begin;
			}
			/* 11_???_??? */
			if ((data[pos + 2] & 0xc0) == 0xc0) {
				printf("%02x%02x%02x    movzx %s,%s\n",
					data[pos],data[pos+1],data[pos+2],
					getregister(data[pos+2]),getrmal(data[pos+2])
					);
				pos += 3;
				goto begin;
			}
		}
		/* 0xb7 */
		if (data[pos+1] == 0xb7 ) {
			/* 11_???_??? */
			if ( ( data[pos+2] & 0xc0 ) == 0xc0 ) {
				printf("%02x%02x%02x    movxz %s,%s(?x)\n",
					data[pos],data[pos+1],data[pos+2],
					getregister(data[pos+2]),getrm(data[pos+2])
					);
				pos += 3;
				goto begin;
			}
		}
		if (data[pos+1]==0x9c) {
			if (data[pos+2]==0xc1) {
				printf("%02x%02x%02x    setl cl\n");
				pos += 3;
				goto begin;
			}
		}
		goto r;
	case 0x10:
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			printf("%02x%02x%02x    adc byte [%s+0x%02x],%s\n",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2],getregisteral(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
	case 0x14:
		printf("%02x%02x    adc al,0x%02x\n",
			data[pos],data[pos+1],data[pos+1]
			);
		pos += 2;
		goto begin;
	case 0x15:
		printf("%02x%02x%02x%02x%02x    adc eax,0x%02x%02x%02x%02x\n",
			data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],
			data[pos+4],data[pos+3],data[pos+2],data[pos+1]
			);
		pos += 5;
		goto begin;
	case 0x16:
		printf("%02x    push ss\n", data[pos]);
		pos++;
		goto begin;
	case 0x18:
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			printf("%02x%02x    sbb %s,%s\n",
				data[pos],data[pos+1],getregisteral(data[pos+1]),getrmal(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x1b:
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			printf("%02x%02x    sbb %s,%s\n", 
				data[pos],data[pos+1],
				getregister(data[pos+1]),getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x1e:
		printf("%02x    push ds\n", data[pos]);
		pos++;
		goto begin;
	case 0x23:
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			printf("%02x%02x    and %s,%s\n",
				data[pos],data[pos+1],
				getregister(data[pos+1]),getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x24:
		printf("%02x%02x    and al,0x%02x\n", data[pos], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x29:
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			printf("%02x%02x%02x    sub dword [%s+0x%02x],%s\n",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2],getregister(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0x2b:
		/* 01_???_100 */
		if ( (data[pos+1] & 0xc7 ) == 0x44 ) {
			printf("%02x%02x%02x%02x    sub %s,%s\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getregister(data[pos+1]),getsib8(data[pos+2],data[pos+3])
				);
			pos += 4;
			goto begin;
		}
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			printf("%02x%02x%02x    mov dword [%s+0x%02x],%s\n",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2],getregister(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ( (data[pos+1] & 0xc0) == 0xc0 ) {
			printf("%02x%02x    sub %s,%s\n", 
				data[pos],data[pos+1],
				getregister(data[pos+1]),getrm(data[pos+1])
				);
			pos += 0x2;
			goto begin;
		}
		goto r;
	case 0x31:
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			printf("%02x%02x    xor %s,%s\n",
				data[pos],data[pos+1],
				getrm(data[pos+1]),getregister(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x32:
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			printf("%02x%02x    xor %s(al),%s(al)\n",
				data[pos],data[pos],
				getregister(data[pos+1]),getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
	case 0x33:
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			printf("%02x%02x%02x    xor %s,dword [%s+0x%02x]\n",
				data[pos],data[pos+1],data[pos+2],
				getregister(data[pos+1]),getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ( ( data[pos+1] & 0xc0 ) == 0xc0 ) {
			printf("%02x%02x    xor %s,%s\n", data[pos], data[pos + 1], getregister(data[pos + 1]), getrm(data[pos + 1]));
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x35:
		printf("%02x%02x%02x%02x%02x    xor eax,0x%02x%02x%02x%02x\n",
			data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],
			data[pos+4],data[pos+3],data[pos+2],data[pos+1]
			);
		pos += 5;
		goto begin;
	case 0x36:
		printf("%02x    ss\n", data[pos]);
		pos++;
		goto begin;
	case 0x37:
		printf("%02x    aaa\n", data[pos]);
		pos++;
		goto begin;
	case 0x38:
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			printf("%02x%02x    cmp byte [%s],%s\n",
				data[pos],data[pos+1],getrm(data[pos+1]),getregisteral(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x39:
		/* 00_???_101 */
		if ((data[pos + 1] & 0xc7) == 0x5) {
			printf("%02x%02x%02x%02x%02x%02x    "
				"cmp [0x%02x%02x%02x%02x],%s\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				data[pos+4],data[pos+5],
				data[pos+5],data[pos+4],data[pos+3],data[pos+2],
				getregister(data[pos+1])
			);
			pos += 6;
			goto begin;
		}
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			printf("%02x%02x    cmp dword [%s],%s\n", 
				data[pos],data[pos+1],
				getrm(data[pos+1]),getregister(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			printf("%02x%02x%02x    cmp dword [%s+0x%02x],%s\n",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2],getregister(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0x3a:
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			printf("%02x%02x    cmp %s,%s\n",
				data[pos],data[pos+1],getregisteral(data[pos+1]),getrmal(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x3b:
		/* 00_???_101 */
		if ((data[pos + 1] & 0xc7) == 0x5) {
			printf("%02x%02x%02x%02x%02x%02x    "
				"cmp %s,dword [0x%02x%02x%02x%02x]\n",
				data[pos],data[pos+1],data[pos+2],
				data[pos+3],data[pos+4],data[pos+5],
				getregister(data[pos+1]),
				data[pos+5],data[pos+4],data[pos+3],data[pos+2]
			);
			pos += 6;
			goto begin;
		}
		/* 01_???_??? */
		if ( (data[pos+1] & 0xc0) == 0x40 ) {
			printf("%02x%02x%02x   cmp %s,dword [%s+0x%02x]\n",
				data[pos],data[pos+1],data[pos+2],
				getregister(data[pos+1]),getrm(data[pos+2]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ( (data[pos+1] & 0xc0) == 0xc0 ) {
			printf("%02x%02x    cmp %s,%s\n", 
				data[pos],data[pos+1],getregister(data[pos+1]),getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x3c:
		printf("%02x%02x    cmp al,0x02x\n",
			data[pos],data[pos+1],data[pos+1]
			);
		pos += 2;
		goto begin;
	case 0x3d:
		printf("%02x%02x%02x%02x%02x    cmp eax,0x%02x%02x%02x%02x\n",
			data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],
			data[pos+4],data[pos+3],data[pos+2],data[pos+1]
			);
		pos += 5;
		goto begin;
	case 0x40:
		printf("%02x    inc eax\n", data[pos]);
		pos++;
		goto begin;
	case 0x41:
		printf("%02x    inc ecx\n", data[pos]);
		pos++;
		goto begin;
	case 0x42:
		printf("%02x    inc edx\n",data[pos]);
		pos++;
		goto begin;
	case 0x43:
		printf("%02x    inc ebx\n", data[pos]);
		pos++;
		goto begin;
	case 0x44:
		printf("%02x    inc esp\n", data[pos]);
		pos++;
		goto begin;
	case 0x45:
		printf("%02x    inc ebp\n", data[pos]);
		pos++;
		goto begin;
	case 0x46:
		printf("%02x    inc esi\n", data[pos]);
		pos++;
		goto begin;
	case 0x47:
		printf("%02x    inc edi\n", data[pos]);
		pos++;
		goto begin;
	case 0x48:
		printf("%02x    dec eax\n", data[pos]);
		pos++;
		goto begin;
	case 0x49:
		printf("%02x    dec ecx\n", data[pos]);
		pos++;
		goto begin;
	case 0x4a:
		printf("%02x    dec edx\n", data[pos]);
		pos++;
		goto begin;
	case 0x4b:
		printf("%02x    dec ebx\n", data[pos]);
		pos++;
		goto begin;
	case 0x4c:
		printf("%02x    dec esp\n", data[pos]);
		pos++;
		goto begin;
	case 0x4d:
		printf("%02x    dec ebp\n", data[pos]);
		pos++;
		goto begin;
	case 0x4e:
		printf("%02x    dec esi\n", data[pos]);
		pos++;
		goto begin;
	case 0x4f:
		printf("%02x    dec edi\n", data[pos]);
		pos++;
		goto begin;
	case 0x50:
		printf("%02x    push eax\n", data[pos]);
		pos++;
		goto begin;
	case 0x51:
		printf("%02x    push ecx\n",data[pos]);
		pos++;
		goto begin;
	case 0x52:
		printf("%02x    push edx\n", data[pos]);
		pos++;
		goto begin;
	case 0x53:
		printf("%02x    push ebx\n", data[pos]);
		pos++;
		goto begin;
	case 0x54:
		printf("%02x    push esp\n", data[pos]);
		pos++;
		goto begin;
	case 0x55:
		printf("%02x    push ebp\n", data[pos]);
		pos++;
		goto begin;
	case 0x56:
		printf("%02x    push esi\n", data[pos]);
		pos++;
		goto begin;
	case 0x57:
		printf("%02x    push edi\n", data[pos]);
		pos++;
		goto begin;
	case 0x58:
		printf("%02x    pop eax\n", data[pos]);
		pos++;
		goto begin;
	case 0x59:
		printf("%02x    pop ecx\n",data[pos]);
		pos++;
		goto begin;
	case 0x5a:
		printf("%02x    pop edx\n", data[pos]);
		pos++;
		goto begin;
	case 0x5b:
		printf("%02x    pop ebx\n", data[pos]);
		pos++;
		goto begin;
	case 0x5c:
		printf("%02x    pop esp\n", data[pos]);
		pos++;
		goto begin;
	case 0x5d:
		printf("%02x    pop ebp\n",data[pos]);
		pos++;
		goto begin;
	case 0x5e:
		printf("%02x    pop esi\n",data[pos]);
		pos++;
		goto begin;
	case 0x5f:
		printf("%02x    pop edi\n", data[pos]);
		pos++;
		goto begin;
	case 0x60:
		printf("%02x    pusha\n", data[pos]);
		pos++;
		goto begin;
	case 0x61:
		printf("%02x    popa\n", data[pos]);
		pos++;
		goto begin;
	case 0x64:
		printf("%02x    fs    \n", data[pos]);
		pos++;
		goto begin;
	case 0x66:
		printf("%02x    66    \n", data[pos]);
		pos++;
		goto begin;
	case 0x68:
		printf("%02x%02x%02x%02x%02x    push 0x%02x%02x%02x%02x\n",
			data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],
			data[pos+4],data[pos+3],data[pos+2],data[pos+1]
			);
		pos += 5;
		goto begin;
	case 0x69:
		/* 11_???_??? */
		if ( (data[pos+1] & 0xc0) == 0xc0 ) {
			printf("%02x%02x%02x%02x%02x%02x    imul %s,%s,0x%02x%02x%02x%02x\n",
				data[pos], data[pos + 1], data[pos + 2],
				data[pos + 3], data[pos + 4], data[pos + 5],
				getregister(data[pos + 1]), getrm(data[pos + 1]),
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		goto begin;
	case 0x6a:
		printf("%02x%02x    push 0x%02x\n", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x6b:
		/* 11_???_??? */
		if ( ( data[pos+1] & 0xc0 ) == 0xc0 ) {
			printf("%02x%02x%02x    imul %s,%s,0x%02x\n", 
				data[pos],data[pos+1],data[pos+2],
				getregister(data[pos+1]),getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0x6c:
		printf("%02x    ins byte es:[edi],dx\n", data[pos]);
		pos++;
		goto begin;
	case 0x6d:
		printf("%02x    ins dword es:[edi],dx\n",data[pos]);
		pos++;
		goto begin;
	case 0x70:
		printf("%02x%02x    jo +0x%02x\n", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x71:
		printf("%02x%02x    jno +0x%02x\n", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x72:
		printf("%02x%02x    jb +0x%02x\n", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x73:
		printf("%02x%02x    jae +0x%02x\n", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x74:
		printf("%02x%02x    je +0x%02x\n", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x75:
		printf("%02x%02x    jne +0x%02x\n", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x76:
		printf("%02x%02x    jbe +0x%02x\n", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x77:
		printf("%02x%02x    ja +0x%02x\n", 
			data[pos],data[pos+1],data[pos+1]
			);
		pos += 2;
		goto begin;
	case 0x78:
		printf("%02x%02x    js +0x%02x\n", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x79:
		printf("%02x%02x    jns +0x%02x\n", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x7a:
		printf("%02x%02x    jp +0x%02x\n", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x7b:
		printf("%02x%02x    jnp +0x%02x\n", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x7c:
		printf("%02x%02x    jl +0x%02x\n", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x7d:
		printf("%02x%02x    jge +0x%02x\n", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x7e:
		printf("%02x%02x    jle +0x%02x\n", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x7f:
		printf("%02x%02x    jg +0x%02x\n", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x80:
		/* 01_111_??? */
		if ((data[pos + 1] & 0xf8) == 0x78) {
			printf("%02x%02x%02x%02x    cmp byte [%s+0x%02x],0x%02x\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getrm(data[pos+1]),data[pos+2],data[pos+3]
				);
			pos += 4;
			goto begin;
		}
		/* 11_100_??? */
		if ((data[pos + 1] & 0xf8) == 0xe0) {
			printf("%02x%02x%02x    and %s,0x%02x\n",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0x81:
		/* 11_000_??? */
		if ((data[pos + 1] & 0xf8) == 0xc0) {
			printf("%02x%02x%02x%02x%02x%02x    "
			"add %s,0x%02x%02x%02x%02x\n",
				data[pos],data[pos+1],data[pos+2],
				data[pos+3],data[pos+4],data[pos+5],
				getrm(data[pos+1]),
				data[pos+5],data[pos+4],data[pos+3],data[pos+2]
			);
			pos += 6;
			goto begin;
		}
		/* 11_100_??? */
		if ((data[pos + 1] & 0xf8) == 0xe0) {
			printf("%02x%02x%02x%02x%02x%02x    "
				"and %s,0x%02x%02x%02x%02x\n",
				data[pos], data[pos + 1], data[pos + 2],
				data[pos + 3], data[pos + 4], data[pos + 5],
				getrm(data[pos + 1]), data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
				);
			pos += 6;
			goto begin;
		}
		/* 11_101_??? */
		if ((data[pos + 1] & 0xf8) == 0xe8) {
			printf("%02x%02x%02x%02x%02x%02x    "
				"sub %s,0x%02x%02x%02x%02x\n",
				data[pos], data[pos + 1], data[pos + 2],
				data[pos + 3], data[pos + 4], data[pos + 5],
				getrm(data[pos + 1]), data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
				);
			pos += 6;
			goto begin;
		}
		/* 11_111_??? */
		if ((data[pos + 1] & 0xf8) == 0xf8) {
			printf("%02x%02x%02x%02x%02x%02x    "
				"cmp %s,0x%02x%02x%02x%02x\n",
				data[pos],data[pos+1],data[pos+2],
				data[pos+3],data[pos+4],data[pos+5],
				getrm(data[pos+1]),data[pos+5],data[pos+4],data[pos+3],data[pos+2]
				);
			pos += 6;
			goto begin;
		}
		goto r;
	case 0x82:
		/* 10_111_??? */
		if ((data[pos + 1] & 0xf8) == 0xb8) {
			printf("%02x%02x%02x%02x%02x%02x%02x    cmp byte [%s+0x%02x%02x%02x%02x],0x%02x\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				data[pos+4],data[pos+5],data[pos+6],
				getrm(data[pos+1]),data[pos+5],data[pos+4],data[pos+3],data[pos+2],
				data[pos+6]
				);
			pos += 7;
			goto begin;
		}
		goto r;
	case 0x83:
		/* 00_111_100 */
		if (data[pos+1]==0x3c) {
			printf("%02x%02x%02x%02x    cmp dword %s,0x%02x\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getsib8(data[pos+2],0),data[pos+3]
				);
			pos += 4;
			goto begin;
		}
		/* 00_111_??? */
		if ((data[pos + 1] & 0xf8) == 0x38) {
			printf("%02x%02x%02x    cmp dword [%s],0x%02x\n",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 01_000_??? */
		if ((data[pos + 1] & 0xf8) == 0x40) {
			printf("%02x%02x%02x%02x    add dword [%s+0x%02x],0x%02x\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getrm(data[pos+1]),data[pos+2],data[pos+3]
				);
			pos += 4;
			goto begin;
		}
		/* 01_001_??? */
		if ((data[pos + 1] & 0xf8) == 0x48) {
			printf("%02x%02x%02x%02x    or dword [%s+0x%02x],0x%02x\n",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3],
				getrm(data[pos + 1]), data[pos + 2], data[pos + 3]
			);
			pos += 4;
			goto begin;
		}
		/* 01_100_??? */
		if ((data[pos + 1] & 0xf8) == 0x60) {
			printf("%02x%02x%02x%02x    and dword [%s+0x%02x],0x%02x\n",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3],
				getrm(data[pos + 1]), data[pos + 2], data[pos + 3]
			);
			pos += 4;
			goto begin;
		}
		/* 01_111_??? */
		if ( (data[pos+1] & 0xf8) == 0x78 ) {
			printf("%02x%02x%02x%02x    cmp dword [%s+0x%02x],0x%02x\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getrm(data[pos+1]),data[pos+2],data[pos+3]
			);
			pos += 4;
			goto begin;
		}
		/* 10_111_??? */
		if ((data[pos + 1] & 0xf8) == 0xb8) {
			printf("%02x%02x%02x%02x%02x%02x%02x    "
				"cmp dword [%s+0x%02x%02x%02x%02x],0x%02x\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				data[pos+4],data[pos+5],data[pos+6],
				getrm(data[pos+1]),data[pos+5],data[pos+4],data[pos+3],data[pos+2],
				data[pos+6]
			);
			pos += 7;
			goto begin;
		}
		/* 11_000_??? */
		if ((data[pos + 1] & 0xf8) == 0xc0) {
			printf("%02x%02x%02x    add %s,0x%02x\n",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2]);
			pos += 3;
			goto begin;
		}
		/* 11_001_??? */
		if ((data[pos + 1] & 0xf8) == 0xc8) {
			printf("%02x%02x%02x    or %s,0x%02x\n",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 11_100_??? */
		if ((data[pos + 1] & 0xf8) == 0xe0) {
			printf("%02x%02x%02x    and %s,0x%02x\n",
				data[pos], data[pos + 1], data[pos + 2],
				getrm(data[pos + 1]), data[pos + 2]);
			pos += 3;
			goto begin;
		}
		/* 11_101_??? */
		if ( (data[pos + 1] & 0xf8) == 0xe8 ) {
			printf("%02x%02x%02x    sub %s,0x%02x\n",
				data[pos], data[pos + 1], data[pos + 2],
				getrm(data[pos + 1]), data[pos + 2]);
			pos += 3;
			goto begin;
		}
		/* 11_111_??? */
		if ((data[pos + 1] & 0xf8) == 0xf8) {
			printf("%02x%02x%02x    cmp %s,0x%02x\n",
				data[pos], data[pos + 1], data[pos + 2],
				getrm(data[pos + 1]), data[pos + 2]);
			pos += 3;
			goto begin;
		}
		/* 11_???_011 */
		if ((data[pos + 1] & 0xc7) == 0xc3) {
			printf("%02x%02x%02x    and %s,0x%02x\n", 
				data[pos],data[pos+1],data[pos+2],
				getregister(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0x84:
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			printf("%02x%02x    test %s(al),%s(al)\n",
				data[pos],data[pos+1],getregister(data[pos+1]),getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
	case 0x85:
		/* 11_???_??? */
		if ( ( data[pos+1] & 0xc0 ) == 0xc0 ) {
			printf("%02x%02x    test %s,%s\n",data[pos],data[pos+1],
				getregister(data[pos+1]),getrm(data[pos+1]));
			pos += 2;
			goto begin;
		}
		/* 01_???_??? */
		if ( ( data[pos+1] & 0xc0 ) == 0x40 ) {
			printf("%02x%02x%02x    test dword [%s+0x%02x],%s\n",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2],getregister(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0x88:
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			printf("%02x%02x    mov byte [%s],%s\n",
				data[pos],data[pos+1],getrm(data[pos+1]),getregisteral(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			printf("%02x%02x%02x    mov byte [%s+0x%02x],%s(al)\n",
				data[pos], data[pos + 1], data[pos + 2],
				getrm(data[pos+1]),data[pos+2],getregister(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0x89:
		/* 00_???_100 */
		if ((data[pos + 1] & 0xc7) == 0x04) {
			printf("%02x%02x%02x%02x%02x%02x%02x    "
				"mov dword %s,%s\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				data[pos+4],data[pos+5],data[pos+6],
				getsib32(data[pos+2],data[pos+6],data[pos+5],data[pos+4],data[pos+3]),getregister(data[pos+1])
				);
			pos += 7;
			goto begin;
		}
		/* 00_???_101 */
		if ((data[pos + 1] & 0xc7) == 0x05) {
			printf("%02x%02x%02x%02x%02x%02x mov dword [0x%02x%02x%02x%02x],%s\n",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2],
				getregister(data[pos + 1])
				);
			pos += 6;
			goto begin;
		}
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			printf("%02x%02x    mov dword [%s],%s\n",
				data[pos], data[pos + 1], getrm(data[pos + 1]), getregister(data[pos + 1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_101 */
		if ((data[pos+1] & 0xc7) == 0x45) {
			printf("%02x%02x%02x    mov dword [%s+0x%02x],%s\n",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]), data[pos + 2],getregister(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
		/* 01_???_100 */
		if ((data[pos + 1] & 0xc7) == 0x44) {
			printf("%02x%02x%02x%02x    mov %s,%s\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getsib8(data[pos+2],data[pos+3]),getregister(data[pos+1])
				);
			pos += 4;
			goto begin;
		}
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			printf("%02x%02x%02x    mov dword [%s+0x%02x],%s\n",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2],getregister(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
		/* 10_???_??? */
		if ((data[pos+1] & 0xc0) == 0x80) {
			printf("%02x%02x%02x%02x%02x%02x    mov dword [%s+0x%02x%02x%02x%02x],%s\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],data[pos+5],
				getrm(data[pos+1]),data[pos+5],data[pos+4],data[pos+3],data[pos+2],
				getregister(data[pos+1])
				);
			pos += 6;
			goto begin;
		}
		goto r;
	case 0x8a:
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			printf("%02x%02x    mov %s(al),byte [%s]\n",
				data[pos],data[pos+1],getregister(data[pos+1]),getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_??? */
		if ( (data[pos + 1] & 0xc0) == 0x40 ) {
			printf("%02x%02x%02x    mov %s(al),byte [%s+0x%02x]\n",
				data[pos], data[pos + 1], data[pos+2],
				getregister(data[pos + 1]), getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			printf("%02x%02x    mov %s,%s\n",
				data[pos],data[pos+1],
				getregisteral(data[pos+1]),getrmal(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x8b:
		/* 00_???_101 */
		if ((data[pos + 1] & 0xc7) == 0x05) {
			printf("%02x%02x%02x%02x%02x%02x    "
				"mov %s,dword [0x%02x%02x%02x%02x]\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				data[pos+4],data[pos+5],getregister(data[pos+1]),
				data[pos+5],data[pos+4],data[pos+3],data[pos+2]
			);
			pos += 6;
			goto begin;
		}
		/* 00_???_??? */
		if ( (data[pos+1] & 0xc0 ) == 0x00 ) {
			printf("%02x%02x    mov %s,dword [%s]\n", 
				data[pos], data[pos + 1], 
				getregister(data[pos + 1]), getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_100 */
		if ((data[pos + 1] & 0xc7) == 0x44) {
			printf("%02x%02x%02x%02x    mov %s,%s\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getregister(data[pos+1]),getsib8(data[pos+2],data[pos+3])
				);
			pos += 4;
			goto begin;
		}
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			printf("%02x%02x%02x    mov %s,[%s+0x%02x]\n",
				data[pos],data[pos+1],data[pos+2],
				getregister(data[pos+1]),getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 10_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x80) {
			printf("%02x%02x%02x%02x%02x%02x    mov %s,dword [%s+0x%02x%02x%02x%02x]\n",
				data[pos],data[pos+1],data[pos+2],
				data[pos+3],data[pos+4],data[pos+5],
				getregister(data[pos+1]),getrm(data[pos+1]),
				data[pos+5],data[pos+4],data[pos+3],data[pos+2]
				);
			pos += 6;
			goto begin;
		}
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			printf("%02x%02x    mov %s,%s\n", data[pos], data[pos + 1],
				getregister(data[pos + 1]), getrm(data[pos + 1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x8d:
		/* 00_???_100 */
		/*
		if ( (data[pos + 1] & 0xc7) == 0x04 ) {
			printf("%02x%02x%02x%02x%02x%02x%02x    lea %s,%s\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],
				data[pos+5],data[pos+6],
				getregister(data[pos+1]),
				getsib32(data[pos+2],data[pos+6],data[pos+5],data[pos+4],data[pos+3])
				);
			pos += 7;
			goto begin;
		}
		*/
		if ((data[pos + 1] & 0xc7) == 0x04) {
			printf("%02x%02x%02x    lea %s,%s\n",
				data[pos], data[pos + 1], data[pos + 2],
				getregister(data[pos + 1]),
				getsib8(data[pos + 2], 0)
			);
			pos += 3;
			goto begin;
		}

		/* 01_???_101 */ 
		if ( (data[pos+1] & 0xc7 ) == 0x45 ) {
			printf("%02x%02x%02x    lea %s,[%s+0x%02x]\n", data[pos], data[pos + 1],
				data[pos + 2], getregister(data[pos + 1]), getrm(data[pos + 1]), data[pos + 2]);
			pos += 3;
			goto begin;
		}
		/* 01_???_100 */
		if ( (data[pos + 1] & 0xc7) == 0x44 ) {
			printf("%02x%02x%02x%02x    lea %s,%s\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getregister(data[pos+1]),getsib8(data[pos+2],data[pos+3])
			);
			pos += 4;
			goto begin;
		}
		/* 01_???_??? */
		if ( (data[pos+1] & 0xc0) == 0x40 ) {
			printf("%02x%02x%02x    lea %s,[%s+0x%02x]\n", 
				data[pos],data[pos+1],data[pos+2],
				getregister(data[pos+1]),getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 10_???_??? */
		if ( (data[pos+1] & 0xc0) == 0x80 ) {
			printf("%02x%02x%02x%02x%02x%02x    lea %s,[%s+0x%02x%02x%02x%02x]\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],data[pos+5],
				getregister(data[pos+1]),getrm(data[pos+1]),
				data[pos+5],data[pos+4],data[pos+3],data[pos+2]
				);
			pos += 6;
			goto begin;
		}
		goto r;
	case 0x90:
		printf("%02x    nop\n", data[pos]);
		pos++;
		goto begin;
	case 0x91:
		printf("%02x    xchg ecx,eax\n", data[pos]);
		pos++;
		goto begin;
	case 0x92:
		printf("%02x    xchg edx,eax\n", data[pos]);
		pos++;
		goto begin;
	case 0x93:
		printf("%02x    xchg ebx,eax\n", data[pos]);
		pos++;
		goto begin;
	case 0x94:
		printf("%02x    xchg esp,eax\n", data[pos]);
		pos++;
		goto begin;
	case 0x95:
		printf("%02x    xchg ebp,eax\n", data[pos]);
		pos++;
		goto begin;
	case 0x96:
		printf("%02x    xchg esi,eax\n", data[pos]);
		pos++;
		goto begin;
	case 0x97:
		printf("%02x    xchg edi,eax\n", data[pos]);
		pos++;
		goto begin;
	case 0x98:
		printf("%02x    cwde\n", data[pos]);
		pos++;
		goto begin;
	case 0x99:
		printf("%02x    cdq\n", data[pos]);
		pos++;
		goto begin;
	case 0xa1:
		printf("%02x%02x%02x%02x%02x    mov eax,dword [0x%02x%02x%02x%02x]\n",
			data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]
		);
		pos += 5;
		goto begin;
	case 0xa3:
		printf("%02x%02x%02x%02x%02x    mov dword [0x%02x%02x%02x%02x],eax\n",
			data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]
		);
		pos += 5;
		goto begin;
	case 0xa4:
		printf("%02x    movs byte es:[edi],byte ds:[esi]\n");
		pos++;
		goto begin;
	case 0xa5:
		printf("%02x    movs dword es:[edi],dword ds:[esi]\n");
		pos++;
		goto begin;
	case 0xa6:
		printf("%02x    cmps byte ds:[esi],byte es:[edi]\n");
		pos++;
		goto begin;
	case 0xa7:
		printf("%02x    cmps dword ds:[esi],dword es:[edi]\n");
		pos++;
		goto begin;
	case 0xa8:
		printf("%02x%02x    test al,0x%02x\n",
			data[pos],data[pos+1],data[pos+1]
			);
		pos += 2;
		goto begin;
	case 0xaf:
		printf("%02x    scas dword ptr es:[edi]\n",data[pos]);
		pos += 1;
		goto begin;
	case 0xb0:
		printf("%02x%02x    mov al,0x%02x\n", data[pos], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0xb1:
		printf("%02x%02x    mov cl,0x%02x\n", data[pos], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0xb2:
		printf("%02x%02x    mov dl,0x%02x\n", data[pos], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0xb3:
		printf("%02x%02x    mov bl,0x%02x\n", data[pos], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0xb4:
		printf("%02x%02x    mov ah,0x%02x\n", data[pos], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0xb5:
		printf("%02x%02x    mov ch,0x%02x\n", data[pos], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0xb6:
		printf("%02x%02x    mov dh,0x%02x\n", data[pos], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0xb7:
		printf("%02x%02x    mov bh,0x%02x\n", data[pos], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0xb8:
		printf("%02x%02x%02x%02x%02x mov eax,0x%02x%02x%02x%02x\n",
			data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]);
		pos += 5;
		goto begin;
	case 0xb9:
		printf("%02x%02x%02x%02x%02x mov ecx,0x%02x%02x%02x%02x\n",
			data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]);
		pos += 5;
		goto begin;
	case 0xba:
		printf("%02x%02x%02x%02x%02x mov edx,0x%02x%02x%02x%02x\n",
			data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]);
		pos += 5;
		goto begin;
	case 0xbb:
		printf("%02x%02x%02x%02x%02x mov ebx,0x%02x%02x%02x%02x\n",
			data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]);
		pos += 5;
		goto begin;
	case 0xbc:
		printf("%02x%02x%02x%02x%02x mov esp,0x%02x%02x%02x%02x\n",
			data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]);
		pos += 5;
		goto begin;
	case 0xbd:
		printf("%02x%02x%02x%02x%02x mov ebp,0x%02x%02x%02x%02x\n",
			data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]);
		pos += 5;
		goto begin;
	case 0xbe:
		printf("%02x%02x%02x%02x%02x mov esi,0x%02x%02x%02x%02x\n",
			data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]);
		pos += 5;
		goto begin;
	case 0xbf:
		printf("%02x%02x%02x%02x%02x mov edi,0x%02x%02x%02x%02x\n",
			data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]);
		pos += 5;
		goto begin;
	case 0xc0:
		/* 00_100_??? */
		if ((data[pos + 1] & 0xf8) == 0x20) {
			printf("%02x%02x%02x    shl byte [%s],0x%02x\n",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 00_110_??? */
		if ((data[pos + 1] & 0xf8) == 0x30) {
			printf("%02x%02x%02x    sal byte [%s],0x%02x\n",
				data[pos], data[pos + 1], data[pos + 2],
				getrm(data[pos + 1]), data[pos + 2]
				);
			pos += 3;
			goto begin;
		}
		/* 00_111_??? */
		if ( ( data[pos+1] & 0xf8 ) == 0x38 ) {
			printf("%02x%02x%02x    sar byte [%s],0x%02x\n",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 10_001_??? */
		if ((data[pos + 1] & 0xf8) == 0x88) {
			printf("%02x%02x%02x%02x%02x%02x%02x    "
				"ror byte [%s+0x%02x%02x%02x%02x],0x%02x\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				data[pos+4],data[pos+5],data[pos+6],
				getrm(data[pos+1]),data[pos+5],data[pos+4],data[pos+3],data[pos+2],
				data[pos+6]
				);
			pos += 7;
			goto begin;
		}
		goto r;
	case 0xc1:
		/* 11_100_??? */
		if ((data[pos + 1] & 0xf8) == 0xe0) {
			printf("%02x%02x%02x   shl %s,0x02x\n",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0xc2:
		printf("%02x%02x%02x    ret 0x%02x%02x\n",
			data[pos],data[pos+1],data[pos+2],
			data[pos+2],data[pos+1]
			);
		pos += 3;
		goto begin;
	case 0xc3:
		printf("%02x    ret\n",data[pos]);
		pos++;
		goto begin;
	case 0xc6:
		/* 01_000_??? */
		if ((data[pos + 1] & 0xf8) == 0x40) {
			printf("%02x%02x%02x%02x    mov byte [%s+0x%02x],0x%02x\n",
				data[pos], data[pos + 1], data[pos+2],data[pos+3],
				getrm(data[pos+1]),data[pos+2],data[pos+3]
				);
			pos += 4;
			goto begin;
		}
	case 0xc7:
		/* 00_000_101 */
		if ( data[pos+1] == 0x5 ) {
			printf("%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x    "
				"mov dword [0x%02x%02x%02x%02x],0x%02x%02x%02x%02x\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				data[pos+4],data[pos+5],data[pos+6],data[pos+7],
				data[pos+8],data[pos+9],
				data[pos+5],data[pos+4],data[pos+3],data[pos+2],
				data[pos+9],data[pos+8],data[pos+7],data[pos+6]
			);
			pos += 10;
			goto begin;
		}
		/* 00_000_??? */
		if ( (data[pos+1] & 0xf8) == 0x00 ) {
			printf("%02x%02x%02x%02x%02x%02x    "
				"mov dword [%s],0x%02x%02x%02x%02x\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				data[pos+4],data[pos+5],getrm(data[pos+1]),
				data[pos+5],data[pos+4],data[pos+3],data[pos+2]
			);
			pos += 6;
			goto begin;
		}
		/* 01_000_??? */
		if ( ( data[pos+1] & 0xf8 ) == 0x40 ) {
			printf("%02x%02x%02x%02x%02x%02x%02x    mov dword [%s+0x%02x],0x%02x%02x%02x%02x\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				data[pos+4],data[pos+5],data[pos+6],
				getrm(data[pos+1]),data[pos+2],
				data[pos+6],data[pos+5],data[pos+4],data[pos+3]
				);
			pos += 7;
			goto begin;
		}
		goto r;
	case 0xc8:
		printf("%02x%02x%02x%02x    enter 0x%02x,0x%02x%02x\n",
			data[pos],data[pos+1],data[pos+2],data[pos+3],
			data[pos+1],data[pos+3],data[pos+2]
			);
		pos += 4;
		goto begin;
	case 0xc9:
		printf("%02x    leave\n", data[pos]);
		pos++;
		goto begin;
	case 0xcc:
		printf("%02x    int3\n", data[pos]);
		pos++;
		goto begin;
	case 0xd1:
		/* 11_101_??? */
		if ((data[pos + 1] & 0xf8) == 0xe8) {
			printf("%02x%02x    shr %s,1\n",
				data[pos],data[pos+1],getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0xd3:
		/* 11_100_??? */
		if ((data[pos + 1] & 0xf8) == 0xe0) {
			printf("%02x%02x    shl %s,cl\n",
				data[pos],data[pos+1],getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0xd8:
		/* 01_011_??? */
		if ((data[pos + 1] & 0xf8) == 0x58) {
			printf("%02x%02x%02x    fcomp dword [%s+0x%02x]\n",
				data[pos], data[pos + 1],data[pos+2],
				getrm(data[pos+1]),data[pos+2]
			);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0xe4:
		printf("%02x%02x    in al,0x%02x\n",
			data[pos],data[pos+1],data[pos+1]
			);
		pos += 2;
		goto begin;
	case 0xe5:
		printf("%02x%02x    in eax,0x%02x\n",
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
	case 0xe7:
		printf("%02x%02x    out 0x%02x,eax\n",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xe8:
		printf("%02x%02x%02x%02x%02x call 0x%02x%02x%02x%02x\n",
			data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]);
		pos += 5;
		goto begin;
	case 0xe9:
		printf("%02x%02x%02x%02x%02x    jmp 0x%02x%02x%02x%02x\n",
			data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],
			data[pos+4],data[pos+3],data[pos+2],data[pos+1]
			);
		pos += 5;
		goto begin;
	case 0xea:
		printf("%02x%02x%02x%02x%02x%02x%02x    jmp %02x%02x:%02x%02x%02x%02x\n",
			data[pos],data[pos+1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 5], data[pos + 6], 
			data[pos + 6], data[pos + 5],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]
			);
		pos += 7;
		goto begin;
	case 0xeb:
		printf("%02x%02x    jmp +0x%02x\n", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0xf3:
		printf("%02x  repz   \n", data[pos]);
		pos += 1;
		goto begin;
	case 0xf4:
		printf("%02x    hlt\n",data[pos]);
		pos += 1;
		goto begin;
	case 0xf6:
		/* 01_000_??? */
		if ((data[pos + 1] & 0xf8) == 0x40) {
			printf("%02x%02x%02x%02x    test byte [%s+0x%02x],0x%02x\n", 
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getrm(data[pos+1]),data[pos+2],data[pos+3]
				);
			pos += 4;
			goto begin;
		}
		/* 11_000_??? */
		if ((data[pos + 1] & 0xf8) == 0xc0) {
			printf("%02x%02x%02x    test %s,0x%02x\n",
				data[pos],data[pos+1],data[pos+2],
				getrmal(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0xf7:
		/* 01_000_??? */
		if ( ( data[pos+1] &0xf8 ) == 0x40 ) {
			printf("%02x%02x%02x%02x%02x%02x%02x    test dword [%s+0x%02x],0x%02x%02x%02x%02x\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				data[pos+4],data[pos+5],data[pos+6],
				getrm(data[pos+1]),data[pos+2],
				data[pos+6],data[pos+5],data[pos+4],data[pos+3]
				);
			pos += 7;
			goto begin;
		}
		/* 11_011_??? */
		if ((data[pos + 1] & 0xf8) == 0xd8) {
			printf("%02x%02x    neg %s\n",
				data[pos],data[pos+1],getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 11_100_??? */
		if ((data[pos + 1] & 0xf8) == 0xe0) {
			printf("%02x%02x    mul eax,%s\n",
				data[pos],data[pos+1],getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 11_???_??? */
		if ( (data[pos+1] & 0xc0) == 0xc0 ) {
			printf("%02x%02x    idiv %s,%s\n",
				data[pos],data[pos+1],getregister(data[pos+1]),getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0xfc:
		printf("%02x    cld\n", data[pos]);
		pos++;
		goto begin;
	case 0xff:
		/* 0x05 */
		if (data[pos + 1] == 0x05) {
			printf("%02x%02x%02x%02x%02x%02x    inc dword [0x%02x%02x%02x%02x]\n", 
				data[pos],data[pos+1],data[pos+2],
				data[pos+3],data[pos+4],data[pos+5],
				data[pos+5],data[pos+4],data[pos+3],data[pos+2]
				);
			pos += 6;
			goto begin;
		}
		/* 0x15 */
		if ( data[pos+1] == 0x15 ) {
			printf("%02x%02x%02x%02x%02x%02x    "
				"call dword [0x%02x%02x%02x%02x]\n",
				data[pos],data[pos+1],data[pos+2],
				data[pos+3],data[pos+4],data[pos+5],
				data[pos+5],data[pos+4],data[pos+3],data[pos+2]
			);
			pos += 6;
			goto begin;
		}
		/* 0x24 */
		if (data[pos + 1] == 0x24) {
			printf("%02x%02x%02x%02x%02x%02x    "
				"jmp dword %s",
				data[pos], data[pos + 1], data[pos + 2],
				data[pos + 3], data[pos + 4], data[pos + 5],
				getsib32(data[pos+2],data[pos+5],data[pos+4],data[pos+3],data[pos+2])
				);
			pos += 6;
			goto begin;
		}
		/* 0x45 */
		if (data[pos + 1] == 0x45) {
			printf("%02x%02x%02x    inc dword [ebp+0x%02x]\n",
				data[pos],data[pos+1],data[pos+2],data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 0xc0 */
		if (data[pos + 1] == 0xc0) {
			printf("%02x%02x    inc eax\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xc1 */
		if (data[pos + 1] == 0xc1) {
			printf("%02x%02x    inc ecx\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xc2 */
		if (data[pos + 1] == 0xc2) {
			printf("%02x%02x    inc edx\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xc3 */
		if (data[pos + 1] == 0xc3) {
			printf("%02x%02x    inc ebx\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xc4 */
		if (data[pos + 1] == 0xc4) {
			printf("%02x%02x    inc esp\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xc5 */
		if (data[pos + 1] == 0xc5) {
			printf("%02x%02x    inc ebp\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xc6 */
		if (data[pos + 1] == 0xc6) {
			printf("%02x%02x    inc esi\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xc7 */
		if (data[pos+1]==0xc7) {
			printf("%02x%02x    inc edi\n",data[pos],data[pos+1]);
			pos += 2;
			goto begin;
		}
		/* 0xc8 */
		if (data[pos + 1] == 0xc8) {
			printf("%02x%02x    dec eax\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xc9 */
		if (data[pos + 1] == 0xc9) {
			printf("%02x%02x    dec ecx\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xca */
		if (data[pos + 1] == 0xca) {
			printf("%02x%02x    dec edx\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xcb */
		if (data[pos + 1] == 0xcb) {
			printf("%02x%02x    dec ebx\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xcc */
		if (data[pos + 1] == 0xcc) {
			printf("%02x%02x    dec esp\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xcd */
		if (data[pos + 1] == 0xcd) {
			printf("%02x%02x    dec ebp\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xce */
		if (data[pos + 1] == 0xce) {
			printf("%02x%02x    dec esi\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xcf */
		if (data[pos + 1] == 0xcf) {
			printf("%02x%02x    dec edi\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xd0 */
		if (data[pos + 1] == 0xd0) {
			printf("%02x%02x    call eax\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xd1 */
		if (data[pos + 1] == 0xd1) {
			printf("%02x%02x    call ecx\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xd2 */
		if (data[pos + 1] == 0xd2) {
			printf("%02x%02x    call edx\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xd3 */
		if (data[pos + 1] == 0xd3) {
			printf("%02x%02x    call ebx\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xd4 */
		if (data[pos + 1] == 0xd4) {
			printf("%02x%02x    call esp\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xd5 */
		if (data[pos + 1] == 0xd5) {
			printf("%02x%02x    call ebp\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xd6 */
		if (data[pos + 1] == 0xd6) {
			printf("%02x%02x    call esi\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xd7 */
		if (data[pos + 1] == 0xd7) {
			printf("%02x%02x    call edi\n", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 00_110_??? */
		if ((data[pos + 1] & 0xf8) == 0x30) {
			printf("%02x%02x    push dword [%s]\n",
				data[pos],data[pos+1],getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_110_??? */
		if ((data[pos + 1] & 0xf8) == 0x70) {
			printf("%02x%02x%02x    push dword [%s+0x%02x]\n",
				data[pos], data[pos + 1], data[pos + 2],
				getrm(data[pos + 1]), data[pos + 2]
				);
			pos += 3;
			goto begin;
		}
		/* 10_001_??? */
		if ((data[pos + 1] & 0xf8) == 0x88) {
			printf("%02x%02x%02x%02x%02x%02x    dec dword [%s+0x%02x%02x%02x%02x]\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				data[pos+4],data[pos+5],
				getrm(data[pos+1]),data[pos+5],data[pos+4],data[pos+3],data[pos+2]
				);
			pos += 6;
			goto begin;
		}
		/* 10_110_??? */
		if ((data[pos + 1] & 0xf8) == 0xb0 ) {
			printf("%02x%02x%02x%02x%02x%02x    push dword [%s+0x%02x%02x%02x%02x]\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],data[pos+5],
				getrm(data[pos+1]),data[pos+5],data[pos+4],data[pos+3],data[pos+2]
				);
			pos += 6;
			goto begin;
		}
		goto r;
	default:	
		break;
	}
r:
	printf("it over : %02x%02x\n", data[pos],data[pos+1]);
	return;
}

static char* getscale(char arg0) {
	switch ( (arg0 & 0xc0) )
	{
	case 0x0:
		return "0";
	case 0x40:
		return "1";
	case 0x80:
		return "2";
	case 0xc0:
		return "3";
	default:
		return "unknown";
	}
}

static char* getsib32(char arg0, char arg1,char arg2,char arg3,char arg4) {
	static char r[0x20];
	memset(r, 0, sizeof(r));
	char* base = getrm(arg0);
	char* index = getregister(arg0);
	char* scale = getscale(arg0);

	snprintf(r, sizeof(r), "[%s+%s*2^%s+0x%02x%02x%02x%02x]", base, index, scale, 
		(unsigned char)arg1, (unsigned char)arg2,(unsigned char)arg3,(unsigned char)arg4);
	return r;
}

static char* getsib8(char arg0,char arg1) {
	static char r[0x20];
	memset(r,0,sizeof(r));
	char* base = getrm(arg0);
	char* index = getregister(arg0);
	char* scale = getscale(arg0);

	snprintf(r,sizeof(r),"[%s+%s*2^%s+0x%02x]",base,index,scale,(unsigned char)arg1);
	return r;
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
	switch ( (arg0 & 0x7) )
	{
	case 0x00:
		return "eax";
	case 0x01:
		return "ecx";
	case 0x02:
		return "edx";
	case 0x03:
		return "ebx";
	case 0x04:
		return "esp";
	case 0x05:
		return "ebp";
	case 0x06:
		return "esi";
	case 0x07:
		return "edi";
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
	switch ( (arg0 & 0x38) )
	{
	case 0x00:
		return "eax";
	case 0x08:
		return "ecx";
	case 0x10:
		return "edx";
	case 0x18:
		return "ebx";
	case 0x20:
		return "esp";
	case 0x28:
		return "ebp";
	case 0x30:
		return "esi";
	case 0x38:
		return "edi";
	default:
		return "unknown";
	}
}


