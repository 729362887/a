#include<stdio.h>


extern char* opcode(unsigned char* arg0);
extern char* prefix(unsigned char* arg0, int* arg1);
extern void r_rm(unsigned char* arg0, int* arg1, char** r, char** rm);
extern char* hex(unsigned char* arg0, int arg1);

static char* _0(unsigned char* arg0);
static char* _1(unsigned char* arg0);

char* dis16(unsigned char* arg0, int* arg1) {

	static char buffer[0x100];

	char* o;
	char* p;
	char* r;
	char* rm;
	int index;
	int count;

	p = prefix(arg0, &index);
	o = opcode(&arg0[index]);
	r_rm(&arg0[index + 1], &count, &r, &rm);

	switch (arg0[index])
	{
	case 0x31:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s,%s", hex(arg0, index + 1 + count), p, o, rm, r);
		return buffer;
	case 0x3c:
		snprintf(buffer, sizeof(buffer), "%s    %s %s al,0x%02x", hex(arg0, index + 1 + 1 ), p, o, arg0[index+1]);
		return buffer;
	case 0x70:
	case 0x71:
	case 0x72:
	case 0x73:
	case 0x74:
	case 0x75:
	case 0x76:
	case 0x77:
	case 0x78:
	case 0x79:
	case 0x7a:
	case 0x7b:
	case 0x7c:
	case 0x7d:
	case 0x7e:
	case 0x7f:
		snprintf(buffer, sizeof(buffer), "%s    %s %s +0x%02x", hex(arg0, index + 1 + 1), p, o, arg0[index + 1]);
		return buffer;
	case 0xb0:
	case 0xb1:
	case 0xb2:
	case 0xb3:
	case 0xb4:
	case 0xb5:
	case 0xb6:
	case 0xb7:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s,0x%02x", hex(arg0, index + 1 + 1), p, o,_0(&arg0[index]), arg0[index + 1]);
		return buffer;
	case 0xe4:
		snprintf(buffer, sizeof(buffer), "%s    %s %s al,0x%02x", hex(arg0, index + 1 + 1), p, o, arg0[index + 1]);
		return buffer;
	case 0xe6:
		snprintf(buffer, sizeof(buffer), "%s    %s %s 0x%02x,al", hex(arg0, index + 1 + 1), p, o, arg0[index + 1]);
		return buffer;
	case 0xfa:
		snprintf(buffer, sizeof(buffer), "%s    %s %s", hex(arg0, index+1), p, o);
		return buffer;
	default:
		return "unknown";
	}

}

static char* _0(unsigned char* arg0) {

	switch (arg0[0] & 0x07)
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

static char* _1(unsigned char* arg0) {

	switch (arg0[0] & 0x07)
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





