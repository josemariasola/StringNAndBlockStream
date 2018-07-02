/* StringPacker.h
2015-11-08 - 2018-06-30
Esp. Ing. José María Sola
Professor
UTN FRBA */

#ifndef HEADER_STRINGN_INCLUDED
#define HEADER_STRINGN_INCLUDED

#include <string>
#include <array>

// Type: String<N>
template<std::size_t N>
struct String
{
	private:
		using ContainerType = std::array<char, N>;
		using ContainerIterator = typename ContainerType::iterator;
		using ContainerConstIterator = typename ContainerType::const_iterator;

	public:
		String() = default;

		// C++ implicit conversion shenanigans
		explicit String(const char* theCString)
		{
			*this = std::string{ theCString };
		}

		explicit String(const std::string& theString)
		{
			*this = theString;
		}

		char& at(std::size_t pos) { return _impl.at(pos); }
		const char& at(std::size_t pos) const { return _impl.at(pos); }

		inline operator std::string() const
		{
			std::string s;
			for (auto c : _impl)
			{
				if (c == '\0')
					break;
				s.push_back(c);
			}

			return s;
		}

		inline String<N>& operator=(const std::string& theString)
		{
			auto len = theString.length();
			if (len < N)
			{
				theString.copy(_impl.data(), len);
				_impl.at(len) = '\0'; // from _impl.at(len+1) to _impl.at(N-1) undefined content.
			}
			else
				theString.copy(_impl.data(), N);

			return *this;
		}

		auto begin()        -> ContainerIterator      { return _impl.begin(); }
		auto end()          -> ContainerIterator      { return _impl.end(); }

		auto begin()  const -> ContainerConstIterator { return _impl.cbegin(); }
		auto end()    const -> ContainerConstIterator { return _impl.cend(); }

		auto cbegin() const -> ContainerConstIterator { return begin(); }
		auto cend()   const -> ContainerConstIterator { return end(); }

	private:
		ContainerType _impl;
};

struct PackString
{
	public:
		explicit PackString(const std::string& unpackedString) : _ref{ unpackedString } { }

		template<std::size_t N>
		operator String<N>() const
		{
			return String<N>{ _ref };
		}

	private:
		const std::string& _ref;
};

template<std::size_t N>
inline std::string UnpackString(const String<N>& packedString)
{
	return std::string{ packedString };
}

template<std::size_t N>
inline bool operator==(const String<N>& packedString, const std::string& theString)
{
	return theString == std::string{ packedString };
}

template<std::size_t N>
inline bool operator==(const std::string& theString, const String<N>& packedString)
{
	return packedString == theString;
}

#endif
