#ifndef CPU_H
#define CPU_H

#include "common.h"
#include "Utils.h"
#include <istream>
#include <fstream>
#include "Alu.h"
#include "Cond.h"


class Cpu {
	public:
		stream run(stream, bool);

	private:
		void printRegisters();
		stream input, r0, r1, r2, r3, r4, r5, output, counter = 0;
		Alu alu;
		Cond cond;
		void move(stream);
};

#endif // CPU_H