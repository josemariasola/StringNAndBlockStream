/* BlockStreamDriver.cpp
 * Test BlockStream: WriteBlock and ReadBlock
 * 20151109
 * Esp. Ing. José María Sola
 * Profesor
 * UTN FRBA
 */

#include <fstream>
#include <iostream> 
#include <array>
#include <cassert>
#include "BlockStream.h"
#include "StringPacker.h"

int main(){
	struct {
		int id;
		std::array<char,25> name; 
	} aBlock, anotherBlock;

	constexpr auto filename{"people"};
	
	std::ofstream out{filename, std::ios::binary};
	aBlock = {10, PackString("Joe")}; 
	WriteBlock(out, aBlock);
	std::cout
		<< aBlock.id << ' '
		<< UnpackString(aBlock.name) << '\n';
	out.close();
	
	std::ifstream in{filename, std::ios::binary};
	ReadBlock(in, anotherBlock);
	assert(aBlock.id == anotherBlock.id);
	assert(UnpackString(aBlock.name) == UnpackString(anotherBlock.name));
	std::cout
		<< anotherBlock.id << ' '
		<< UnpackString(anotherBlock.name) << '\n';
}
