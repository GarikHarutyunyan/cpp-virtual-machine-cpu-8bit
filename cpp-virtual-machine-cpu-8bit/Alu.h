#ifndef ALU_H
#define ALU_H

#include "common.h"
#include "Utils.h"

class Alu {
public:
	stream run(stream, stream, stream);

private:
	stream streamOr (stream, stream);
	stream streamNand (stream, stream);
	stream streamNor (stream, stream);
	stream streamAnd (stream, stream);
	stream streamAdd(stream, stream);
	stream streamSub(stream, stream);
};
#endif // ALU_H