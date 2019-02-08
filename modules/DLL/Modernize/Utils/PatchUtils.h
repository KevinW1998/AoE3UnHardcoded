#include <AsmPatchBuilder.h>
#include <remod/patch_manager.h>

namespace UHCDLL::PatchUtils
{
	template<typename ResolveStrategy>
	remod::trackable_wrapper<remod::trackable_memory_patch> AddPatchAndApply(remod::patch_manager<ResolveStrategy>& manager, AsmPatch::AsmPatchData data) {
		
		std::pair<std::uintptr_t, std::vector<std::uint8_t>> dataPack = std::move(data.getDataPack());
		remod::trackable_wrapper<remod::trackable_memory_patch> patch = manager.create_trackable_memory_patch_with_data(dataPack.first, dataPack.second);
		patch->patch();

		return patch;
	}
}