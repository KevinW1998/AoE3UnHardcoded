#include <AsmPatchBuilder.h>
#include <remod/patch_manager.h>

namespace UHCDLL::PatchUtils
{
	template<typename ResolveStrategy>
	remod::trackable_wrapper<remod::trackable_memory_patch> AddPatchAndApply(remod::patch_manager<ResolveStrategy>& manager, AsmPatch::AsmPatchData data) {
		remod::trackable_wrapper<remod::trackable_memory_patch> patch = manager.create_trackable_memory_patch_with_data(data.getAddress(), std::move(data.getDataRef()));
		patch->patch();

		return patch;
	}
}