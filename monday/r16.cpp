char* getr16(unsigned char* arg0) {

	switch (arg0[0] & 0x38)
	{
	case 0x00:
		return "ax";
	case 0x08:
		return "cx";
	case 0x10:
		return "dx";
	case 0x18:
		return "bx";
	case 0x20:
		return "sp";
	case 0x28:
		return "bp";
	case 0x30:
		return "si";
	case 0x38:
		return "di";
	default:
		return "unknown";
	}

}