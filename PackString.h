/* PackString.h
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
 * Prof. Esp. Ing. José María Sola
 */

#include <string>
#include <array>

/* Provides the constructs to pack strings with a simple and clearn syntax:
 * a=PackString(s)
 */
struct PackString{
	std::string theString;
	
	// Build from string
	PackString(const std::string& aString) : theString(aString) {}
	
	// User-defined conversion: from string to array<char,N>
	template<std::size_t N>
	inline operator std::array<char, N>(){
		std::array<char, N> anArray;
		auto len = theString.length();
		
		if( len < N ){
			theString.copy(anArray.data(), len);
			anArray.at(len) = '\0';
		}else
			theString.copy(anArray.data(), N);
			
	    return anArray;
	}
};

/* Construct a string from an array up to the first null characater 
 * or the end of the array
 */
template<std::size_t N> 
inline std::string UnpackString(const std::array<char,N>& a){
	std::string s;
	
	for(auto c : a){
		if(c=='\0')
			break;
		s.push_back(c);
	}
	
	return s;
}

