#pragma once
#include <xstring>


namespace UHCDLL
{
	template<typename CharT>
	bool hasEnding(std::basic_string_view<CharT> fullString, std::basic_string_view<CharT> ending) {
		if (fullString.length() >= ending.length()) {
			return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
		}
		return false;
	}

	template <typename CharT, typename Container>
	void splitString(std::basic_string_view<CharT> str, Container& cont,
		std::basic_string_view<CharT> delims = " ")
	{
		std::size_t current, previous = 0;
		current = str.find_first_of(delims);
		while (current != std::string::npos) {
			cont.push_back(str.substr(previous, current - previous));
			previous = current + 1;
			current = str.find_first_of(delims, previous);
		}
		cont.push_back(str.substr(previous, current - previous));
	}
}
