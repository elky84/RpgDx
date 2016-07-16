#pragma once

namespace ExcelData
{

class Name
{
public:
	Name()
	{
		memset(&m_LastName, 0, sizeof(m_LastName));

		memset(&m_Index, 0, sizeof(m_Index));

		memset(&m_FirstName, 0, sizeof(m_FirstName));

	}

	std::wstring& LastNameReference()
	{
		return m_LastName;
	}

	std::wstring LastName() const
	{
		return m_LastName;
	}

	void LastName(const std::wstring& _LastName)
	{
		m_LastName = _LastName;
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

	std::wstring& FirstNameReference()
	{
		return m_FirstName;
	}

	std::wstring FirstName() const
	{
		return m_FirstName;
	}

	void FirstName(const std::wstring& _FirstName)
	{
		m_FirstName = _FirstName;
	}

private:
	std::wstring m_LastName;
	int m_Index;
	std::wstring m_FirstName;
};

class NameData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		Name Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, _T("./XML/Name.XML"));
		if( false == parser.read_file(_T("./XML/Name.XML")))
		{
			LOG_ERROR(_T("%s, Open() Failed. Path(./XML/Name.XML"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.execute(_T("/NameList")))
		{
			LOG_ERROR(_T("%s, execute() Failed. /NameList"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_elem(_T("Data")))
		{
			LOG_ERROR(_T("%s, execute() Failed. Data"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("FirstName"), Instance.FirstNameReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.FirstNameReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("Index"), Instance.IndexReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.IndexReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("LastName"), Instance.LastNameReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.LastNameReference()"), __FUNCTIONW__);
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, Name>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, Name& Instance)
	{
		std::map<int, Name>::iterator it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, Name>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, Name> m_Map;
};

__declspec(selectany) NameData NameDataInstance;

} // ExcelData

