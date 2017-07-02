/* BlockStream.h
 * Este header facilita la lectura y escritura de bloques desde flujos mediante
 * dos funciones: WriteBlock y ReadBlock.
 * En este contexto bloque es un tipo de valor que no cotienen referencia a 
 * otros valores.
 * 20151108
 * Esp. Ing. José María Sola
 * Profesor
 * UTN FRBA
 *
 * Ejemplo de uso:
 *  #include <fstream>
 *  #include "BlockStream.h"
 *
 *  using namespace std;
 *
 *  T block = {...}; // e.g., struct T {double x,y;};
 *  T must be a "self-contained" type:
 *  static_assert(std::is_pod<T>::value, "T must be POD");
 *
 *  ofstream out("filename", ios::binary);
 *  WriteBlock(out, block);
 *
 *  ifstream in("filename", ios::binary);
 *  ReadBlock(in, block);
 */

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
