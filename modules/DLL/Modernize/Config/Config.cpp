#include "Config.h"

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
