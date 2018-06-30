# (EN) What are StringN and BlockStream?
Two headers that provide abstractions to manipulate *Bounded Strings* and *Stream of Blocks* in C++ with a cleaner syntax.

*by Esp. Ing. José María Sola  
Professor  
UTN FRBA*

## StringN
The standard type `std::string` provee strings with dynamic and unbounded length, but it comes with a trade off, it's tedious to put them into or get them from fixed size objects.

The type `String<N>` provides a solution, based upon a template type that wraps a `std::array<char,N>` and a pair of functions to pack and unpack from an to bouned and unbounded strings: `PackString` and `UnpackString`

### How do I use it?
Just copy the header `StringN.h` to your C++ project folder, include it in your source files, and start packing and unpacking strings.

```c++
	#include "StringN.h"
	#include <cassert>
	int main(){
		std::string s{"Hello, World!"}; // Standard unbounded string s.
		String<5> a = PackString(s);    // Put s into bounded string a.
		auto t{UnpackString(a)};        // Get the string from a.
		assert("Hello" == t);           // Check.
	}
```

## BlockStream
Using the standard functions `read` and `write` can be cumbersome and requieres the use of low level concepts. These are example statements that use those funcitons:

	out.write(reinterpret_cast<char*>(&block),sizeof block);
	in.read(reinterpret_cast<const char*>(&block),sizeof block);

They requiere:
- Three arguments (the stream, the start of the character block, its size).
- One `reinterpret_cast`.
- Use of a pointer type.
- Use of the address-of operator (`&`).
- And in the case of `read` use of const.

Each time you need to write o read, you end up copy-pasting that boilerplate code.

The header `BlockStream.h` abstracts out all six items, with a cleaner an simple syntax:

	WriteBlock(out, block);
	ReadBlock(in, block);

### How do I use it?
Just copy the header `BlockStream.h` to your C++ project folder, include it in your source files, and writing and reading blocks to file streams.

```c++
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
```

# (ES) ¿Qué son StringN y BlockStream?
Son dos headers que proveen abstracciones para manipular *Cadenas Acotadas* y *Flujo de Bloques* en C++ con una sintaxis clara.

*por Esp. Ing. José María Sola  
Profesor  
UTN FRBA*

## StringN
El tipo standar `std::string` provee cadenas con largo dinámico y no acotado, pero viene una contra, es tedioso almacerlas o leerlas en o desde objetos de tamaño fijo.

El tipo `String<N>` provee una solución, basada en un tipo template que envuelve un  `std::array<char,N>` y en un par de funciones para empaquetar y desempaquetar desde y hace cadenas acotadas y no acotadas: `PackString` y `UnpackString`

### ¿Cómo lo uso?
Con simplemente copiar el encabezado `StringN.h` a su carpeta de proyecto C++, e incluirlo en sus archivos fuente, ya es posible empaquetar y desempaquetas cadenas.

```c++
	#include "StringN.h"
	#include <cassert>
	int main(){
		std::string s{"Hello, World!"}; // Standard unbounded string s.
		String<5> a = PackString(s);    // Put s into bounded string a.
		auto t{UnpackString(a)};        // Get the string from a.
		assert("Hello" == t);           // Check.
	}
```

## BlockStream
Using the standard functions `read` and `write` can me cumbersome and requieres the use of low level concepts. These are example statements that use those funcitons:

	out.write(reinterpret_cast<char*>(&block),sizeof block);
	in.read(reinterpret_cast<const char*>(&block),sizeof block);

They requiere:
- Three arguments (the stream, the start of the character block, its size).
- One `reinterpret_cast`.
- Use of a pointer type.
- Use of the address-of operator (`&`).
- And in the case of `read` use of const.

Each time you need to write o read, you end up copy-pasting that boilerplate code.

The header `BlockStream.h` abstracts out all six items, with a cleaner an simple syntax:

	WriteBlock(out, block);
	ReadBlock(in, block);

### ¿Cómo lo uso?
Just copy the header `BlockStream.h` to your C++ project folder, include it in your source files, and writing and reading blocks to file streams.

```c++
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
```