class CMyButton
{
public:
	typedef signals::signal<void(CMyButton & button)> ButtonClickSignal;
	signals::connection DoOnClick(const ButtonClickSignal::slot_type & handler)
	{
		return m_onClick.connect(handler);
	}

	// Вызывается при клике
	void HandleClick()
	{
		m_onClick(*this);
	}
private:
	ButtonClickSignal m_onClick;
};

class CController
{
public:
	CController(CMyButton & button)
		: m_button(button)
	{
		m_clickConnection = button.DoOnClick([](CMyButton & button)
		{
			std::cout « "clicked\n";
		});
	}
private:
	CMyButton & m_button;
	signals::scoped_connection m_clickConnection;
};

int _tmain(int argc, _TCHAR* argv[])
{
	CMyButton button;
	CController controleler(button);

	button.HandleClick();

	return 0;
}

#pragma warning (disable: 4503)