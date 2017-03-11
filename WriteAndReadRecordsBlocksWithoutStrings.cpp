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
	using namespace std;
	
	struct {
		char especialidad;
		int codigo;
		int nivel;
		int alumnos;
		double promedio;
	} curso;
	
	constexpr auto filename = "cursos";

	ofstream out(filename, ios::binary);

	curso = {'K', 1051, 1, 29, 7.8};
	WriteBlock(out, curso);
	
	curso = {'R', 4152, 4, 41, 6.66};
	WriteBlock(out, curso);

	curso = {'K', 2051, 1, 22, 6.7};
	WriteBlock(out, curso);

	curso = {'K', 2011, 1, 26, 7.9};
	WriteBlock(out, curso);

	out.close();
	
	ifstream in(filename, ios::binary);
	
	while( ReadBlock(in, curso) )
		if( curso.nivel == 1 and curso.alumnos > 25 )
			cout
				<< "Especialidad: " << curso.especialidad << ", "
				<< "      Código: " << curso.codigo       << ", "
				<< "       Nivel: " << curso.nivel        << ", "
				<< "     Alumnos: " << curso.alumnos      << ", "
				<< "    Promedio: " << curso.promedio     << '\n'
				<< '\n';

	in.close();
}
