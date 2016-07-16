#pragma once

namespace ExcelData
{

class Class
{
public:
	Class()
	{
		memset(&m_kitely, 0, sizeof(m_kitely));

		memset(&m_Wis_Min, 0, sizeof(m_Wis_Min));

		memset(&m_Wis_Max, 0, sizeof(m_Wis_Max));

		memset(&m_Thoughtful, 0, sizeof(m_Thoughtful));

		memset(&m_TendencySum, 0, sizeof(m_TendencySum));

		memset(&m_Talent, 0, sizeof(m_Talent));

		memset(&m_Str_Min, 0, sizeof(m_Str_Min));

		memset(&m_Str_Max, 0, sizeof(m_Str_Max));

		memset(&m_StatSum, 0, sizeof(m_StatSum));

		memset(&m_Speed_Min, 0, sizeof(m_Speed_Min));

		memset(&m_Speed_Max, 0, sizeof(m_Speed_Max));

		memset(&m_Phy_Min, 0, sizeof(m_Phy_Min));

		memset(&m_Phy_Max, 0, sizeof(m_Phy_Max));

		memset(&m_Name, 0, sizeof(m_Name));

		memset(&m_Luck_Min, 0, sizeof(m_Luck_Min));

		memset(&m_Luck_Max, 0, sizeof(m_Luck_Max));

		memset(&m_Int_Min, 0, sizeof(m_Int_Min));

		memset(&m_Int_Max, 0, sizeof(m_Int_Max));

		memset(&m_Initiative, 0, sizeof(m_Initiative));

		memset(&m_Index, 0, sizeof(m_Index));

		memset(&m_Hp_Min, 0, sizeof(m_Hp_Min));

		memset(&m_Hp_Max, 0, sizeof(m_Hp_Max));

		memset(&m_Godliness, 0, sizeof(m_Godliness));

		memset(&m_Dex_Min, 0, sizeof(m_Dex_Min));

		memset(&m_Dex_Max, 0, sizeof(m_Dex_Max));

		memset(&m_Ambition, 0, sizeof(m_Ambition));

		memset(&m_Agi_Min, 0, sizeof(m_Agi_Min));

		memset(&m_Agi_Max, 0, sizeof(m_Agi_Max));

		memset(&m_Aggressive, 0, sizeof(m_Aggressive));

	}

	int& kitelyReference()
	{
		return m_kitely;
	}

	int kitely() const
	{
		return m_kitely;
	}

	void kitely(const int& _kitely)
	{
		m_kitely = _kitely;
	}

	int& Wis_MinReference()
	{
		return m_Wis_Min;
	}

	int Wis_Min() const
	{
		return m_Wis_Min;
	}

	void Wis_Min(const int& _Wis_Min)
	{
		m_Wis_Min = _Wis_Min;
	}

	int& Wis_MaxReference()
	{
		return m_Wis_Max;
	}

	int Wis_Max() const
	{
		return m_Wis_Max;
	}

	void Wis_Max(const int& _Wis_Max)
	{
		m_Wis_Max = _Wis_Max;
	}

	int& ThoughtfulReference()
	{
		return m_Thoughtful;
	}

	int Thoughtful() const
	{
		return m_Thoughtful;
	}

	void Thoughtful(const int& _Thoughtful)
	{
		m_Thoughtful = _Thoughtful;
	}

	int& TendencySumReference()
	{
		return m_TendencySum;
	}

	int TendencySum() const
	{
		return m_TendencySum;
	}

	void TendencySum(const int& _TendencySum)
	{
		m_TendencySum = _TendencySum;
	}

	int& TalentReference()
	{
		return m_Talent;
	}

	int Talent() const
	{
		return m_Talent;
	}

	void Talent(const int& _Talent)
	{
		m_Talent = _Talent;
	}

	int& Str_MinReference()
	{
		return m_Str_Min;
	}

	int Str_Min() const
	{
		return m_Str_Min;
	}

	void Str_Min(const int& _Str_Min)
	{
		m_Str_Min = _Str_Min;
	}

	int& Str_MaxReference()
	{
		return m_Str_Max;
	}

	int Str_Max() const
	{
		return m_Str_Max;
	}

	void Str_Max(const int& _Str_Max)
	{
		m_Str_Max = _Str_Max;
	}

	int& StatSumReference()
	{
		return m_StatSum;
	}

	int StatSum() const
	{
		return m_StatSum;
	}

	void StatSum(const int& _StatSum)
	{
		m_StatSum = _StatSum;
	}

	int& Speed_MinReference()
	{
		return m_Speed_Min;
	}

	int Speed_Min() const
	{
		return m_Speed_Min;
	}

	void Speed_Min(const int& _Speed_Min)
	{
		m_Speed_Min = _Speed_Min;
	}

	int& Speed_MaxReference()
	{
		return m_Speed_Max;
	}

	int Speed_Max() const
	{
		return m_Speed_Max;
	}

	void Speed_Max(const int& _Speed_Max)
	{
		m_Speed_Max = _Speed_Max;
	}

	int& Phy_MinReference()
	{
		return m_Phy_Min;
	}

	int Phy_Min() const
	{
		return m_Phy_Min;
	}

	void Phy_Min(const int& _Phy_Min)
	{
		m_Phy_Min = _Phy_Min;
	}

	int& Phy_MaxReference()
	{
		return m_Phy_Max;
	}

	int Phy_Max() const
	{
		return m_Phy_Max;
	}

	void Phy_Max(const int& _Phy_Max)
	{
		m_Phy_Max = _Phy_Max;
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

	int& Luck_MinReference()
	{
		return m_Luck_Min;
	}

	int Luck_Min() const
	{
		return m_Luck_Min;
	}

	void Luck_Min(const int& _Luck_Min)
	{
		m_Luck_Min = _Luck_Min;
	}

	int& Luck_MaxReference()
	{
		return m_Luck_Max;
	}

	int Luck_Max() const
	{
		return m_Luck_Max;
	}

	void Luck_Max(const int& _Luck_Max)
	{
		m_Luck_Max = _Luck_Max;
	}

	int& Int_MinReference()
	{
		return m_Int_Min;
	}

	int Int_Min() const
	{
		return m_Int_Min;
	}

	void Int_Min(const int& _Int_Min)
	{
		m_Int_Min = _Int_Min;
	}

	int& Int_MaxReference()
	{
		return m_Int_Max;
	}

	int Int_Max() const
	{
		return m_Int_Max;
	}

	void Int_Max(const int& _Int_Max)
	{
		m_Int_Max = _Int_Max;
	}

	int& InitiativeReference()
	{
		return m_Initiative;
	}

	int Initiative() const
	{
		return m_Initiative;
	}

	void Initiative(const int& _Initiative)
	{
		m_Initiative = _Initiative;
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

	int& Hp_MinReference()
	{
		return m_Hp_Min;
	}

	int Hp_Min() const
	{
		return m_Hp_Min;
	}

	void Hp_Min(const int& _Hp_Min)
	{
		m_Hp_Min = _Hp_Min;
	}

	int& Hp_MaxReference()
	{
		return m_Hp_Max;
	}

	int Hp_Max() const
	{
		return m_Hp_Max;
	}

	void Hp_Max(const int& _Hp_Max)
	{
		m_Hp_Max = _Hp_Max;
	}

	int& GodlinessReference()
	{
		return m_Godliness;
	}

	int Godliness() const
	{
		return m_Godliness;
	}

	void Godliness(const int& _Godliness)
	{
		m_Godliness = _Godliness;
	}

	int& Dex_MinReference()
	{
		return m_Dex_Min;
	}

	int Dex_Min() const
	{
		return m_Dex_Min;
	}

	void Dex_Min(const int& _Dex_Min)
	{
		m_Dex_Min = _Dex_Min;
	}

	int& Dex_MaxReference()
	{
		return m_Dex_Max;
	}

	int Dex_Max() const
	{
		return m_Dex_Max;
	}

	void Dex_Max(const int& _Dex_Max)
	{
		m_Dex_Max = _Dex_Max;
	}

	int& AmbitionReference()
	{
		return m_Ambition;
	}

	int Ambition() const
	{
		return m_Ambition;
	}

	void Ambition(const int& _Ambition)
	{
		m_Ambition = _Ambition;
	}

	int& Agi_MinReference()
	{
		return m_Agi_Min;
	}

	int Agi_Min() const
	{
		return m_Agi_Min;
	}

	void Agi_Min(const int& _Agi_Min)
	{
		m_Agi_Min = _Agi_Min;
	}

	int& Agi_MaxReference()
	{
		return m_Agi_Max;
	}

	int Agi_Max() const
	{
		return m_Agi_Max;
	}

	void Agi_Max(const int& _Agi_Max)
	{
		m_Agi_Max = _Agi_Max;
	}

	int& AggressiveReference()
	{
		return m_Aggressive;
	}

	int Aggressive() const
	{
		return m_Aggressive;
	}

	void Aggressive(const int& _Aggressive)
	{
		m_Aggressive = _Aggressive;
	}

private:
	int m_kitely;
	int m_Wis_Min;
	int m_Wis_Max;
	int m_Thoughtful;
	int m_TendencySum;
	int m_Talent;
	int m_Str_Min;
	int m_Str_Max;
	int m_StatSum;
	int m_Speed_Min;
	int m_Speed_Max;
	int m_Phy_Min;
	int m_Phy_Max;
	std::wstring m_Name;
	int m_Luck_Min;
	int m_Luck_Max;
	int m_Int_Min;
	int m_Int_Max;
	int m_Initiative;
	int m_Index;
	int m_Hp_Min;
	int m_Hp_Max;
	int m_Godliness;
	int m_Dex_Min;
	int m_Dex_Max;
	int m_Ambition;
	int m_Agi_Min;
	int m_Agi_Max;
	int m_Aggressive;
};

class ClassData : public light::Excel::Data
{
public:
	virtual bool Load()
	{
		Class Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, _T("./XML/Class.XML"));
		if( false == parser.File(_T("./XML/Class.XML")))
		{
			LOG_ERROR(_T("%s, Open() Failed. Path(./XML/Class.XML"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.Execute(_T("/ClassList")))
		{
			LOG_ERROR(_T("%s, Execute() Failed. /ClassList"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindElem(_T("Data")))
		{
			LOG_ERROR(_T("%s, Execute() Failed. Data"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Aggressive"), Instance.AggressiveReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.AggressiveReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Agi_Max"), Instance.Agi_MaxReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.Agi_MaxReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Agi_Min"), Instance.Agi_MinReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.Agi_MinReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Ambition"), Instance.AmbitionReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.AmbitionReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Dex_Max"), Instance.Dex_MaxReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.Dex_MaxReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Dex_Min"), Instance.Dex_MinReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.Dex_MinReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Godliness"), Instance.GodlinessReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.GodlinessReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Hp_Max"), Instance.Hp_MaxReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.Hp_MaxReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Hp_Min"), Instance.Hp_MinReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.Hp_MinReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Index"), Instance.IndexReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.IndexReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Initiative"), Instance.InitiativeReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.InitiativeReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Int_Max"), Instance.Int_MaxReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.Int_MaxReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Int_Min"), Instance.Int_MinReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.Int_MinReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Luck_Max"), Instance.Luck_MaxReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.Luck_MaxReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Luck_Min"), Instance.Luck_MinReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.Luck_MinReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Name"), Instance.NameReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.NameReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Phy_Max"), Instance.Phy_MaxReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.Phy_MaxReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Phy_Min"), Instance.Phy_MinReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.Phy_MinReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Speed_Max"), Instance.Speed_MaxReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.Speed_MaxReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Speed_Min"), Instance.Speed_MinReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.Speed_MinReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("StatSum"), Instance.StatSumReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.StatSumReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Str_Max"), Instance.Str_MaxReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.Str_MaxReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Str_Min"), Instance.Str_MinReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.Str_MinReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Talent"), Instance.TalentReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.TalentReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("TendencySum"), Instance.TendencySumReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.TendencySumReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Thoughtful"), Instance.ThoughtfulReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.ThoughtfulReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Wis_Max"), Instance.Wis_MaxReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.Wis_MaxReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("Wis_Min"), Instance.Wis_MinReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.Wis_MinReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.BindAttrib(_T("kitely"), Instance.kitelyReference()))
		{
			LOG_ERROR(_T("%s, BindAttrib() Failed. Instance.kitelyReference()"), __FUNCTIONW__);
			return false;
		}

		while (parser.Next())
		{
			m_Map.insert(std::map<int, Class>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, Class& Instance)
	{
		std::map<int, Class>::iterator it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, Class>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, Class> m_Map;
};

__declspec(selectany) ClassData ClassDataInstance;

} // ExcelData

