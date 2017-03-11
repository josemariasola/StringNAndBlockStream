# StringPacker and BlockStream
Provides abstractions to manipulate *Bounded Strings* and *Stream of Blocks* in C++ with a cleaner syntax.

**by Esp. Ing. José María Sola**
*Professor
UTN FRBA*


## StringPacker.h
```c++
#include "StringPacker.h"
string s = "Hello, World!";
array<char,5> a = PackString(s);
string t = UnpackString(a);
assert(t=="Hello");
```

## BlockStream.h
```c++
#include "BlockStream.h"
T block = {...}; // e.g., struct T {double x,y;};
ofstream out(filename, ios::binary);
WriteBlock(out, block);
ifstream in(filename, ios::binary);
ReadBlock(in, block);
```
