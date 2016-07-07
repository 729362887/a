#include<stdio.h>
#include<string.h>

extern int REX_W;
extern int REX_R;
extern int REX_X;
extern int REX_B;

static char* _(unsigned char* arg0, int* arg1, int modbits);
static char* W(unsigned char* arg0, int* arg1, int modbits);

char* sib(unsigned char* arg0, int* arg1,int modbits=0 ) {

	if (REX_W == 0 && REX_R == 0 && REX_X == 0 && REX_B == 0) {
		return _(arg0,arg1,modbits);
	}
	else if (REX_W == 1 && REX_R == 0 && REX_X == 0 && REX_B == 0) {
		return W(arg0,arg1,modbits);
	}

}


static char* _(unsigned char* arg0, int* arg1, int modbits = 0) {

	switch (arg0[0])
	{
	default:
		*arg1 = 0;
		return "unknown";
	}

}

static char* W(unsigned char* arg0, int* arg1, int modbits = 0) {

	static char buffer[0x30];

	switch (arg0[0])
	{
	case 0x24:
		*arg1 = 1;
		return "[rsp]";
	case 0x25:
		if (modbits==0) {
			*arg1 = 5;
			snprintf(buffer,sizeof(buffer),"[0x%02x%02x%02x%02x]",arg0[4], arg0[3], arg0[2], arg0[1]);
			return buffer;
		}
		else if (modbits==1) {
			*arg1 = 2;
			snprintf(buffer, sizeof(buffer), "[rbp+0x%02x]", arg0[1]);
			return buffer;
		}
		else if(modbits==2)
		{
			*arg1 = 5;
			snprintf(buffer, sizeof(buffer), "[rbp+0x%02x%02x%02x%02x]", arg0[4], arg0[3], arg0[2], arg0[1]);
			return buffer;
		}
		*arg1 = 0;
		return "unknown";
	default:
		*arg1 = 0;
		return "unknown";
	}

}
