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

	public:
		virtual ~BaseFeature() = default;
		virtual void Init(UHCDLL::Config& config, remod::patch_manager<remod::resolve_strategy_noop>& patchManager) = 0;

	};

}
