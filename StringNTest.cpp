/* BlockStreamTest.cpp
2015-11-09 - 2018-06-30
Esp. Ing. José María Sola
Profesor
UTN FRBA */

#include "StringN.h"
#include <cassert>

int main(){
	std::string s{"Hello, World!"}; // Standard unbounded string s.
	String<5> a = PackString(s);    // Put s into bounded string a.
	auto t{UnpackString(a)};        // Get the string from a.
	assert("Hello" == t);           // Check.
}
