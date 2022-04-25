#ifndef CPU_H
#define CPU_H

#include "common.h"
#include "Utils.h"
#include <istream>
#include <fstream>
#include "Alu.h"


class Cpu {
	public:
		stream run(stream);

	private:
		stream input, r0, r1, r2, r3, r4, r5, r6, output, counter = 0;
		Alu alu;
		void move(stream);
};

#endif // CPU_H