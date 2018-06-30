/* BlockStream.h
2015-11-08 - 2018-06-30
Esp. Ing. José María Sola
Profesor
UTN FRBA */

#ifndef HEADER_BLOCKSTREAM_INCLUDED
#define HEADER_BLOCKSTREAM_INCLUDED

#include <fstream>

template<typename T>
std::ostream& WriteBlock(std::ostream& out, const T& block){
	return out.write(
		reinterpret_cast<const char*>(&block),
		sizeof block
	);
}

template<typename T>
std::istream& ReadBlock(std::istream& in, T& block){
	return in.read(
		reinterpret_cast<char*>(&block),
		sizeof block
	);
}

#endif
