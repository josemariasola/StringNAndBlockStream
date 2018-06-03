# Backlog
## Requested
- [ ] `BlockStreamDriver.cpp`: Make it a test file, rename it?.
- [ ] `StringPacker.h`: Simplify header, move example to new file.
- [ ] `StringPackerDriver.cpp`: Remove `using namespace std`.
- [ ] `StringPackerDriver.cpp`: Move `PrintArrayWithString` declaration to `main`.
- [ ] `StringPackerDriver.cpp`: Rename `PrintArrayWithString` to `PrintArrayOfStrings`.
- [ ] `WriteAndReadRecordsBlocksWithoutStrings.cpp`: Remove `using namespace std;`
- [ ] `WriteAndReadRecordsBlocksWithoutStrings.cpp`: Use brace instead of constructors for both streams.
- [ ] `WriteAndReadRecordsBlocksWithoutStrings.cpp`: Remove equales for initialization.
- [ ] Make new type: `String<N>` templated alias. of `array<char,N>`.
- [ ] Strings and Streams.adoc: Write it.
- [ ] `BlockStream.h`: Simplify header, move example to new file.
- [ ] `README.md`: Remove equals.
- [ ] `README.md`: Add includes and scopes.
- [ ] `README.md`: Include examples from source file.
- [ ] `Makefile`: build, test, runexampls, clean install, uninstall.
- [ ] Add folders: `src`, `test`, `examples`, `project(?)`.
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
- [x] `BlockStreamDriver.cpp`: Add comments.
- [x] `BlockStreamDriver.cpp`: Remove `using namespace std;`.
- [x] `BlockStreamDriver.cpp`: Use brace instead of constructors for both streams.
- [x] `BlockStreamDriver.cpp`: Remove equales for initialization.
- [x] Rename `PackString.h` to `StringPacker.h`.
