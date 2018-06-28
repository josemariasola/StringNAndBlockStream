#include "StringN.h"
#include <cassert>
int main(){
	std::string s{"Hello, World!"};
	String<5> a = PackString(s);
	auto t{UnpackString(a)};
	assert("Hello" == t);
}
