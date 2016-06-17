#include "stdafx.h"
#include "AppWindow.h"
#include "Utils.h"
#include "OneStepCheckersView.h"
#include "tinyfiledialogs.h"
#include <fstream>

namespace
{
const unsigned WINDOW_WIDTH = 800;
const unsigned WINDOW_HEIGHT = 600;
const unsigned MENU_BAR_HEIGHT = 20;
const unsigned WINDOW_STYLE = sf::Style::Titlebar | sf::Style::Close;
const int FRAME_SWITCH_INTERVAL = 1000;
}

CAppWindow::CAppWindow()
    : sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "One-Step Checkers", WINDOW_STYLE)
	
{
    m_menu = std::make_unique<CAppMenu>("File");
    m_menu->SetFrame(sf::FloatRect(0, 0, float(WINDOW_WIDTH), float(MENU_BAR_HEIGHT)));
    m_openActionId = m_menu->AddAction("Open...", std::bind(&CAppWindow::AskOpenInput, this));
    m_saveActionId = m_menu->AddAction("Save...", std::bind(&CAppWindow::AskSaveOutput, this));
	m_menu->SetActionEnabled(m_openActionId, true);
	m_menu->SetActionEnabled(m_saveActionId, false);
	m_font.loadFromFile("res/Ubuntu-R.ttf");
	m_button.Init(m_font, "Start");
	m_button.text.setCharacterSize(55);
	m_button.SetSize(sf::Vector2f(200, 150));
	m_button.SetPosition(sf::Vector2f(30, 250));
	m_button.handler = [&] { m_state = State::RunningDemo; };
    setFramerateLimit(60);
    setVerticalSyncEnabled(true);


}

CAppWindow::~CAppWindow()
{
    m_menu.reset();
}

void CAppWindow::EnterLoop()
{
    while (isOpen())
    {
        sf::Event event;
        while (pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                close();
                return;
            }
            m_menu->OnEvent(event);
			m_button.OnEvent(event);
        }

        clear(sf::Color(255, 208, 130));
        if (m_state != State::WaitingInput)
        {
            OnRunningDemo();
        }
        draw(*m_menu);
		if (m_checkersView)
		{
			draw(*m_checkersView);
			m_button.Draw(*this);
		}
        display();
    }
}

void CAppWindow::OnRunningDemo()
{
	if (m_state == State::RunningDemo && m_clock.getElapsedTime().asMilliseconds() >= FRAME_SWITCH_INTERVAL)
	{
		if (!m_checkersView->ProcessStep())
		{
			m_state = State::WaitingOutput;
			m_menu->SetActionEnabled(m_saveActionId, true);
		}
		else
		{
			m_clock.restart();
		}
		
	}
}


void CAppWindow::AskOpenInput()
{
    const char *filters[] = { "*.txt" };
    char const *result = tinyfd_openFileDialog("Select input file", "", 1, filters, "", false);
    // Пользователь отменил выбор файла.
    if (result == nullptr)
    {
        return;
    }

    std::ifstream in(result);
    if (!in.is_open())
    {
        tinyfd_messageBox("Error", "I/O error when reading input file", "ok", "error", 1);
    }
    else
    {
		m_checkers = std::make_unique<COneStepCheckers>(in);
		auto chiefPos = m_checkers->GetChiefCheckerPosition();
		auto blacksPos = (m_checkers->GetBlackPositions());
		m_checkersView = std::make_unique<COneStepCheckersView>(blacksPos, chiefPos);
		m_checkers->Connect(boost::bind(&COneStepCheckersView::UpdateStateData, &*m_checkersView, boost::placeholders::_1));
		m_checkersView->SetPosition(WINDOW_WIDTH / 2.f + 100, WINDOW_HEIGHT / 2.f);
		m_checkers->Run();
		m_button.SetVisible(true);
    }
}

void CAppWindow::AskSaveOutput()
{
    const char *filters[] = { "*.txt" };
    char const *result = tinyfd_saveFileDialog("Select output file", "", 1, filters, "");
    // Пользователь отменил выбор файла.
    if (result == nullptr)
    {
        return;
    }
    std::ofstream out(result);
    if (!out.is_open())
    {
        tinyfd_messageBox("Error", "I/O error when writing output file", "ok", "error", 1);
    }
    else
    {
		m_checkers->WriteResult(out);
        tinyfd_messageBox("Success", "File saved OK", "ok", "info", 1);
    }
}
