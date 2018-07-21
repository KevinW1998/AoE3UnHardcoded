#pragma once

#include <remod/patch_manager.h>
#include <remod/resolve_strategy.h>
#include "../Config/Config.h"

namespace UHCDLL
{

	class BaseFeature
	{
	protected:
		BaseFeature() = default;

		virtual bool Init(UHCDLL::Config& config) { return true; }
		virtual void ManualDeactivate() {}
		virtual void ApplyPatches(remod::patch_manager<remod::resolve_strategy_noop>& patchManager) {}
	
	};

}
