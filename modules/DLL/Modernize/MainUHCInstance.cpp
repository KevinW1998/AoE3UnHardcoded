#include "MainUHCInstance.h"

#include <memory>
#include <stdexcept>
#include <remod/remod_functions.h>
#include "native/BWorkDirManager.h"
#include "Feature/Features.h"

std::unique_ptr<UHCDLL::MainUHCInstance> g_MainUHCInstance;


UHCDLL::MainUHCInstance::MainUHCInstance(_constructor_tag)
{
	// First let remod resolve all global function bridges
	remod::resolve_all();

	m_config.ReadFromFile(BWorkDirManager::StartUpSubPath);

	// TODO: Load Features
	m_features = RegistersFeatures();

	// Init features
	for (auto& feature : m_features)
		feature->Init(m_config, m_patch_manager);
}

void UHCDLL::MainUHCInstance::Init()
{
	g_MainUHCInstance = std::make_unique<MainUHCInstance>(_constructor_tag{});
}

void UHCDLL::MainUHCInstance::Deinit()
{
	g_MainUHCInstance.reset();
}

UHCDLL::MainUHCInstance& UHCDLL::MainUHCInstance::GetInstance()
{
	if (!g_MainUHCInstance)
		throw std::runtime_error("Attempted to get invalid instance!");
	return *g_MainUHCInstance;
}
