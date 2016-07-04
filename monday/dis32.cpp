#include<stdio.h>

extern char* getopcode(unsigned char* arg0);
extern char* getmodrm(unsigned char* arg0, int* arg1);
extern char* getr32(unsigned char* arg0);
extern char* gethex(unsigned char* arg0, int arg1);
extern char* getimm8(unsigned char* arg0);
extern char* getimm32(unsigned char* arg0);

char* dis32(unsigned char* arg0, int* arg1) {

	static char buffer[0x100];

	char* opcode;
	char* modrm;
	char* r32;
	char* hex;
	char* imm8;
	char* imm32;
	int count;

	opcode = getopcode(arg0);
	modrm = getmodrm(&arg0[1],&count);
	r32 = getr32(&arg0[1]);
	hex = gethex(arg0, count+1);
	imm8 = getimm8(&arg0[count + 1]);
	imm32 = getimm32(&arg0[count + 1]);

	switch ( arg0[0] )
	{
	case 0x33:
		snprintf(buffer, sizeof(buffer), "%s    %s %s,%s", hex, opcode, r32, modrm);
		return buffer;
	case 0x83:
		snprintf(buffer, sizeof(buffer), "%s    %s %s,%s", gethex(arg0, count + 2), opcode, modrm, imm8);
		return buffer;
	case 0x89:
		snprintf(buffer, sizeof(buffer), "%s    %s %s,%s", hex, opcode, modrm, r32);
		return buffer;
	case 0x8b:
		snprintf(buffer, sizeof(buffer), "%s    %s %s,%s", hex, opcode, r32, modrm);
		return buffer;
	case 0x8d:
		snprintf(buffer, sizeof(buffer), "%s    %s %s,%s", hex, opcode, r32, modrm);
		return buffer;
	case 0xc7:
		snprintf(buffer, sizeof(buffer), "%s    %s %s,%s", gethex(arg0, count + 1 + 4 ), opcode, modrm, imm32);
		return buffer;
	case 0xff:
		snprintf(buffer, sizeof(buffer), "%s    %s %s", hex, opcode, modrm);
		return buffer;
	default:
		return "unknown";
	}

}


