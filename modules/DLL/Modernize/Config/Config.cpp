#include "Config.h"

#include <filesystem>
#include <fstream>

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
	__debugbreak();
	fs::path file_path = fs::path(path) / "uhc.cfg";
	if(!exists(file_path))
		return;

	std::ifstream configFile(file_path);
	if (!configFile.is_open())
		return;

	while(!configFile.eof())
	{
		std::string out;
		std::getline(configFile, out);


	}
	

}
