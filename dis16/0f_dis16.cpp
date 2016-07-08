#include<stdio.h>


extern char* _0f_opcode(unsigned char* arg0);
extern char* prefix(unsigned char* arg0, int* arg1);
extern void r_rm(unsigned char* arg0, int* arg1, char** r, char** rm, char** r8, char** r32, char** sreg, char** rm8, char** rm32);
extern char* hex(unsigned char* arg0, int arg1);


char* _0f_dis16(unsigned char* arg0, int* arg1) {

	static char buffer[0x100];

	char* o;
	char* p;
	char* r;
	char* r8;
	char* r32;
	char* sreg;
	char* rm;
	char* rm8;
	char* rm32;
	int index;
	int count;

	p = prefix(arg0, &index);
	o = _0f_opcode(&arg0[index+1]);
	r_rm(&arg0[index + 2], &count, &r, &rm, &r8, &r32, &sreg, &rm8, &rm32);

	switch (arg0[index+1])
	{
	case 0x80:
	case 0x81:
	case 0x82:
	case 0x83:
	case 0x84:
	case 0x85:
	case 0x86:
	case 0x87:
	case 0x88:
	case 0x89:
	case 0x8a:
	case 0x8b:
	case 0x8c:
	case 0x8d:
	case 0x8e:
	case 0x8f:
		snprintf(buffer, sizeof(buffer), "%s    %s %s +0x%02x%02x", hex(arg0, index + 2 + 2), p, o, arg0[index + 1 + 1], arg0[index + 1]);
		return buffer;
	case 0x90:
	case 0x91:
	case 0x92:
	case 0x93:
	case 0x94:
	case 0x95:
	case 0x96:
	case 0x97:
	case 0x98:
	case 0x99:
	case 0x9a:
	case 0x9b:
	case 0x9c:
	case 0x9d:
	case 0x9e:
	case 0x9f:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s", hex(arg0, index + 2 + count), p, o, rm8 );
		return buffer;
	default:
		return "unknown";
	}

}
