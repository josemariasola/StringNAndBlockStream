/* StringPacker.h
2015-11-08 - 2018-06-30
Esp. Ing. José María Sola
Professor
UTN FRBA */

#ifndef HEADER_STRINGN_INCLUDED
#define HEADER_STRINGN_INCLUDED

#include <string>
#include <array>

// Type: String<N>
template<size_t N> using String = std::array<char,N>;

/* Builds a string from a String<N> upto its first null characater or end,
e.g.: s=UnpackString(a) */
template<std::size_t N> 
inline std::string UnpackString(const String<N>& a){
	std::string s{""};
	
	for(auto c : a){
		if(c=='\0')
			break;
		s.push_back(c);
	}
	
	return s;
}

/* Provides the constructs to pack strings with a simple and clear syntax:
	a=PackString(s)
Implemantation based upon 
http://stackoverflow.com/questions/8165659/why-cant-c-deduce-template-type-from-assignment
*/
struct PackString{
	std::string theString;
	
	// Build from string
	PackString(const std::string& aString) : theString(aString) {}
	
	// User-defined conversion: from string to String<N>
	template<std::size_t N>
	inline operator String<N>(){
		String<N> aString; // undefined content
		auto len = theString.length();
		
		if( len < N ){
			theString.copy(aString.data(), len);
			aString.at(len) = '\0'; // form aString.at(len+1) to aString.at(N-1) undefined content.
		}else
			theString.copy(aString.data(), N);
			
	    return aString;
	}
};

#endif
