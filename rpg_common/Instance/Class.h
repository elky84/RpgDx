#pragma once

namespace Instance
{

class Class
{
public:
	Class()
	{
		memset(&m_Wis, 0, sizeof(m_Wis));

		memset(&m_Str, 0, sizeof(m_Str));

		memset(&m_Speed, 0, sizeof(m_Speed));

		memset(&m_Phy, 0, sizeof(m_Phy));

		memset(&m_Name, 0, sizeof(m_Name));

		memset(&m_Luck, 0, sizeof(m_Luck));

		memset(&m_Int, 0, sizeof(m_Int));

		memset(&m_Index, 0, sizeof(m_Index));

		memset(&m_Hp, 0, sizeof(m_Hp));

		memset(&m_Dex, 0, sizeof(m_Dex));

		memset(&m_Agi, 0, sizeof(m_Agi));

	}

	int& Wis()
	{
		return m_Wis;
	}

	void Wis(const int& _Wis)
	{
		m_Wis = _Wis;
	}

	int& Str()
	{
		return m_Str;
	}

	void Str(const int& _Str)
	{
		m_Str = _Str;
	}

	int& Speed()
	{
		return m_Speed;
	}

	void Speed(const int& _Speed)
	{
		m_Speed = _Speed;
	}

	int& Phy()
	{
		return m_Phy;
	}

	void Phy(const int& _Phy)
	{
		m_Phy = _Phy;
	}

	std::wstring& Name()
	{
		return m_Name;
	}

	void Name(const std::wstring& _Name)
	{
		m_Name = _Name;
	}

	int& Luck()
	{
		return m_Luck;
	}

	void Luck(const int& _Luck)
	{
		m_Luck = _Luck;
	}

	int& Int()
	{
		return m_Int;
	}

	void Int(const int& _Int)
	{
		m_Int = _Int;
	}

	int& Index()
	{
		return m_Index;
	}

	void Index(const int& _Index)
	{
		m_Index = _Index;
	}

	int& Hp()
	{
		return m_Hp;
	}

	void Hp(const int& _Hp)
	{
		m_Hp = _Hp;
	}

	int& Dex()
	{
		return m_Dex;
	}

	void Dex(const int& _Dex)
	{
		m_Dex = _Dex;
	}

	int& Agi()
	{
		return m_Agi;
	}

	void Agi(const int& _Agi)
	{
		m_Agi = _Agi;
	}

private:
	int m_Wis;
	int m_Str;
	int m_Speed;
	int m_Phy;
	std::wstring m_Name;
	int m_Luck;
	int m_Int;
	int m_Index;
	int m_Hp;
	int m_Dex;
	int m_Agi;
};


} // Instance
