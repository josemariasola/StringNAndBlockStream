#include "BlockStream.h"
#include <cassert>
int main(){
	struct Color{unsigned char r,g,b;};
	std::ofstream out("color", std::ios::binary);
	WriteBlock(out, Color{70,30,180});
	std::ifstream in("color", std::ios::binary);
	Color steelBlue;
	ReadBlock(in, steelBlue);
	assert( 70 == steelBlue.r);
	assert( 30 == steelBlue.g);
	assert(180 == steelBlue.b);
}
