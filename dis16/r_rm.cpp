#include<stdio.h>

void r_rm(unsigned char* arg0, int* arg1, char** r, char** rm, char** r8, char** r32, char** sreg, char** rm8, char** rm32) {

	static char buffer[0x40];

	switch (arg0[0])
	{
	case 0x00:
		*arg1 = 1;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		*rm = "[bx+si]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x01:
		*arg1 = 1;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		*rm = "[bx+di]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x02:
		*arg1 = 1;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		*rm = "[bp+si]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x03:
		*arg1 = 1;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		*rm = "[bp+di]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x04:
		*arg1 = 1;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		*rm = "[si]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x05:
		*arg1 = 1;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		*rm = "[di]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x06:
		*arg1 = 3;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		snprintf(buffer, sizeof(buffer), "0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x07:
		*arg1 = 1;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		*rm = "[bx]";
		*rm8 = *rm32 = *rm;
		return;
		/****************************************************************************/
	case 0x08:
		*arg1 = 1;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		*rm = "[bx+si]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x09:
		*arg1 = 1;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		*rm = "[bx+di]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x0a:
		*arg1 = 1;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		*rm = "[bp+si]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x0b:
		*arg1 = 1;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		*rm = "[bp+di]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x0c:
		*arg1 = 1;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		*rm = "[si]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x0d:
		*arg1 = 1;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		*rm = "[di]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x0e:
		*arg1 = 3;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		snprintf(buffer, sizeof(buffer), "0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x0f:
		*arg1 = 1;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		*rm = "[bx]";
		*rm8 = *rm32 = *rm;
		return;
		/****************************************************************************/
	case 0x10:
		*arg1 = 1;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		*rm = "[bx+si]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x11:
		*arg1 = 1;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		*rm = "[bx+di]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x12:
		*arg1 = 1;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		*rm = "[bp+si]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x13:
		*arg1 = 1;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		*rm = "[bp+di]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x14:
		*arg1 = 1;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		*rm = "[si]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x15:
		*arg1 = 1;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		*rm = "[di]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x16:
		*arg1 = 3;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		snprintf(buffer, sizeof(buffer), "0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x17:
		*arg1 = 1;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		*rm = "[bx]";
		*rm8 = *rm32 = *rm;
		return;
		/****************************************************************************/
	case 0x18:
		*arg1 = 1;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		*rm = "[bx+si]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x19:
		*arg1 = 1;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		*rm = "[bx+di]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x1a:
		*arg1 = 1;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		*rm = "[bp+si]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x1b:
		*arg1 = 1;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		*rm = "[bp+di]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x1c:
		*arg1 = 1;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		*rm = "[si]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x1d:
		*arg1 = 1;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		*rm = "[di]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x1e:
		*arg1 = 3;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		snprintf(buffer, sizeof(buffer), "0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x1f:
		*arg1 = 1;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		*rm = "[bx]";
		*rm8 = *rm32 = *rm;
		return;
		/****************************************************************************/
	case 0x20:
		*arg1 = 1;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		*rm = "[bx+si]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x21:
		*arg1 = 1;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		*rm = "[bx+di]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x22:
		*arg1 = 1;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		*rm = "[bp+si]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x23:
		*arg1 = 1;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		*rm = "[bp+di]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x24:
		*arg1 = 1;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		*rm = "[si]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x25:
		*arg1 = 1;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		*rm = "[di]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x26:
		*arg1 = 3;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		snprintf(buffer, sizeof(buffer), "0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x27:
		*arg1 = 1;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		*rm = "[bx]";
		*rm8 = *rm32 = *rm;
		return;
		/****************************************************************************/
	case 0x28:
		*arg1 = 1;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		*rm = "[bx+si]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x29:
		*arg1 = 1;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		*rm = "[bx+di]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x2a:
		*arg1 = 1;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		*rm = "[bp+si]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x2b:
		*arg1 = 1;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		*rm = "[bp+di]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x2c:
		*arg1 = 1;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		*rm = "[si]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x2d:
		*arg1 = 1;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		*rm = "[di]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x2e:
		*arg1 = 3;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		snprintf(buffer, sizeof(buffer), "0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x2f:
		*arg1 = 1;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		*rm = "[bx]";
		*rm8 = *rm32 = *rm;
		return;
		/****************************************************************************/
	case 0x30:
		*arg1 = 1;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		*rm = "[bx+si]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x31:
		*arg1 = 1;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		*rm = "[bx+di]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x32:
		*arg1 = 1;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		*rm = "[bp+si]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x33:
		*arg1 = 1;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		*rm = "[bp+di]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x34:
		*arg1 = 1;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		*rm = "[si]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x35:
		*arg1 = 1;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		*rm = "[di]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x36:
		*arg1 = 3;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x37:
		*arg1 = 1;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		*rm = "[bx]";
		*rm8 = *rm32 = *rm;
		return;
		/****************************************************************************/
	case 0x38:
		*arg1 = 1;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		*rm = "[bx+si]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x39:
		*arg1 = 1;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		*rm = "[bx+di]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x3a:
		*arg1 = 1;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		*rm = "[bp+si]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x3b:
		*arg1 = 1;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		*rm = "[bp+di]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x3c:
		*arg1 = 1;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		*rm = "[si]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x3d:
		*arg1 = 1;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		*rm = "[di]";
		*rm8 = *rm32 = *rm;
		return;
	case 0x3e:
		*arg1 = 3;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x3f:
		*arg1 = 1;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		*rm = "[bx]";
		*rm8 = *rm32 = *rm;
		return;
		/****************************************************************************/
	case 0x40:
		*arg1 = 2;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x41:
		*arg1 = 2;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x42:
		*arg1 = 2;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x43:
		*arg1 = 2;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x44:
		*arg1 = 2;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x45:
		*arg1 = 2;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x46:
		*arg1 = 2;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x47:
		*arg1 = 2;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
		/****************************************************************************/
	case 0x48:
		*arg1 = 2;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x49:
		*arg1 = 2;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x4a:
		*arg1 = 2;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x4b:
		*arg1 = 2;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x4c:
		*arg1 = 2;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x4d:
		*arg1 = 2;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x4e:
		*arg1 = 2;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x4f:
		*arg1 = 2;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
		/****************************************************************************/
	case 0x50:
		*arg1 = 2;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x51:
		*arg1 = 2;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x52:
		*arg1 = 2;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x53:
		*arg1 = 2;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x54:
		*arg1 = 2;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x55:
		*arg1 = 2;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x56:
		*arg1 = 2;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x57:
		*arg1 = 2;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
		/****************************************************************************/
	case 0x58:
		*arg1 = 2;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x59:
		*arg1 = 2;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x5a:
		*arg1 = 2;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x5b:
		*arg1 = 2;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x5c:
		*arg1 = 2;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x5d:
		*arg1 = 2;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x5e:
		*arg1 = 2;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x5f:
		*arg1 = 2;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
		/****************************************************************************/
	case 0x60:
		*arg1 = 2;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x61:
		*arg1 = 2;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x62:
		*arg1 = 2;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x63:
		*arg1 = 2;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x64:
		*arg1 = 2;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x65:
		*arg1 = 2;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x66:
		*arg1 = 2;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x67:
		*arg1 = 2;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
		/****************************************************************************/
	case 0x68:
		*arg1 = 2;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x69:
		*arg1 = 2;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x6a:
		*arg1 = 2;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x6b:
		*arg1 = 2;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x6c:
		*arg1 = 2;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x6d:
		*arg1 = 2;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x6e:
		*arg1 = 2;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x6f:
		*arg1 = 2;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
		/****************************************************************************/
	case 0x70:
		*arg1 = 2;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x71:
		*arg1 = 2;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x72:
		*arg1 = 2;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x73:
		*arg1 = 2;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x74:
		*arg1 = 2;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x75:
		*arg1 = 2;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x76:
		*arg1 = 2;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x77:
		*arg1 = 2;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
		/****************************************************************************/
	case 0x78:
		*arg1 = 2;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x79:
		*arg1 = 2;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x7a:
		*arg1 = 2;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x7b:
		*arg1 = 2;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x7c:
		*arg1 = 2;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x7d:
		*arg1 = 2;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x7e:
		*arg1 = 2;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x7f:
		*arg1 = 2;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x", arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
		/****************************************************************************/
	case 0x80:
		*arg1 = 3;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x81:
		*arg1 = 3;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x82:
		*arg1 = 3;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x83:
		*arg1 = 3;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x84:
		*arg1 = 3;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x85:
		*arg1 = 3;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x86:
		*arg1 = 3;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x87:
		*arg1 = 3;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
		/****************************************************************************/
	case 0x88:
		*arg1 = 3;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x89:
		*arg1 = 3;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x8a:
		*arg1 = 3;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x8b:
		*arg1 = 3;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x8c:
		*arg1 = 3;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x8d:
		*arg1 = 3;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x8e:
		*arg1 = 3;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x8f:
		*arg1 = 3;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
		/****************************************************************************/
	case 0x90:
		*arg1 = 3;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x91:
		*arg1 = 3;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x92:
		*arg1 = 3;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x93:
		*arg1 = 3;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x94:
		*arg1 = 3;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x95:
		*arg1 = 3;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x96:
		*arg1 = 3;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x97:
		*arg1 = 3;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
		/****************************************************************************/
	case 0x98:
		*arg1 = 3;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x99:
		*arg1 = 3;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x9a:
		*arg1 = 3;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x9b:
		*arg1 = 3;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x9c:
		*arg1 = 3;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x9d:
		*arg1 = 3;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x9e:
		*arg1 = 3;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0x9f:
		*arg1 = 3;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
		/****************************************************************************/
	case 0xa0:
		*arg1 = 3;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xa1:
		*arg1 = 3;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xa2:
		*arg1 = 3;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xa3:
		*arg1 = 3;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xa4:
		*arg1 = 3;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xa5:
		*arg1 = 3;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xa6:
		*arg1 = 3;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xa7:
		*arg1 = 3;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
		/****************************************************************************/
	case 0xa8:
		*arg1 = 3;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xa9:
		*arg1 = 3;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xaa:
		*arg1 = 3;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xab:
		*arg1 = 3;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xac:
		*arg1 = 3;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xad:
		*arg1 = 3;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xae:
		*arg1 = 3;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xaf:
		*arg1 = 3;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
		/****************************************************************************/
	case 0xb0:
		*arg1 = 3;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xb1:
		*arg1 = 3;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xb2:
		*arg1 = 3;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xb3:
		*arg1 = 3;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xb4:
		*arg1 = 3;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xb5:
		*arg1 = 3;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xb6:
		*arg1 = 3;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xb7:
		*arg1 = 3;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
		/****************************************************************************/
	case 0xb8:
		*arg1 = 3;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[bx+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xb9:
		*arg1 = 3;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[bx+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xba:
		*arg1 = 3;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[bp+si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xbb:
		*arg1 = 3;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[bp+di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xbc:
		*arg1 = 3;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[si]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xbd:
		*arg1 = 3;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[di]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xbe:
		*arg1 = 3;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[bp]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
	case 0xbf:
		*arg1 = 3;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		snprintf(buffer, sizeof(buffer), "[bx]+0x%02x%02x", arg0[2], arg0[1]);
		*rm = buffer;
		*rm8 = *rm32 = *rm;
		return;
		/****************************************************************************/
	case 0xc0:
		*arg1 = 1;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		*rm = "ax";
		*rm8 = "al";
		*rm32 = "eax";
		return;
	case 0xc1:
		*arg1 = 1;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		*rm = "cx";
		*rm8 = "cl";
		*rm32 = "ecx";
		return;
	case 0xc2:
		*arg1 = 1;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		*rm = "dx";
		*rm8 = "dl";
		*rm32 = "edx";
		return;
	case 0xc3:
		*arg1 = 1;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		*rm = "bx";
		*rm8 = "bl";
		*rm32 = "ebx";
		return;
	case 0xc4:
		*arg1 = 1;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		*rm = "sp";
		*rm8 = "ah";
		*rm32 = "esp";
		return;
	case 0xc5:
		*arg1 = 1;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		*rm = "bp";
		*rm8 = "ch";
		*rm32 = "ebp";
		return;
	case 0xc6:
		*arg1 = 1;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		*rm = "si";
		*rm8 = "dh";
		*rm32 = "esi";
		return;
	case 0xc7:
		*arg1 = 1;
		*r = "ax";
		*r8 = "al";
		*r32 = "eax";
		*sreg = "es";
		*rm = "di";
		*rm8 = "bh";
		*rm32 = "edi";
		return;
		/****************************************************************************/
	case 0xc8:
		*arg1 = 1;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		*rm = "ax";
		*rm8 = "al";
		*rm32 = "eax";
		return;
	case 0xc9:
		*arg1 = 1;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		*rm = "cx";
		*rm8 = "cl";
		*rm32 = "ecx";
		return;
	case 0xca:
		*arg1 = 1;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		*rm = "dx";
		*rm8 = "dl";
		*rm32 = "edx";
		return;
	case 0xcb:
		*arg1 = 1;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		*rm = "bx";
		*rm8 = "bl";
		*rm32 = "ebx";
		return;
	case 0xcc:
		*arg1 = 1;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		*rm = "sp";
		*rm8 = "ah";
		*rm32 = "esp";
		return;
	case 0xcd:
		*arg1 = 1;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		*rm = "bp";
		*rm8 = "ch";
		*rm32 = "ebp";
		return;
	case 0xce:
		*arg1 = 1;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		*rm = "si";
		*rm8 = "dh";
		*rm32 = "esi";
		return;
	case 0xcf:
		*arg1 = 1;
		*r = "cx";
		*r8 = "cl";
		*r32 = "ecx";
		*sreg = "cs";
		*rm = "di";
		*rm8 = "bh";
		*rm32 = "edi";
		return;
		/****************************************************************************/
	case 0xd0:
		*arg1 = 1;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		*rm = "ax";
		*rm8 = "al";
		*rm32 = "eax";
		return;
	case 0xd1:
		*arg1 = 1;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		*rm = "cx";
		*rm8 = "cl";
		*rm32 = "ecx";
		return;
	case 0xd2:
		*arg1 = 1;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		*rm = "dx";
		*rm8 = "dl";
		*rm32 = "edx";
		return;
	case 0xd3:
		*arg1 = 1;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		*rm = "bx";
		*rm8 = "bl";
		*rm32 = "ebx";
		return;
	case 0xd4:
		*arg1 = 1;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		*rm = "sp";
		*rm8 = "ah";
		*rm32 = "esp";
		return;
	case 0xd5:
		*arg1 = 1;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		*rm = "bp";
		*rm8 = "ch";
		*rm32 = "ebp";
		return;
	case 0xd6:
		*arg1 = 1;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		*rm = "si";
		*rm8 = "dh";
		*rm32 = "esi";
		return;
	case 0xd7:
		*arg1 = 1;
		*r = "dx";
		*r8 = "dl";
		*r32 = "edx";
		*sreg = "ss";
		*rm = "di";
		*rm8 = "bh";
		*rm32 = "edi";
		return;
		/****************************************************************************/
	case 0xd8:
		*arg1 = 1;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		*rm = "ax";
		*rm8 = "al";
		*rm32 = "eax";
		return;
	case 0xd9:
		*arg1 = 1;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		*rm = "cx";
		*rm8 = "cl";
		*rm32 = "ecx";
		return;
	case 0xda:
		*arg1 = 1;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		*rm = "dx";
		*rm8 = "dl";
		*rm32 = "edx";
		return;
	case 0xdb:
		*arg1 = 1;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		*rm = "bx";
		*rm8 = "bl";
		*rm32 = "ebx";
		return;
	case 0xdc:
		*arg1 = 1;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		*rm = "sp";
		*rm8 = "ah";
		*rm32 = "esp";
		return;
	case 0xdd:
		*arg1 = 1;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		*rm = "bp";
		*rm8 = "ch";
		*rm32 = "ebp";
		return;
	case 0xde:
		*arg1 = 1;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		*rm = "si";
		*rm8 = "dh";
		*rm32 = "esi";
		return;
	case 0xdf:
		*arg1 = 1;
		*r = "bx";
		*r8 = "bl";
		*r32 = "ebx";
		*sreg = "ds";
		*rm = "di";
		*rm8 = "bh";
		*rm32 = "edi";
		return;
		/****************************************************************************/
	case 0xe0:
		*arg1 = 1;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		*rm = "ax";
		*rm8 = "al";
		*rm32 = "eax";
		return;
	case 0xe1:
		*arg1 = 1;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		*rm = "cx";
		*rm8 = "cl";
		*rm32 = "ecx";
		return;
	case 0xe2:
		*arg1 = 1;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		*rm = "dx";
		*rm8 = "dl";
		*rm32 = "edx";
		return;
	case 0xe3:
		*arg1 = 1;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		*rm = "bx";
		*rm8 = "bl";
		*rm32 = "ebx";
		return;
	case 0xe4:
		*arg1 = 1;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		*rm = "sp";
		*rm8 = "ah";
		*rm32 = "esp";
		return;
	case 0xe5:
		*arg1 = 1;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		*rm = "bp";
		*rm8 = "ch";
		*rm32 = "ebp";
		return;
	case 0xe6:
		*arg1 = 1;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		*rm = "si";
		*rm8 = "dh";
		*rm32 = "esi";
		return;
	case 0xe7:
		*arg1 = 1;
		*r = "sp";
		*r8 = "ah";
		*r32 = "esp";
		*sreg = "fs";
		*rm = "di";
		*rm8 = "bh";
		*rm32 = "edi";
		return;
		/****************************************************************************/
	case 0xe8:
		*arg1 = 1;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		*rm = "ax";
		*rm8 = "al";
		*rm32 = "eax";
		return;
	case 0xe9:
		*arg1 = 1;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		*rm = "cx";
		*rm8 = "cl";
		*rm32 = "ecx";
		return;
	case 0xea:
		*arg1 = 1;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		*rm = "dx";
		*rm8 = "dl";
		*rm32 = "edx";
		return;
	case 0xeb:
		*arg1 = 1;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		*rm = "bx";
		*rm8 = "bl";
		*rm32 = "ebx";
		return;
	case 0xec:
		*arg1 = 1;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		*rm = "sp";
		*rm8 = "ah";
		*rm32 = "esp";
		return;
	case 0xed:
		*arg1 = 1;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		*rm = "bp";
		*rm8 = "ch";
		*rm32 = "ebp";
		return;
	case 0xee:
		*arg1 = 1;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		*rm = "si";
		*rm8 = "dh";
		*rm32 = "esi";
		return;
	case 0xef:
		*arg1 = 1;
		*r = "bp";
		*r8 = "ch";
		*r32 = "ebp";
		*sreg = "gs";
		*rm = "di";
		*rm8 = "bh";
		*rm32 = "edi";
		return;
		/****************************************************************************/
	case 0xf0:
		*arg1 = 1;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		*rm = "ax";
		*rm8 = "al";
		*rm32 = "eax";
		return;
	case 0xf1:
		*arg1 = 1;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		*rm = "cx";
		*rm8 = "cl";
		*rm32 = "ecx";
		return;
	case 0xf2:
		*arg1 = 1;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		*rm = "dx";
		*rm8 = "dl";
		*rm32 = "edx";
		return;
	case 0xf3:
		*arg1 = 1;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		*rm = "bx";
		*rm8 = "bl";
		*rm32 = "ebx";
		return;
	case 0xf4:
		*arg1 = 1;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		*rm = "sp";
		*rm8 = "ah";
		*rm32 = "esp";
		return;
	case 0xf5:
		*arg1 = 1;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		*rm = "bp";
		*rm8 = "ch";
		*rm32 = "ebp";
		return;
	case 0xf6:
		*arg1 = 1;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		*rm = "si";
		*rm8 = "dh";
		*rm32 = "esi";
		return;
	case 0xf7:
		*arg1 = 1;
		*r = "si";
		*r8 = "dh";
		*r32 = "esi";
		*sreg = "res.";
		*rm = "di";
		*rm8 = "bh";
		*rm32 = "edi";
		return;
		/****************************************************************************/
	case 0xf8:
		*arg1 = 1;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		*rm = "ax";
		*rm8 = "al";
		*rm32 = "eax";
		return;
	case 0xf9:
		*arg1 = 1;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		*rm = "cx";
		*rm8 = "cl";
		*rm32 = "ecx";
		return;
	case 0xfa:
		*arg1 = 1;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		*rm = "dx";
		*rm8 = "dl";
		*rm32 = "edx";
		return;
	case 0xfb:
		*arg1 = 1;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		*rm = "bx";
		*rm8 = "bl";
		*rm32 = "ebx";
		return;
	case 0xfc:
		*arg1 = 1;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		*rm = "sp";
		*rm8 = "ah";
		*rm32 = "esp";
		return;
	case 0xfd:
		*arg1 = 1;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		*rm = "bp";
		*rm8 = "ch";
		*rm32 = "ebp";
		return;
	case 0xfe:
		*arg1 = 1;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		*rm = "si";
		*rm8 = "dh";
		*rm32 = "esi";
		return;
	case 0xff:
		*arg1 = 1;
		*r = "di";
		*r8 = "bh";
		*r32 = "edi";
		*sreg = "res.";
		*rm = "di";
		*rm8 = "bh";
		*rm32 = "edi";
		return;
		/****************************************************************************/

	default:
		*r = "unknown";
		*rm = "unknown";
		*arg1 = 0;
		return;
	}

}




