#pragma once

#include <string_view>

namespace UHCDLL::DataConverter {
	void Convert(const std::string_view name, const std::string& data, double& dataOut);
	void Convert(const std::string_view name, const std::string& data, float& dataOut);
	void Convert(const std::string_view name, const std::string& data, std::int8_t& dataOut);
	void Convert(const std::string_view name, const std::string& data, std::uint8_t& dataOut);
	void Convert(const std::string_view name, const std::string& data, std::int16_t& dataOut);
	void Convert(const std::string_view name, const std::string& data, std::uint16_t& dataOut);
	void Convert(const std::string_view name, const std::string& data, int& dataOut);
	void Convert(const std::string_view name, const std::string& data, long& dataOut);
	void Convert(const std::string_view name, const std::string& data, long long& dataOut);
	void Convert(const std::string_view name, const std::string& data, long double& dataOut);
	void Convert(const std::string_view name, const std::string& data, unsigned int& dataOut);
	void Convert(const std::string_view name, const std::string& data, unsigned long& dataOut);
	void Convert(const std::string_view name, const std::string& data, unsigned long long& dataOut);
	void Convert(const std::string_view name, const std::string& data, std::string& dataOut);

}


