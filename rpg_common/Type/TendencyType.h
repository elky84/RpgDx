#pragma once

namespace Enum
{

class TendencyType
{
public:
	enum Type
	{
		Aggressive = 0, // ���ݼ�
		Initiative = 1, // ���ؼ�
		Thoughtful = 2, // �����
		kitely = 3, // ������
		Godliness = 4, // �žӽ�
		Talent = 5, // ���
		Ambition = 6, // �߸�
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
