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
	struct { // Dos variables con tipo anónimo: par (int, String de máximo 25 caracteres)
		int id;
		String<25> name;  // Sinónimo de array<char,25>
	} aBlock, anotherBlock;

	constexpr auto filename{"people"}; // Nombre del archivo de prueba
	
	std::ofstream out{filename, std::ios::binary}; // Crear archivo y conectar flujo en modo binario
	aBlock = {10, PackString("Joe")}; // Asignar par, empaquetar el string en un String de máximo 25 caracteres
	WriteBlock(out, aBlock); // Escribir en el flujo out aBlock
	out.close(); // Cerrar conexión
	std::cout << aBlock.id << ' '<< UnpackString(aBlock.name) << '\n'; // Salida de control
	
	std::ifstream in{filename, std::ios::binary};  // Conectar flujo al archivo existente, en modo binario
	ReadBlock(in, anotherBlock); // Leed del flujo in y guardar en anotherBlock
	in.close(); // Cerrar conexión
	remove(filename); // c++17 // std::filesystem::remove(filename); // Remover el archivo de prueba
	std::cout << anotherBlock.id << ' '<< UnpackString(anotherBlock.name) << '\n'; // Salida de control
	
	// Test: Verificar que leemos lo que habíamos escrito
	assert(                aBlock.id == anotherBlock.id                ); 
	assert(UnpackString(aBlock.name) == UnpackString(anotherBlock.name));
}
