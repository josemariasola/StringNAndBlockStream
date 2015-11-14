= PackString and BlockStream

Provides abstractions to manipulate *Bounded Strings* and *Stream of Blocks* in C++ with a cleaner syntax.
 
== PackString.h

```
#include "PackString.h"
std::string s = "Hello, World!";
std::array<char,5> a = PackString(s);
std::string t = UnpackString(a);
assert(t=="Hello");
```

== BlockStream.h

```
#include "BlockStream.h"
T block = {...}; // e.g., struct T {double x,y;};
ofstream out(filename, ios::binary);
WriteBlock(out, block);
ifstream in(filename, ios::binary);
ReadBlock(in, block);
```
