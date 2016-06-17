#include "stdafx.h"
#include "OneStepCheckersView.h"
#include "Utils.h"

COneStepCheckersView::COneStepCheckersView(std::vector<SPosition> const & blackPosVec, SPosition const& chiefPos)
{
	CreateChiefChecker(chiefPos);
	CreateBlackCheckers(blackPosVec);
	InitBoard();
	InitText();
}


COneStepCheckersView::~COneStepCheckersView()
{
}

void COneStepCheckersView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	auto boardStates = states;
	boardStates.transform.translate(m_boardPos - sf::Vector2f(m_board.second.getSize() / 2u));
	auto countStates = boardStates;
	auto maxStates = boardStates;
	countStates.transform.translate(-260, 0);
	maxStates.transform.translate(-260, 50);
	target.draw(m_board.first, boardStates);
	target.draw(m_visCount, countStates);
	target.draw(m_visMax, maxStates);
	boardStates.transform.translate(BOARD_PADDING);
	target.draw(*m_chiefPtr, boardStates);
	for (auto const & blackPtr : m_blackCheckersPtr)
	{
		target.draw(*blackPtr, boardStates);
	}
}

void COneStepCheckersView::UpdateStateData(SStateData const & data)
{
	m_stateData.push(data);
}

void COneStepCheckersView::SetPosition(float x, float y)
{
	m_boardPos = sf::Vector2f(x, y);
}

bool COneStepCheckersView::ProcessStep()
{
	if (m_stateData.empty())
	{
		return false;
	}
	auto stateData = m_stateData.front();
	m_chiefPtr->SetPosition(stateData.chiefPos);
	m_visCount.setString("Eaten checkers: " + std::to_string(stateData.count));
	m_visMax.setString("Max eaten checkers: " + std::to_string(stateData.max));
	m_stateData.pop();
	return true;
}

void COneStepCheckersView::InitText()
{
	m_font.loadFromFile("res/Ubuntu-R.ttf");
	m_visCount.setFont(m_font);
	m_visCount.setCharacterSize(25);
	m_visCount.setColor(sf::Color(130, 81, 0));
	m_visMax.setFont(m_font);
	m_visMax.setCharacterSize(25);
	m_visMax.setColor(sf::Color(130, 81, 0));
	m_visCount.setString("Eaten checkers: 0");
	m_visMax.setString("Max eaten checkers: 0");
}

void COneStepCheckersView::InitBoard()
{
	m_board.second.loadFromFile("res/board.png");
	m_board.first.setTexture(m_board.second);
}

void COneStepCheckersView::CreateBlackCheckers(std::vector<SPosition> const & blackPosVec)
{
	for (size_t i = 0; i != blackPosVec.size(); i++)
	{
		m_blackCheckersPtr.push_back(std::make_unique<SCheckerView>("res/black.png"));
		m_blackCheckersPtr[i]->SetPosition(blackPosVec[i]);
	}
}

void COneStepCheckersView::CreateChiefChecker(SPosition const & chiefPos)
{
	m_chiefPtr = std::make_unique<SCheckerView>("res/white.png");
	m_chiefPtr->SetPosition(chiefPos);
}

COneStepCheckersView::SCheckerView::SCheckerView(std::string const & fileName)
{
	if (!m_texture.loadFromFile(fileName))
	{
		throw std::invalid_argument("Cannot load texture from file");
	}
	m_sprite.setTexture(m_texture);
}

void COneStepCheckersView::SCheckerView::SetPosition(SPosition const & pos)
{
	m_sprite.setPosition(pos.col * CELL_SIZE.x, pos.row * CELL_SIZE.y);
}

void COneStepCheckersView::SCheckerView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}
