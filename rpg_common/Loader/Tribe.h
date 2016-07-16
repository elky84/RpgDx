#pragma once

namespace ExcelData
{

class Tribe
{
public:
	Tribe()
	{
		memset(&m_kitely, 0, sizeof(m_kitely));

		memset(&m_Thoughtful, 0, sizeof(m_Thoughtful));

		memset(&m_TendencySum, 0, sizeof(m_TendencySum));

		memset(&m_Talent, 0, sizeof(m_Talent));

		memset(&m_Name, 0, sizeof(m_Name));

		memset(&m_Initiative, 0, sizeof(m_Initiative));

		memset(&m_Index, 0, sizeof(m_Index));

		memset(&m_Godliness, 0, sizeof(m_Godliness));

		memset(&m_Ambition, 0, sizeof(m_Ambition));

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
	int m_kitely;
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
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, _T("./XML/Tribe.XML"));
		if( false == parser.read_file(_T("./XML/Tribe.XML")))
		{
			LOG_ERROR(_T("%s, Open() Failed. Path(./XML/Tribe.XML"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.execute(_T("/TribeList")))
		{
			LOG_ERROR(_T("%s, execute() Failed. /TribeList"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_elem(_T("Data")))
		{
			LOG_ERROR(_T("%s, execute() Failed. Data"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("Aggressive"), Instance.AggressiveReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.AggressiveReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("Ambition"), Instance.AmbitionReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.AmbitionReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("Godliness"), Instance.GodlinessReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.GodlinessReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("Index"), Instance.IndexReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.IndexReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("Initiative"), Instance.InitiativeReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.InitiativeReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("Name"), Instance.NameReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.NameReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("Talent"), Instance.TalentReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.TalentReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("TendencySum"), Instance.TendencySumReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.TendencySumReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("Thoughtful"), Instance.ThoughtfulReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.ThoughtfulReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("kitely"), Instance.kitelyReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.kitelyReference()"), __FUNCTIONW__);
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
		std::map<int, Tribe>::iterator it = m_Map.find(key);
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

