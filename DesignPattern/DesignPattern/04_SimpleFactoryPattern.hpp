#pragma once

#include <iostream>
#include <string>

// ¼òµ¥¹¤³§

class Pizza
{
public:
	Pizza() {};
	virtual ~Pizza() {};

	virtual void prepare() { std::cout << "Pizza Preparing.\n"; };
	virtual void bake() { std::cout << "Pizza baking.\n"; };
	virtual void cut() { std::cout << "Pizza cutting.\n"; };
	virtual void box() { std::cout << "Pizza boxed.\n"; };

	virtual void Name() = 0;
};

class CheesePizza : public Pizza
{
public:
	CheesePizza() {};
	~CheesePizza() {};

	void Name() { std::cout << "CheesePizza.\n"; };

private:

};

class PepperoniPizza : public Pizza
{
public:
	PepperoniPizza() {};
	~PepperoniPizza() {};

	void Name() { std::cout << "PepperoniPizza.\n"; };

private:

};

class ClamPizza : public Pizza
{
public:
	ClamPizza() {};
	~ClamPizza() {};

	void Name() { std::cout << "ClamPizza.\n"; };

private:

};

class VeggiePizza : public Pizza
{
public:
	VeggiePizza() {};
	~VeggiePizza() {};

	void Name() { std::cout << "VeggiePizza.\n"; };

private:

};

class SimplePizzaFactory
{
public:
	std::shared_ptr<Pizza> createPizza(std::string type)
	{
		std::shared_ptr<Pizza> pizza = nullptr;

		if (type == "cheese")	pizza = std::make_shared<CheesePizza>();
		else if (type == "pepperoni")	pizza = std::make_shared<PepperoniPizza>();
		else if (type == "clam")	pizza = std::make_shared<ClamPizza>();
		else if (type == "veggie")	pizza = std::make_shared<VeggiePizza>();

		return pizza;
	}
};

class PizzaStore
{
public:
	PizzaStore() {};
	~PizzaStore() {};

	PizzaStore(SimplePizzaFactory factory)
	{
		pizza_factory = factory;
	}

	std::shared_ptr<Pizza> orderPizza(std::string type)
	{
		std::shared_ptr<Pizza> pizza = pizza_factory.createPizza(type);

		pizza->Name();
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();

		return pizza;
	}

private:
	SimplePizzaFactory pizza_factory;
};


void simpleFactoryPatternTest()
{
	SimplePizzaFactory factory;
	PizzaStore store(factory);
	store.orderPizza("veggie");
}