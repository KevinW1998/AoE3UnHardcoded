#pragma once

#include <string_view>

namespace UHCDLL::DataConverter {
	void Convert(std::string_view name, std::string& data, double& dataOut);
	void Convert(std::string_view name, std::string& data, float& dataOut);
	void Convert(std::string_view name, std::string& data, int& dataOut);
	void Convert(std::string_view name, std::string& data, long& dataOut);
	void Convert(std::string_view name, std::string& data, long long& dataOut);
	void Convert(std::string_view name, std::string& data, long double& dataOut);
	void Convert(std::string_view name, std::string& data, unsigned int& dataOut);
	void Convert(std::string_view name, std::string& data, unsigned long& dataOut);
	void Convert(std::string_view name, std::string& data, unsigned long long& dataOut);
	void Convert(std::string_view name, std::string& data, std::string& dataOut);

}


