#pragma once

#include <vector>
#include <string>
#include <unordered_map>

namespace UHCDLL
{
	class Config
	{
		std::unordered_map<std::string, std::vector<std::string>> m_configElements;
	public:
		template<typename T>
		T ReadSingle(std::string_view name)
		{
			return {};
		}

		template<typename T>
		std::vector<T> ReadMulti(std::string_view name)
		{
			return {};
		}

		template<typename... Args>
		void ReadTuple(std::string_view name, Args... args)
		{
			
		}

		bool IsSet(const std::string& name) const
		{
			return m_configElements.find(name) != m_configElements.cend();
		}
	};
}

