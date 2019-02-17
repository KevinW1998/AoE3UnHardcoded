#include "Features.h"

#include "BasicFeature/BasicMemoryPatch.h"
#include "GameplayFeature/MaxPopOverrideFeature.h"

std::vector<std::unique_ptr<UHCDLL::BaseFeature>> UHCDLL::RegistersFeatures()
{
	std::vector<std::unique_ptr<UHCDLL::BaseFeature>> retVal;

	// Config "basePop", "extraPop"
	retVal.emplace_back(new MaxPopOverrideFeature());
	
	// Config "deckCardCount"
	// TODO: If deck card count needs to be bigger than 128 then use patch
	retVal.emplace_back(new BasicMemoryPatch<std::int8_t>("deckCardCount", 0x007EF028));
	retVal.emplace_back(new BasicMemoryPatch<std::int8_t>("deckCardCount", 0x007EF02C));





	return retVal;
}
