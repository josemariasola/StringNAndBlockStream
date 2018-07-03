/* BlockStreamAndStringNTest.cpp
2015-11-09 - 2018-06-30
Esp. Ing. José María Sola
Profesor
UTN FRBA */

#include "BlockStream.h"
#include "StringN.h"
#include <iostream> // cout
#include <cassert>

int main(){
	struct Person{       // Person: par (int, String de máximo 25 caracteres)
		int id;
		String<25> name; // Sinónimo de array<char,25>
	};

	constexpr auto filename{"people"}; // Nombre del archivo de prueba
	
	// Write
	std::ofstream out{filename, std::ios::binary};   // Crear archivo y conectar flujo en modo binario
	WriteBlock(out, Person{10, PackString("León")}); // Escribir en el flujo out una Persona.
	out.close();                                     // Cerrar conexión.
	
	// Read
	std::ifstream in{filename, std::ios::binary};  // Conectar flujo al archivo existente, en modo binario
	Person p;         // Declarar una persona para almacenar la lectua
	ReadBlock(in, p); // Leer del flujo in y guardar en p
	in.close();       // Cerrar conexión
	
	remove(filename); // c++17 // std::filesystem::remove(filename); // Remover el archivo de prueba
	
	// Test: Verificar que leemos lo que habíamos escrito
	assert(     10 == p.id   );
	assert( "León" == p.name );
}
