#pragma once

#include <vector>
#include <memory>
#include "BaseFeature.h"

namespace UHCDLL
{
	std::vector<std::unique_ptr<BaseFeature>> RegistersFeatures();
}

