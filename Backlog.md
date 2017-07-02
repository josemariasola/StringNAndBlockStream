# Backlog

[x] Rename PackString.h to StringPacker.h
Make << and >> part of BlockStram.h, right now I can't work arround the ambiguities: o<<block o<<aChar o<<aString.

Incorporte Block Type

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
