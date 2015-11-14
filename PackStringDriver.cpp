/* StringPackerDriver.cpp
 * 20151108
 * Prof. Esp. Ing. José María Sola
 */

#include <string>
#include <array>
#include <iostream>
#include <cassert>
#include "PackString.h"

template <std::size_t N>
void PrintArrayWithString(const std::array<char,N>& a);
	
int main(){
	// Sample in header
	std::string s = "Hello, World!";
    std::array<char,5> a = PackString(s);
    std::string t = UnpackString(a);
    assert(t=="Hello");

	using namespace std;

	//Empaqueta y desempaqueta un string mas corto que el arreglo
	string s0="1234"; // string type
	cout
		<< "s0       : " << s0          << '\n'
		<< "sizeof s0: " << sizeof s0   << '\n'
		<< "length s0: " << s0.length() << '\n';
	array<char,7> a0 = PackString(s0);
	cout << "a0       : ";
	PrintArrayWithString(a0);
	cout << '\n';
	auto t0 = UnpackString(a0);
	cout << "t0       : " << t0 << '\n' << '\n';
	assert(s0 == t0);
	
	//Empaqueta y desempaqueta un string más corto que el arreglo
	array<char,7> a1 = PackString("abc"); // string literal
	cout << "a1       : ";
	PrintArrayWithString(a1);
	cout << '\n';
	auto t1 = UnpackString(a1);
	cout << "t1       : " << t1 << '\n' << '\n';
	assert("abc" == t1);
	
	// Empaqueta y desempaqueta un string mas largo que el arreglo,
	string s2="Texto muy largo que sobrepasa límites de uso en registros de datos";
	cout
		<< "s2       : " << s2          << '\n'
		<< "sizeof s2: " << sizeof s2   << '\n'
		<< "length s2: " << s2.length() << '\n';
	array<char,12> a2 = PackString(s2); 
	cout << "a2       : ";
	PrintArrayWithString(a2);
	cout << '\n';
	auto t2 = UnpackString(a2); // desempaque todo lo que se pudo guardar
	cout << "t2       : " << t2 << '\n' << '\n';
	assert(s2.compare(0, 12, t2) == 0);

	// Simple test Packs a string and assigns
	array<char,5> a3 = PackString("Hello, World!");
 	assert(UnpackString(a3)=="Hello");
}
 
template <std::size_t N>
void PrintArrayWithString(const std::array<char,N>& a){
	for(auto c : a){
		if(c=='\0')
			break;
		std::cout << c; 
	}
}

