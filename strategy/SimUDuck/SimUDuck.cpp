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
	void Dance() override
	{
		cout << "I dance the waltz" << endl;
	}
};

class DanceNoWay: public IDanceBehavior
{
public:
	void Dance() override {}
};

class DanceMinuet : public IDanceBehavior
{
public:
	void Dance() override
	{
		cout << "I dance the minuet" << endl;
	}
};

class Counter 
{
public:
	size_t Get()
	{

	}

	void operator++(int)
	{
		m_counter++;
	}
private:
	size_t m_counter = 0;

};
class FlyWithWings : public IFlyBehavior
{
public:
	FlyWithWings()
	{

	}
	void Fly() override
	{
		counter++;
		cout << "I'm flying with wings!! I fly " << counter.Get() << " times." << endl;
	}
private:
	Counter counter;
};

class FlyNoWay : public IFlyBehavior
{
public:
	void Fly() override {}
};

class QuackBehavior : public IQuackBehavior
{
public:
	void Quack() override
	{
		cout << "Quack Quack!!!" << endl;
	}
};
class SqueakBehavior : public IQuackBehavior
{
public:
	void Quack() override
	{
		cout << "Squeek!!!" << endl;
	}
};

class MuteQuackBehavior : public IQuackBehavior
{
public:
	void Quack() override{}
};

class Duck
{
public:
	Duck(std::function<void()> && func, unique_ptr<IQuackBehavior> && quackBehavior, 
unique_ptr<IDanceBehavior> && danceBehavior)
	{
		SetQuackBehavior(move(quackBehavior));
		SetFlyBehavior(move(func));
		SetDanceBehavior(move(danceBehavior));
	}
	void Quack() const
	{
		m_quackBehavior->Quack();
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
		m_danceBehavior->Dance();
	}
	void SetFlyBehavior(std::function<void()> && func)
	{
		//assert(flyBehavior);
		m_flyBehavior = func;
	}
	void SetQuackBehavior(unique_ptr<IQuackBehavior> && quackBehavior)
	{
		assert(quackBehavior);
		m_quackBehavior = move(quackBehavior);
	}
	void SetDanceBehavior(unique_ptr<IDanceBehavior> && danceBehavior)
	{
		assert(danceBehavior);
		m_danceBehavior = move(danceBehavior);
	}
	virtual void Display() const = 0;
	virtual ~Duck() {};
private:
	std::function<void()> m_flyBehavior;
	unique_ptr<IQuackBehavior> m_quackBehavior;
	unique_ptr<IDanceBehavior> m_danceBehavior;
};

void FlyWithWings()
{
	cout << "I'm flying with wings!!" << endl;
}

void FlyNoWay()
{

}
class MallardDuck : public Duck
{
public:
	MallardDuck()
		: Duck(move(FlyWithWings), make_unique<QuackBehavior>(), make_unique<DanceWaltz>())
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
		: Duck(move(FlyWithWings), make_unique<QuackBehavior>(), make_unique<DanceMinuet>())
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
		: Duck(move(FlyNoWay), make_unique<MuteQuackBehavior>(), make_unique<DanceNoWay>())
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
		: Duck(move(FlyNoWay), make_unique<QuackBehavior>(), make_unique<DanceNoWay>())
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
		: Duck(move(FlyNoWay), make_unique<QuackBehavior>(), make_unique<DanceNoWay>())
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
	modelDuck.SetFlyBehavior(move(FlyNoWay));
	PlayWithDuck(modelDuck);
}