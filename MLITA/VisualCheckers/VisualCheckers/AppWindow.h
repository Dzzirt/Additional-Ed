#pragma once
#include "stdafx.h"
#include "AppMenu.h"
#include "button.h"

class COneStepCheckers;
class COneStepCheckersView;

class CAppWindow : public sf::RenderWindow
{
public:
    CAppWindow();
    ~CAppWindow();

    void EnterLoop();

private:
    enum class State
    {
        WaitingInput,
        RunningDemo,
        WaitingOutput,
    };

    void OnRunningDemo();
    void AskOpenInput();
    void AskSaveOutput();

    State m_state = State::WaitingInput;
    sf::Clock m_clock;
    sf::Font m_font;
    sf::Texture m_activeFrame;
	std::unique_ptr<COneStepCheckers> m_checkers;
	std::unique_ptr<COneStepCheckersView> m_checkersView;
    std::unique_ptr<CAppMenu> m_menu;
	SCustomButton m_button;
    size_t m_openActionId = 0;
    size_t m_saveActionId = 0;
};
