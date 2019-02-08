#pragma once

#include "../BaseFeature.h"
#include "../../Utils/PatchUtils.h"

namespace UHCDLL
{
	class MaxPopOverrideFeature : public BaseFeature
	{
		remod::trackable_wrapper<remod::trackable_memory_patch> asm_mem_patch;
	public:
		virtual ~MaxPopOverrideFeature() = default;
		
		void Init(UHCDLL::Config& config, remod::patch_manager<remod::resolve_strategy_noop>& patchManager) override {
			std::optional<int> basePopOpt = config.ReadSingleOpt<int>("basePop");
			std::optional<int> extraPopOpt = config.ReadSingleOpt<int>("extraPop");
			int basePop = basePopOpt.value_or(200);
			int extraPop = extraPopOpt.value_or(50);
			
			if (basePopOpt || extraPopOpt) {
				asm_mem_patch = PatchUtils::AddPatchAndApply(patchManager, 
					AsmPatch::Patch(0x004581F3)
						.pushECX() // curMaxPop
						.pushEAX() // curPop
						.callLambdaStdcall([extraPop, basePop](int curPop, int curMaxPop) {
							if (curMaxPop > extraPop)
								curMaxPop = extraPop;
							if (curPop > curMaxPop + basePop)
								curPop = curMaxPop + basePop;

							return curPop;
					}).nops<0x45>().compile());
			}
		}

	};

}
