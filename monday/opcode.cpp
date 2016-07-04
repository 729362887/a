
char* _0_7(unsigned char* arg0);
char* _0_6(unsigned char* arg0);

char* getopcode(unsigned char* arg0) {

	switch (arg0[0])
	{
	case 0x33:
		return "xor";
	case 0x83:
		return _0_7(&arg0[1]);
	case 0x89:
		return "mov";
	case 0x8b:
		return "mov";
	case 0x8d:
		return "lea";
	case 0xc7:
		return "mov";
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
