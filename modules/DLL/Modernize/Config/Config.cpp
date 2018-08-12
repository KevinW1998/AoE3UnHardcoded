#include "Config.h"

#include <string_view>
#include <filesystem>
#include <fstream>
#include "../Utils/StringUtils.h"


namespace fs = std::filesystem;

const std::vector<std::string>& UHCDLL::Config::FindValueOrThrow(const std::string& name) const
{
	auto it = m_configElements.find(name);
	if (it == m_configElements.end())
		throw std::runtime_error(std::string("Failed to find config element ") + name);
	return it->second;
}

const std::vector<std::string>& UHCDLL::Config::FindAtLeastOneElementOrThrow(const std::string& name) const
{
	const auto& elem = FindValueOrThrow(name);
	if (elem.empty())
		throw std::runtime_error(std::string("Invalid config element ") + name + " [must have at least one config value]");

	return elem;
}

void UHCDLL::Config::ReadFromFile(std::wstring_view path)
{
	using namespace std::literals;
	fs::path cur_path = fs::current_path();
	if (!hasEnding(std::string_view(cur_path.u8string()), "bin"sv))
		cur_path /= "bin";
	
	fs::path file_path = cur_path / fs::path(path) / "uhc.cfg";
	if(!exists(file_path))
		return;

	std::ifstream configFile(file_path);
	if (!configFile.is_open())
		return;

	while(true) // TODO: check how to correctly eof
	{
		std::string out;
		std::getline(configFile, out);

		if (configFile.eof())
			break;

		if(out.empty())
			continue;

		if(out.find('=') != std::string::npos)
		{
			std::vector<std::string_view> elements;
			splitString(std::string_view(out), elements, "="sv);

			m_configElements[std::string(elements[0])] = { { std::string(elements[1])} };
		}
		else if(out.find(' ') != std::string::npos)
		{
			std::vector<std::string_view> elements;
			splitString(std::string_view(out), elements, " "sv);

			std::vector<std::string> allocElements;
			std::transform(elements.begin() + 1, elements.end(), std::back_inserter(allocElements), [](std::string_view elem) { return std::string(elem); });

			m_configElements[std::string(elements[0])] = std::move(allocElements); // move the rest of the elements
		}
		else
		{
			// Create new empty vector
			m_configElements[out] = {};
		}
	}
}
