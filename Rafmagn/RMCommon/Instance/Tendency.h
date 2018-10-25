#pragma once

namespace Instance
{

class Tendency
{
public:
	Tendency()
	{
		memset(&m_Wisely, 0, sizeof(m_Wisely));

		memset(&m_Thoughtful, 0, sizeof(m_Thoughtful));

		memset(&m_Talent, 0, sizeof(m_Talent));

		memset(&m_Initiative, 0, sizeof(m_Initiative));

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
	int m_Talent;
	int m_Initiative;
	int m_Godliness;
	int m_Ambition;
	int m_Aggressive;
};


} // Instance

