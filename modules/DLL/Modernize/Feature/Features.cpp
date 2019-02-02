#include "Features.h"

#include "BasicFeature/BasicMemoryPatch.h"

std::vector<std::unique_ptr<UHCDLL::BaseFeature>> UHCDLL::RegistersFeatures()
{
	std::vector<std::unique_ptr<UHCDLL::BaseFeature>> retVal;

	retVal.emplace_back(new BasicMemoryPatch<std::int32_t>("basePop", 0x004581F5));
	retVal.emplace_back(new BasicMemoryPatch<std::int8_t>("extraPop", 0x004581FF));

	return {};
}
