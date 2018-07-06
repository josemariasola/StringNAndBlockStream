/* BlockStreamTest.cpp
2015-11-09 - 2018-07-01
Esp. Ing. José María Sola
Profesor
UTN FRBA */

#include "StringN.h"
#include <cassert>

int main(){
	// Simple test
	std::string s{"Hello, World!"}; // Standard unbounded string s.
	String<5> a = PackString(s);    // Put s into bounded string a.
	auto t{UnpackString(a)};        // Get the string from a.
	assert("Hello" == t);           // Check.
	
	// Test against non-pod (standard layout, trivial) implementation.
	union Color{
		String<3> s; // Try n' do this with a std::string.
		int i;
	};
	Color c{PackString("Red")};
	assert("Red" == c.s);
	c.s = PackString("Blue");
	assert("Blu" == c.s);
}
