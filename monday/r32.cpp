
char* getr32(unsigned char* arg0) {

	switch (arg0[0] & 0x38)
	{
	case 0x00:
		return "eax";
	case 0x08:
		return "ecx";
	case 0x10:
		return "edx";
	case 0x18:
		return "ebx";
	case 0x20:
		return "esp";
	case 0x28:
		return "ebp";
	case 0x30:
		return "esi";
	case 0x38:
		return "edi";
	default:
		return "unknown";
	}

}







