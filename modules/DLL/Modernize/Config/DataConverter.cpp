#include "DataConverter.h"
#include <string>

using namespace std::string_literals;

namespace UHCDLL::details
{
	template<typename T>
	void ConvertSafe(std::string_view name, std::string& data, T& dataOut, T(*func)(const std::string&, size_t *, int))
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
	void ConvertSafe(std::string_view name, std::string& data, T& dataOut, T(*func)(const std::string&, size_t *))
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
}

void UHCDLL::DataConverter::Convert(std::string_view name, std::string& data, double& dataOut)
{
	details::ConvertSafe(name, data, dataOut, &std::stod);
}

void UHCDLL::DataConverter::Convert(std::string_view name, std::string& data, float& dataOut)
{
	details::ConvertSafe(name, data, dataOut, &std::stof);
}

void UHCDLL::DataConverter::Convert(std::string_view name, std::string& data, int& dataOut)
{
	details::ConvertSafe(name, data, dataOut, &std::stoi);
}


void UHCDLL::DataConverter::Convert(std::string_view name, std::string& data, long& dataOut)
{
	details::ConvertSafe(name, data, dataOut, &std::stol);
}

void UHCDLL::DataConverter::Convert(std::string_view name, std::string& data, long long& dataOut)
{
	details::ConvertSafe(name, data, dataOut, &std::stoll);
}

void UHCDLL::DataConverter::Convert(std::string_view name, std::string& data, long double& dataOut)
{
	details::ConvertSafe(name, data, dataOut, &std::stold);
}

void UHCDLL::DataConverter::Convert(std::string_view name, std::string& data, unsigned& dataOut)
{
	unsigned long tmp;
	details::ConvertSafe(name, data, tmp, &std::stoul);
	dataOut = static_cast<unsigned int>(dataOut);
}

void UHCDLL::DataConverter::Convert(std::string_view name, std::string& data, unsigned long& dataOut)
{
	details::ConvertSafe(name, data, dataOut, &std::stoul);
}

void UHCDLL::DataConverter::Convert(std::string_view name, std::string& data, unsigned long long& dataOut)
{
	details::ConvertSafe(name, data, dataOut, &std::stoull);
}

void UHCDLL::DataConverter::Convert(std::string_view name, std::string& data, std::string& dataOut)
{
	dataOut = data;
}

