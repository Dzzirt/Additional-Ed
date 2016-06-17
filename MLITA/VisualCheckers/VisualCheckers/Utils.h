#pragma once

class CUtils
{
public:
    CUtils() = delete;

    static bool RunProcess(std::string const& command);
	static std::string GetResourcesRoot();
};

class CTransformTranslateScope
{
public:
	CTransformTranslateScope(sf::Transform &transform, sf::Vector2f delta)
		: m_transform(transform)
		, m_delta(delta)
	{
		m_transform.translate(m_delta.x, m_delta.y);
	}

	~CTransformTranslateScope()
	{
		m_transform.translate(-m_delta.x, -m_delta.y);
	}

private:
	sf::Transform &m_transform;
	sf::Vector2f m_delta;
};
