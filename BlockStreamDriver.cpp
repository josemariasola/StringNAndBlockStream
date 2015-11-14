/* BlockStreamDriver.cpp
 * Test BlockStream: WriteBlock and ReadBlock
 * 20151109
 * Prof. Esp. Ing. José María Sola
 */

#include <fstream>
#include <iostream> 
#include <array>
#include <cassert>
#include "BlockStream.h"
#include "PackString.h"

int main(){
	using namespace std;
	
	struct {
		int id;
		array<char,25> name; 
	} aBlock, anotherBlock;

	constexpr auto filename = "people";
	
	ofstream out(filename, ios::binary);
	aBlock = {10, PackString("Joe")}; 
	WriteBlock(out, aBlock);
	std::cout
		<< aBlock.id << ' '
		<< UnpackString(aBlock.name) << '\n';
	out.close();
	
	ifstream in(filename, ios::binary);
	ReadBlock(in, anotherBlock);
	assert(aBlock.id == anotherBlock.id);
	assert(UnpackString(aBlock.name) == UnpackString(anotherBlock.name));
	std::cout
		<< anotherBlock.id << ' '
		<< UnpackString(anotherBlock.name) << '\n';
}

