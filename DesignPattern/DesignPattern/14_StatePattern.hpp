#pragma once

#include <iostream>

class State
{
public:
	State() {};
	virtual ~State() {};

	// ²åÈëÓ²±Ò
	virtual void insertQuarter() = 0;
	// ÍË»ØÓ²±Ò
	virtual void ejectQuarter() = 0;
	// ×ª¶¯Çú±ú
	virtual void turnCrank() = 0;
	// µ¯³öÌÇ¹û
	virtual void dispense() = 0;

private:

};

class NoQuarterState : public State
{
public:
	NoQuarterState() {};
	~NoQuarterState() {};

	void insertQuarter()
	{
		printf("You inserted a quarter\n");
	}

	void ejectQuarter()
	{
		printf("You haven't inserted a quarter\n");
	}

	void turnCrank()
	{
		printf("You turned, but there's no quarter\n");
	}

	void dispense()
	{
		printf("You need pay first\n");
	}

private:

};

class HasQuarterState : public State
{
public:
	HasQuarterState() {};
	~HasQuarterState() {};

	void insertQuarter()
	{
		printf("HasQuarterState\n");
	}

	void ejectQuarter()
	{
		printf("HasQuarterState\n");
	}

	void turnCrank()
	{
		printf("HasQuarterState\n");
	}

	void dispense()
	{
		printf("HasQuarterState\n");
	}

private:

};

class SoldOutState : public State
{
public:
	SoldOutState() {};
	~SoldOutState() {};

	void insertQuarter()
	{
		printf("SoldOutState\n");
	}

	void ejectQuarter()
	{
		printf("SoldOutState\n");
	}

	void turnCrank()
	{
		printf("SoldOutState\n");
	}

	void dispense()
	{
		printf("SoldOutState\n");
	}

private:

};

class SoldState : public State
{
public:
	SoldState() {};
	~SoldState() {};

	void insertQuarter()
	{
		printf("Please wait, we're already giving you a gumball\n");
	}

	void ejectQuarter()
	{
		printf("Sorry, you already turned the crank\n");
	}

	void turnCrank()
	{
		printf("Turing twince doesn't get you another gumball\n");
	}

	void dispense()
	{
		printf("A gumball comes rolling out the slot\n");
	}

private:

};

class WinnerState : public State
{
public:
	WinnerState() {};
	~WinnerState() {};

	void insertQuarter()
	{
		printf("WinnerState\n");
	}

	void ejectQuarter()
	{
		printf("WinnerState\n");
	}

	void turnCrank()
	{
		printf("WinnerState\n");
	}

	void dispense()
	{
		printf("WinnerState\n");
	}

private:

};

class GumballMachine
{
public:
	GumballMachine(int count) 
	{
		_count = count;
		if (_count > 0)
		{
			_state = std::make_shared<NoQuarterState>();
		}
	};
	~GumballMachine() {};

	void insertQuarter()
	{
		_state->insertQuarter();
		if (dynamic_cast<NoQuarterState*>(_state.get()))
		{
			_state = std::make_shared<HasQuarterState>();
		}
	}

	void ejectQuarter()
	{
		_state->ejectQuarter();
		if (dynamic_cast<HasQuarterState*>(_state.get()))
		{
			_state = std::make_shared<NoQuarterState>();
		}
	}

	void turnCrank()
	{
		_state->turnCrank();
		if (dynamic_cast<HasQuarterState*>(_state.get()))
		{
			if (_count >= 3)
			{
				_state = std::make_shared<WinnerState>();
			}
			else
			{
				_state = std::make_shared<SoldState>();
			}
			dispense();
		}
	}

	void dispense()
	{
		_state->dispense();
		_count--;
		if (dynamic_cast<WinnerState*>(_state.get()))
		{
			_count--;
		}
		if (_count < 1) {
			_state = std::make_shared<SoldOutState>();
		}
		else
		{
			_state = std::make_shared<NoQuarterState>();
		}
		
	}

	int getCount()
	{
		return _count;
	}

private:
	int _count = 0;
	std::shared_ptr<State> _state = std::make_shared<SoldOutState>();
};


void statePatternTest() 
{
	GumballMachine gumball(5);
	gumball.insertQuarter();
	//gumball.ejectQuarter();
	gumball.turnCrank();
	gumball.insertQuarter();
	//gumball.ejectQuarter();
	gumball.turnCrank();
	gumball.insertQuarter();
	//gumball.ejectQuarter();
	gumball.turnCrank();
	gumball.insertQuarter();
	//gumball.ejectQuarter();
	gumball.turnCrank();

	printf("%d", gumball.getCount());
}