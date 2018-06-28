/* StringPacker.h
 * Este header facilita el manejo de strings de un tamaño variable
 * pero acotado, se base en arrays<char,N> y define 
 * PackString(s) y s = UnpackString(a)
 * 
 * Si s.length()>=N, entonces solo guarda los primeros N caracteres de s en a,
 * sino, guarda todos los caracteres de s en a y agrega un '\0' al final. Esto
 * implica que dado:
 *   a=PackString(s), t=UnpackString(a)
 *   entonces s!=t si |a|<|s|
 * Pero si se vuelve a aplicar:
 * 	 a=PackString(t), u=UnpackString(a)
 *   entonces se cumple t==a.
 * Características de la solución:
 * - Los arreglos tienen un tamaño fijo.
 * - El tamaño del array denota la capacidad máxima real de caracteres 
 *   del array, no la cantidad de caracteres menos uno.
 * - No requiere conocer conocer el concepto punteros para usar la solución.
 * - No requiere conocer conocer el concepto del centinela '\0' para usar
 *   la solución.
 * - El centinela se usa internamente para strings más cortos que el array 
 *   que lo contiene.
 * 
 * Ejemplo de uso:
 *  #include <string>
 *  #include <array>
 *  #include <cassert>
 *  #include "PackString.h"
 *
 *  std::string s = "Hello, World!";
 *  std::array<char,5> a = PackString(s);
 *  std::string t = UnpackString(a);
 *  assert(t=="Hello");
 *
2015-11-08 - 2018-06-03
Esp. Ing. José María Sola
Professor
UTN FRBA */

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
		String<N> aString;
		auto len = theString.length();
		
		if( len < N ){
			theString.copy(aString.data(), len);
			aString.at(len) = '\0';
		}else
			theString.copy(aString.data(), N);
			
	    return aString;
	}
};
