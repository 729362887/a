#include<stdio.h>

extern char* _0f_getopcode(unsigned char* arg0);
extern char* getmodrm16(unsigned char* arg0, int* arg1);
extern char* getmodrm32(unsigned char* arg0, int* arg1);
extern char* getr16(unsigned char* arg0);
extern char* getr32(unsigned char* arg0);
extern char* gethex(unsigned char* arg0, int arg1);
extern char* getimm8(unsigned char* arg0);
extern char* getimm32(unsigned char* arg0);
extern char* getrel8(unsigned char* arg0);
extern char* getrel16(unsigned char* arg0);
extern char* getrel32(unsigned char* arg0);

char* _0f(unsigned char* arg0, int* arg1) {

	static char buffer[0x100];

	char* opcode;
	char* modrm;
	char* modrm16;
	char* modrm32;
	char* r;
	char* r16;
	char* r32;
	char* hex;
	char* imm8;
	char* imm;
	char* imm16;
	char* imm32;
	char* rel8;
	char* rel;
	char* rel16;
	char* rel32;
	int count;
	int _66 = 0;
	int index = 0;

	if (arg0[0] == 0x66) {
		index = 1;
		_66 = 1;
	}

	opcode = _0f_getopcode(&arg0[index+1]);
	modrm16 = getmodrm16(&arg0[index + 2], &count);
	modrm32 = getmodrm32(&arg0[index + 2], &count);
	r16 = getr16(&arg0[index + 2]);
	r32 = getr32(&arg0[index + 2]);
	hex = gethex(arg0, index + count + 2);
	rel16 = getrel16(&arg0[index + 2]);
	rel32 = getrel32(&arg0[index + 2]);

	if (_66) {
		r = r16;
		rel = rel16;
		modrm = modrm16;
	}
	else {
		r = r32;
		rel = rel32;
		modrm = modrm32;
	}

	switch (arg0[index+1])
	{
	case 0x83:
		snprintf(buffer, sizeof(buffer), "%s    %s +%s", gethex(arg0, index + 2 + (_66 ? 2 : 4)), opcode, rel);
		return buffer;
	case 0x84:
		snprintf(buffer, sizeof(buffer), "%s    %s +%s", gethex(arg0, index + 2 + (_66 ? 2 : 4)), opcode, rel);
		return buffer;
	case 0x85:
		snprintf(buffer, sizeof(buffer), "%s    %s +%s", gethex(arg0, index + 2 + (_66 ? 2 : 4)), opcode, rel);
		return buffer;
	case 0x86:
		snprintf(buffer, sizeof(buffer), "%s    %s +%s", gethex(arg0, index + 2 + (_66 ? 2 : 4) ), opcode, rel);
		return buffer;
	case 0x87:
		snprintf(buffer, sizeof(buffer), "%s    %s +%s", gethex(arg0, index + 2 + (_66 ? 2 : 4)), opcode, rel);
		return buffer;
	case 0x8c:
		snprintf(buffer, sizeof(buffer), "%s    %s +%s", gethex(arg0, index + 2 + (_66 ? 2 : 4)), opcode, rel);
		return buffer;
	case 0xb7:
		snprintf(buffer, sizeof(buffer), "%s    %s %s,%s", hex, opcode, r, modrm);
		return buffer;
	default:
		return "unknown";
	}


}