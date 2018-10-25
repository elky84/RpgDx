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

		memset(&m_Luck, 0, sizeof(m_Luck));

		memset(&m_Int, 0, sizeof(m_Int));

		memset(&m_Index, 0, sizeof(m_Index));

		memset(&m_Hp, 0, sizeof(m_Hp));

		memset(&m_Dex, 0, sizeof(m_Dex));

		memset(&m_Agi, 0, sizeof(m_Agi));

	}

	int& WisReference()
	{
		return m_Wis;
	}

	int Wis() const
	{
		return m_Wis;
	}

	void Wis(const int& _Wis)
	{
		m_Wis = _Wis;
	}

	int& StrReference()
	{
		return m_Str;
	}

	int Str() const
	{
		return m_Str;
	}

	void Str(const int& _Str)
	{
		m_Str = _Str;
	}

	int& SpeedReference()
	{
		return m_Speed;
	}

	int Speed() const
	{
		return m_Speed;
	}

	void Speed(const int& _Speed)
	{
		m_Speed = _Speed;
	}

	int& PhyReference()
	{
		return m_Phy;
	}

	int Phy() const
	{
		return m_Phy;
	}

	void Phy(const int& _Phy)
	{
		m_Phy = _Phy;
	}

	std::wstring& NameReference()
	{
		return m_Name;
	}

	std::wstring Name() const
	{
		return m_Name;
	}

	void Name(const std::wstring& _Name)
	{
		m_Name = _Name;
	}

	int& LuckReference()
	{
		return m_Luck;
	}

	int Luck() const
	{
		return m_Luck;
	}

	void Luck(const int& _Luck)
	{
		m_Luck = _Luck;
	}

	int& IntReference()
	{
		return m_Int;
	}

	int Int() const
	{
		return m_Int;
	}

	void Int(const int& _Int)
	{
		m_Int = _Int;
	}

	int& IndexReference()
	{
		return m_Index;
	}

	int Index() const
	{
		return m_Index;
	}

	void Index(const int& _Index)
	{
		m_Index = _Index;
	}

	int& HpReference()
	{
		return m_Hp;
	}

	int Hp() const
	{
		return m_Hp;
	}

	void Hp(const int& _Hp)
	{
		m_Hp = _Hp;
	}

	int& DexReference()
	{
		return m_Dex;
	}

	int Dex() const
	{
		return m_Dex;
	}

	void Dex(const int& _Dex)
	{
		m_Dex = _Dex;
	}

	int& AgiReference()
	{
		return m_Agi;
	}

	int Agi() const
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

