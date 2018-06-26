/* BlockStreamDriver.cpp
Test BlockStream: WriteBlock and ReadBlock
2015-11-09 - 2018-06-03
Esp. Ing. José María Sola
Profesor
UTN FRBA */

#include <fstream>
#include <iostream> 
#include <cassert>
#include <cstdio> // Pre C++17 // #include <filesystem> // C++17
#include "BlockStream.h"
#include "StringPacker.h"

int main(){
	struct Block{ // Block: par (int, String de máximo 25 caracteres)
		int id;
		String<25> name; // Sinónimo de array<char,25>
	};

	constexpr auto filename{"people"}; // Nombre del archivo de prueba
	
	// Write
	std::ofstream out{filename, std::ios::binary}; // Crear archivo y conectar flujo en modo binario
	Block x{10, PackString("Joe")}; // Asignar par, empaquetar el string en un String de máximo 25 caracteres
	WriteBlock(out, x); // Escribir en el flujo out aBlock
	out.close(); // Cerrar conexión
	std::cout << x.id << ' '<< UnpackString(x.name) << '\n'; // Salida de control
	
	// Read
	std::ifstream in{filename, std::ios::binary};  // Conectar flujo al archivo existente, en modo binario
	Block y;
	ReadBlock(in, y); // Leed del flujo in y guardar en anotherBlock
	in.close(); // Cerrar conexión
	remove(filename); // c++17 // std::filesystem::remove(filename); // Remover el archivo de prueba
	std::cout << y.id << ' '<< UnpackString(y.name) << '\n'; // Salida de control
	
	// Test: Verificar que leemos lo que habíamos escrito
	assert(                x.id == y.id                ); 
	assert(UnpackString(x.name) == UnpackString(y.name));
}
