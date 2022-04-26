#include "Cond.h"
#include <iostream>

bool Cond::run(stream instruction, stream value) {
	int instructionCode = Utils::decoder3bit(instruction[0], instruction[1], instruction[2]);
	bool result = 0;
	switch (instructionCode) {
	case 0: {
		result =  0;
		break;
	}
	case 1: {
		result = value == 0;
		break;
	}
	case 2: {
		result = value[7] == 1;
		break;
	}
	case 3: {
		result = value[7] == 1 || value == 0;
		break;
	}
	case 4: {
		result = 1;
		break;
	}
	case 5: {
		result = !(value == 0);
		break;
	}
	case 6: {
		result = value[7] == 0;
		break;
	}
	case 7: {
		result = value[7] == 0 && !(value == 0);
		break;
	}
	}
	return result;
}