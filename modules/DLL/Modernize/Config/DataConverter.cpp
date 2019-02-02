#include "DataConverter.h"
#include <string>

using namespace std::string_literals;

namespace UHCDLL::details
{
	template<typename T>
	void ConvertSafe(const std::string_view name, const std::string& data, T& dataOut, T(*func)(const std::string&, size_t *, int))
	{
		try
		{
			dataOut = std::invoke(func, data, nullptr, 10);
		} 
		catch(const std::exception& ex)
		{
			throw std::runtime_error("Invalid value for config \""s + name.data() + "\"");
		}
	}

	template<typename T>
	void ConvertSafe(const std::string_view name, const std::string& data, T& dataOut, T(*func)(const std::string&, size_t *))
	{
		try
		{
			dataOut = std::invoke(func, data, nullptr);
		}
		catch (const std::exception& ex)
		{
			throw std::runtime_error("Invalid value for config \""s + name.data() + "\"");
		}
	}

	template<typename T>
	void ConvertAsIntBasis(const std::string_view name, const std::string& data, T& dataOut) {
		int value;
		DataConverter::Convert(name, data, value);
		if (value > std::numeric_limits<T>::max() || value < std::numeric_limits<T>::min())
			throw std::runtime_error("Invalid value for config \""s + name.data() + "\"");
		dataOut = static_cast<T>(value);
	}
}

void UHCDLL::DataConverter::Convert(const std::string_view name, const std::string& data, double& dataOut)
{
	details::ConvertSafe(name, data, dataOut, &std::stod);
}

void UHCDLL::DataConverter::Convert(const std::string_view name, const std::string& data, float& dataOut)
{
	details::ConvertSafe(name, data, dataOut, &std::stof);
}

void UHCDLL::DataConverter::Convert(const std::string_view name, const std::string & data, std::int8_t & dataOut)
{
	details::ConvertAsIntBasis(name, data, dataOut);
}

void UHCDLL::DataConverter::Convert(const std::string_view name, const std::string & data, std::uint8_t & dataOut)
{
	details::ConvertAsIntBasis(name, data, dataOut);
}

void UHCDLL::DataConverter::Convert(const std::string_view name, const std::string & data, std::int16_t & dataOut)
{
	details::ConvertAsIntBasis(name, data, dataOut);
}

void UHCDLL::DataConverter::Convert(const std::string_view name, const std::string & data, std::uint16_t & dataOut)
{
	details::ConvertAsIntBasis(name, data, dataOut);
}

void UHCDLL::DataConverter::Convert(const std::string_view name, const std::string& data, int& dataOut)
{
	details::ConvertSafe(name, data, dataOut, &std::stoi);
}


void UHCDLL::DataConverter::Convert(const std::string_view name, const std::string& data, long& dataOut)
{
	details::ConvertSafe(name, data, dataOut, &std::stol);
}

void UHCDLL::DataConverter::Convert(const std::string_view name, const std::string& data, long long& dataOut)
{
	details::ConvertSafe(name, data, dataOut, &std::stoll);
}

void UHCDLL::DataConverter::Convert(const std::string_view name, const std::string& data, long double& dataOut)
{
	details::ConvertSafe(name, data, dataOut, &std::stold);
}

void UHCDLL::DataConverter::Convert(const std::string_view name, const std::string& data, unsigned& dataOut)
{
	unsigned long tmp;
	details::ConvertSafe(name, data, tmp, &std::stoul);
	dataOut = static_cast<unsigned int>(dataOut);
}

void UHCDLL::DataConverter::Convert(const std::string_view name, const std::string& data, unsigned long& dataOut)
{
	details::ConvertSafe(name, data, dataOut, &std::stoul);
}

void UHCDLL::DataConverter::Convert(const std::string_view name, const std::string& data, unsigned long long& dataOut)
{
	details::ConvertSafe(name, data, dataOut, &std::stoull);
}

void UHCDLL::DataConverter::Convert(const std::string_view name, const std::string& data, std::string& dataOut)
{
	dataOut = data;
}

