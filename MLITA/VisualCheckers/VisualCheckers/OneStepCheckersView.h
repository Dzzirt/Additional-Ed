#pragma once
#include "OneStepCheckers.h"

static const sf::Vector2f BOARD_PADDING = sf::Vector2f(18, 20);
static const sf::Vector2f CELL_SIZE = sf::Vector2f(50, 50);

class COneStepCheckersView : public sf::Drawable
{
public:
	COneStepCheckersView() = delete;
	COneStepCheckersView(std::vector<SPosition> const & blackPosVec, SPosition const& chiefPos);
	void SetPosition(float x, float y);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void UpdateStateData(SStateData const & data);
	bool ProcessStep();
	~COneStepCheckersView();
private:
	void InitText();
	void CreateChiefChecker(SPosition const & chiefPos);
	void CreateBlackCheckers(std::vector<SPosition> const & blackPosVec);
	void InitBoard();
	class SCheckerView : public sf::Drawable
	{
	public:
		SCheckerView() = delete;
		SCheckerView(std::string const & fileName);
		void SetPosition(SPosition const & pos);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	private:
		sf::Texture m_texture;
		sf::Sprite m_sprite;
	};
	std::queue<SStateData> m_stateData;

	sf::Vector2f m_boardPos;

	std::unique_ptr<SCheckerView> m_chiefPtr;
	std::vector<std::unique_ptr<SCheckerView>> m_blackCheckersPtr;
	std::pair<sf::Sprite, sf::Texture> m_board;

	sf::Text m_visMax;
	sf::Text m_visCount;
	sf::Font m_font;

};

