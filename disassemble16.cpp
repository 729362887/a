#include<stdio.h>
#include<string.h>


static char* getregister(char arg0);
static char* getrm(char arg0);
static char* getregisteral(char arg0);
static char* getrmal(char arg0);

void disassemble16( char* arg0 ) {

	int pos = 0;
	unsigned char* data = (unsigned char*)arg0;

begin:
	printf("%04x      ", pos);
	switch (data[pos]) {
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
	case 0x74:
		printf("%02x%02x    jz +0x%02x\n",
			data[pos], data[pos + 1], data[pos + 1]
		);
		pos += 2;
		goto begin;
	case 0x88:
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
	case 0xb0:
		printf("%02x%02x    mov al,0x%02x\n",
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
	case 0xea:
		printf("%02x%02x%02x%02x%02x    jmpf 0x%02x%02x:%02x%02x\n",
			data[pos], data[pos + 1], data[pos + 2],
			data[pos + 3], data[pos + 4],
			data[pos + 4], data[pos + 3], data[pos + 2], data[pos + 2]
		);
		pos += 5;
		goto begin;
	case 0xfa:
		printf("%02x    cli\n", data[pos]);
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




