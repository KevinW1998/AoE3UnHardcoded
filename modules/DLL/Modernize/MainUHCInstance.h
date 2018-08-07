#pragma once
#include "Config/Config.h"

namespace UHCDLL
{
	class MainUHCInstance
	{
		struct _constructor_tag { explicit _constructor_tag() = default; }; // Borrowed from http://seanmiddleditch.com/enabling-make_unique-with-private-constructors/

		Config m_config;
	public:
		MainUHCInstance(_constructor_tag);


		static void Init();
		static void Deinit();
		static MainUHCInstance& GetInstance();
	};


}



