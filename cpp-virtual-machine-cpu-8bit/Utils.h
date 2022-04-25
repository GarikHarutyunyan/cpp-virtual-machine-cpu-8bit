#ifndef UTILS_H
#define UTILS_H

#include "common.h"

namespace Utils {
	int binaryToInt(stream);
	stream stringToStream(std::string);
	int decoder3bit(bool,bool,bool);
	std::pair<bool, bool> bitHalfAdder(bool, bool);
	std::pair<bool, bool> bitFullAdder(bool, bool, bool);
	stream streamAdd(stream, stream);
	stream streamNot(stream);
	stream streamSignedNegator(stream);
	stream streamSub(stream, stream);

};

#endif // UTILS_H