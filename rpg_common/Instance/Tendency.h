#pragma once

namespace Instance
{

class Tendency
{
public:
	Tendency()
	{
		memset(&m_kitely, 0, sizeof(m_kitely));

		memset(&m_Thoughtful, 0, sizeof(m_Thoughtful));

		memset(&m_Talent, 0, sizeof(m_Talent));

		memset(&m_Initiative, 0, sizeof(m_Initiative));

		memset(&m_Godliness, 0, sizeof(m_Godliness));

		memset(&m_Ambition, 0, sizeof(m_Ambition));

		memset(&m_Aggressive, 0, sizeof(m_Aggressive));

	}

	int& kitely()
	{
		return m_kitely;
	}

	void kitely(const int& _kitely)
	{
		m_kitely = _kitely;
	}

	int& Thoughtful()
	{
		return m_Thoughtful;
	}

	void Thoughtful(const int& _Thoughtful)
	{
		m_Thoughtful = _Thoughtful;
	}

	int& Talent()
	{
		return m_Talent;
	}

	void Talent(const int& _Talent)
	{
		m_Talent = _Talent;
	}

	int& Initiative()
	{
		return m_Initiative;
	}

	void Initiative(const int& _Initiative)
	{
		m_Initiative = _Initiative;
	}

	int& Godliness()
	{
		return m_Godliness;
	}

	void Godliness(const int& _Godliness)
	{
		m_Godliness = _Godliness;
	}

	int& Ambition()
	{
		return m_Ambition;
	}

	void Ambition(const int& _Ambition)
	{
		m_Ambition = _Ambition;
	}

	int& Aggressive()
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
	int m_Talent;
	int m_Initiative;
	int m_Godliness;
	int m_Ambition;
	int m_Aggressive;
};


} // Instance
