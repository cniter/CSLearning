#pragma once

#include <iostream>
#include <string>
#include <vector>

class MenuComponent
{
public:
	MenuComponent() {};
	virtual ~MenuComponent() {};
	
	bool operator ==(MenuComponent rhs)
	{
		return getName() == rhs.getName();
	}

	virtual void add(MenuComponent menuComponet) {};
	virtual void remove(MenuComponent menuComponet) {};
	virtual MenuComponent* getChild(int i) { return nullptr; };
	virtual std::string getName() { return ""; };
	virtual std::string getDescription() { return ""; };
	virtual double getPrice() { return 0; };
	virtual bool isVegetarian() { return false; };
	virtual void print() {};

private:

};

class MenuItem : public MenuComponent
{
public:
	MenuItem() {};
	MenuItem(std::string name, std::string description, bool isVegetarian, double price)
	{
		_name = name;
		_description = description;
		_isVegetarian = isVegetarian;
		_price = price;
	};
	~MenuItem() {};

	std::string getName()
	{
		return _name;
	}

	std::string getDescription()
	{
		return _description;
	}

	double getPrice() { return _price; };
	bool isVegetarian() { return _isVegetarian; };
	void print() { std::cout << getName() << getPrice() << isVegetarian() << getDescription() << std::endl; };


private:
	std::string _name;
	std::string _description;
	bool _isVegetarian;
	double _price;
};



class Menu : public MenuComponent
{
public:
	Menu() {};
	Menu(std::string name, std::string description)
	{
		_name = name;
		_description = description;
	};
	~Menu() {};

	std::string getName()
	{
		return _name;
	}

	std::string getDescription()
	{
		return _description;
	}

	void add(MenuComponent *menuComponet) 
	{
		_menuItems.push_back(menuComponet);
	};
	void remove(MenuComponent menuComponet) 
	{
		for (auto iterator = _menuItems.begin(); iterator != _menuItems.end(); iterator++)
		{
			if (**iterator == menuComponet)
			{
				_menuItems.erase(iterator);
				break;
			}
		}
	};
	MenuComponent* getChild(int i) 
	{
		return _menuItems[i];
	};

	void print() 
	{ 
		std::cout << getName() << getDescription() << std::endl;

		for (auto iterator = _menuItems.begin(); iterator != _menuItems.end(); iterator++)
		{
			(*iterator)->print();
		}
	};


private:
	std::string _name;
	std::string _description;
	std::vector<MenuComponent*> _menuItems;
};

class Waitress
{
public:
	Waitress(MenuComponent *allMenus) 
	{
		_allMenus = allMenus;
	};
	~Waitress() {};

	void print()
	{
		_allMenus->print();
	}

private:
	MenuComponent *_allMenus;
};

void compositePatternTest()
{
	Menu pancakeHouseMenu("PANCAKE HOUSE Menu", "Breakfast");
	Menu dinerMenu("DINER MENU", "Lunch");
	Menu cafeMenu("CAFE Menu", "Dinner");
	Menu dessertMenu("DESSERT Menu", "Dessert");

	Menu allMenus("ALL Menu", "All menu combined");
	allMenus.add(&pancakeHouseMenu);
	allMenus.add(&dinerMenu);
	allMenus.add(&cafeMenu);
	
	MenuItem pasta("Pasta", "Spaghetti with Marinara ...", true, 3.89);
	MenuItem applePie("Apple Pie", "Apple pie with flakey ...", true, 1.59);

	dinerMenu.add(&pasta);
	dinerMenu.add(&dessertMenu);

	dessertMenu.add(&applePie);

	Waitress waitress(&allMenus);
	waitress.print();
}