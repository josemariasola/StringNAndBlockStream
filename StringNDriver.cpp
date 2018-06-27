/* StringPackerDriver.cpp
2015-11-08 - 2018-06-03
Esp. Ing. José María Sola
Profesor
UTN FRBA */

#include <string>
#include <array>
#include <iostream>
#include <cassert>
#include "StringN.h"

template <std::size_t N>
void PrintSizesAndContents(std::string, String<N>, std::string);

int main(){
	{ // Tests
		{ // array más corto que string
			std::array<char,5> a = PackString("Hello, World!");
			assert( UnpackString(a) == "Hello" );
		}
		{ // String<N> más corto que string
			String<4> s = PackString("Hello, World!");
			assert( UnpackString(s) == "Hell" );
		}
		{ // String<N> igual de largo que string
			String<13> s = PackString("Hello, World!");
			assert( UnpackString(s) == "Hello, World!" );
		}
		{ // String<N> más largo que string
			String<42> s = PackString("Hello, World!");
			assert( UnpackString(s) == "Hello, World!" );
		}
	}
		
	{ // Ejemplos
		using std::array;
		using std::string;

		{ // String<N>
			string    s{"Hello, World!"};
			String<5> a = PackString(s);
			string    t{UnpackString(a)};
			assert( t == "Hello" );
		}
		
		{ // array<char,N>
			string        s{"Hello, World!"};
			array<char,5> a = PackString(s);
			string        t{UnpackString(a)};
			assert( t == "Hello");
		}

		{ // String<N> más corto que string
			string s{"Texto de largo mayor a límite de registro."};
			String<12> a = PackString(s); // array<char,12>
			auto t{UnpackString(a)}; // desempaque todo lo que se pudo guardar
			assert(s.compare(0, 12, t) == 0);
			PrintSizesAndContents(s,a,t);
		}

		{ // String<N> igual de largo que string
			string s{"abcd"}; // string type
			String<4> a = PackString(s); // array<char,4> 
			auto t{UnpackString(a)};
			assert(s == t);
			PrintSizesAndContents(s,a,t);
		}
		
		{ // String<N> más largo que string
			string s{"xyz"};
			array<char,7> a = PackString(s);
			auto t{UnpackString(a)};
			assert(s == t);
			PrintSizesAndContents(s,a,t);
		}
	}
}

template <std::size_t N>
void PrintString(const String<N>&);
	
template <std::size_t N>
void PrintSizesAndContents(std::string s, String<N> a, std::string t){
	std::cout
		<< "s       : " << s          << "\n"
		<< "sizeof s: " << sizeof s   << "\n"
		<< "length s: " << s.length() << "\n"
		<< "a       : "; PrintString(a); std::cout << "\n"
		<< "sizeof a: " << sizeof a   << "\n"
		<< "t       : " << t          << "\n"
		<< "sizeof t: " << sizeof t   << "\n"
		<< "length t: " << t.length() << "\n\n";
}

template <std::size_t N>
void PrintString(const String<N>& s){
	for(auto c : s){
		if(c=='\0')
			break;
		std::cout << c; 
	}
}
