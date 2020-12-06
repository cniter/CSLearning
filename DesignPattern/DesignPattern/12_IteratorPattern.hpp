#pragma once

#include <iostream>
#include <string>
#include <vector>

class MenuItem
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

	std::string getDesc()
	{
		return _description;
	}


private:
	std::string _name;
	std::string _description;
	bool _isVegetarian;
	double _price;
};

template<class T>
class Iterator
{
public:
	Iterator() {};
	virtual ~Iterator() {};

	virtual bool hasNext() = 0;
	virtual T next() = 0;

private:

};

class DinnerMenuIterator : public Iterator<MenuItem>
{
public:
	DinnerMenuIterator(MenuItem items[], int len)
	{
		menuItems = items;
		length = len;
	};
	~DinnerMenuIterator() {};

	bool hasNext()
	{
		if (_position >= length)
		{
			return false;
		}

		return true;
	}

	MenuItem next()
	{
		return menuItems[_position++];
	}

private:
	MenuItem *menuItems;
	int length;
	int _position = 0;
};




class PancakeHouseMenu
{
public:
	PancakeHouseMenu() 
	{
		addItem("Blueberry Pancakes", "Pancakes made with fresh blueberries", true, 3.49);
		addItem("Waffles", "Waffles", true, 3.59);
	};
	~PancakeHouseMenu() {};

	void addItem(std::string name, std::string description, bool isVegetarian, double price)
	{
		MenuItem menuItem(name, description, isVegetarian, price);
		_menuItems.push_back(menuItem);
	}

private:
	std::vector<MenuItem> _menuItems;
};

class DinnerMenu
{
public:
	DinnerMenu() 
	{
		addItem("BLT", "BLT", false, 3.49);
		addItem("Hotdog", "Hotdog", false, 3.05);
	};
	~DinnerMenu() {};

	void addItem(std::string name, std::string description, bool isVegetarian, double price)
	{
		MenuItem menuItem(name, description, isVegetarian, price);
		if (numberOfItems >= MAX_ITEMS)
		{
			std::cout << "Sorry, menu is full! Can't add item to menu. \n";
		}
		else
		{
			_menuItems[numberOfItems++] = menuItem;
		}
	}

	void printMenu()
	{
		DinnerMenuIterator iterator(_menuItems, numberOfItems);
		while (iterator.hasNext())
		{
			MenuItem menuItem = iterator.next();
			std::cout << menuItem.getName() << ". \n";
			std::cout << menuItem.getDesc() << ". \n";
		}
	}

private:
	static const int MAX_ITEMS = 6;
	int numberOfItems = 0;
	MenuItem _menuItems[MAX_ITEMS];
	//std::shared_ptr<MenuItem> _menuItems;
};


void iteratorPatternTest()
{
	PancakeHouseMenu pancakeHouseMenu;
	DinnerMenu dinnerMenu;

	dinnerMenu.printMenu();
}