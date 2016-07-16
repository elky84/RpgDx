#pragma once

namespace Enum
{

class TendencyType
{
public:
	enum Type
	{
		Aggressive = 0, // 공격성
		Initiative = 1, // 적극성
		Thoughtful = 2, // 배려심
		kitely = 3, // 현명함
		Godliness = 4, // 신앙심
		Talent = 5, // 재능
		Ambition = 6, // 야망
	};
};

static const std::wstring TendencyType_STR[] = {
		_T("Aggressive"), 
		_T("Initiative"), 
		_T("Thoughtful"), 
		_T("kitely"), 
		_T("Godliness"), 
		_T("Talent"), 
		_T("Ambition"), 
};

} // Enum
