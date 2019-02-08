#pragma once

#include "../BaseFeature.h"

namespace UHCDLL
{

	template<typename T>
	class BasicMemoryPatch : public BaseFeature
	{
		const char* m_configElementName;
		std::uintptr_t m_memAddress;
		remod::trackable_wrapper<remod::trackable_memory_patch> data_patch;
	public:
		BasicMemoryPatch(const char* configName, int address) : m_configElementName(configName), m_memAddress(address) {};

		virtual ~BasicMemoryPatch() = default;
		
		void Init(UHCDLL::Config& config, remod::patch_manager<remod::resolve_strategy_noop>& patchManager) override {
			auto configValueOpt = config.ReadSingleOpt<T>(m_configElementName);
			if (configValueOpt) {
				data_patch = patchManager.create_trackable_memory_patch(m_memAddress, *configValueOpt);
				data_patch->patch();
			}
		}

	};

}
