#include <iostream>
#include <memory>
#include <cassert>
#include <vector>
#include <functional>

using namespace std;

struct IFlyBehavior
{
	virtual ~IFlyBehavior() {};
	virtual void Fly() = 0;
};

struct IDanceBehavior
{
	virtual ~IDanceBehavior() {};
	virtual void Dance() = 0;
};

struct IQuackBehavior
{
	virtual ~IQuackBehavior() {};
	virtual void Quack() = 0;
};

class DanceWaltz: public IDanceBehavior
{
public:
	void operator()()
	{
		Dance();
	}
	void Dance() override
	{
		cout << "I dance the waltz" << endl;
	}
};

class DanceNoWay: public IDanceBehavior
{
public:
	void operator()()
	{
		Dance();
	}
	void Dance() override {}
};

class DanceMinuet : public IDanceBehavior
{
public:
	void operator()()
	{
		Dance();
	}
	void Dance() override
	{
		cout << "I dance the minuet" << endl;
	}
};

class FlyWithWings : public IFlyBehavior
{
public:
	FlyWithWings()
	{

	}
	void operator()()
	{
		Fly();
	}
	void Fly() override
	{
		counter++;
		cout << "I'm flying with wings!! I fly " << counter << " times." << endl;
	}
private:
	size_t counter = 0;
};

class FlyNoWay : public IFlyBehavior
{
public:
	void operator()()
	{
		Fly();
	}
	void Fly() override {}
};

class QuackBehavior : public IQuackBehavior
{
public:
	void operator()()
	{
		Quack();
	}
	void Quack() override
	{
		cout << "Quack Quack!!!" << endl;
	}
};
class SqueakBehavior : public IQuackBehavior
{
public:
	void operator()()
	{
		Quack();
	}
	void Quack() override
	{
		cout << "Squeek!!!" << endl;
	}
};

class MuteQuackBehavior : public IQuackBehavior
{
public:
	void operator()()
	{
		Quack();
	}
	void Quack() override{}
};

class Duck
{
public:
	Duck(std::function<void()> const& flyBehavior, std::function<void()> const& quackBehavior,
		std::function<void()> const& danceBehavior)
	{
		SetQuackBehavior(quackBehavior);
		SetFlyBehavior(flyBehavior);
		SetDanceBehavior(danceBehavior);
	}
	void Quack() const
	{
		m_quackBehavior();
	}
	void Swim()
	{
		cout << "I'm swimming" << endl;
	}
	void Fly()
	{
		m_flyBehavior();
	}
	virtual void Dance()
	{
		m_danceBehavior();
	}
	void SetFlyBehavior(std::function<void()> const& flyBehavior)
	{
		assert(flyBehavior);
		m_flyBehavior = flyBehavior;
	}
	void SetQuackBehavior(std::function<void()> const& quackBehavior)
	{
		assert(quackBehavior);
		m_quackBehavior = quackBehavior;
	}
	void SetDanceBehavior(std::function<void()> const& danceBehavior)
	{
		assert(danceBehavior);
		m_danceBehavior = danceBehavior;
	}
	virtual void Display() const = 0;
	virtual ~Duck() {};
private:
	std::function<void()> m_flyBehavior;
	std::function<void()> m_quackBehavior;
	std::function<void()> m_danceBehavior;
};

class MallardDuck : public Duck
{
public:
	MallardDuck()
		: Duck(FlyWithWings(), QuackBehavior(), DanceWaltz())
	{
	}

	void Display() const override
	{
		cout << "I'm mallard duck" << endl;
	}
};

class RedheadDuck : public Duck
{
public:
	RedheadDuck()
		: Duck(FlyWithWings(), QuackBehavior(), DanceMinuet())
	{
	}
	void Display() const override
	{
		cout << "I'm redhead duck" << endl;
	}
};
class DeckoyDuck : public Duck
{
public:
	DeckoyDuck()
		: Duck(FlyNoWay(), MuteQuackBehavior(), DanceNoWay())
	{
	}
	void Display() const override
	{
		cout << "I'm deckoy duck" << endl;
	}

};
class RubberDuck : public Duck
{
public:
	RubberDuck()
		: Duck(FlyNoWay(), QuackBehavior(), DanceNoWay())
	{
	}
	void Display() const override
	{
		cout << "I'm rubber duck" << endl;
	}
};

class ModelDuck : public Duck
{
public:
	ModelDuck()
		: Duck(FlyNoWay(), QuackBehavior(), DanceNoWay())
	{
	}
	void Display() const override
	{
		cout << "I'm model duck" << endl;
	}
	void Dance() override {}
};

void DrawDuck(Duck const& duck)
{
	duck.Display();
}

void PlayWithDuck(Duck & duck)
{
	duck.Quack();
	duck.Dance();
	duck.Fly();
	DrawDuck(duck);
}


void main()
{
	MallardDuck mallarDuck;
	PlayWithDuck(mallarDuck);
	PlayWithDuck(mallarDuck);
	PlayWithDuck(mallarDuck);
	RedheadDuck redheadDuck;
	PlayWithDuck(redheadDuck);
	RubberDuck rubberDuck;
	PlayWithDuck(rubberDuck);
	DeckoyDuck deckoyDuck;
	PlayWithDuck(deckoyDuck);
	ModelDuck modelDuck;
	PlayWithDuck(modelDuck);
	modelDuck.SetFlyBehavior(FlyNoWay());
	PlayWithDuck(modelDuck);
}