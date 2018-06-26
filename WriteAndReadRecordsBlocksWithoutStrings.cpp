/* Escribe y lee archivo de registros, y muestra los cursos de 
 * primer año con cantidad de alumnos mayor a 25.
 * 20151108
 * Esp. Ing. José María Sola
 * Profesor
 * UTN FRBA
 */

#include <iostream>
#include <fstream>
#include "BlockStream.h"

int main(){
	struct Curso{
		char especialidad;
		int codigo;
		int nivel;
		int alumnos;
		double promedio;
	};
	
	constexpr auto filename{"cursos"};

	std::ofstream out{filename, std::ios::binary};

	WriteBlock(out, Curso{'K', 1051, 1, 29, 7.8});
	WriteBlock(out, Curso{'R', 4152, 4, 41, 6.6});
	WriteBlock(out, Curso{'K', 2051, 1, 22, 6.7});
	WriteBlock(out, Curso{'K', 2011, 1, 26, 7.9});

	out.close();
	
	std::ifstream in{filename, std::ios::binary};
	
	for(Curso curso; ReadBlock(in, curso) ;)
		if( curso.nivel == 1 and curso.alumnos > 25 )
			std::cout
				<< "Especialidad: " << curso.especialidad << ", "
				<< "      Código: " << curso.codigo       << ", "
				<< "       Nivel: " << curso.nivel        << ", "
				<< "     Alumnos: " << curso.alumnos      << ", "
				<< "    Promedio: " << curso.promedio     << '\n'
				<< '\n';

	in.close();
}
