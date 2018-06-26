/* Escribe y lee archivo de registros con cadenas, 
 * muestra los empleados con legajo mayor a 10.
 * 20151108
 * Esp. Ing. José María Sola
 * Profesor
 * UTN FRBA
 */

#include <iostream>
#include <fstream>
#include <string>
#include "BlockStream.h"
#include "StringPacker.h"

int main(){
	struct Block{
		int id;
		String<25> name; // instead of string name;
	};

	constexpr auto filename{"people"};

	std::ofstream out{filename, std::ios::binary};

	WriteBlock(out, Block{10, PackString("Bruce")});
	WriteBlock(out, Block{11, PackString("Clark")});
	WriteBlock(out, Block{12, PackString("Joseph")});

	out.close();
	
	std::ifstream in{filename, std::ios::binary};
	
	for(Block b; ReadBlock(in, b); )
		if( b.id > 10 )
			std::cout
				<< b.id << ", "
				<< UnpackString(b.name)
				<< '\n';

	in.close();
}
