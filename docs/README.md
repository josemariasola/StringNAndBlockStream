# (EN) What is StringPacker and BlockStream?
Provides abstractions to manipulate *Bounded Strings* and *Stream of Blocks* in C++ with a cleaner syntax.

*by Esp. Ing. José María Sola  
Professor  
UTN FRBA*


## StringPacker
### How does it work?

Just copy the header to your project, include it and start packing and unpacking strings.

```c++
#include "StringN.h"
#include <cassert>
int main(){
	std::string s{"Hello, World!"};
	String<5> a = PackString(s);
	auto t{UnpackString(a)};
	assert("Hello" == t);
}
```

## BlockStream?
### How does it work?
Just copy the header to your project, include it in your source files, and and writing and reading blocks to file streams.

```c++
#include "BlockStream.h"
T block = {...}; // e.g., struct T {double x,y;};
ofstream out(filename, ios::binary);
WriteBlock(out, block);
ifstream in(filename, ios::binary);
ReadBlock(in, block);
```
