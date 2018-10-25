#pragma once

namespace ExcelData
{

class Name
{
public:
	Name()
	{
		memset(&m_Index, 0, sizeof(m_Index));

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
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/Name.XML");
		if( false == parser.read_file(L"./XML/Name.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/Name.XML");
			return false;
		}

		if ( false == parser.execute(L"/NameList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /NameList");
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(L"%s, execute() Failed. Data");
			return false;
		}

		if ( false == parser.bind_attrib(L"FirstName", Instance.FirstNameReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.FirstNameReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Index", Instance.IndexReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.IndexReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"LastName", Instance.LastNameReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.LastNameReference()");
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
		auto it = m_Map.find(key);
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

