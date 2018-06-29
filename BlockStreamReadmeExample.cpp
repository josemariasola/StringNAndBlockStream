#include "BlockStream.h"
#include <cassert>

int main(){
	using Byte = unsigned char; // std::byte C++17 #include<cstddef>
	struct Color{Byte red, green, blue;};

	constexpr auto filename{"color.bin"};
	
	std::ofstream out{filename, std::ios::binary};
	WriteBlock(out, Color{70,130,180});
	out.close();

	std::ifstream in{filename, std::ios::binary};
	Color steelBlue;
	ReadBlock(in, steelBlue);
	in.close();

	remove(filename); // C++17 // std::filesystem::remove(filename); 
	
	assert(  70 == steelBlue.red   );
	assert( 130 == steelBlue.green );
	assert( 180 == steelBlue.blue  );
}
