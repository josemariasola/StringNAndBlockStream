# Backlog
## Requested
### 2.0.0
- [ ] !!! StringPackerDriver: Use braces for initialization.
- [ ] !! Strings and Streams.adoc: Write it.
- [ ] ! `README.md`: Remove equals.
- [ ] `README.md`: Add includes and scopes.
- [ ] `README.md`: Include examples from source file.
- [ ] `BlockStreamDriver.cpp`: Make it a test file, rename it, divide in two separatefiles?.
- [ ] `StringPacker.h`: Simplify header, move example to new file or to adoc file.
- [ ] `BlockStream.h`: Simplify header, move example to new file or to adoc file..
- [ ] `WriteAndReadRecordsBlocksWithoutStrings.cpp`: Remove `using namespace std;`
### 2.1.0
- [ ] `Makefile`: build, test, runexampls, clean install, uninstall.
- [ ] Add folders: `src`, `test`, `examples`, `project(?)`.
### 3.0.0
- [ ] Make `<<` and `>>` part of BlockStram.h, right now I can't work arround the ambiguities: `o<<block` `o<<aChar` `o<<aString`.
- [ ] Incorporte Block Type
	template<typename T>
	struct Blockk{T data;};

	template<typename T>
	std::istream& RB(std::istream& in, Blockk<T>& block){
		return in.read(
			reinterpret_cast<char*>(&block.data),
			sizeof block
		);
	}
	std::istream& operator>>(std::istream& in, Curso& v){ return ReadBlock(in, v);}
	std::ostream& operator<<(std::ostream& out, const Curso& v){return WriteBlock(out, v);}
	static_assert(std::is_compound<T>::value,":("); // TODO: Test

## In Progress

## Done
### 2.0.0
- [x] ! WriteAndReadRecordsBlocksWithStrings: use a temporary or litertal instead of variable in `WriteBlock(...);`
- [x] ! WriteAndReadRecordsBlocksWithoutStrings: use a temporary or litertal instead of variable in `WriteBlock(...);`
- [x] ! `StringPackerDriver.cpp`: Remove `using namespace std`.
- [x] ! `WriteAndReadRecordsBlocksWithoutStrings.cpp`: Use for instead of while.
- [x] ! `WriteAndReadRecordsBlocksWithStrings.cpp`: Use for instead of while.
- [x] ! `WriteAndReadRecordsBlocksWithStrings.cpp`: Remove `using namespace std`.
- [x] ! `WriteAndReadRecordsBlocksWithoutStrings.cpp`: Remove equales for initialization.
- [x] ! `WriteAndReadRecordsBlocksWithStrings.cpp`: Remove equales for initialization.
- [x] ! `WriteAndReadRecordsBlocksWithoutStrings.cpp`: Use brace instead of constructors for both streams.
- [x] ! `WriteAndReadRecordsBlocksWithStrings.cpp`: Use brace instead of constructors for both streams.
- [x] Make new type: `String<N>` templated alias of `array<char,N>`.
- [x] `StringPackerDriver.cpp`: Rename `PrintArrayWithString` to `PrintStringInsideArray`.
- [x] `StringPackerDriver.cpp`: Make a print table function.
- [x] `StringPackerDriver.cpp`: Remove `using namespace std`.
- [x] `BlockStreamDriver.cpp`: Add comments.
- [x] `BlockStreamDriver.cpp`: Remove `using namespace std;`.
- [x] `BlockStreamDriver.cpp`: Use brace instead of constructors for both streams.
- [x] `BlockStreamDriver.cpp`: Remove equales for initialization.
### 1.0.0
- [x] Rename `PackString.h` to `StringPacker.h`.
