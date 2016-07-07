#include<stdio.h>

extern int REX_W;
extern int REX_R;
extern int REX_X;
extern int REX_B;

extern char* sib(unsigned char* arg0, int* arg1, int modbits = 0);

static void _(unsigned char* arg0, int* arg1, char** r, char** rm);
static void W(unsigned char* arg0, int* arg1, char** r, char** rm);

void r_rm(unsigned char* arg0, int* arg1, char** r, char** rm) {

	if (REX_W == 0 && REX_R == 0 && REX_X == 0 && REX_B == 0) {
		_(arg0, arg1, r, rm);
	}
	else if (REX_W==1 && REX_R==0 && REX_X==0 && REX_B==0) {
		W(arg0, arg1, r, rm);
	}

}

static void _(unsigned char* arg0, int* arg1, char** r, char** rm) {

	switch (arg0[0])
	{
	case 0xc9:
		*arg1 = 1;
		*rm = "ecx";
		*r = "ecx";
		return;
	case 0xf6:
		*arg1 = 1;
		*rm = "esi";
		*r = "esi";
		return;
	default:
		*arg1 = 1;
		*r = "unknown";
		*rm = "unknown";
		return;
	}

}

static void W(unsigned char* arg0, int* arg1, char** r, char** rm) {

	static char buffer[0x40];
	int i;

	switch (arg0[0])
	{
	case 0x04:
		*arg1 = 1;
		*rm = sib(&arg0[1],&i);
		*arg1 += i;
		*r = "rax";
		return;
	case 0x50:
		*arg1 = 2;
		snprintf(buffer, sizeof(buffer), "[rax]+0x%02x", arg0[1]);
		*rm = buffer;
		*r = "rdx";
		return;
	case 0x5c:
		*arg1 = 1+1;
		snprintf(buffer,sizeof(buffer),"%s+0x%02x",sib(&arg0[1],&i),arg0[2] );
		*arg1 += i;
		*rm = buffer;
		*r = "rbx";
		return;
	case 0x74:
		*arg1 = 2;
		snprintf(buffer, sizeof(buffer), "%s+0x%02x", sib(&arg0[1], &i), arg0[2]);
		*arg1 += i;
		*rm = buffer;
		*r = "rsi";
		return;
	case 0x9a:
		*arg1 = 5;
		snprintf(buffer, sizeof(buffer), "[rdx]+0x%02x%02x%02x%02x", arg0[4], arg0[3], arg0[2], arg0[1] );
		*rm = buffer;
		*r = "rbx";
		return;
	case 0xc4:
		*arg1 = 1;
		*rm = "rsp";
		*r = "rax";
		return;
	case 0xdb:
		*arg1 = 1;
		*rm = "rbx";
		*r = "rbx";
		return;
	case 0xec:
		*arg1 = 1;
		*rm = "rsp";
		*r = "rbp";
		return;
	default:
		*arg1 = 1;
		*r = "unknown";
		*rm = "unknown";
		return;
	}

}
