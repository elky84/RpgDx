#include "stdafx.h"
#include "RMCharacterFactory.h"
#include "MetaData.h"

#include "Random.hpp"

#include "RMCharacter.h"

namespace RM
{

CHARACTER_INDEX CharacterFactory::m_Index = 0;

SHARED_CHARACTER CharacterFactory::Pick(light::weak_raw_ptr<light::view::DirectX> directX)
{
	SHARED_CHARACTER character(new Character(directX, m_Index++));

	auto& mapClass = light::excel::Loader::Instance()->find<ExcelData::ClassData>()->Map();
	int n = light::Random::rand() % mapClass.size() + 1;
	ExcelData::Class _class = mapClass[n];

	character->GetClass().Name(_class.Name());
	character->GetClass().Hp(light::Random::rand(_class.Hp_Min(), _class.Hp_Max()));
	character->GetClass().Agi(light::Random::rand(_class.Agi_Min(), _class.Agi_Max()));
	character->GetClass().Speed(light::Random::rand(_class.Speed_Min(), _class.Speed_Max()));
	character->GetClass().Str(light::Random::rand(_class.Str_Min(), _class.Str_Max()));
	character->GetClass().Phy(light::Random::rand(_class.Phy_Min(), _class.Phy_Max()));
	character->GetClass().Dex(light::Random::rand(_class.Dex_Min(), _class.Dex_Max()));
	character->GetClass().Int(light::Random::rand(_class.Int_Min(), _class.Int_Max()));
	character->GetClass().Wis(light::Random::rand(_class.Wis_Min(), _class.Wis_Max()));
	character->GetClass().Luck(light::Random::rand(_class.Luck_Min(), _class.Luck_Max()));

	auto& mapTribe = light::excel::Loader::Instance()->find<ExcelData::TribeData>()->Map();
	ExcelData::Tribe _tribe = mapTribe[n];
	character->SetTribe(_tribe);

	return character;
}

} // namespace RM