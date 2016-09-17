/* Escribe y lee archivo de registros con cadenas, 
 * muestra los empleados con legajo mayor a 10.
 * 20151108
 * Prof. Esp. Ing. José María Sola
 */

#include <iostream>
#include <fstream>
#include <string>
#include "BlockStream.h"
#include "PackString.h"

int main(){
	using namespace std;
	
	struct {
		int id;
		array<char,25> name; // instead of string name;
	} emp;

	constexpr auto filename = "people";
	ofstream out(filename, ios::binary);

	emp = {10, PackString("Bruce")}; // instead of emp = {10, "Bruce"};
	WriteBlock(out, emp);
	
	emp = {11, PackString("Clark")};
	WriteBlock(out, emp);

	emp = {12, PackString("Joseph")};
	WriteBlock(out, emp);

	out.close();
	
	ifstream in(filename, ios::binary);
	
	while( ReadBlock(in, emp) )
		if( emp.id > 10 )
			cout
				<< emp.id << ", "
				<< UnpackString(emp.name)
				<< '\n';

	in.close();
}
