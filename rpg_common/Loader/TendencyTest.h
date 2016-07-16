#pragma once

namespace ExcelData
{

class TendencyTest
{
public:
	TendencyTest()
	{
		m_Answer.resize(4);

		m_TendencyType.resize(4);

		m_TendencyValue.resize(4);

		memset(&m_Question, 0, sizeof(m_Question));

		memset(&m_Index, 0, sizeof(m_Index));

	}

	int& TendencyValue3Reference()
	{
		return m_TendencyValue[3];
	}

	std::vector<int>& VectorTendencyValue()
	{
		return m_TendencyValue;
	}

	int& TendencyValue2Reference()
	{
		return m_TendencyValue[2];
	}

	int& TendencyValue1Reference()
	{
		return m_TendencyValue[1];
	}

	int& TendencyValue0Reference()
	{
		return m_TendencyValue[0];
	}

	int& TendencyType3Reference()
	{
		return m_TendencyType[3];
	}

	std::vector<int>& VectorTendencyType()
	{
		return m_TendencyType;
	}

	int& TendencyType2Reference()
	{
		return m_TendencyType[2];
	}

	int& TendencyType1Reference()
	{
		return m_TendencyType[1];
	}

	int& TendencyType0Reference()
	{
		return m_TendencyType[0];
	}

	std::wstring& QuestionReference()
	{
		return m_Question;
	}

	std::wstring Question() const
	{
		return m_Question;
	}

	void Question(const std::wstring& _Question)
	{
		m_Question = _Question;
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

	std::wstring& Answer3Reference()
	{
		return m_Answer[3];
	}

	std::vector<std::wstring>& VectorAnswer()
	{
		return m_Answer;
	}

	std::wstring& Answer2Reference()
	{
		return m_Answer[2];
	}

	std::wstring& Answer1Reference()
	{
		return m_Answer[1];
	}

	std::wstring& Answer0Reference()
	{
		return m_Answer[0];
	}

private:
	std::vector<int> m_TendencyValue;
	std::vector<int> m_TendencyType;
	std::wstring m_Question;
	int m_Index;
	std::vector<std::wstring> m_Answer;
};

class TendencyTestData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		TendencyTest Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, _T("./XML/TendencyTest.XML"));
		if( false == parser.read_file(_T("./XML/TendencyTest.XML")))
		{
			LOG_ERROR(_T("%s, Open() Failed. Path(./XML/TendencyTest.XML"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.execute(_T("/TendencyTestList")))
		{
			LOG_ERROR(_T("%s, execute() Failed. /TendencyTestList"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_elem(_T("Data")))
		{
			LOG_ERROR(_T("%s, execute() Failed. Data"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("Answer0"), Instance.Answer0Reference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.Answer0Reference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("Answer1"), Instance.Answer1Reference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.Answer1Reference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("Answer2"), Instance.Answer2Reference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.Answer2Reference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("Answer3"), Instance.Answer3Reference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.Answer3Reference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("Index"), Instance.IndexReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.IndexReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("Question"), Instance.QuestionReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.QuestionReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("TendencyType0"), Instance.TendencyType0Reference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.TendencyType0Reference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("TendencyType1"), Instance.TendencyType1Reference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.TendencyType1Reference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("TendencyType2"), Instance.TendencyType2Reference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.TendencyType2Reference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("TendencyType3"), Instance.TendencyType3Reference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.TendencyType3Reference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("TendencyValue0"), Instance.TendencyValue0Reference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.TendencyValue0Reference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("TendencyValue1"), Instance.TendencyValue1Reference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.TendencyValue1Reference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("TendencyValue2"), Instance.TendencyValue2Reference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.TendencyValue2Reference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(_T("TendencyValue3"), Instance.TendencyValue3Reference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.TendencyValue3Reference()"), __FUNCTIONW__);
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, TendencyTest>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, TendencyTest& Instance)
	{
		std::map<int, TendencyTest>::iterator it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, TendencyTest>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, TendencyTest> m_Map;
};

__declspec(selectany) TendencyTestData TendencyTestDataInstance;

} // ExcelData

