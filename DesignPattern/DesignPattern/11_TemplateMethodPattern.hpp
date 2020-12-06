#pragma once

#include <iostream>

class CaffeineBeverage
{
public:
	CaffeineBeverage() {};
	virtual ~CaffeineBeverage() {};

	void prepareRecipe()
	{
		boilWater();
		brew();
		pourInCup();
		addCondiments();

		if (isUseHook()) hook();
	}

	virtual void brew() = 0;
	virtual void addCondiments() = 0;

	void boilWater() { std::cout << "Boiling water \n"; };
	void pourInCup() { std::cout << "Pouring into cup \n"; };

	virtual bool isUseHook() { return true; }
	virtual void hook() { std::cout << "It's Hook \n"; };

private:

};

class Coffee : public CaffeineBeverage
{
public:
	Coffee() {};
	~Coffee() {};

	void brew() {
		brewCoffeeGrinds();
	}

	void addCondiments()
	{
		addSugarAndMilk();
	}

	
	void brewCoffeeGrinds() { std::cout << "Dripping Coffee through filter \n"; };
	
	void addSugarAndMilk() { std::cout << "Adding Sugar and Milk \n"; };

private:

};

class Tea : public CaffeineBeverage
{
public:
	Tea() {};
	~Tea() {};

	void brew()
	{
		steepTeaBag();
	}

	void addCondiments()
	{
		addLemon();
	}

	void steepTeaBag() { std::cout << "Steeping the Tea \n"; };
	void addLemon() { std::cout << "Adding Lemon \n"; };

	bool isUseHook()
	{
		bool a;
		std::cin >> a;
		if (a) return true;
		else	return false;
	}

private:

};

void templateMethodPatternTest()
{
	Coffee cof;
	cof.prepareRecipe();

	Tea tea;
	tea.prepareRecipe();
}
