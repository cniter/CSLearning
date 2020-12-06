#pragma once

#include <iostream>
#include <string>

#include "04_SimpleFactoryPattern.hpp"

// 工厂模式

class NYStyleCheesePizza : public Pizza
{
public:
	NYStyleCheesePizza() {};
	~NYStyleCheesePizza() {};

	void Name() { std::cout << "NYStyleCheesePizza.\n"; };

private:

};

class NYStylePepperoniPizza : public Pizza
{
public:
	NYStylePepperoniPizza() {};
	~NYStylePepperoniPizza() {};

	void Name() { std::cout << "NYStylePepperoniPizza.\n"; };

private:

};

class NYStyleClamPizza : public Pizza
{
public:
	NYStyleClamPizza() {};
	~NYStyleClamPizza() {};

	void Name() { std::cout << "NYStyleClamPizza.\n"; };

private:

};

class NYStyleVeggiePizza : public Pizza
{
public:
	NYStyleVeggiePizza() {};
	~NYStyleVeggiePizza() {};

	void Name() { std::cout << "NYStyleVeggiePizza.\n"; };

private:

};

class ChicagoStyleCheesePizza : public Pizza
{
public:
	ChicagoStyleCheesePizza() {};
	~ChicagoStyleCheesePizza() {};

	void Name() { std::cout << "ChicagoStyleCheesePizza.\n"; };

private:

};

class ChicagoStylePepperoniPizza : public Pizza
{
public:
	ChicagoStylePepperoniPizza() {};
	~ChicagoStylePepperoniPizza() {};

	void Name() { std::cout << "ChicagoStylePepperoniPizza.\n"; };

private:

};

class ChicagoStyleClamPizza : public Pizza
{
public:
	ChicagoStyleClamPizza() {};
	~ChicagoStyleClamPizza() {};

	void Name() { std::cout << "ChicagoStyleClamPizza.\n"; };

private:

};

class ChicagoStyleVeggiePizza : public Pizza
{
public:
	ChicagoStyleVeggiePizza() {};
	~ChicagoStyleVeggiePizza() {};

	void Name() { std::cout << "ChicagoStyleVeggiePizza.\n"; };

private:

};

class PizzaStoreFactory
{
public:
	PizzaStoreFactory() {};
	virtual ~PizzaStoreFactory() {};

	std::shared_ptr<Pizza> orderPizza(std::string type)
	{
		std::shared_ptr<Pizza> pizza = createPizza(type);

		pizza->Name();
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();

		return pizza;
	}

	virtual std::shared_ptr<Pizza> createPizza(std::string type) = 0;

private:

};

class NYStylePizzaStore : public PizzaStoreFactory
{
public:
	NYStylePizzaStore() {};
	~NYStylePizzaStore() {};

	std::shared_ptr<Pizza> createPizza(std::string type)
	{
		std::shared_ptr<Pizza> pizza = nullptr;

		if (type == "cheese")	pizza = std::make_shared<NYStyleCheesePizza>();
		else if (type == "pepperoni")	pizza = std::make_shared<NYStylePepperoniPizza>();
		else if (type == "clam")	pizza = std::make_shared<NYStyleClamPizza>();
		else if (type == "veggie")	pizza = std::make_shared<NYStyleVeggiePizza>();

		return pizza;
	}

private:

};

class ChicagoStylePizzaStore : public PizzaStoreFactory
{
public:
	ChicagoStylePizzaStore() {};
	~ChicagoStylePizzaStore() {};

	std::shared_ptr<Pizza> createPizza(std::string type)
	{
		std::shared_ptr<Pizza> pizza = nullptr;

		if (type == "cheese")	pizza = std::make_shared<ChicagoStyleCheesePizza>();
		else if (type == "pepperoni")	pizza = std::make_shared<ChicagoStylePepperoniPizza>();
		else if (type == "clam")	pizza = std::make_shared<ChicagoStyleClamPizza>();
		else if (type == "veggie")	pizza = std::make_shared<ChicagoStyleVeggiePizza>();

		return pizza;
	}

private:

};

void factoryMethodPatternTest()
{
	std::shared_ptr<PizzaStoreFactory> pizza_store = std::make_shared<NYStylePizzaStore>();
	pizza_store->orderPizza("clam");

	std::shared_ptr<PizzaStoreFactory> pizza_store_Chi = std::make_shared<ChicagoStylePizzaStore>();
	pizza_store_Chi->orderPizza("clam");
}