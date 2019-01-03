#pragma once
#include "Config/Config.h"
#include <remod.h>
#include "Feature/BaseFeature.h"

namespace UHCDLL
{
	class MainUHCInstance
	{
		struct _constructor_tag { explicit _constructor_tag() = default; }; // Borrowed from http://seanmiddleditch.com/enabling-make_unique-with-private-constructors/

		Config m_config;
		remod::patch_manager<remod::resolve_strategy_noop> m_patch_manager;
		std::vector<std::unique_ptr<BaseFeature>> m_features;
	public:
		MainUHCInstance(_constructor_tag);


		static void Init();
		static void Deinit();
		static MainUHCInstance& GetInstance();
	};


}



