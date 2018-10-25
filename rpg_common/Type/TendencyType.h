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
		Wisely = 3, // ������
		Godliness = 4, // �žӽ�
		Talent = 5, // ���
		Ambition = 6, // �߸�
	};
};

static const std::wstring TendencyType_STR[] = {
		L"���ݼ�", 
		L"���ؼ�", 
		L"�����", 
		L"������", 
		L"�žӽ�", 
		L"���", 
		L"�߸�", 
};

} // Enum

