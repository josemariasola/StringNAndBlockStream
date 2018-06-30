#include "BlockStream.h"
#include <cassert>

int main(){
	using Byte = unsigned char; // std::byte C++17 #include<cstddef>
	struct Color{Byte red, green, blue;};          // A sample block.

	constexpr auto filename{"color.bin"};
	
	std::ofstream out{filename, std::ios::binary}; // Connect to write.
	WriteBlock(out, Color{70,130,180});            // Write to out.
	out.close();                                   // Disconnect.

	std::ifstream in{filename, std::ios::binary};  // Connect to read.
	Color steelBlue;                               // Object to store read data.                   
	ReadBlock(in, steelBlue);                      // Read from in.
	in.close();                                    // Disconcect,

	remove(filename); // C++17 // std::filesystem::remove(filename); 
	
	assert(  70 == steelBlue.red   );
	assert( 130 == steelBlue.green );
	assert( 180 == steelBlue.blue  );
}
