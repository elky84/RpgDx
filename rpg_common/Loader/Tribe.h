#pragma once

namespace ExcelData
{

class Tribe
{
public:
	Tribe()
	{
		memset(&m_Wisely, 0, sizeof(m_Wisely));

		memset(&m_Thoughtful, 0, sizeof(m_Thoughtful));

		memset(&m_TendencySum, 0, sizeof(m_TendencySum));

		memset(&m_Talent, 0, sizeof(m_Talent));

		memset(&m_Initiative, 0, sizeof(m_Initiative));

		memset(&m_Index, 0, sizeof(m_Index));

		memset(&m_Godliness, 0, sizeof(m_Godliness));

		memset(&m_Ambition, 0, sizeof(m_Ambition));

		memset(&m_Aggressive, 0, sizeof(m_Aggressive));

	}

	int& WiselyReference()
	{
		return m_Wisely;
	}

	int Wisely() const
	{
		return m_Wisely;
	}

	void Wisely(const int& _Wisely)
	{
		m_Wisely = _Wisely;
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
	int m_Wisely;
	int m_Thoughtful;
	int m_TendencySum;
	int m_Talent;
	std::wstring m_Name;
	int m_Initiative;
	int m_Index;
	int m_Godliness;
	int m_Ambition;
	int m_Aggressive;
};

class TribeData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		Tribe Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/Tribe.XML");
		if( false == parser.read_file(L"./XML/Tribe.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/Tribe.XML");
			return false;
		}

		if ( false == parser.execute(L"/TribeList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /TribeList");
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(L"%s, execute() Failed. Data");
			return false;
		}

		if ( false == parser.bind_attrib(L"Aggressive", Instance.AggressiveReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.AggressiveReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Ambition", Instance.AmbitionReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.AmbitionReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Godliness", Instance.GodlinessReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.GodlinessReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Index", Instance.IndexReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.IndexReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Initiative", Instance.InitiativeReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.InitiativeReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Name", Instance.NameReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.NameReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Talent", Instance.TalentReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.TalentReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"TendencySum", Instance.TendencySumReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.TendencySumReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Thoughtful", Instance.ThoughtfulReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.ThoughtfulReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Wisely", Instance.WiselyReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.WiselyReference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, Tribe>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, Tribe& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, Tribe>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, Tribe> m_Map;
};

__declspec(selectany) TribeData TribeDataInstance;

} // ExcelData

