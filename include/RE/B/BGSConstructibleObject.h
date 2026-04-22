#pragma once

#include "RE/B/BGSCraftableForm.h"
#include "RE/B/BGSCraftingUseSound.h"
#include "RE/B/BGSPickupPutdownSounds.h"
#include "RE/B/BSTList.h"
#include "RE/T/TESValueForm.h"

namespace RE
{
	class TESBoundObject;
	class TESGlobal;

	class BGSConstructibleObject :
		public BGSCraftableForm,        // 000
		public BGSPickupPutdownSounds,  // 0A0
		public TESValueForm,            // 108
		public BGSCraftingUseSound      // 118
	{
	public:
		SF_RTTI_VTABLE(BGSConstructibleObject);
		SF_FORMTYPE(COBJ);

		enum class LEARN_METHOD
		{
			kPickupOrScript,
			kScrapping,
			kIngestion,
			kDefaultOrConditionsMet,
			kPlan
		};

		~BGSConstructibleObject() override;  // 00

		// members
		std::byte                                                                       category[0x18];  // 150 - std::vector<BGSKeyword*, BSTHeapSTLAllocator<BGSKeyword, 2>
		TESBoundObject*                                                                 unk168;          // 168
		BGSCurveForm*                                                                   unk170;          // 170
		TESGlobal*                                                                      buildLimit;      // 178
		BSTArray<BSTTuple3<TESForm*, BGSCurveForm*, BGSTypedFormValuePair::SharedVal>>* unk180;          // 180
		REX::TEnum<LEARN_METHOD, std::uint8_t>                                          learnMethod;     // 188
		TESGlobal*                                                                      unk190;          // 190
		BGSKeyword*                                                                     unk198;          // 198
		std::uint32_t                                                                   unk1A0;          // 1A0
	};
	static_assert(sizeof(BGSConstructibleObject) == 0x1A8);
}
