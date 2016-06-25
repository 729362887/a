#include<stdio.h>
#include<string.h>

static char* getregister(char arg0);
static char* getrm(char arg0);
static char* getsib8(char arg0, char arg1);

void disassemble(char* arg0) {

	int pos = 0;
	unsigned char* data = (unsigned char*)arg0;

begin:
	switch (data[pos])
	{
	case 0x0f:
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
		if (data[pos + 1] == 0x8c) {
			printf("%02x%02x%02x%02x%02x%02x    jl +0x%02x%02x%02x%02x\n",
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
	case 0x3b:
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
	case 0x50:
		printf("%02x    push eax\n", data[pos]);
		pos++;
		goto begin;
	case 0x51:
		printf("%02x    push ecx\n",data[pos]);
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
	case 0x59:
		printf("%02x    pop ecx\n",data[pos]);
		pos++;
		goto begin;
	case 0x5b:
		printf("%02x    pop ebx\n", data[pos]);
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
	case 0x64:
		printf("%02x    fs    ", data[pos]);
		pos++;
		goto begin;
	case 0x68:
		printf("%02x%02x%02x%02x%02x    push 0x%02x%02x%02x%02x\n",
			data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],
			data[pos+4],data[pos+3],data[pos+2],data[pos+1]
			);
		pos += 5;
		goto begin;
	case 0x6a:
		printf("%02x%02x    push 0x%02x\n", data[pos], data[pos + 1], data[pos + 1]);
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
	case 0x77:
		printf("%02x%02x    ja +0x%02x\n", 
			data[pos],data[pos+1],data[pos+1]
			);
		pos += 2;
		goto begin;
	case 0x83:
		/* 01_111_??? */
		if ( (data[pos+1] & 0xf8) == 0x78 ) {
			printf("%02x%02x%02x%02x    cmp dword [%s+0x%02x],0x%02x\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getrm(data[pos+1]),data[pos+2],data[pos+3]
			);
			pos += 4;
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
		goto r;
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
	case 0x89:
		/* 01_???_101 */
		if ((data[pos+1] & 0xc7) == 0x45) {
			printf("%02x%02x%02x    mov dword [%s+0x%02x],%s\n",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]), data[pos + 2],getregister(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
		/* 00_???_101 */
		if ((data[pos + 1] & 0xc7) == 0x05) {
			printf("%02x%02x%02x%02x%02x%02x mov dword [0x%02x%02x%02x%02x],%s\n",
				data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],data[pos+5],
				data[pos+5],data[pos+4],data[pos+3],data[pos+2],
				getregister(data[pos+1])
				);
			pos += 6;
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
	case 0x8b:
		/* 00_???_??? */
		if ( (data[pos+1] & 0xc0 ) == 0x00 ) {
			printf("%02x%02x    mov %s,dword [%s]\n", 
				data[pos], data[pos + 1], 
				getregister(data[pos + 1]), getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 11_???_??? */
		if ( (data[pos+1]&0xc0)==0xc0 ) {
			printf("%02x%02x    mov %s,%s\n", data[pos], data[pos + 1],
				getregister(data[pos + 1]), getrm(data[pos + 1])
			);
			pos += 2;
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

		goto r;
	case 0x8d:
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
	case 0xa1:
		printf("%02x%02x%02x%02x%02x    mov eax,dword [0x%02x%02x%02x%02x]\n",
			data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]
		);
		pos += 5;
		goto begin;
	case 0xaf:
		printf("%02x    scas dword ptr es:[edi]\n",data[pos]);
		pos += 1;
		goto begin;
	case 0xb8:
		printf("%02x%02x%02x%02x%02x mov eax,0x%02x%02x%02x%02x\n",
			data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]);
		pos += 5;
		goto begin;
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
	case 0xcc:
		printf("%02x    int3\n", data[pos]);
		pos++;
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
		printf("%02x  repz   ", data[pos]);
		pos += 1;
		goto begin;
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
		goto r;
	case 0xff:
		/* 01_110_000 */
		if ( (data[pos+1] & 0xf8 ) == 0x70 ) {
			printf("%02x%02x%02x    push dowrd [%s+0x%02x]\n",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2]
				);
			pos += 2;
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

static char* getsib8(char arg0,char arg1) {
	static char r[0x20];
	memset(r,0,sizeof(r));
	char* base = getrm(arg0);
	char* index = getregister(arg0);
	char* scale = getscale(arg0);

	snprintf(r,sizeof(r),"[%s+%s*2^%s+0x%02x]",base,index,scale,arg1);
	return r;
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


