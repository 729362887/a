
char* _0f_getopcode(unsigned char* arg0) {

	switch (arg0[0])
	{
	case 0x83:
		return "jnb jae jnc";
	case 0x84:
		return "jz je";
	case 0x85:
		return "jnz jne";
	case 0x86:
		return "jbe jna";
	case 0x87:
		return "jnbe ja";
	case 0x8c:
		return "jl jnge";
	case 0xb7:
		return "movzx";
	default:
		return "unknown";
	}

}