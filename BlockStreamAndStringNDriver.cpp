/* BlockStreamAndStringNDriver.cpp
Escribe y lee archivo de registros con cadenas de tamaño acotado, 
muestra los empleados con legajo mayor a 10.
2015-11-08 - 2018-06-30
Esp. Ing. José María Sola
Profesor
UTN FRBA */

#include <iostream>
#include "BlockStream.h"
#include "StringN.h"

int main(){
	struct Person{
		int id;
		String<25> name; // instead of string name;
	};

	constexpr auto filename{"people"};

	std::ofstream out{filename, std::ios::binary};

	WriteBlock(out, Person{10, PackString("Bruce")});  // Wayne
	WriteBlock(out, Person{11, PackString("Clark")});  // Kent
	WriteBlock(out, Person{12, PackString("Joseph")}); // Dredd

	out.close();
	
	std::ifstream in{filename, std::ios::binary};
	
	for(Person p; ReadBlock(in, p); )
		if( p.id > 10 )
			std::cout
				<< p.id << ", "
				<< UnpackString(p.name)
				<< '\n';

	in.close();
}
