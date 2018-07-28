#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <filesystem>

#include "DataConverter.h"

namespace UHCDLL
{
	class Config
	{
		std::unordered_map<std::string, std::vector<std::string>> m_configElements;

		const std::vector<std::string>& FindValueOrThrow(const std::string& name) const;
		const std::vector<std::string>& FindAtLeastOneElementOrThrow(const std::string& name) const;
	

		template<size_t NextIndex, size_t... RestIndex, typename NextArgType, typename... RestArgsType>
		void ReadNextElement(std::index_sequence<NextIndex, RestIndex...>, const std::string& name, const std::vector<std::string>& elems, NextArgType& nextArg, RestArgsType&... args)
		{
			DataConverter::Convert(name, elems[NextIndex], nextArg);

			ReadNextElement(std::index_sequence<RestIndex...>{}, elems, args...);
		}

	public:


		template<typename T>
		T ReadSingle(const std::string& name)
		{
			const auto& elems = FindAtLeastOneElementOrThrow(name);

			T outElem{};
			DataConverter::Convert(name, elems[0], outElem);

			return outElem;
		}

		template<typename T>
		std::vector<T> ReadMulti(const std::string& name)
		{
			const auto& elems = FindAtLeastOneElementOrThrow(name);

			std::vector<T> outElemList;
			for(const auto& elemStr : elems)
			{
				T outElem{};
				DataConverter::Convert(name, elemStr, outElem);
				outElemList.push_back(outElem);
			}
			
			return outElemList;
		}

		

		template<typename... Args>
		void ReadTuple(const std::string& name, Args&... args)
		{
			constexpr static const size_t SizeOfT = sizeof...(Args);
			using seq = std::make_index_sequence<SizeOfT>;
			const auto& elems = FindValueOrThrow(name);
			if (elems.size() < SizeOfT)
				throw std::runtime_error(std::string("config element ") + name + " requires at least " + std::to_string(SizeOfT) + " config values");

			ReadNextElement(seq{}, name, elems, args...);
		}

		bool IsSet(const std::string& name) const
		{
			return m_configElements.find(name) != m_configElements.cend();
		}
	};

}

