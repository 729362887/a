
char* _0_7(unsigned char* arg0);
char* _0_6(unsigned char* arg0);
char* _0_7_rol(unsigned char* arg0);

char* getopcode(unsigned char* arg0) {

	switch (arg0[0])
	{
	case 0x03:
		return "add";
	case 0x2b:
		return "sub";
	case 0x33:
		return "xor";
	case 0x39:
		return "cmp";
	case 0x3b:
		return "cmp";
	case 0x50:
		return "push eax";
	case 0x56:
		return "push";
	case 0x57:
		return "push edi";
	case 0x6a:
		return "push";
	case 0x75:
		return "jne";
	case 0x81:
		return _0_7(&arg0[1]);
	case 0x83:
		return _0_7(&arg0[1]);
	case 0x85:
		return "test";
	case 0x89:
		return "mov";
	case 0x8b:
		return "mov";
	case 0x8d:
		return "lea";
	case 0xa1:
		return "mov";
	case 0xb8:
		return "mov";
	case 0xc7:
		return "mov";
	case 0xd1:
		return _0_7_rol(&arg0[1]);
	case 0xe8:
		return "call";
	case 0xe9:
		return "jmp";
	case 0xea:
		return "jmpf";
	case 0xff:
		return _0_6(&arg0[1]);
	default:
		return "unknown";
	}

}

char* _0_6(unsigned char* arg0) {
	switch (arg0[0] & 0x38)
	{
	case 0x00:
		return "inc";
	case 0x08:
		return "dec";
	case 0x10:
		return "call";
	case 0x18:
		return "callf";
	case 0x20:
		return "jmp";
	case 0x28:
		return "jmpf";
	case 0x30:
		return "push";
	default:
		return "unknown";
	}
}

char* _0_7(unsigned char* arg0) {
	switch (arg0[0] & 0x38)
	{
	case 0x00:
		return "add";
	case 0x08:
		return "or";
	case 0x10:
		return "adc";
	case 0x18:
		return "sbb";
	case 0x20:
		return "and";
	case 0x28:
		return "sub";
	case 0x30:
		return "xor";
	case 0x38:
		return "cmp";
	default:
		return "unknown";
	}
}

char* _0_7_rol(unsigned char* arg0) {
	switch (arg0[0] & 0x38)
	{
	case 0x00:
		return "rol";
	case 0x08:
		return "ror";
	case 0x10:
		return "rcl";
	case 0x18:
		return "rcr";
	case 0x20:
		return "shl sal";
	case 0x28:
		return "shr";
	case 0x30:
		return "sal shl";
	case 0x38:
		return "sar";
	default:
		return "unknown";
	}
}
