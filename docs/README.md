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
Using the standard functions `read` and `write` can be cumbersome and requieres the use of low level concepts. These are example statements that use those two funcitons:

	out.write(reinterpret_cast<char*>(&block),sizeof block);
	in.read(reinterpret_cast<const char*>(&block),sizeof block);

Each time we need to write o read, we end up copy-pasting that un-intuitive boilerplate code.

They requiere:
- Three arguments (the stream, the start of the character block, its size).
- One `reinterpret_cast`.
- Use of a pointer type.
- Use of the address-of operator (`&`).
- And in the case of `read`, use of `const`.

The header `BlockStream.h` abstracts out all six items, with a cleaner an simpler syntax:

	WriteBlock(out, block);
	ReadBlock(in, block);

### How do I use it?
Just copy the header `BlockStream.h` to your C++ project folder, include it in your source files, and start writing and reading blocks to and from file streams.

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
Usar las funciones estdándar `read` y `write` puede ser incómodo y requiere el suto de conceptos de bajo nivel. Estos son ejemplos de sentencias que usan esas dos funciones:

	out.write(reinterpret_cast<char*>(&block),sizeof block);
	in.read(reinterpret_cast<const char*>(&block),sizeof block);

Cada vez que necesitamos usar `write` o `read`, terminamos copiando-y-pegando ese código repetitivo y poco intuitivo.

El uso requiere:
- Tres argumentos (el flujo, el comienzo del bloque de caracteres, su tamaño).
- Un `reinterpret_cast`.
- Usar un tipo puntero.
- Usar el operador dirección-de (`&`).
- Y en el caso de `read`, usar `const`.

El ecanbezado `BlockStream.h` abstrae los seís ítems, con una sintaxis más clara y simple:

	WriteBlock(out, block);
	ReadBlock(in, block);

### ¿Cómo lo uso?
Con simplemente copiar el encabezado `BlockStream.h` a su carpeta de proyecto C++, e incluirlo en sus archivos fuente, ya es posible escribir y leer bloques a y desde flujos.

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