#include<stdio.h>
#include<string.h>

int _66 = 0;
int _67 = 0;


char* getprefix(unsigned char* arg0, int* arg1) {

	static char buffer[0x30];
	memset(buffer, 0, sizeof(buffer));

	int index = 0;
	int i = 0;

	for (i = 0; i < 5; i++) {

		switch (arg0[i])
		{
		case 0x26:
			index += 1;
			snprintf(buffer, sizeof(buffer), "%s ES", buffer);
			break;
		case 0x2e:
			index += 1;
			snprintf(buffer, sizeof(buffer), "%s CS", buffer);
			break;
		case 0x36:
			index += 1;
			snprintf(buffer, sizeof(buffer), "%s SS", buffer);
			break;
		case 0x3e:
			index += 1;
			snprintf(buffer, sizeof(buffer), "%s DS", buffer);
			break;
		case 0x64:
			index += 1;
			snprintf(buffer, sizeof(buffer), "%s FS", buffer);
			break;
		case 0x65:
			index += 1;
			snprintf(buffer, sizeof(buffer), "%s GS", buffer);
			break;
		case 0x9b:
			index += 1;
			snprintf(buffer, sizeof(buffer), "%s wait", buffer);
			break;
		case 0xf0:
			index += 1;
			snprintf(buffer, sizeof(buffer), "%s LOCK", buffer);
			break;
		case 0xf2:
			index += 1;
			snprintf(buffer, sizeof(buffer), "%s repnz repne", buffer);
			break;
		case 0xf3:
			index += 1;
			snprintf(buffer, sizeof(buffer), "%s repz repe", buffer);
			break;
		case 0x66:
			index += 1;
			_66 = 1;
			snprintf(buffer,sizeof(buffer),"%s _66",buffer);
			break;
		case 0x67:
			index += 1;
			_67 = 1;
			snprintf(buffer, sizeof(buffer), "%s _67", buffer);
			break;
		default:
			goto r;
		}

	}

r:
	*arg1 = index;
	if (index) {
		return buffer;
	}
	else {
		return "";
	}

}









