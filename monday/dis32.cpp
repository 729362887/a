#include<stdio.h>

extern char* getopcode(unsigned char* arg0);
extern char* getmodrm32(unsigned char* arg0, int* arg1);
extern char* getmodrm16(unsigned char* arg0, int* arg1);
extern char* getr16(unsigned char* arg0);
extern char* getr32(unsigned char* arg0);
extern char* gethex(unsigned char* arg0, int arg1);
extern char* getimm8(unsigned char* arg0);
extern char* getimm16(unsigned char* arg0);
extern char* getimm32(unsigned char* arg0);
extern char* getrel8(unsigned char* arg0);
extern char* getrel16(unsigned char* arg0);
extern char* getrel32(unsigned char* arg0);
extern char* getmoffs16(unsigned char* arg0);
extern char* getmoffs32(unsigned char* arg0);
extern char* getprefix(unsigned char* arg0, int* arg1);
extern char* get16(unsigned char* arg0);
extern char* get32(unsigned char* arg0);
extern char* getptr16(unsigned char* arg0);
extern char* _0f(unsigned char* arg0, int* arg1);

extern int _66;
extern int _67;

char* dis32(unsigned char* arg0, int* arg1) {

	static char buffer[0x100];

	char* opcode;
	char* modrm;
	char* modrm16;
	char* modrm32;
	char* r;
	char* r8;
	char* r16;
	char* r32;
	char* hex;
	char* imm;
	char* imm8;
	char* imm16;
	char* imm32;
	char* rel8;
	char* rel;
	char* rel16;
	char* rel32;
	char* moffs;
	char* moffs16;
	char* moffs32;
	char* prefix;
	int count;
	int index;

	prefix = getprefix(arg0, &index);
	opcode = getopcode(&arg0[index]);
	modrm32 = getmodrm32(&arg0[index + 1], &count);
	modrm16 = getmodrm16(&arg0[index + 1], &count);
	r32 = getr32(&arg0[index + 1]);
	r16 = getr16(&arg0[index + 1]);
	hex = gethex(arg0, index + count + 1);
	imm8 = getimm8(&arg0[index + count + 1]);
	imm16 = getimm16(&arg0[index + count + 1]);
	imm32 = getimm32(&arg0[index + count + 1]);
	rel8 = getrel8(&arg0[index + 1]);
	rel16 = getrel16(&arg0[index + 1]);
	rel32 = getrel32(&arg0[index + 1]);
	moffs16 = getmoffs16(&arg0[index + 1]);
	moffs32 = getmoffs32(&arg0[index + 1]);

	if (_66) {
		r = r16;
		imm = imm16;
		rel = rel16;
		modrm = modrm16;
	}
	else {
		r = r32;
		imm = imm32;
		rel = rel32;
		modrm = modrm32;
	}

	if (_67) {
		moffs = moffs16;
	}
	else {
		moffs = moffs32;
	}

	switch (arg0[index])
	{
	case 0x03:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s,%s", hex, prefix, opcode, r, modrm);
		return buffer;
	case 0x0f:
		return _0f(arg0, arg1);
	case 0x2b:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s,%s", hex, prefix, opcode, r, modrm);
		return buffer;
	case 0x33:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s,%s", hex, prefix, opcode, r, modrm);
		return buffer;
	case 0x39:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s,%s", hex, prefix, opcode, modrm, r);
		return buffer;
	case 0x3b:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s,%s", hex, prefix, opcode, r, modrm);
		return buffer;
	case 0x50:
		*arg1 = 1;
		snprintf(buffer, sizeof(buffer), "%s    %s %s", gethex(arg0, index + 1), prefix, opcode);
		return buffer;
	case 0x56:
		*arg1 = 1;
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s", gethex(arg0, index + 1), prefix, opcode, _66 ? "si" : "esi");
		return buffer;
	case 0x57:
		*arg1 = 1;
		snprintf(buffer, sizeof(buffer), "%s    %s %s", gethex(arg0, index + 1), prefix, opcode);
		return buffer;
	case 0x6a:
		*arg1 = 2;
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s", gethex(arg0, index + 2), prefix, opcode, getimm8(&arg0[1]));
		return buffer;
	case 0x75:
		*arg1 = 2;
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s", gethex(arg0, index + 2), prefix, opcode, rel8);
		return buffer;
	case 0x81:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s,%s", gethex(arg0, index + count + 1 + (_66 ? 2 : 4)), prefix, opcode, modrm, imm);
		return buffer;
	case 0x83:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s,%s", gethex(arg0, index + count + 2), prefix, opcode, modrm, imm8);
		return buffer;
	case 0x85:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s,%s", hex, prefix, opcode, modrm, r);
		return buffer;
	case 0x89:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s,%s", hex, prefix, opcode, modrm, r);
		return buffer;
	case 0x8b:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s,%s", hex, prefix, opcode, r, modrm);
		return buffer;
	case 0x8d:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s,%s", hex, prefix, opcode, r, modrm);
		return buffer;
	case 0xa1:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s,%s %s", gethex(arg0, index + 1 + (_67 ? 2 : 4)), prefix, opcode, _66 ? "ax" : "eax", _66 ? "word ptr" : "dword ptr", moffs);
		return buffer;
	case 0xb8:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s,%s", gethex(arg0, index + 1 + (_66 ? 2 : 4)), prefix, opcode, _66 ? "ax" : "eax", _66 ? getimm16(&arg0[index + 1]) : getimm32(&arg0[index + 1]));
		return buffer;
	case 0xc7:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s,%s", gethex(arg0, index + count + 1 + (_66 ? 2 : 4)), prefix, opcode, modrm, imm);
		return buffer;
	case 0xd1:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s,1", hex, prefix, opcode, modrm);
		return buffer;
	case 0xe8:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s", gethex(arg0, index + 1 + (_66 ? 2 : 4)), prefix, opcode, rel);
		return buffer;
	case 0xe9:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s", gethex(arg0, index + 1 + (_66 ? 2 : 4)), prefix, opcode, rel);
		return buffer;
	case 0xea:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s:%s", gethex(arg0, index + 1 + (_66 ? 2 : 4) + 2), prefix, opcode, getptr16(&arg0[index + 1 + (_66 ? 2 : 4)]), _66 ? get16(&arg0[index + 1]) : get32(&arg0[index + 1]));
		return buffer;
	case 0xff:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s", hex, prefix, opcode, modrm);
		return buffer;
	default:
		return "unknown";
	}

}


