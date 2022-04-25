#include "Alu.h"
#include <iostream>

stream Alu::run(stream instruction, stream value1, stream value2){
	int instructionCode = Utils::decoder3bit(instruction[0],instruction[1], instruction[2]);
	stream result;
	switch (instructionCode){
		case 0: {
			result = Alu::streamOr(value1, value2);
			break;
		}
		case 1: {
			result = Alu::streamNand(value1, value2);
			break;
		}
		case 2: {
			result = Alu::streamNor(value1, value2);
			break;
		}
		case 3: {
			result = Alu::streamAnd(value1, value2);
			break;
		}
		case 4: {
			result = Alu::streamAdd(value1, value2);
			break;
		}
		case 5: {
			result = Alu::streamSub(value1, value2);
			break;
		}
	}
	return result;
}

stream Alu::streamOr(stream value1 , stream value2) {
	stream result = (value1 ^ value2);
	
	return result;
};

stream Alu::streamNand(stream value1, stream value2) {
	stream result = ~(value1 & value2);

	return result;
};

stream Alu::streamNor(stream value1, stream value2) {
	stream result = ~(value1 | value2);
	
	return result;
};

stream Alu::streamAnd(stream value1, stream value2) {
	stream result = (value1 & value2);
	
	return result;
};


stream Alu::streamAdd(stream value1, stream value2) {
	stream result = Utils::streamAdd(value1, value2);

	return result;
}



stream Alu::streamSub(stream value1, stream value2) {
	stream result = Utils::streamSub(value1, value2);

	return result;
}