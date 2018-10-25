#pragma once

namespace ExcelData
{

class Image
{
public:
	Image()
	{
		memset(&m_Index, 0, sizeof(m_Index));

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

private:
	std::wstring m_Name;
	int m_Index;
};

class ImageData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		Image Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/Image.XML");
		if( false == parser.read_file(L"./XML/Image.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/Image.XML");
			return false;
		}

		if ( false == parser.execute(L"/ImageList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /ImageList");
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(L"%s, execute() Failed. Data");
			return false;
		}

		if ( false == parser.bind_attrib(L"Index", Instance.IndexReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.IndexReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Name", Instance.NameReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.NameReference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, Image>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, Image& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, Image>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, Image> m_Map;
};

__declspec(selectany) ImageData ImageDataInstance;

} // ExcelData

