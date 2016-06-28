#include<stdio.h>
#include<string.h>

static char* getregister(char arg0);
static char* getrm(char arg0);
static char* getregisteral(char arg0);
static char* getrmal(char arg0);
static char* getsib8(char arg0, char arg1);
static char* getsib32(char arg0, char arg1, char arg2, char arg3, char arg4);

static char buffer[0x40];

char* disassemble32(char* arg0,int* arg1 ) {

	int pos = 0;
	unsigned char* data = (unsigned char*)arg0;

	switch (data[pos])
	{
	case 0x00:
		/* 00_???_??? */
		if ( ( data[pos+1] & 0xc0 ) == 0x00 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    add byte [%s],%s(al)",
				data[pos],data[pos+1],getrm(data[pos+1]),getregister(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_100 */
		if ((data[pos + 1] & 0x47) == 0x44) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x    add byte %s,%s",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getsib8(data[pos+2],data[pos+3]),getregisteral(data[pos+1])
				);
			pos += 4;
			goto begin;
		}
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    add byte [%s+0x%02x],%s",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2],getregisteral(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
		/* 10_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x80) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x      add byte [%s+0x%02x%02x%02x%02x],%s",
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
			snprintf(buffer,sizeof(buffer),"%02x%02x    add %s,%s",
				data[pos],data[pos+1],
				getrmal(data[pos + 1]),getregisteral(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x01:
		/* 00_???_101 */
		if ((data[pos + 1] & 0xc7) == 0x05) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    "
				"add dword [0x%02x%02x%02x%02x],%s",
				data[pos],data[pos+1],data[pos+2],
				data[pos+3],data[pos+4],data[pos+5],
				data[pos+5],data[pos+4],data[pos+3],data[pos+2],
				getregister(data[pos+1])
				);
			pos += 6;
			goto begin;
		}
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    add dword [%s],%s",
				data[pos],data[pos+1],getrm(data[pos+1]),getregister(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    add dword [%s+0x%02x],%s",
				data[pos], data[pos + 1], data[pos + 2],
				getrm(data[pos + 1]), data[pos + 2], getregister(data[pos + 1])
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    add %s,%s",
				data[pos],data[pos+1],getregister(data[pos+1]),getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x02:
		/* 01_???_100 */
		if ( (data[pos+1] & 0xc7) ==0x44 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x    add %s,byte %s",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getregisteral(data[pos+1]),getsib8(data[pos+2],data[pos+3])
				);
			pos += 4;
			goto begin;
		}
		goto r;
	case 0x03:
		/* 00_???_101 */
		if ((data[pos + 1] & 0xc7) == 0x05) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    add %s,dword [0x%02x%02x%02x%02x]",
				data[pos],data[pos+1],data[pos+2],
				data[pos+3],data[pos+4],data[pos+5],
				getregister(data[pos+1]),
				data[pos+5],data[pos+4],data[pos+3],data[pos+2]
				);
			pos += 6;
			goto begin;
		}
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    add %s,dword [%s]",
				data[pos],data[pos+1],
				getregister(data[pos]),getrm(data[pos])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    add %s,[%s+0x%02x]",
				data[pos],data[pos+1],data[pos+2],
				getregister(data[pos+1]),getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    add %s,%s", 
				data[pos],data[pos+1],
				getregister(data[pos+1]),getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x04:
		snprintf(buffer,sizeof(buffer),"%02x%02x    add al,0x%02x", data[pos], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x05:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x    add eax,0x%02x%02x%02x%02x", 
			data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],
			data[pos+4],data[pos+3],data[pos+2],data[pos+1]
			);
		pos += 5;
		goto begin;
	case 0x06:
		snprintf(buffer,sizeof(buffer),"%02x    push es", data[pos]);
		pos++;
		goto begin;
	case 0x08:
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    or byte [%s],%s",
				data[pos], data[pos + 1],
				getrm(data[pos + 1]), getregisteral(data[pos + 1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    or byte [%s+0x%02x],%s",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2],getregisteral(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    or %s,%s", data[pos], data[pos + 1],
				getregisteral(data[pos + 1]), getrmal(data[pos + 1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x09:
		/* 00_???_101 */
		if ((data[pos + 1] & 0xc7) == 0x05) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    "
				"or dword [0x%02x%02x%02x%02x],%s",
				data[pos],data[pos+1],data[pos+2],
				data[pos+3],data[pos+4],data[pos+5],
				data[pos+5],data[pos+4],data[pos+3],data[pos+2],
				getregister(data[pos+1])
				);
			pos += 6;
			goto begin;
		}
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    or dword [%s+0x%02x],%s",
				data[pos], data[pos + 1], data[pos + 2],
				getrm(data[pos + 1]), data[pos + 2], getregister(data[pos + 1])
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			snprintf(buffer, sizeof(buffer), "%02x%02x    or %s,%s",
				data[pos], data[pos + 1],
				getregister(data[pos + 1]),getrm(data[pos + 1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x0a:
		/* 10_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x80) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    "
				"or %s,byte [%s+0x%02x%02x%02x%02x]",
				data[pos],data[pos+1],data[pos+2],
				data[pos+3],data[pos+4],data[pos+5],
				getregisteral(data[pos+1]),getrm(data[pos+1]),
				data[pos+5],data[pos+4],data[pos+3],data[pos+2]
				);
			pos += 6;
			goto begin;
		}
		goto r;
	case 0x0b:
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    or %s,dword [%s+0x%02x]",
				data[pos],data[pos+1],data[pos+2],
				getregister(data[pos+1]),getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ( (data[pos+1] & 0xc0) == 0xc0 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    or %s,%s", data[pos],data[pos+1],
				getregister(data[pos+1]),getrm(data[pos+1])
			);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x0c:
		snprintf(buffer,sizeof(buffer),"%02x%02x    or al,0x%02x",
			data[pos],data[pos+1],data[pos+1]
			);
		pos += 2;
		goto begin;
	case 0x0d:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x    or eax,0x%02x%02x%02x%02x",
			data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],
			data[pos+4],data[pos+3],data[pos+2],data[pos+1]
			);
		pos += 5;
		goto begin;
	case 0x0e:
		snprintf(buffer,sizeof(buffer),"%02x    push cs", data[pos]);
		pos++;
		goto begin;
	case 0x0f:
		/* 0x80 */
		if (data[pos + 1] == 0x80) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    jo +0x%02x%02x%02x%02x",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		/* 0x81 */
		if (data[pos + 1] == 0x81) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    jno +0x%02x%02x%02x%02x",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		/* 0x82 */
		if (data[pos + 1] == 0x82) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    jb +0x%02x%02x%02x%02x",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		/* 0x83 */
		if (data[pos + 1] == 0x83) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    jae +0x%02x%02x%02x%02x",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		/* 0x84 */
		if (data[pos + 1] == 0x84) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    je +0x%02x%02x%02x%02x",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		/* 0x85 */
		if ( data[pos+1] == 0x85 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    jne +0x%02x%02x%02x%02x",
				data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],data[pos+5],
				data[pos+5],data[pos+4],data[pos+3],data[pos+2]
				);
			pos += 6;
			goto begin;
		}
		/* 0x86 */
		if (data[pos + 1] == 0x86) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    jbe +0x%02x%02x%02x%02x",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		/* 0x87 */
		if (data[pos + 1] == 0x87) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    ja +0x%02x%02x%02x%02x",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		/* 0x88 */
		if (data[pos + 1] == 0x88) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    js +0x%02x%02x%02x%02x",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		/* 0x89 */
		if (data[pos + 1] == 0x89) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    jns +0x%02x%02x%02x%02x",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		/* 0x8a */
		if (data[pos + 1] == 0x8a) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    jp +0x%02x%02x%02x%02x",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		/* 0x8b */
		if (data[pos + 1] == 0x8b) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    jnp +0x%02x%02x%02x%02x",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		/* 0x8c */
		if (data[pos + 1] == 0x8c) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    jl +0x%02x%02x%02x%02x",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		/* 0x8d */
		if (data[pos + 1] == 0x8d) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    jge +0x%02x%02x%02x%02x",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		/* 0x8e */
		if (data[pos + 1] == 0x8e) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    jle +0x%02x%02x%02x%02x",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		/* 0x8f */
		if (data[pos + 1] == 0x8f) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    jg +0x%02x%02x%02x%02x",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
			);
			pos += 6;
			goto begin;
		}
		/* 0x94 */
		if (data[pos + 1] == 0x94) {
			/* 11_000_??? */
			if ((data[pos + 2] & 0xf8) == 0xc0) {
				snprintf(buffer,sizeof(buffer),"%02x%02x%02x    sete %s",
					data[pos], data[pos + 1], data[pos + 2],
					getrmal(data[pos + 2])
					);
				pos += 3;
				goto begin;
			}
		}
		/* 0x95 */
		if (data[pos + 1] == 0x95) {
			/* 11_000_??? */
			if ((data[pos + 2] & 0xf8) == 0xc0) {
				snprintf(buffer,sizeof(buffer),"%02x%02x%02x    setne %s",
					data[pos],data[pos+1],data[pos+2],
					getrmal(data[pos+2])
					);
				pos += 3;
				goto begin;
			}
		}
		/* 0x9c */
		if (data[pos + 1] == 0x9c) {
			if (data[pos + 2] == 0xc1) {
				snprintf(buffer,sizeof(buffer),"%02x%02x%02x    setl cl");
				pos += 3;
				goto begin;
			}
		}
		/* 0xa0 */
		if (data[pos + 1] == 0xa0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    push fs", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xa8 */
		if (data[pos + 1] == 0xa8) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    push gs", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xaf */
		if (data[pos + 1] == 0xaf) {
			/* 11_???_??? */
			if ( (data[pos+2] & 0xc0) == 0xc0 ) {
				snprintf(buffer,sizeof(buffer),"%02x%02x%02x   imul %s,%s",
					data[pos],data[pos+1],data[pos+2],
					getregister(data[pos+2]),getrm(data[pos+2])
					);
				pos += 3;
				goto begin;
			}
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x    imul %s,dword [%s+0x%02x]",
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
				snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x    movzx %s,byte [%s+0x%02x]",
					data[pos],data[pos+1],data[pos+2],data[pos+3],
					getregister(data[pos+2]),getrm(data[pos+2]),data[pos+3]
					);
				pos += 4;
				goto begin;
			}
			/* 11_???_??? */
			if ((data[pos + 2] & 0xc0) == 0xc0) {
				snprintf(buffer,sizeof(buffer),"%02x%02x%02x    movzx %s,%s",
					data[pos],data[pos+1],data[pos+2],
					getregister(data[pos+2]),getrmal(data[pos+2])
					);
				pos += 3;
				goto begin;
			}
		}
		/* 0xb7 */
		if (data[pos+1] == 0xb7 ) {
			/* 00_???_??? */
			if ((data[pos + 2] & 0xc0) == 0x00) {
				snprintf(buffer,sizeof(buffer),"%02x%02x%02x    movzx %s,word [%s]", 
					data[pos],data[pos+1],data[pos+2],
					getregister(data[pos+2]),getrm(data[pos+2])
					);
				pos += 3;
				goto begin;
			}
			/* 01_???_100 */
			if ((data[pos + 2] & 0xc7) == 0x44) {
				snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x    "
					"movzx %s,word %s",
					data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
					getregister(data[pos + 2]), getsib8(data[pos + 3], data[pos + 4])
					);
				pos += 5;
				goto begin;
			}
			/* 11_???_??? */
			if ( ( data[pos+2] & 0xc0 ) == 0xc0 ) {
				snprintf(buffer,sizeof(buffer),"%02x%02x%02x    movxz %s,%s",
					data[pos],data[pos+1],data[pos+2],
					getregister(data[pos+2]),getrmal(data[pos+2])
					);
				pos += 3;
				goto begin;
			}
		}
		/* 0xbe */
		if (data[pos + 1] == 0xbe) {
			/* 00_???_101 */
			if ((data[pos + 2] & 0xc7) == 0x05) {
				snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x%02x    "
					"movsx %s,byte [0x%02x%02x%02x%02x]",
					data[pos],data[pos+1],data[pos+2],data[pos+3],
					data[pos+4],data[pos+5],data[pos+6],
					getregister(data[pos+2]),
					data[pos+6],data[pos+5],data[pos+4],data[pos+3]
					);
				pos += 7;
				goto begin;
			}
			/* 00_???_??? */
			if ((data[pos + 2] & 0xc0) == 0x00) {
				snprintf(buffer,sizeof(buffer),"%02x%02x%02x    movsx %s,byte [%s]", 
					data[pos],data[pos+1],data[pos+2],
					getregister(data[pos+2]),getrm(data[pos+2])
					);
				pos += 3;
				goto begin;
			}
		}
		goto r;
	case 0x10:
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    adc byte [%s+0x%02x],%s",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2],getregisteral(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
	case 0x11:
		/* 10_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x80) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    "
				"adc dword [%s+0x%02x%02x%02x%02x],%s",
				data[pos], data[pos + 1], data[pos + 2],
				data[pos + 3], data[pos + 4], data[pos + 5],
				getrm(data[pos + 1]),
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2],
				getregister(data[pos + 1])
				);
			pos += 6;
			goto begin;
		}
		goto r;
	case 0x12:
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    adc %s,%s", 
				data[pos],data[pos+1],getregisteral(data[pos+1]),getrmal(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x13:
		/* 10_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x80) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    "
				"adc %s,dword [%s+0x%02x%02x%02x%02x]",
				data[pos], data[pos + 1], data[pos + 2],
				data[pos + 3], data[pos + 4], data[pos + 5],
				getregister(data[pos + 1]), getrm(data[pos + 1]),
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
				);
			pos += 6;
			goto begin;
		}
		goto r;
	case 0x14:
		snprintf(buffer,sizeof(buffer),"%02x%02x    adc al,0x%02x",
			data[pos],data[pos+1],data[pos+1]
			);
		pos += 2;
		goto begin;
	case 0x15:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x    adc eax,0x%02x%02x%02x%02x",
			data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],
			data[pos+4],data[pos+3],data[pos+2],data[pos+1]
			);
		pos += 5;
		goto begin;
	case 0x16:
		snprintf(buffer,sizeof(buffer),"%02x    push ss", data[pos]);
		pos++;
		goto begin;
	case 0x17:
		snprintf(buffer,sizeof(buffer),"%02x    pop ss", data[pos]);
		pos++;
		goto begin;
	case 0x18:
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    sbb byte [%s],%s", 
				data[pos],data[pos+1],
				getrm(data[pos+1]),getregisteral(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    sbb byte [%s+0x%02x],%s", 
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2],getregisteral(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    sbb %s,%s",
				data[pos],data[pos+1],getregisteral(data[pos+1]),getrmal(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x19:
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    sbb dword [%s+0x%02x],%s", 
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2],getregister(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0x1a:
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    sbb %s,byte [%s+0x%02x]", 
				data[pos],data[pos+1],data[pos+2],
				getregisteral(data[pos+1]),getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0x1b:
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    sbb %s,byte [%s+0x%02x]",
				data[pos], data[pos + 1], data[pos + 2],
				getregister(data[pos + 1]), getrm(data[pos + 1]), data[pos + 2]
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    sbb %s,%s", 
				data[pos],data[pos+1],
				getregister(data[pos+1]),getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x1c:
		snprintf(buffer,sizeof(buffer),"%02x%02x    sbb al,0x%02x",
			data[pos],data[pos+1],data[pos+1]
			);
		pos += 2;
		goto begin;
	case 0x1d:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x     sbb eax,0x%02x%02x%02x%02x", 
			data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],
			data[pos+4],data[pos+3],data[pos+2],data[pos+1]
			);
		pos += 5;
		goto begin;
	case 0x1e:
		snprintf(buffer,sizeof(buffer),"%02x    push ds", data[pos]);
		pos++;
		goto begin;
	case 0x1f:
		snprintf(buffer,sizeof(buffer),"%02x    pop ds", data[pos]);
		pos++;
		goto begin;
	case 0x20:
		/* 01_???_?? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    and byte [%s+0x%02x],%s", 
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2],getregisteral(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    and %s,%s",
				data[pos],data[pos+1],getregisteral(data[pos+1]),getrmal(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x22:
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    and %s,byte [%s+0x%02x]",
				data[pos], data[pos + 1], data[pos + 2],
				getregisteral(data[pos + 1]),getrm(data[pos + 1]), data[pos + 2]
				);
			pos += 3;
			goto begin;
		}
		/* 10_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x80) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    and %s,byte [%s+0x%02x%02x%02x%02x]", 
				data[pos],data[pos+1],data[pos+2],
				data[pos+3],data[pos+4],data[pos+5],
				getregisteral(data[pos+1]),getrm(data[pos+1]),
				data[pos+5],data[pos+4],data[pos+3],data[pos+2]
				);
			pos += 6;
			goto begin;
		}
		goto r;
	case 0x23:
		/* 00_011_??? */
		if ((data[pos + 1] & 0xf8) == 0x18) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    and %s,dword [%s]", 
				data[pos],data[pos+1],
				getregister(data[pos+1]),getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    and %s,dword [%s+0x%02x]",
				data[pos],data[pos+1],data[pos+2],
				getregister(data[pos+1]),getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    and %s,%s",
				data[pos],data[pos+1],
				getregister(data[pos+1]),getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x24:
		snprintf(buffer,sizeof(buffer),"%02x%02x    and al,0x%02x", data[pos], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x25:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x    and eax,0x%02x%02x%02x%02x",
			data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],
			data[pos+4],data[pos+3],data[pos+2],data[pos+1]
			);
		pos += 5;
		goto begin;
	case 0x26:
		snprintf(buffer,sizeof(buffer),"%02x    es", data[pos]);
		pos++;
		goto begin;
	case 0x27:
		snprintf(buffer,sizeof(buffer),"%02x    daa", data[pos]);
		pos++;
		goto begin;
	case 0x28:
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    sub byte [%s],%s", 
				data[pos],data[pos+1],getrm(data[pos+1]),getregisteral(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    sub byte [%s+0x%02x],%s", 
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2],getregisteral(data[pos+2])
				);
			pos += 3;
			goto begin;
		}
		/* 10_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x80) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    "
				"sub byte [%s+0x%02x%02x%02x%02x],%s",
				data[pos], data[pos+1],data[pos+2],
				data[pos+3],data[pos+4],data[pos+5],
				getrm(data[pos+1]),data[pos+5],data[pos+4],data[pos+3],data[pos+2],
				getregister(data[pos+1])
				);
			pos += 6;
			goto begin;
		}
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    sub %s,%s",
				data[pos], data[pos + 1],
				getregisteral(data[pos + 1]), getrmal(data[pos + 1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x29:
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    sub dword [%s+0x%02x],%s",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2],getregister(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    sub %s,%s", 
				data[pos],data[pos+1],getrm(data[pos+1]),getregister(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x2a:
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    sub %s,byte [%s]",
				data[pos],data[pos+1],getregisteral(data[pos+1]),getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto begin;
	case 0x2b:
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    sub %s,dword [%s]",
				data[pos],data[pos+1],getregister(data[pos+1]),getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_100 */
		if ( (data[pos+1] & 0xc7 ) == 0x44 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x    sub %s,%s",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getregister(data[pos+1]),getsib8(data[pos+2],data[pos+3])
				);
			pos += 4;
			goto begin;
		}
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    mov dword [%s+0x%02x],%s",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2],getregister(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ( (data[pos+1] & 0xc0) == 0xc0 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    sub %s,%s", 
				data[pos],data[pos+1],
				getregister(data[pos+1]),getrm(data[pos+1])
				);
			pos += 0x2;
			goto begin;
		}
		goto r;
	case 0x2c:
		snprintf(buffer,sizeof(buffer),"%02x%02x    sub al,0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0x2d:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x    sub eax,0x%02x%02x%02x%02x",
			data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],
			data[pos+4],data[pos+3],data[pos+2],data[pos+1]
			);
		pos += 5;
		goto begin;
	case 0x2e:
		snprintf(buffer,sizeof(buffer),"%02x    cs", data[pos]);
		pos++;
		goto begin;
	case 0x2f:
		snprintf(buffer,sizeof(buffer),"%02x    das", data[pos]);
		pos++;
		goto begin;
	case 0x30:
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    xor byte [%s+0x%02x],%s",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2],
				getregisteral(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    xor %s,%s", 
				data[pos],data[pos+1],getregisteral(data[pos+1]),getrmal(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x31:
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    xor %s,%s",
				data[pos],data[pos+1],
				getrm(data[pos+1]),getregister(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x32:
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    xor %s,byte [%s]", 
				data[pos],data[pos+1],
				getregisteral(data[pos+1]),getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    xor %s,byte [%s+0x%02x]", 
				data[pos],data[pos+1],data[pos+2],
				getregisteral(data[pos+1]),getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 10_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x80) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    "
				"xor %s,byte [%s+0x%02x%02x%02x%02x]",
				data[pos],data[pos+1],data[pos+2],
				data[pos+3],data[pos+4],data[pos+5],
				getregisteral(data[pos+1]),getrm(data[pos+1]),
				data[pos+5],data[pos+4],data[pos+3],data[pos+2]
				);
			pos += 6;
			goto begin;
		}
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    xor %s,%s",
				data[pos],data[pos],
				getregisteral(data[pos+1]),getrmal(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x33:
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    xor %s,dword [%s+0x%02x]",
				data[pos],data[pos+1],data[pos+2],
				getregister(data[pos+1]),getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ( ( data[pos+1] & 0xc0 ) == 0xc0 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    xor %s,%s", data[pos], data[pos + 1], getregister(data[pos + 1]), getrm(data[pos + 1]));
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x35:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x    xor eax,0x%02x%02x%02x%02x",
			data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],
			data[pos+4],data[pos+3],data[pos+2],data[pos+1]
			);
		pos += 5;
		goto begin;
	case 0x36:
		snprintf(buffer,sizeof(buffer),"%02x    ss", data[pos]);
		pos++;
		goto begin;
	case 0x37:
		snprintf(buffer,sizeof(buffer),"%02x    aaa", data[pos]);
		pos++;
		goto begin;
	case 0x38:
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    cmp byte [%s],%s",
				data[pos],data[pos+1],getrm(data[pos+1]),getregisteral(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    cmp byte [%s+0x%02x],%s",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2],getregisteral(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    cmp %s,%s", 
				data[pos],data[pos+1],
				getregisteral(data[pos+1]),getrmal(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x39:
		/* 00_???_101 */
		if ((data[pos + 1] & 0xc7) == 0x5) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    "
				"cmp [0x%02x%02x%02x%02x],%s",
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
			snprintf(buffer,sizeof(buffer),"%02x%02x    cmp dword [%s],%s", 
				data[pos],data[pos+1],
				getrm(data[pos+1]),getregister(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    cmp dword [%s+0x%02x],%s",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2],getregister(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0x3a:
		/* 10_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x80) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    "
				"cmp %s,byte [%s+0x%02x%02x%02x%02x]",
				data[pos],data[pos+1],data[pos+2],
				data[pos+3],data[pos+4],data[pos+5],
				getregisteral(data[pos+1]),getrm(data[pos+1]),
				data[pos+5],data[pos+4],data[pos+3],data[pos+2]
				);
			pos += 6;
			goto begin;
		}
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    cmp %s,%s",
				data[pos],data[pos+1],getregisteral(data[pos+1]),getrmal(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x3b:
		/* 00_???_101 */
		if ((data[pos + 1] & 0xc7) == 0x5) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    "
				"cmp %s,dword [0x%02x%02x%02x%02x]",
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
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x   cmp %s,dword [%s+0x%02x]",
				data[pos],data[pos+1],data[pos+2],
				getregister(data[pos+1]),getrm(data[pos+2]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ( (data[pos+1] & 0xc0) == 0xc0 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    cmp %s,%s", 
				data[pos],data[pos+1],getregister(data[pos+1]),getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x3c:
		snprintf(buffer,sizeof(buffer),"%02x%02x    cmp al,0x02x",
			data[pos],data[pos+1],data[pos+1]
			);
		pos += 2;
		goto begin;
	case 0x3d:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x    cmp eax,0x%02x%02x%02x%02x",
			data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],
			data[pos+4],data[pos+3],data[pos+2],data[pos+1]
			);
		pos += 5;
		goto begin;
	case 0x3e:
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    cmp %s,%s",
				data[pos],data[pos+1],data[pos+2],
				getregister(data[pos]),getrm(data[pos])
				);
			pos += 3;
			goto begin;
		}
		/* 01_000_??? */
		if ((data[pos + 1] & 0xf8) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    inc %s",
				data[pos],data[pos+1],getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 10_101_??? */
		if ((data[pos + 1] & 0xf8) == 0xa8) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    test %s,0x%02x",
				data[pos],data[pos+1],data[pos+2],
				getrmal(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0x40:
		snprintf(buffer,sizeof(buffer),"%02x    inc eax", data[pos]);
		pos++;
		goto begin;
	case 0x41:
		snprintf(buffer,sizeof(buffer),"%02x    inc ecx", data[pos]);
		pos++;
		goto begin;
	case 0x42:
		snprintf(buffer,sizeof(buffer),"%02x    inc edx",data[pos]);
		pos++;
		goto begin;
	case 0x43:
		snprintf(buffer,sizeof(buffer),"%02x    inc ebx", data[pos]);
		pos++;
		goto begin;
	case 0x44:
		snprintf(buffer,sizeof(buffer),"%02x    inc esp", data[pos]);
		pos++;
		goto begin;
	case 0x45:
		snprintf(buffer,sizeof(buffer),"%02x    inc ebp", data[pos]);
		pos++;
		goto begin;
	case 0x46:
		snprintf(buffer,sizeof(buffer),"%02x    inc esi", data[pos]);
		pos++;
		goto begin;
	case 0x47:
		snprintf(buffer,sizeof(buffer),"%02x    inc edi", data[pos]);
		pos++;
		goto begin;
	case 0x48:
		snprintf(buffer,sizeof(buffer),"%02x    dec eax", data[pos]);
		pos++;
		goto begin;
	case 0x49:
		snprintf(buffer,sizeof(buffer),"%02x    dec ecx", data[pos]);
		pos++;
		goto begin;
	case 0x4a:
		snprintf(buffer,sizeof(buffer),"%02x    dec edx", data[pos]);
		pos++;
		goto begin;
	case 0x4b:
		snprintf(buffer,sizeof(buffer),"%02x    dec ebx", data[pos]);
		pos++;
		goto begin;
	case 0x4c:
		snprintf(buffer,sizeof(buffer),"%02x    dec esp", data[pos]);
		pos++;
		goto begin;
	case 0x4d:
		snprintf(buffer,sizeof(buffer),"%02x    dec ebp", data[pos]);
		pos++;
		goto begin;
	case 0x4e:
		snprintf(buffer,sizeof(buffer),"%02x    dec esi", data[pos]);
		pos++;
		goto begin;
	case 0x4f:
		snprintf(buffer,sizeof(buffer),"%02x    dec edi", data[pos]);
		pos++;
		goto begin;
	case 0x50:
		snprintf(buffer,sizeof(buffer),"%02x    push eax", data[pos]);
		pos++;
		goto begin;
	case 0x51:
		snprintf(buffer,sizeof(buffer),"%02x    push ecx",data[pos]);
		pos++;
		goto begin;
	case 0x52:
		snprintf(buffer,sizeof(buffer),"%02x    push edx", data[pos]);
		pos++;
		goto begin;
	case 0x53:
		snprintf(buffer,sizeof(buffer),"%02x    push ebx", data[pos]);
		pos++;
		goto begin;
	case 0x54:
		snprintf(buffer,sizeof(buffer),"%02x    push esp", data[pos]);
		pos++;
		goto begin;
	case 0x55:
		snprintf(buffer,sizeof(buffer),"%02x    push ebp", data[pos]);
		pos++;
		goto begin;
	case 0x56:
		snprintf(buffer,sizeof(buffer),"%02x    push esi", data[pos]);
		pos++;
		goto begin;
	case 0x57:
		snprintf(buffer,sizeof(buffer),"%02x    push edi", data[pos]);
		pos++;
		goto begin;
	case 0x58:
		snprintf(buffer,sizeof(buffer),"%02x    pop eax", data[pos]);
		pos++;
		goto begin;
	case 0x59:
		snprintf(buffer,sizeof(buffer),"%02x    pop ecx",data[pos]);
		pos++;
		goto begin;
	case 0x5a:
		snprintf(buffer,sizeof(buffer),"%02x    pop edx", data[pos]);
		pos++;
		goto begin;
	case 0x5b:
		snprintf(buffer,sizeof(buffer),"%02x    pop ebx", data[pos]);
		pos++;
		goto begin;
	case 0x5c:
		snprintf(buffer,sizeof(buffer),"%02x    pop esp", data[pos]);
		pos++;
		goto begin;
	case 0x5d:
		snprintf(buffer,sizeof(buffer),"%02x    pop ebp",data[pos]);
		pos++;
		goto begin;
	case 0x5e:
		snprintf(buffer,sizeof(buffer),"%02x    pop esi",data[pos]);
		pos++;
		goto begin;
	case 0x5f:
		snprintf(buffer,sizeof(buffer),"%02x    pop edi", data[pos]);
		pos++;
		goto begin;
	case 0x60:
		snprintf(buffer,sizeof(buffer),"%02x    pusha", data[pos]);
		pos++;
		goto begin;
	case 0x61:
		snprintf(buffer,sizeof(buffer),"%02x    popa", data[pos]);
		pos++;
		goto begin;
	case 0x64:
		snprintf(buffer,sizeof(buffer),"%02x    fs    ", data[pos]);
		pos++;
		goto begin;
	case 0x66:
		goto begin;
	case 0x68:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x    push 0x%02x%02x%02x%02x",
			data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],
			data[pos+4],data[pos+3],data[pos+2],data[pos+1]
			);
		pos += 5;
		goto begin;
	case 0x69:
		/* 11_???_??? */
		if ( (data[pos+1] & 0xc0) == 0xc0 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    imul %s,%s,0x%02x%02x%02x%02x",
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
		snprintf(buffer,sizeof(buffer),"%02x%02x    push 0x%02x", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x6b:
		/* 11_???_??? */
		if ( ( data[pos+1] & 0xc0 ) == 0xc0 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    imul %s,%s,0x%02x", 
				data[pos],data[pos+1],data[pos+2],
				getregister(data[pos+1]),getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0x6c:
		snprintf(buffer,sizeof(buffer),"%02x    ins byte es:[edi],dx", data[pos]);
		pos++;
		goto begin;
	case 0x6d:
		snprintf(buffer,sizeof(buffer),"%02x    ins dword es:[edi],dx",data[pos]);
		pos++;
		goto begin;
	case 0x70:
		snprintf(buffer,sizeof(buffer),"%02x%02x    jo +0x%02x", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x71:
		snprintf(buffer,sizeof(buffer),"%02x%02x    jno +0x%02x", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x72:
		snprintf(buffer,sizeof(buffer),"%02x%02x    jb +0x%02x", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x73:
		snprintf(buffer,sizeof(buffer),"%02x%02x    jae +0x%02x", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x74:
		snprintf(buffer,sizeof(buffer),"%02x%02x    je +0x%02x", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x75:
		snprintf(buffer,sizeof(buffer),"%02x%02x    jne +0x%02x", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x76:
		snprintf(buffer,sizeof(buffer),"%02x%02x    jbe +0x%02x", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x77:
		snprintf(buffer,sizeof(buffer),"%02x%02x    ja +0x%02x", 
			data[pos],data[pos+1],data[pos+1]
			);
		pos += 2;
		goto begin;
	case 0x78:
		snprintf(buffer,sizeof(buffer),"%02x%02x    js +0x%02x", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x79:
		snprintf(buffer,sizeof(buffer),"%02x%02x    jns +0x%02x", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x7a:
		snprintf(buffer,sizeof(buffer),"%02x%02x    jp +0x%02x", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x7b:
		snprintf(buffer,sizeof(buffer),"%02x%02x    jnp +0x%02x", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x7c:
		snprintf(buffer,sizeof(buffer),"%02x%02x    jl +0x%02x", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x7d:
		snprintf(buffer,sizeof(buffer),"%02x%02x    jge +0x%02x", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x7e:
		snprintf(buffer,sizeof(buffer),"%02x%02x    jle +0x%02x", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x7f:
		snprintf(buffer,sizeof(buffer),"%02x%02x    jg +0x%02x", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0x80:
		/* 00_111_??? */
		if ((data[pos + 1] & 0xf8) == 0x38) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    cmp byte [%s],0x%02x",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 01_001_??? */
		if ((data[pos + 1] & 0xf8) == 0x48) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x    or byte [%s+0x%02x],0x%02x", 
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getrm(data[pos+1]),data[pos+2],data[pos+3]
				);
			pos += 4;
			goto begin;
		}
		/* 01_111_??? */
		if ((data[pos + 1] & 0xf8) == 0x78) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x    cmp byte [%s+0x%02x],0x%02x",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getrm(data[pos+1]),data[pos+2],data[pos+3]
				);
			pos += 4;
			goto begin;
		}
		/* 11_100_??? */
		if ((data[pos + 1] & 0xf8) == 0xe0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    and %s,0x%02x",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 11_111_??? */
		if ((data[pos + 1] & 0xf8) == 0xf8) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    cmp %s,0x%02x", 
				data[pos],data[pos+1],data[pos+2],
				getregisteral(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0x81:
		/* 01_111_??? */
		if ((data[pos + 1] & 0xf8) == 0x78) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x%02x    "
				"cmp dword [%s+0x%02x].0x%02x%02x%02x%02x",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				data[pos+4],data[pos+5],data[pos+6],
				getrm(data[pos+1]),data[pos+2],
				data[pos+6],data[pos+5],data[pos+4],data[pos+3]
				);
			pos += 7;
			goto begin;
		}
		/* 11_000_??? */
		if ((data[pos + 1] & 0xf8) == 0xc0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    "
			"add %s,0x%02x%02x%02x%02x",
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
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    "
				"and %s,0x%02x%02x%02x%02x",
				data[pos], data[pos + 1], data[pos + 2],
				data[pos + 3], data[pos + 4], data[pos + 5],
				getrm(data[pos + 1]), data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
				);
			pos += 6;
			goto begin;
		}
		/* 11_101_??? */
		if ((data[pos + 1] & 0xf8) == 0xe8) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    "
				"sub %s,0x%02x%02x%02x%02x",
				data[pos], data[pos + 1], data[pos + 2],
				data[pos + 3], data[pos + 4], data[pos + 5],
				getrm(data[pos + 1]), data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
				);
			pos += 6;
			goto begin;
		}
		/* 11_111_??? */
		if ((data[pos + 1] & 0xf8) == 0xf8) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    "
				"cmp %s,0x%02x%02x%02x%02x",
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
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x%02x    cmp byte [%s+0x%02x%02x%02x%02x],0x%02x",
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
		/* 0x05 */
		if (data[pos + 1] == 0x05) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x%02x    "
				"add dword [0x%02x%02x%02x%02x],0x%02x",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				data[pos+4],data[pos+5],data[pos+6],
				data[pos+5],data[pos+4],data[pos+3],data[pos+2],
				data[pos+6]
				);
			pos += 7;
			goto begin;
		}
		/* 0x0d */
		if (data[pos + 1] == 0x0d) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x%02x    "
				"or dword [0x%02x%02x%02x%02x],0x%02x",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3],
				data[pos + 4], data[pos + 5], data[pos + 6],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2],
				data[pos + 6]
				);
			pos += 7;
			goto begin;
		}
		/* 0x25 */
		if (data[pos + 1] == 0x25) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x%02x    "
				"and dword [0x%02x%02x%02x%02x],0x%02x",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3],
				data[pos + 4], data[pos + 5], data[pos + 6],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2],
				data[pos + 6]
				);
			pos += 7;
			goto begin;
		}
		/* 00_111_100 0x3c */
		if (data[pos+1]==0x3c) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x    cmp dword %s,0x%02x",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getsib8(data[pos+2],0),data[pos+3]
				);
			pos += 4;
			goto begin;
		}
		/* 00_111_??? */
		if ((data[pos + 1] & 0xf8) == 0x38) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    cmp dword [%s],0x%02x",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 01_000_??? */
		if ((data[pos + 1] & 0xf8) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x    add dword [%s+0x%02x],0x%02x",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getrm(data[pos+1]),data[pos+2],data[pos+3]
				);
			pos += 4;
			goto begin;
		}
		/* 01_001_??? */
		if ((data[pos + 1] & 0xf8) == 0x48) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x    or dword [%s+0x%02x],0x%02x",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3],
				getrm(data[pos + 1]), data[pos + 2], data[pos + 3]
			);
			pos += 4;
			goto begin;
		}
		/* 01_100_??? */
		if ((data[pos + 1] & 0xf8) == 0x60) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x    and dword [%s+0x%02x],0x%02x",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3],
				getrm(data[pos + 1]), data[pos + 2], data[pos + 3]
			);
			pos += 4;
			goto begin;
		}
		/* 01_111_??? */
		if ( (data[pos+1] & 0xf8) == 0x78 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x    cmp dword [%s+0x%02x],0x%02x",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getrm(data[pos+1]),data[pos+2],data[pos+3]
			);
			pos += 4;
			goto begin;
		}
		/* 10_111_??? */
		if ((data[pos + 1] & 0xf8) == 0xb8) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x%02x    "
				"cmp dword [%s+0x%02x%02x%02x%02x],0x%02x",
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
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    add %s,0x%02x",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2]);
			pos += 3;
			goto begin;
		}
		/* 11_001_??? */
		if ((data[pos + 1] & 0xf8) == 0xc8) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    or %s,0x%02x",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 11_100_??? */
		if ((data[pos + 1] & 0xf8) == 0xe0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    and %s,0x%02x",
				data[pos], data[pos + 1], data[pos + 2],
				getrm(data[pos + 1]), data[pos + 2]);
			pos += 3;
			goto begin;
		}
		/* 11_101_??? */
		if ( (data[pos + 1] & 0xf8) == 0xe8 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    sub %s,0x%02x",
				data[pos], data[pos + 1], data[pos + 2],
				getrm(data[pos + 1]), data[pos + 2]);
			pos += 3;
			goto begin;
		}
		/* 11_111_??? */
		if ((data[pos + 1] & 0xf8) == 0xf8) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    cmp %s,0x%02x",
				data[pos], data[pos + 1], data[pos + 2],
				getrm(data[pos + 1]), data[pos + 2]);
			pos += 3;
			goto begin;
		}
		/* 11_???_011 */
		if ((data[pos + 1] & 0xc7) == 0xc3) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    and %s,0x%02x", 
				data[pos],data[pos+1],data[pos+2],
				getregister(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0x84:
		/* 10_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x80) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    test byte [%s+0x%02x%02x%02x%02x],%s",
				data[pos],data[pos+1],data[pos+2],
				data[pos+3],data[pos+4],data[pos+5],
				getrm(data[pos+1]),
				data[pos+5],data[pos+4],data[pos+3],data[pos+2],
				getregisteral(data[pos+1])
				);
			pos += 6;
			goto begin;
		}
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    test %s,%s",
				data[pos],data[pos+1],getregisteral(data[pos+1]),getrmal(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x85:
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    test dword [%s],%s", 
				data[pos],data[pos+1],getrm(data[pos+1]),getregister(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    test dword [%s+0x%02x],%s",
				data[pos], data[pos + 1], data[pos + 2],
				getrm(data[pos + 1]), data[pos + 2], getregister(data[pos + 1])
				);
			pos += 3;
			goto begin;
		}
		/* 10_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x80) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    "
				"test dword [%s+0x%02x%02x%02x%02x],%s",
				data[pos], data[pos + 1], data[pos + 2],
				data[pos + 3], data[pos + 4], data[pos + 5],
				getrm(data[pos + 1]),
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2],
				getregister(data[pos + 1])
				);
			pos += 6;
			goto begin;
		}
		/* 11_???_??? */
		if ( ( data[pos+1] & 0xc0 ) == 0xc0 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    test %s,%s",data[pos],data[pos+1],
				getregister(data[pos+1]),getrm(data[pos+1]));
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x86:
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    xchg %s,byte [%s+0x%02x]",
				data[pos],data[pos+1],data[pos+2],
				getregisteral(data[pos+1]),getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0x88:
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    mov byte [%s],%s",
				data[pos],data[pos+1],getrm(data[pos+1]),getregisteral(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    mov byte [%s+0x%02x],%s(al)",
				data[pos], data[pos + 1], data[pos + 2],
				getrm(data[pos+1]),data[pos+2],getregister(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
		/* 10_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x80) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    "
				"move byte [%s+0x%02x%02x%02x%02x],%s",
				data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],data[pos+5],
				getrm(data[pos+1]),data[pos+5],data[pos+4],data[pos+3],data[pos+2],
				getregisteral(data[pos+1])
				);
			pos += 6;
			goto begin;
		}
		goto r;
	case 0x89:
		/* 00_???_100 */
		if ((data[pos + 1] & 0xc7) == 0x04) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x%02x    "
				"mov dword %s,%s",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				data[pos+4],data[pos+5],data[pos+6],
				getsib32(data[pos+2],data[pos+6],data[pos+5],data[pos+4],data[pos+3]),getregister(data[pos+1])
				);
			pos += 7;
			goto begin;
		}
		/* 00_???_101 */
		if ((data[pos + 1] & 0xc7) == 0x05) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x mov dword [0x%02x%02x%02x%02x],%s",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2],
				getregister(data[pos + 1])
				);
			pos += 6;
			goto begin;
		}
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    mov dword [%s],%s",
				data[pos], data[pos + 1], getrm(data[pos + 1]), getregister(data[pos + 1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_101 */
		if ((data[pos+1] & 0xc7) == 0x45) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    mov dword [%s+0x%02x],%s",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]), data[pos + 2],getregister(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
		/* 01_???_100 */
		if ((data[pos + 1] & 0xc7) == 0x44) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x    mov %s,%s",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getsib8(data[pos+2],data[pos+3]),getregister(data[pos+1])
				);
			pos += 4;
			goto begin;
		}
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    mov dword [%s+0x%02x],%s",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2],getregister(data[pos+1])
				);
			pos += 3;
			goto begin;
		}
		/* 10_???_??? */
		if ((data[pos+1] & 0xc0) == 0x80) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    mov dword [%s+0x%02x%02x%02x%02x],%s",
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
			snprintf(buffer,sizeof(buffer),"%02x%02x    mov %s(al),byte [%s]",
				data[pos],data[pos+1],getregister(data[pos+1]),getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_??? */
		if ( (data[pos + 1] & 0xc0) == 0x40 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    mov %s(al),byte [%s+0x%02x]",
				data[pos], data[pos + 1], data[pos+2],
				getregister(data[pos + 1]), getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 11_???_??? */
		if ((data[pos + 1] & 0xc0) == 0xc0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    mov %s,%s",
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
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    "
				"mov %s,dword [0x%02x%02x%02x%02x]",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				data[pos+4],data[pos+5],getregister(data[pos+1]),
				data[pos+5],data[pos+4],data[pos+3],data[pos+2]
			);
			pos += 6;
			goto begin;
		}
		/* 00_???_??? */
		if ( (data[pos+1] & 0xc0 ) == 0x00 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    mov %s,dword [%s]", 
				data[pos], data[pos + 1], 
				getregister(data[pos + 1]), getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_???_100 */
		if ((data[pos + 1] & 0xc7) == 0x44) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x    mov %s,%s",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getregister(data[pos+1]),getsib8(data[pos+2],data[pos+3])
				);
			pos += 4;
			goto begin;
		}
		/* 01_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    mov %s,[%s+0x%02x]",
				data[pos],data[pos+1],data[pos+2],
				getregister(data[pos+1]),getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 10_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x80) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    mov %s,dword [%s+0x%02x%02x%02x%02x]",
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
			snprintf(buffer,sizeof(buffer),"%02x%02x    mov %s,%s", data[pos], data[pos + 1],
				getregister(data[pos + 1]), getrm(data[pos + 1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0x8c:
		/* 00_000_??? */
		if ((data[pos + 1] & 0xf8) == 0x00) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    mov word [%s],es", 
				data[pos],data[pos+1],getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 10_101_??? */
		if ((data[pos + 1] & 0xf8) == 0xa8) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    "
				"mov word [%s+0x%02x%02x%02x%02x],gs",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				getrm(data[pos + 1]),
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
				);
			pos += 6;
			goto begin;
		}
		goto r;
	case 0x8d:
		/* 00_???_100 */
		/*
		if ( (data[pos + 1] & 0xc7) == 0x04 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x%02x    lea %s,%s",
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
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    lea %s,%s",
				data[pos], data[pos + 1], data[pos + 2],
				getregister(data[pos + 1]),
				getsib8(data[pos + 2], 0)
			);
			pos += 3;
			goto begin;
		}

		/* 01_???_101 */ 
		if ( (data[pos+1] & 0xc7 ) == 0x45 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    lea %s,[%s+0x%02x]", data[pos], data[pos + 1],
				data[pos + 2], getregister(data[pos + 1]), getrm(data[pos + 1]), data[pos + 2]);
			pos += 3;
			goto begin;
		}
		/* 01_???_100 */
		if ( (data[pos + 1] & 0xc7) == 0x44 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x    lea %s,%s",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getregister(data[pos+1]),getsib8(data[pos+2],data[pos+3])
			);
			pos += 4;
			goto begin;
		}
		/* 01_???_??? */
		if ( (data[pos+1] & 0xc0) == 0x40 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    lea %s,[%s+0x%02x]", 
				data[pos],data[pos+1],data[pos+2],
				getregister(data[pos+1]),getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 10_???_??? */
		if ( (data[pos+1] & 0xc0) == 0x80 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    lea %s,[%s+0x%02x%02x%02x%02x]",
				data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],data[pos+5],
				getregister(data[pos+1]),getrm(data[pos+1]),
				data[pos+5],data[pos+4],data[pos+3],data[pos+2]
				);
			pos += 6;
			goto begin;
		}
		goto r;
	case 0x8e:
		/* 10_101_??? */
		if ((data[pos + 1] & 0xf8) == 0xa8) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    "
				"mov gs,word [%s+0x%02x%02x%02x%02x]",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4], data[pos + 5],
				getrm(data[pos + 1]),
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
				);
			pos += 6;
			goto begin;
		}
		goto r;
	case 0x90:
		snprintf(buffer,sizeof(buffer),"%02x    nop", data[pos]);
		pos++;
		goto begin;
	case 0x91:
		snprintf(buffer,sizeof(buffer),"%02x    xchg ecx,eax", data[pos]);
		pos++;
		goto begin;
	case 0x92:
		snprintf(buffer,sizeof(buffer),"%02x    xchg edx,eax", data[pos]);
		pos++;
		goto begin;
	case 0x93:
		snprintf(buffer,sizeof(buffer),"%02x    xchg ebx,eax", data[pos]);
		pos++;
		goto begin;
	case 0x94:
		snprintf(buffer,sizeof(buffer),"%02x    xchg esp,eax", data[pos]);
		pos++;
		goto begin;
	case 0x95:
		snprintf(buffer,sizeof(buffer),"%02x    xchg ebp,eax", data[pos]);
		pos++;
		goto begin;
	case 0x96:
		snprintf(buffer,sizeof(buffer),"%02x    xchg esi,eax", data[pos]);
		pos++;
		goto begin;
	case 0x97:
		snprintf(buffer,sizeof(buffer),"%02x    xchg edi,eax", data[pos]);
		pos++;
		goto begin;
	case 0x98:
		snprintf(buffer,sizeof(buffer),"%02x    cwde", data[pos]);
		pos++;
		goto begin;
	case 0x99:
		snprintf(buffer,sizeof(buffer),"%02x    cdq", data[pos]);
		pos++;
		goto begin;
	case 0x9a:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x%02x    "
			"call 0x%02x%02x:0x%02x%02x%02x%02x",
			data[pos],data[pos+1],data[pos+2],data[pos+3],
			data[pos+4],data[pos+5],data[pos+6],
			data[pos+4],data[pos+3],data[pos+2],data[pos+1],
			data[pos+6],data[pos+5]
			);
		pos += 7;
		goto begin;
	case 0x9b:
		snprintf(buffer,sizeof(buffer),"%02x    fwait", data[pos]);
		pos++;
		goto begin;
	case 0x9c:
		snprintf(buffer,sizeof(buffer),"%02x    pushf", data[pos]);
		pos++;
		goto begin;
	case 0x9d:
		snprintf(buffer,sizeof(buffer),"%02x    popf", data[pos]);
		pos++;
		goto begin;
	case 0x9e:
		snprintf(buffer,sizeof(buffer),"%02x    sahf", data[pos]);
		pos++;
		goto begin;
	case 0x9f:
		snprintf(buffer,sizeof(buffer),"%02x    lahf", data[pos]);
		pos++;
		goto begin;
	case 0xa0:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x    mov al,byte [0x%02x%02x%02x%02x]",
			data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]
			);
		pos += 5;
		goto begin;
	case 0xa1:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x    mov eax,dword [0x%02x%02x%02x%02x]",
			data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]
		);
		pos += 5;
		goto begin;
	case 0xa2:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x    mov byte [0x%02x%02x%02x%02x],al",
			data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]
			);
		pos += 5;
		goto begin;
	case 0xa3:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x    mov dword [0x%02x%02x%02x%02x],eax",
			data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]
		);
		pos += 5;
		goto begin;
	case 0xa4:
		snprintf(buffer,sizeof(buffer),"%02x    movs byte es:[edi],byte ds:[esi]");
		pos++;
		goto begin;
	case 0xa5:
		snprintf(buffer,sizeof(buffer),"%02x    movs dword es:[edi],dword ds:[esi]");
		pos++;
		goto begin;
	case 0xa6:
		snprintf(buffer,sizeof(buffer),"%02x    cmps byte ds:[esi],byte es:[edi]");
		pos++;
		goto begin;
	case 0xa7:
		snprintf(buffer,sizeof(buffer),"%02x    cmps dword ds:[esi],dword es:[edi]");
		pos++;
		goto begin;
	case 0xa8:
		snprintf(buffer,sizeof(buffer),"%02x%02x    test al,0x%02x",
			data[pos],data[pos+1],data[pos+1]
			);
		pos += 2;
		goto begin;
	case 0xa9:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x    test eax,0x%02x%02x%02x%02x", 
			data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],
			data[pos+4],data[pos+3],data[pos+2],data[pos+1]
			);
		pos += 5;
		goto begin;
	case 0xaa:
		snprintf(buffer,sizeof(buffer),"%02x    stos byte es:[edi],al", data[pos]);
		pos += 1;
		goto begin;
	case 0xab:
		snprintf(buffer,sizeof(buffer),"%02x    stos byte es:[edi],eax", data[pos]);
		pos += 1;
		goto begin;
	case 0xac:
		snprintf(buffer,sizeof(buffer),"%02x    lods al,byte es:[edi]", data[pos]);
		pos += 1;
		goto begin;
	case 0xad:
		snprintf(buffer,sizeof(buffer),"%02x    lods eax,byte es:[edi]", data[pos]);
		pos += 1;
		goto begin;
	case 0xae:
		snprintf(buffer,sizeof(buffer),"%02x    scas al,byte es:[edi]", data[pos]);
		pos += 1;
		goto begin;
	case 0xaf:
		snprintf(buffer,sizeof(buffer),"%02x    scas eax,dword ptr es:[edi]",data[pos]);
		pos += 1;
		goto begin;
	case 0xb0:
		snprintf(buffer,sizeof(buffer),"%02x%02x    mov al,0x%02x", data[pos], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0xb1:
		snprintf(buffer,sizeof(buffer),"%02x%02x    mov cl,0x%02x", data[pos], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0xb2:
		snprintf(buffer,sizeof(buffer),"%02x%02x    mov dl,0x%02x", data[pos], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0xb3:
		snprintf(buffer,sizeof(buffer),"%02x%02x    mov bl,0x%02x", data[pos], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0xb4:
		snprintf(buffer,sizeof(buffer),"%02x%02x    mov ah,0x%02x", data[pos], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0xb5:
		snprintf(buffer,sizeof(buffer),"%02x%02x    mov ch,0x%02x", data[pos], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0xb6:
		snprintf(buffer,sizeof(buffer),"%02x%02x    mov dh,0x%02x", data[pos], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0xb7:
		snprintf(buffer,sizeof(buffer),"%02x%02x    mov bh,0x%02x", data[pos], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0xb8:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x mov eax,0x%02x%02x%02x%02x",
			data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]);
		pos += 5;
		goto begin;
	case 0xb9:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x mov ecx,0x%02x%02x%02x%02x",
			data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]);
		pos += 5;
		goto begin;
	case 0xba:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x mov edx,0x%02x%02x%02x%02x",
			data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]);
		pos += 5;
		goto begin;
	case 0xbb:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x mov ebx,0x%02x%02x%02x%02x",
			data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]);
		pos += 5;
		goto begin;
	case 0xbc:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x mov esp,0x%02x%02x%02x%02x",
			data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]);
		pos += 5;
		goto begin;
	case 0xbd:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x mov ebp,0x%02x%02x%02x%02x",
			data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]);
		pos += 5;
		goto begin;
	case 0xbe:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x mov esi,0x%02x%02x%02x%02x",
			data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]);
		pos += 5;
		goto begin;
	case 0xbf:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x mov edi,0x%02x%02x%02x%02x",
			data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]);
		pos += 5;
		goto begin;
	case 0xc0:
		/* 00_100_??? */
		if ((data[pos + 1] & 0xf8) == 0x20) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    shl byte [%s],0x%02x",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 00_110_??? */
		if ((data[pos + 1] & 0xf8) == 0x30) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    sal byte [%s],0x%02x",
				data[pos], data[pos + 1], data[pos + 2],
				getrm(data[pos + 1]), data[pos + 2]
				);
			pos += 3;
			goto begin;
		}
		/* 00_111_??? */
		if ( ( data[pos+1] & 0xf8 ) == 0x38 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    sar byte [%s],0x%02x",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 01_110_100 0x74 */
		if (data[pos+1] == 0x74) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x    "
				"sal byte %s,0x%02x",
				data[pos], data[pos + 1], data[pos + 2], data[pos + 3], data[pos + 4],
				getsib8(data[pos + 2], data[pos + 3]), data[pos + 4]
				);
			pos += 5;
			goto begin;
		}
		/* 10_001_??? */
		if ((data[pos + 1] & 0xf8) == 0x88) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x%02x    "
				"ror byte [%s+0x%02x%02x%02x%02x],0x%02x",
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
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x   shl %s,0x02x",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 11_101_??? */
		if ((data[pos + 1] & 0xf8) == 0xe8) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    shr %s,0x%02x", 
				data[pos], data[pos + 1], data[pos + 2],
				getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 11_111_??? */
		if ((data[pos + 1] & 0xf8) == 0xf8) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x   sar %s,0x02x",
				data[pos], data[pos + 1], data[pos + 2],
				getrm(data[pos + 1]), data[pos + 2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0xc2:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x    ret 0x%02x%02x",
			data[pos],data[pos+1],data[pos+2],
			data[pos+2],data[pos+1]
			);
		pos += 3;
		goto begin;
	case 0xc3:
		snprintf(buffer,sizeof(buffer),"%02x    ret",data[pos]);
		pos++;
		goto begin;
	case 0xc6:
		/* 01_000_??? */
		if ((data[pos + 1] & 0xf8) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x    mov byte [%s+0x%02x],0x%02x",
				data[pos], data[pos + 1], data[pos+2],data[pos+3],
				getrm(data[pos+1]),data[pos+2],data[pos+3]
				);
			pos += 4;
			goto begin;
		}
	case 0xc7:
		/* 00_000_101 */
		if ( data[pos+1] == 0x5 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x    "
				"mov dword [0x%02x%02x%02x%02x],0x%02x%02x%02x%02x",
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
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    "
				"mov dword [%s],0x%02x%02x%02x%02x",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				data[pos+4],data[pos+5],getrm(data[pos+1]),
				data[pos+5],data[pos+4],data[pos+3],data[pos+2]
			);
			pos += 6;
			goto begin;
		}
		/* 01_000_??? */
		if ( ( data[pos+1] & 0xf8 ) == 0x40 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x%02x    mov dword [%s+0x%02x],0x%02x%02x%02x%02x",
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
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x    enter 0x%02x,0x%02x%02x",
			data[pos],data[pos+1],data[pos+2],data[pos+3],
			data[pos+1],data[pos+3],data[pos+2]
			);
		pos += 4;
		goto begin;
	case 0xc9:
		snprintf(buffer,sizeof(buffer),"%02x    leave", data[pos]);
		pos++;
		goto begin;
	case 0xca:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x    retf 0x%02x%02x", 
			data[pos],data[pos+1],data[pos+2],
			data[pos+2],data[pos+1]
			);
		pos += 3;
		goto begin;
	case 0xcb:
		snprintf(buffer,sizeof(buffer),"%02x    retf", data[pos]);
		pos++;
		goto begin;
	case 0xcc:
		snprintf(buffer,sizeof(buffer),"%02x    int3", data[pos]);
		pos++;
		goto begin;
	case 0xcf:
		snprintf(buffer,sizeof(buffer),"%02x    iretd", data[pos]);
		pos++;
		goto begin;
	case 0xd0:
		/* 0x15 */
		if ( data[pos+1] == 0x15 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    "
				"rcl byte [0x%02x%02x%02x%02x],1",
				data[pos],data[pos+1],data[pos+2],
				data[pos+3],data[pos+4],data[pos+5],
				data[pos+5],data[pos+4],data[pos+3],data[pos+2]
				);
			pos += 6;
			goto begin;
		}
		/* 00_001_??? */
		if ((data[pos + 1] & 0xf8) == 0x08) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    ror byte [%s],1",
				data[pos],data[pos+1],
				getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0xd1:
		/* 11_101_??? */
		if ((data[pos + 1] & 0xf8) == 0xe8) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    shr %s,1",
				data[pos],data[pos+1],getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0xd2:
		/* 00_???_??? */
		if ((data[pos + 1] & 0xc0) == 0x00) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    rcr byte [%s],%s",
				data[pos],data[pos+1],
				getrm(data[pos+1]),getregisteral(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0xd3:
		/* 00_111_??? */
		if ((data[pos + 1] & 0xf8) == 0x38) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    sar dword [%s],cl", 
				data[pos],data[pos+1],getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 11_100_??? */
		if ((data[pos + 1] & 0xf8) == 0xe0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    shl %s,cl",
				data[pos],data[pos+1],getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 11_111_??? */
		if ((data[pos + 1] & 0xf8) == 0xf8) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    sar %s,cl",
				data[pos], data[pos + 1], getrm(data[pos + 1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0xd8:
		/* 01_011_??? */
		if ((data[pos + 1] & 0xf8) == 0x58) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    fcomp dword [%s+0x%02x]",
				data[pos], data[pos + 1],data[pos+2],
				getrm(data[pos+1]),data[pos+2]
			);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0xd9:
		/* 10_100_??? */
		if ((data[pos + 1] & 0xf8) == 0xa0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    "
				"fldenv [%s+0x%02x%02x%02x%02x]",
				data[pos],data[pos+1],data[pos+2],
				data[pos+3],data[pos+4],data[pos+5],
				getrm(data[pos+1]),
				data[pos+5],data[pos+4],data[pos+3],data[pos+2]
				);
			pos += 6;
			goto begin;
		}
		goto r;
	case 0xda:
		/* 00_101_??? */
		if ((data[pos + 1] & 0xf8) == 0x28) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    fisubr dword [%s]",
				data[pos],data[pos+1],getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
	case 0xdb:
		/* 01_000_??? */
		if ((data[pos + 1] & 0xf8) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    fild dword [%s+0x%02x]",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		goto r;
	case 0xdf:
		/* 00_000_??? */
		if ((data[pos + 1] & 0xf8) == 0x00) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    fild word [%s]",
				data[pos],data[pos+1],getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 00_010_??? */
		if ((data[pos + 1] & 0xf8) == 0x10) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    fist word [%s]",
				data[pos], data[pos + 1], getrm(data[pos + 1])
				);
			pos += 2;
			goto begin;
		}
		/* 00_100_??? */
		if ((data[pos + 1] & 0xf8) == 0x20) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    fbld tbyte [%s]",
				data[pos], data[pos + 1], getrm(data[pos + 1])
				);
			pos += 2;
			goto begin;
		}
		/* 00_110_??? */
		if ((data[pos + 1] & 0xf8) == 0x30) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    fbstp tbyte [%s]",
				data[pos], data[pos + 1], getrm(data[pos + 1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0xe0:
		snprintf(buffer,sizeof(buffer),"%02x%02x    loopne +0x%02x",
			data[pos],data[pos+1],data[pos+1]
			);
		pos += 2;
		goto begin;
	case 0xe1:
		snprintf(buffer,sizeof(buffer),"%02x%02x    loope +0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xe2:
		snprintf(buffer,sizeof(buffer),"%02x%02x    loop +0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xe3:
		snprintf(buffer,sizeof(buffer),"%02x%02x    jecxz +0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xe4:
		snprintf(buffer,sizeof(buffer),"%02x%02x    in al,0x%02x",
			data[pos],data[pos+1],data[pos+1]
			);
		pos += 2;
		goto begin;
	case 0xe5:
		snprintf(buffer,sizeof(buffer),"%02x%02x    in eax,0x%02x",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xe6:
		snprintf(buffer,sizeof(buffer),"%02x%02x    out 0x%02x,al",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xe7:
		snprintf(buffer,sizeof(buffer),"%02x%02x    out 0x%02x,eax",
			data[pos], data[pos + 1], data[pos + 1]
			);
		pos += 2;
		goto begin;
	case 0xe8:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x call 0x%02x%02x%02x%02x",
			data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]);
		pos += 5;
		goto begin;
	case 0xe9:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x    jmp 0x%02x%02x%02x%02x",
			data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],
			data[pos+4],data[pos+3],data[pos+2],data[pos+1]
			);
		pos += 5;
		goto begin;
	case 0xea:
		snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x%02x    jmp %02x%02x:%02x%02x%02x%02x",
			data[pos],data[pos+1], data[pos + 2], data[pos + 3], data[pos + 4],
			data[pos + 5], data[pos + 6], 
			data[pos + 6], data[pos + 5],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 1]
			);
		pos += 7;
		goto begin;
	case 0xeb:
		snprintf(buffer,sizeof(buffer),"%02x%02x    jmp +0x%02x", data[pos], data[pos + 1], data[pos + 1]);
		pos += 2;
		goto begin;
	case 0xec:
		snprintf(buffer,sizeof(buffer),"%02x    in al,dx", data[pos]);
		pos++;
		goto begin;
	case 0xed:
		snprintf(buffer,sizeof(buffer),"%02x    in eax,dx", data[pos]);
		pos++;
		goto begin;
	case 0xee:
		snprintf(buffer,sizeof(buffer),"%02x    out dx,al", data[pos]);
		pos++;
		goto begin;
	case 0xef:
		snprintf(buffer,sizeof(buffer),"%02x    out dx,eax", data[pos]);
		pos++;
		goto begin;
	case 0xf0:
		snprintf(buffer,sizeof(buffer),"%02x    lock", data[pos]);
		pos++;
		goto begin;
	case 0xf1:
		snprintf(buffer,sizeof(buffer),"%02x    icebp", data[pos]);
		pos++;
		goto begin;
	case 0xf2:
		snprintf(buffer,sizeof(buffer),"%02x    repnz", data[pos]);
		pos++;
		goto begin;
	case 0xf3:
		snprintf(buffer,sizeof(buffer),"%02x  repz   ", data[pos]);
		pos += 1;
		goto begin;
	case 0xf4:
		snprintf(buffer,sizeof(buffer),"%02x    hlt",data[pos]);
		pos += 1;
		goto begin;
	case 0xf5:
		snprintf(buffer,sizeof(buffer),"%02x    cmc", data[pos]);
		pos++;
		goto begin;
	case 0xf6:
		/* 0x05 */
		if ( data[pos+1] == 0x05 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x%02x    "
				"test byte [0x%02x%02x%02x%02x],0x%02x",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				data[pos+4],data[pos+5],data[pos+6],
				data[pos+5],data[pos+4],data[pos+3],data[pos+2],
				data[pos+6]
				);
			pos += 7;
			goto begin;
		}
		/* 00_000_??? */
		if ((data[pos + 1] & 0xf8) == 0x00) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    test byte [%s],0x%02x", 
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 01_000_??? */
		if ((data[pos + 1] & 0xf8) == 0x40) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x    test byte [%s+0x%02x],0x%02x", 
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				getrm(data[pos+1]),data[pos+2],data[pos+3]
				);
			pos += 4;
			goto begin;
		}
		/* 11_000_??? */
		if ((data[pos + 1] & 0xf8) == 0xc0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    test %s,0x%02x",
				data[pos],data[pos+1],data[pos+2],
				getrmal(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 11_011_??? */
		if ((data[pos + 1] & 0xf8) == 0xd8) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    neg %s",
				data[pos], data[pos + 1], getrmal(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0xf7:
		/* 01_000_??? */
		if ( ( data[pos+1] &0xf8 ) == 0x40 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x%02x    test dword [%s+0x%02x],0x%02x%02x%02x%02x",
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
			snprintf(buffer,sizeof(buffer),"%02x%02x    neg %s",
				data[pos],data[pos+1],getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 11_100_??? */
		if ((data[pos + 1] & 0xf8) == 0xe0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    mul eax,%s",
				data[pos],data[pos+1],getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 11_???_??? */
		if ( (data[pos+1] & 0xc0) == 0xc0 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    idiv %s,%s",
				data[pos],data[pos+1],getregister(data[pos+1]),getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		goto r;
	case 0xf8:
		snprintf(buffer,sizeof(buffer),"%02x    clc", data[pos]);
		pos++;
		goto begin;
	case 0xf9:
		snprintf(buffer,sizeof(buffer),"%02x    stc", data[pos]);
		pos++;
		goto begin;
	case 0xfa:
		snprintf(buffer,sizeof(buffer),"%02x    cli", data[pos]);
		pos++;
		goto begin;
	case 0xfb:
		snprintf(buffer,sizeof(buffer),"%02x    sti", data[pos]);
		pos++;
		goto begin;
	case 0xfc:
		snprintf(buffer,sizeof(buffer),"%02x    cld", data[pos]);
		pos++;
		goto begin;
	case 0xfd:
		snprintf(buffer,sizeof(buffer),"%02x    std", data[pos]);
		pos++;
		goto begin;
	case 0xfe:
		/* 0x05 */
		if (data[pos + 1] == 0x05) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    inc byte [0x%02x%02x%02x%02x]",
				data[pos], data[pos + 1], data[pos + 2],
				data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
				);
			pos += 6;
			goto begin;
		}
	case 0xff:
		/* 0x05 */
		if (data[pos + 1] == 0x05) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    inc dword [0x%02x%02x%02x%02x]", 
				data[pos],data[pos+1],data[pos+2],
				data[pos+3],data[pos+4],data[pos+5],
				data[pos+5],data[pos+4],data[pos+3],data[pos+2]
				);
			pos += 6;
			goto begin;
		}
		/* 0x0d */
		if (data[pos + 1] == 0x0d) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    dec dword [0x%02x%02x%02x%02x]",
				data[pos], data[pos + 1], data[pos + 2],
				data[pos + 3], data[pos + 4], data[pos + 5],
				data[pos + 5], data[pos + 4], data[pos + 3], data[pos + 2]
				);
			pos += 6;
			goto begin;
		}
		/* 0x15 */
		if ( data[pos+1] == 0x15 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    "
				"call dword [0x%02x%02x%02x%02x]",
				data[pos],data[pos+1],data[pos+2],
				data[pos+3],data[pos+4],data[pos+5],
				data[pos+5],data[pos+4],data[pos+3],data[pos+2]
			);
			pos += 6;
			goto begin;
		}
		/* 0x24 */
		if (data[pos + 1] == 0x24) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    "
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
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    inc dword [ebp+0x%02x]",
				data[pos],data[pos+1],data[pos+2],data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 0xc0 */
		if (data[pos + 1] == 0xc0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    inc eax", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xc1 */
		if (data[pos + 1] == 0xc1) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    inc ecx", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xc2 */
		if (data[pos + 1] == 0xc2) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    inc edx", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xc3 */
		if (data[pos + 1] == 0xc3) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    inc ebx", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xc4 */
		if (data[pos + 1] == 0xc4) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    inc esp", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xc5 */
		if (data[pos + 1] == 0xc5) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    inc ebp", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xc6 */
		if (data[pos + 1] == 0xc6) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    inc esi", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xc7 */
		if (data[pos+1]==0xc7) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    inc edi",data[pos],data[pos+1]);
			pos += 2;
			goto begin;
		}
		/* 0xc8 */
		if (data[pos + 1] == 0xc8) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    dec eax", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xc9 */
		if (data[pos + 1] == 0xc9) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    dec ecx", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xca */
		if (data[pos + 1] == 0xca) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    dec edx", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xcb */
		if (data[pos + 1] == 0xcb) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    dec ebx", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xcc */
		if (data[pos + 1] == 0xcc) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    dec esp", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xcd */
		if (data[pos + 1] == 0xcd) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    dec ebp", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xce */
		if (data[pos + 1] == 0xce) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    dec esi", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xcf */
		if (data[pos + 1] == 0xcf) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    dec edi", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xd0 */
		if (data[pos + 1] == 0xd0) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    call eax", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xd1 */
		if (data[pos + 1] == 0xd1) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    call ecx", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xd2 */
		if (data[pos + 1] == 0xd2) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    call edx", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xd3 */
		if (data[pos + 1] == 0xd3) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    call ebx", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xd4 */
		if (data[pos + 1] == 0xd4) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    call esp", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xd5 */
		if (data[pos + 1] == 0xd5) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    call ebp", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xd6 */
		if (data[pos + 1] == 0xd6) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    call esi", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 0xd7 */
		if (data[pos + 1] == 0xd7) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    call edi", data[pos], data[pos + 1]);
			pos += 2;
			goto begin;
		}
		/* 00_000_??? */
		if ((data[pos + 1] & 0xf8) == 0x00) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    inc dword [%s]",
				data[pos], data[pos + 1], getrm(data[pos + 1])
				);
			pos += 2;
			goto begin;
		}
		/* 00_001_??? */
		if ((data[pos + 1] & 0xf8) == 0x08) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    dec dword [%s]",
				data[pos],data[pos+1],getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 00_010_??? */
		if ((data[pos + 1] & 0xf8) == 0x10) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    call dword [%s]",
				data[pos],data[pos+1],getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 00_110_??? */
		if ((data[pos + 1] & 0xf8) == 0x30) {
			snprintf(buffer,sizeof(buffer),"%02x%02x    push dword [%s]",
				data[pos],data[pos+1],getrm(data[pos+1])
				);
			pos += 2;
			goto begin;
		}
		/* 01_010_??? */
		if ((data[pos + 1] & 0xf8) == 0x50) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    call dword [%s+0x%02x]",
				data[pos],data[pos+1],data[pos+2],
				getrm(data[pos+1]),data[pos+2]
				);
			pos += 3;
			goto begin;
		}
		/* 01_110_??? */
		if ((data[pos + 1] & 0xf8) == 0x70) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x    push dword [%s+0x%02x]",
				data[pos], data[pos + 1], data[pos + 2],
				getrm(data[pos + 1]), data[pos + 2]
				);
			pos += 3;
			goto begin;
		}
		/* 10_001_??? */
		if ((data[pos + 1] & 0xf8) == 0x88) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    dec dword [%s+0x%02x%02x%02x%02x]",
				data[pos],data[pos+1],data[pos+2],data[pos+3],
				data[pos+4],data[pos+5],
				getrm(data[pos+1]),data[pos+5],data[pos+4],data[pos+3],data[pos+2]
				);
			pos += 6;
			goto begin;
		}
		/* 10_110_??? */
		if ((data[pos + 1] & 0xf8) == 0xb0 ) {
			snprintf(buffer,sizeof(buffer),"%02x%02x%02x%02x%02x%02x    push dword [%s+0x%02x%02x%02x%02x]",
				data[pos],data[pos+1],data[pos+2],data[pos+3],data[pos+4],data[pos+5],
				getrm(data[pos+1]),data[pos+5],data[pos+4],data[pos+3],data[pos+2]
				);
			pos += 6;
			goto begin;
		}
		goto r;
	default:	
		goto r;
	}

begin:
r:
	*arg1 = pos;
	return buffer;
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


