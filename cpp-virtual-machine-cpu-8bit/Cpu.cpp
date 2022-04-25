#include "Cpu.h"
#include <istream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>

stream Cpu::run(stream inputValue) {
	this->input = inputValue;
	std::ifstream configFile;
	std::string s = "Program.txt";
	std::string content;
	configFile.open(s);
	int sizeOfStream = inputValue.size() + 2;
	while (getline(configFile, content)) {
		int counterIntValue = Utils::binaryToInt(this->counter);
		this->counter = Utils::streamAdd(this->counter, 1);

		stream currentCommand = Utils::stringToStream(content);
		Cpu::move(currentCommand);
		configFile.seekg((counterIntValue+1)*sizeOfStream);
	}

	return this->output;
}

void Cpu::move(stream value) {
	stream source, destination;

	int destinationCode = Utils::decoder3bit(value[0], value[1], value[2]);
	int sourceCode = Utils::decoder3bit(value[3], value[4], value[5]);

	switch (sourceCode)
	{
		case 0: {
			source = this->r0;
			break;
		}
		case 1: {
			source = this->r1;
			break;
		}
		case 2: {
			source = this->r2;
			break;
		}
		case 3: {
			source = this->r3;
			break;
		}
		case 4: {
			source = this->r4;
			break;
		}
		case 5: {
			source = this->r5;
			break;
		}
		case 6: {
			source = this->r6;
			break;
		}
		case 7: {
			source = this->input;
			break;
		}
	}

	switch (destinationCode)
	{
		case 0: {
			this->r0 = source;
			break;
		}
		case 1: {
			this->r1 = source;
			break;
		}
		case 2: {
			this->r2 = source;
			break;
		}
		case 3: {
			this->r3 = source;
			break;
		}
		case 4: {
			this->r4 = source;
			break;
		}
		case 5: {
			this->r5 = source;
			break;
		}
		case 6: {
			this->r6 = source;
			break;
		}
		case 7: {
			this->output = source;
			break;
		}
	}
}