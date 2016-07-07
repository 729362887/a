#include<stdio.h>

void r_rm(unsigned char* arg0, int* arg1, char** r, char** rm) {

	static char buffer[0x40];

	switch (arg0[0])
	{
	case 0x00:
		*arg1 = 1;
		*r = "ax";
		*rm = "[bx+si]";
		return;
	case 0x01:
		*arg1 = 1;
		*r = "ax";
		*rm = "[bx+di]";
		return;
	case 0x02:
		*arg1 = 1;
		*r = "ax";
		*rm = "[bp+si]";
		return;
	case 0x03:
		*arg1 = 1;
		*r = "ax";
		*rm = "[bp+di]";
		return;
	case 0x04:
		*arg1 = 1;
		*r = "ax";
		*rm = "[si]";
		return;
	case 0x05:
		*arg1 = 1;
		*r = "ax";
		*rm = "[di]";
		return;
	case 0x06:
		*arg1 = 3;
		*r = "ax";
		snprintf(buffer, sizeof(buffer), "0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x07:
		*arg1 = 1;
		*r = "ax";
		*rm = "[bx]";
		return;
		/****************************************************************************/
	case 0x08:
		*arg1 = 1;
		*r = "cx";
		*rm = "[bx+si]";
		return;
	case 0x09:
		*arg1 = 1;
		*r = "cx";
		*rm = "[bx+di]";
		return;
	case 0x0a:
		*arg1 = 1;
		*r = "cx";
		*rm = "[bp+si]";
		return;
	case 0x0b:
		*arg1 = 1;
		*r = "cx";
		*rm = "[bp+di]";
		return;
	case 0x0c:
		*arg1 = 1;
		*r = "cx";
		*rm = "[si]";
		return;
	case 0x0d:
		*arg1 = 1;
		*r = "cx";
		*rm = "[di]";
		return;
	case 0x0e:
		*arg1 = 3;
		*r = "cx";
		snprintf(buffer, sizeof(buffer), "0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x0f:
		*arg1 = 1;
		*r = "cx";
		*rm = "[bx]";
		return;
		/****************************************************************************/
	case 0x10:
		*arg1 = 1;
		*r = "dx";
		*rm = "[bx+si]";
		return;
	case 0x11:
		*arg1 = 1;
		*r = "dx";
		*rm = "[bx+di]";
		return;
	case 0x12:
		*arg1 = 1;
		*r = "dx";
		*rm = "[bp+si]";
		return;
	case 0x13:
		*arg1 = 1;
		*r = "dx";
		*rm = "[bp+di]";
		return;
	case 0x14:
		*arg1 = 1;
		*r = "dx";
		*rm = "[si]";
		return;
	case 0x15:
		*arg1 = 1;
		*r = "dx";
		*rm = "[di]";
		return;
	case 0x16:
		*arg1 = 3;
		*r = "dx";
		snprintf(buffer, sizeof(buffer), "0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x17:
		*arg1 = 1;
		*r = "dx";
		*rm = "[bx]";
		return;
		/****************************************************************************/
	case 0x18:
		*arg1 = 1;
		*r = "bx";
		*rm = "[bx+si]";
		return;
	case 0x19:
		*arg1 = 1;
		*r = "bx";
		*rm = "[bx+di]";
		return;
	case 0x1a:
		*arg1 = 1;
		*r = "bx";
		*rm = "[bp+si]";
		return;
	case 0x1b:
		*arg1 = 1;
		*r = "bx";
		*rm = "[bp+di]";
		return;
	case 0x1c:
		*arg1 = 1;
		*r = "bx";
		*rm = "[si]";
		return;
	case 0x1d:
		*arg1 = 1;
		*r = "bx";
		*rm = "[di]";
		return;
	case 0x1e:
		*arg1 = 3;
		*r = "bx";
		snprintf(buffer, sizeof(buffer), "0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x1f:
		*arg1 = 1;
		*r = "bx";
		*rm = "[bx]";
		return;
		/****************************************************************************/
	case 0x20:
		*arg1 = 1;
		*r = "sp";
		*rm = "[bx+si]";
		return;
	case 0x21:
		*arg1 = 1;
		*r = "sp";
		*rm = "[bx+di]";
		return;
	case 0x22:
		*arg1 = 1;
		*r = "sp";
		*rm = "[bp+si]";
		return;
	case 0x23:
		*arg1 = 1;
		*r = "sp";
		*rm = "[bp+di]";
		return;
	case 0x24:
		*arg1 = 1;
		*r = "sp";
		*rm = "[si]";
		return;
	case 0x25:
		*arg1 = 1;
		*r = "sp";
		*rm = "[di]";
		return;
	case 0x26:
		*arg1 = 3;
		*r = "sp";
		snprintf(buffer, sizeof(buffer), "0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x27:
		*arg1 = 1;
		*r = "sp";
		*rm = "[bx]";
		return;
		/****************************************************************************/
	case 0x28:
		*arg1 = 1;
		*r = "bp";
		*rm = "[bx+si]";
		return;
	case 0x29:
		*arg1 = 1;
		*r = "bp";
		*rm = "[bx+di]";
		return;
	case 0x2a:
		*arg1 = 1;
		*r = "bp";
		*rm = "[bp+si]";
		return;
	case 0x2b:
		*arg1 = 1;
		*r = "bp";
		*rm = "[bp+di]";
		return;
	case 0x2c:
		*arg1 = 1;
		*r = "bp";
		*rm = "[si]";
		return;
	case 0x2d:
		*arg1 = 1;
		*r = "bp";
		*rm = "[di]";
		return;
	case 0x2e:
		*arg1 = 3;
		*r = "bp";
		snprintf(buffer, sizeof(buffer), "0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x2f:
		*arg1 = 1;
		*r = "bp";
		*rm = "[bx]";
		return;
		/****************************************************************************/
	case 0x30:
		*arg1 = 1;
		*r = "si";
		*rm = "[bx+si]";
		return;
	case 0x31:
		*arg1 = 1;
		*r = "si";
		*rm = "[bx+di]";
		return;
	case 0x32:
		*arg1 = 1;
		*r = "si";
		*rm = "[bp+si]";
		return;
	case 0x33:
		*arg1 = 1;
		*r = "si";
		*rm = "[bp+di]";
		return;
	case 0x34:
		*arg1 = 1;
		*r = "si";
		*rm = "[si]";
		return;
	case 0x35:
		*arg1 = 1;
		*r = "si";
		*rm = "[di]";
		return;
	case 0x36:
		*arg1 = 3;
		*r = "si";
		snprintf(buffer, sizeof(buffer), "0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x37:
		*arg1 = 1;
		*r = "si";
		*rm = "[bx]";
		return;
		/****************************************************************************/
	case 0x38:
		*arg1 = 1;
		*r = "di";
		*rm = "[bx+si]";
		return;
	case 0x39:
		*arg1 = 1;
		*r = "di";
		*rm = "[bx+di]";
		return;
	case 0x3a:
		*arg1 = 1;
		*r = "di";
		*rm = "[bp+si]";
		return;
	case 0x3b:
		*arg1 = 1;
		*r = "di";
		*rm = "[bp+di]";
		return;
	case 0x3c:
		*arg1 = 1;
		*r = "di";
		*rm = "[si]";
		return;
	case 0x3d:
		*arg1 = 1;
		*r = "di";
		*rm = "[di]";
		return;
	case 0x3e:
		*arg1 = 3;
		*r = "di";
		snprintf(buffer, sizeof(buffer), "0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x3f:
		*arg1 = 1;
		*r = "di";
		*rm = "[bx]";
		return;
		/****************************************************************************/
	case 0x40:
		*arg1 = 2;
		*r = "ax";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x41:
		*arg1 = 2;
		*r = "ax";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x42:
		*arg1 = 2;
		*r = "ax";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x43:
		*arg1 = 2;
		*r = "ax";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x44:
		*arg1 = 2;
		*r = "ax";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x45:
		*arg1 = 2;
		*r = "ax";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x46:
		*arg1 = 2;
		*r = "ax";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x47:
		*arg1 = 2;
		*r = "ax";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
		/****************************************************************************/
	case 0x48:
		*arg1 = 2;
		*r = "cx";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x49:
		*arg1 = 2;
		*r = "cx";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x4a:
		*arg1 = 2;
		*r = "cx";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x4b:
		*arg1 = 2;
		*r = "cx";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x4c:
		*arg1 = 2;
		*r = "cx";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x4d:
		*arg1 = 2;
		*r = "cx";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x4e:
		*arg1 = 2;
		*r = "cx";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x4f:
		*arg1 = 2;
		*r = "cx";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
		/****************************************************************************/
	case 0x50:
		*arg1 = 2;
		*r = "dx";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x51:
		*arg1 = 2;
		*r = "dx";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x52:
		*arg1 = 2;
		*r = "dx";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x53:
		*arg1 = 2;
		*r = "dx";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x54:
		*arg1 = 2;
		*r = "dx";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x55:
		*arg1 = 2;
		*r = "dx";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x56:
		*arg1 = 2;
		*r = "dx";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x57:
		*arg1 = 2;
		*r = "dx";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
		/****************************************************************************/
	case 0x58:
		*arg1 = 2;
		*r = "bx";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x59:
		*arg1 = 2;
		*r = "bx";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x5a:
		*arg1 = 2;
		*r = "bx";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x5b:
		*arg1 = 2;
		*r = "bx";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x5c:
		*arg1 = 2;
		*r = "bx";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x5d:
		*arg1 = 2;
		*r = "bx";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x5e:
		*arg1 = 2;
		*r = "bx";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x5f:
		*arg1 = 2;
		*r = "bx";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
		/****************************************************************************/
	case 0x60:
		*arg1 = 2;
		*r = "sp";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x61:
		*arg1 = 2;
		*r = "sp";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x62:
		*arg1 = 2;
		*r = "sp";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x63:
		*arg1 = 2;
		*r = "sp";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x64:
		*arg1 = 2;
		*r = "sp";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x65:
		*arg1 = 2;
		*r = "sp";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x66:
		*arg1 = 2;
		*r = "sp";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x67:
		*arg1 = 2;
		*r = "sp";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
		/****************************************************************************/
	case 0x68:
		*arg1 = 2;
		*r = "bp";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x69:
		*arg1 = 2;
		*r = "bp";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x6a:
		*arg1 = 2;
		*r = "bp";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x6b:
		*arg1 = 2;
		*r = "bp";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x6c:
		*arg1 = 2;
		*r = "bp";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x6d:
		*arg1 = 2;
		*r = "bp";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x6e:
		*arg1 = 2;
		*r = "bp";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x6f:
		*arg1 = 2;
		*r = "bp";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
		/****************************************************************************/
	case 0x70:
		*arg1 = 2;
		*r = "si";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x71:
		*arg1 = 2;
		*r = "si";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x72:
		*arg1 = 2;
		*r = "si";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x73:
		*arg1 = 2;
		*r = "si";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x74:
		*arg1 = 2;
		*r = "si";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x75:
		*arg1 = 2;
		*r = "si";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x76:
		*arg1 = 2;
		*r = "si";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x77:
		*arg1 = 2;
		*r = "si";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
		/****************************************************************************/
	case 0x78:
		*arg1 = 2;
		*r = "di";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x79:
		*arg1 = 2;
		*r = "di";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x7a:
		*arg1 = 2;
		*r = "di";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x7b:
		*arg1 = 2;
		*r = "di";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x7c:
		*arg1 = 2;
		*r = "di";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x7d:
		*arg1 = 2;
		*r = "di";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x7e:
		*arg1 = 2;
		*r = "di";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
	case 0x7f:
		*arg1 = 2;
		*r = "di";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x", arg0[1]);
		*rm = buffer;
		return;
		/****************************************************************************/
	case 0x80:
		*arg1 = 3;
		*r = "ax";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x81:
		*arg1 = 3;
		*r = "ax";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x82:
		*arg1 = 3;
		*r = "ax";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x83:
		*arg1 = 3;
		*r = "ax";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x84:
		*arg1 = 3;
		*r = "ax";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x85:
		*arg1 = 3;
		*r = "ax";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x86:
		*arg1 = 3;
		*r = "ax";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x87:
		*arg1 = 3;
		*r = "ax";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
		/****************************************************************************/
	case 0x88:
		*arg1 = 3;
		*r = "cx";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x89:
		*arg1 = 3;
		*r = "cx";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x8a:
		*arg1 = 3;
		*r = "cx";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x8b:
		*arg1 = 3;
		*r = "cx";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x8c:
		*arg1 = 3;
		*r = "cx";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x8d:
		*arg1 = 3;
		*r = "cx";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x8e:
		*arg1 = 3;
		*r = "cx";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x8f:
		*arg1 = 3;
		*r = "cx";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
		/****************************************************************************/
	case 0x90:
		*arg1 = 3;
		*r = "dx";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x91:
		*arg1 = 3;
		*r = "dx";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x92:
		*arg1 = 3;
		*r = "dx";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x93:
		*arg1 = 3;
		*r = "dx";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x94:
		*arg1 = 3;
		*r = "dx";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x95:
		*arg1 = 3;
		*r = "dx";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x96:
		*arg1 = 3;
		*r = "dx";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x97:
		*arg1 = 3;
		*r = "dx";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
		/****************************************************************************/
	case 0x98:
		*arg1 = 3;
		*r = "bx";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x99:
		*arg1 = 3;
		*r = "bx";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x9a:
		*arg1 = 3;
		*r = "bx";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x9b:
		*arg1 = 3;
		*r = "bx";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x9c:
		*arg1 = 3;
		*r = "bx";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x9d:
		*arg1 = 3;
		*r = "bx";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x9e:
		*arg1 = 3;
		*r = "bx";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0x9f:
		*arg1 = 3;
		*r = "bx";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
		/****************************************************************************/
	case 0xa0:
		*arg1 = 3;
		*r = "sp";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xa1:
		*arg1 = 3;
		*r = "sp";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xa2:
		*arg1 = 3;
		*r = "sp";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xa3:
		*arg1 = 3;
		*r = "sp";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xa4:
		*arg1 = 3;
		*r = "sp";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xa5:
		*arg1 = 3;
		*r = "sp";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xa6:
		*arg1 = 3;
		*r = "sp";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xa7:
		*arg1 = 3;
		*r = "sp";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
		/****************************************************************************/
	case 0xa8:
		*arg1 = 3;
		*r = "bp";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xa9:
		*arg1 = 3;
		*r = "bp";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xaa:
		*arg1 = 3;
		*r = "bp";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xab:
		*arg1 = 3;
		*r = "bp";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xac:
		*arg1 = 3;
		*r = "bp";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xad:
		*arg1 = 3;
		*r = "bp";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xae:
		*arg1 = 3;
		*r = "bp";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xaf:
		*arg1 = 3;
		*r = "bp";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
		/****************************************************************************/
	case 0xb0:
		*arg1 = 3;
		*r = "si";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xb1:
		*arg1 = 3;
		*r = "si";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xb2:
		*arg1 = 3;
		*r = "si";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xb3:
		*arg1 = 3;
		*r = "si";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xb4:
		*arg1 = 3;
		*r = "si";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xb5:
		*arg1 = 3;
		*r = "si";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xb6:
		*arg1 = 3;
		*r = "si";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xb7:
		*arg1 = 3;
		*r = "si";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
		/****************************************************************************/
	case 0xb8:
		*arg1 = 3;
		*r = "di";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xb9:
		*arg1 = 3;
		*r = "di";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xba:
		*arg1 = 3;
		*r = "di";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xbb:
		*arg1 = 3;
		*r = "di";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xbc:
		*arg1 = 3;
		*r = "di";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xbd:
		*arg1 = 3;
		*r = "di";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xbe:
		*arg1 = 3;
		*r = "di";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
	case 0xbf:
		*arg1 = 3;
		*r = "di";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		return;
		/****************************************************************************/
	case 0xc0:
		*arg1 = 1;
		*r = "ax";
		*rm = "ax";
		return;
	case 0xc1:
		*arg1 = 1;
		*r = "ax";
		*rm = "cx";
		return;
	case 0xc2:
		*arg1 = 1;
		*r = "ax";
		*rm = "dx";
		return;
	case 0xc3:
		*arg1 = 1;
		*r = "ax";
		*rm = "bx";
		return;
	case 0xc4:
		*arg1 = 1;
		*r = "ax";
		*rm = "sp";
		return;
	case 0xc5:
		*arg1 = 1;
		*r = "ax";
		*rm = "bp";
		return;
	case 0xc6:
		*arg1 = 1;
		*r = "ax";
		*rm = "si";
		return;
	case 0xc7:
		*arg1 = 1;
		*r = "ax";
		*rm = "di";
		return;
		/****************************************************************************/
	case 0xc8:
		*arg1 = 1;
		*r = "cx";
		*rm = "ax";
		return;
	case 0xc9:
		*arg1 = 1;
		*r = "cx";
		*rm = "cx";
		return;
	case 0xca:
		*arg1 = 1;
		*r = "cx";
		*rm = "dx";
		return;
	case 0xcb:
		*arg1 = 1;
		*r = "cx";
		*rm = "bx";
		return;
	case 0xcc:
		*arg1 = 1;
		*r = "cx";
		*rm = "sp";
		return;
	case 0xcd:
		*arg1 = 1;
		*r = "cx";
		*rm = "bp";
		return;
	case 0xce:
		*arg1 = 1;
		*r = "cx";
		*rm = "si";
		return;
	case 0xcf:
		*arg1 = 1;
		*r = "cx";
		*rm = "di";
		return;
		/****************************************************************************/
	case 0xd0:
		*arg1 = 1;
		*r = "dx";
		*rm = "ax";
		return;
	case 0xd1:
		*arg1 = 1;
		*r = "dx";
		*rm = "cx";
		return;
	case 0xd2:
		*arg1 = 1;
		*r = "dx";
		*rm = "dx";
		return;
	case 0xd3:
		*arg1 = 1;
		*r = "dx";
		*rm = "bx";
		return;
	case 0xd4:
		*arg1 = 1;
		*r = "dx";
		*rm = "sp";
		return;
	case 0xd5:
		*arg1 = 1;
		*r = "dx";
		*rm = "bp";
		return;
	case 0xd6:
		*arg1 = 1;
		*r = "dx";
		*rm = "si";
		return;
	case 0xd7:
		*arg1 = 1;
		*r = "dx";
		*rm = "di";
		return;
		/****************************************************************************/
	case 0xd8:
		*arg1 = 1;
		*r = "bx";
		*rm = "ax";
		return;
	case 0xd9:
		*arg1 = 1;
		*r = "bx";
		*rm = "cx";
		return;
	case 0xda:
		*arg1 = 1;
		*r = "bx";
		*rm = "dx";
		return;
	case 0xdb:
		*arg1 = 1;
		*r = "bx";
		*rm = "bx";
		return;
	case 0xdc:
		*arg1 = 1;
		*r = "bx";
		*rm = "sp";
		return;
	case 0xdd:
		*arg1 = 1;
		*r = "bx";
		*rm = "bp";
		return;
	case 0xde:
		*arg1 = 1;
		*r = "bx";
		*rm = "si";
		return;
	case 0xdf:
		*arg1 = 1;
		*r = "bx";
		*rm = "di";
		return;
		/****************************************************************************/
	case 0xe0:
		*arg1 = 1;
		*r = "sp";
		*rm = "ax";
		return;
	case 0xe1:
		*arg1 = 1;
		*r = "sp";
		*rm = "cx";
		return;
	case 0xe2:
		*arg1 = 1;
		*r = "sp";
		*rm = "dx";
		return;
	case 0xe3:
		*arg1 = 1;
		*r = "sp";
		*rm = "bx";
		return;
	case 0xe4:
		*arg1 = 1;
		*r = "sp";
		*rm = "sp";
		return;
	case 0xe5:
		*arg1 = 1;
		*r = "sp";
		*rm = "bp";
		return;
	case 0xe6:
		*arg1 = 1;
		*r = "sp";
		*rm = "si";
		return;
	case 0xe7:
		*arg1 = 1;
		*r = "sp";
		*rm = "di";
		return;
		/****************************************************************************/
	case 0xe8:
		*arg1 = 1;
		*r = "bp";
		*rm = "ax";
		return;
	case 0xe9:
		*arg1 = 1;
		*r = "bp";
		*rm = "cx";
		return;
	case 0xea:
		*arg1 = 1;
		*r = "bp";
		*rm = "dx";
		return;
	case 0xeb:
		*arg1 = 1;
		*r = "bp";
		*rm = "bx";
		return;
	case 0xec:
		*arg1 = 1;
		*r = "bp";
		*rm = "sp";
		return;
	case 0xed:
		*arg1 = 1;
		*r = "bp";
		*rm = "bp";
		return;
	case 0xee:
		*arg1 = 1;
		*r = "bp";
		*rm = "si";
		return;
	case 0xef:
		*arg1 = 1;
		*r = "bp";
		*rm = "di";
		return;
		/****************************************************************************/
	case 0xf0:
		*arg1 = 1;
		*r = "si";
		*rm = "ax";
		return;
	case 0xf1:
		*arg1 = 1;
		*r = "si";
		*rm = "cx";
		return;
	case 0xf2:
		*arg1 = 1;
		*r = "si";
		*rm = "dx";
		return;
	case 0xf3:
		*arg1 = 1;
		*r = "si";
		*rm = "bx";
		return;
	case 0xf4:
		*arg1 = 1;
		*r = "si";
		*rm = "sp";
		return;
	case 0xf5:
		*arg1 = 1;
		*r = "si";
		*rm = "bp";
		return;
	case 0xf6:
		*arg1 = 1;
		*r = "si";
		*rm = "si";
		return;
	case 0xf7:
		*arg1 = 1;
		*r = "si";
		*rm = "di";
		return;
		/****************************************************************************/
	case 0xf8:
		*arg1 = 1;
		*r = "di";
		*rm = "ax";
		return;
	case 0xf9:
		*arg1 = 1;
		*r = "di";
		*rm = "cx";
		return;
	case 0xfa:
		*arg1 = 1;
		*r = "di";
		*rm = "dx";
		return;
	case 0xfb:
		*arg1 = 1;
		*r = "di";
		*rm = "bx";
		return;
	case 0xfc:
		*arg1 = 1;
		*r = "di";
		*rm = "sp";
		return;
	case 0xfd:
		*arg1 = 1;
		*r = "di";
		*rm = "bp";
		return;
	case 0xfe:
		*arg1 = 1;
		*r = "di";
		*rm = "si";
		return;
	case 0xff:
		*arg1 = 1;
		*r = "di";
		*rm = "di";
		return;
		/****************************************************************************/

	default:
		*r = "unknown";
		*rm = "unknown";
		*arg1 = 0;
		return;
	}

}




