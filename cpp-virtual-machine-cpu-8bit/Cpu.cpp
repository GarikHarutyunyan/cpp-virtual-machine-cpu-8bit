#include "Cpu.h"
#include <istream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>

stream Cpu::run(stream inputValue, bool debugMode) {
	this->input = inputValue;
	std::ifstream configFile;
	std::string fileName = "Program.txt";
	std::string content;
	configFile.open(fileName);
	int sizeOfStream = inputValue.size() + 2; // stream length(8) + length of "/n"(2) = 10
	while (getline(configFile, content)) {
		int counterIntValue = Utils::binaryToInt(this->counter);
		this->counter = Utils::streamAdd(this->counter, 1);

		stream currentCommand = Utils::stringToStream(content);

		int instructionCode = Utils::decoder3bit(currentCommand[6], currentCommand[7], 0);
		switch (instructionCode)
		{
		case 0: {
			this->r0 = currentCommand;
			break;
		}
		case 1: {
			this->r3 = alu.run(currentCommand,this->r1,this->r2);
			break;
		}
		case 2: {
			Cpu::move(currentCommand);
			break;
		}
		case 3: {
			if (cond.run(currentCommand, r3)) {
				this->counter = this->r0;
			}
			break;
		}
		}
		

		if (debugMode) 
		{
			Cpu::printRegisters();
		}

		// Set index for configFile reading
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
			this->output = source;
			break;
		}
	}
}

void Cpu::printRegisters() {
	std::cout << "in: " << this->input << std::endl;
	std::cout << "r0: " << this->r0 << std::endl;
	std::cout << "r1: " << this->r1 << std::endl;
	std::cout << "r2: " << this->r2 << std::endl;
	std::cout << "r3: " << this->r3 << std::endl;
	std::cout << "r4: " << this->r4 << std::endl;
	std::cout << "r5: " << this->r5 << std::endl;
	std::cout << "out: " << this->output << std::endl << std::endl;
}