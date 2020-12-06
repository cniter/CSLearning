#pragma once

#include <iostream>
#include <string>

// 抽象工厂模式：工厂模式使用继承，而抽象工厂使用组合

// ======== 原料 ==============

// 面团原料
class Dough
{
public:
	Dough() {};
	virtual ~Dough() {};

	virtual void Name() = 0;

private:

};

class ThickCrusDough : public Dough
{
public:
	ThickCrusDough() {};
	~ThickCrusDough() {};

	void Name() { std::cout << "ThickCrusDough.\t"; };

private:

};

class ThinCrusDough : public Dough
{
public:
	ThinCrusDough() {};
	~ThinCrusDough() {};

	void Name() { std::cout << "ThinCrusDough.\t"; };

private:

};

// 蛤蜊原料
class Clams
{
public:
	Clams() {};
	virtual ~Clams() {};

	virtual void Name() = 0;

private:

};

class FrozenClams : public Clams
{
public:
	FrozenClams() {};
	~FrozenClams() {};

	void Name() { std::cout << "FrozenClams.\t"; };

private:

};

class FreshClams : public Clams
{
public:
	FreshClams() {};
	~FreshClams() {};

	void Name() { std::cout << "FreshClams.\t"; };

private:

};

// ======= 原料工厂 =======
class PizzaIngredientFactory
{
public:
	PizzaIngredientFactory() {};
	virtual ~PizzaIngredientFactory() {};

	virtual std::shared_ptr<Dough> createDough() = 0;
	virtual std::shared_ptr<Clams> createClams() = 0;

private:

};

class NYPizzaIngredientFactory : public PizzaIngredientFactory
{
public:
	NYPizzaIngredientFactory() {};
	~NYPizzaIngredientFactory() {};

	std::shared_ptr<Dough> createDough() { return std::make_shared<ThinCrusDough>(); };
	std::shared_ptr<Clams> createClams() { return std::make_shared<FreshClams>(); };

private:

};

class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory
{
public:
	ChicagoPizzaIngredientFactory() {};
	~ChicagoPizzaIngredientFactory() {};

	std::shared_ptr<Dough> createDough() { return std::make_shared<ThickCrusDough>(); };
	std::shared_ptr<Clams> createClams() { return std::make_shared<FrozenClams>(); };

private:

};

class AbstractPizza
{
public:
	AbstractPizza() {};
	virtual ~AbstractPizza() {};

	virtual void prepare() = 0;
	virtual void bake() { std::cout << "Pizza baking.\n"; };
	virtual void cut() { std::cout << "Pizza cutting.\n"; };
	virtual void box() { std::cout << "Pizza boxed.\n"; };
	virtual void Name() = 0;

protected:
	std::shared_ptr<PizzaIngredientFactory> ingredient_factory;
	std::shared_ptr<Dough> dough;
	std::shared_ptr<Clams> clam;
};

class AbstractCheesePizza : public AbstractPizza
{
public:
	AbstractCheesePizza(std::shared_ptr<PizzaIngredientFactory> ingredient_factory) 
	{
		this->ingredient_factory = ingredient_factory;
	};
	~AbstractCheesePizza() {};

	void prepare()
	{
		dough = ingredient_factory->createDough();
		clam = ingredient_factory->createClams();
	}

	void Name() 
	{
		dough->Name();
		clam->Name();
		std::cout << "CheesePizza.\n";
	};

private:

};

class AbstractClamPizza : public AbstractPizza
{
public:
	AbstractClamPizza(std::shared_ptr<PizzaIngredientFactory> ingredient_factory)
	{
		this->ingredient_factory = ingredient_factory;
	};
	~AbstractClamPizza() {};

	void prepare()
	{
		dough = ingredient_factory->createDough();
		clam = ingredient_factory->createClams();
	}

	void Name()
	{
		dough->Name();
		clam->Name();
		std::cout << "ClamPizza.\n";
	};

private:

};

class PizzaStoreAbstractFactory
{
public:
	PizzaStoreAbstractFactory(std::shared_ptr<PizzaIngredientFactory> ingredient_factory)
	{
		this->ingredient_factory = ingredient_factory;
	};
	virtual ~PizzaStoreAbstractFactory() {};

	std::shared_ptr<AbstractPizza> orderPizza(std::string type)
	{
		std::shared_ptr<AbstractPizza> pizza = createPizza(type);

		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();
		pizza->Name();

		return pizza;
	}

	//virtual std::shared_ptr<AbstractPizza> createPizza(std::string type) = 0;

	std::shared_ptr<AbstractPizza> createPizza(std::string type)
	{
		std::shared_ptr<AbstractPizza> pizza = nullptr;

		if (type == "cheese")	pizza = std::make_shared<AbstractCheesePizza>(ingredient_factory);
		else if (type == "clam")	pizza = std::make_shared<AbstractClamPizza>(ingredient_factory);

		return pizza;
	}

private:
	std::shared_ptr<PizzaIngredientFactory> ingredient_factory;
};

//class AbstractNYStylePizzaStore : public PizzaStoreAbstractFactory
//{
//public:
//	AbstractNYStylePizzaStore() {};
//	~AbstractNYStylePizzaStore() {};
//
//	std::shared_ptr<AbstractPizza> createPizza(std::string type)
//	{
//		std::shared_ptr<PizzaIngredientFactory> ingredient_factory = std::make_shared<NYPizzaIngredientFactory>();
//		std::shared_ptr<AbstractPizza> pizza = nullptr;
//
//		if (type == "cheese")	pizza = std::make_shared<AbstractCheesePizza>(ingredient_factory);
//		else if (type == "clam")	pizza = std::make_shared<AbstractClamPizza>(ingredient_factory);
//
//		return pizza;
//	}
//
//private:
//
//};
//
//class AbstractChicagoStylePizzaStore : public PizzaStoreAbstractFactory
//{
//public:
//	AbstractChicagoStylePizzaStore() {};
//	~AbstractChicagoStylePizzaStore() {};
//
//	std::shared_ptr<AbstractPizza> createPizza(std::string type)
//	{
//		std::shared_ptr<PizzaIngredientFactory> ingredient_factory = std::make_shared<ChicagoPizzaIngredientFactory>();
//		std::shared_ptr<AbstractPizza> pizza = nullptr;
//
//		if (type == "cheese")	pizza = std::make_shared<AbstractCheesePizza>(ingredient_factory);
//		else if (type == "clam")	pizza = std::make_shared<AbstractClamPizza>(ingredient_factory);
//
//		return pizza;
//	}
//
//private:
//
//};

void AbstractFactoryMethodPatternTest()
{
	/*std::shared_ptr<PizzaStoreAbstractFactory> pizza_store = std::make_shared<AbstractNYStylePizzaStore>();
	pizza_store->orderPizza("clam");

	std::shared_ptr<PizzaStoreAbstractFactory> pizza_store_Chi = std::make_shared<AbstractChicagoStylePizzaStore>();
	pizza_store_Chi->orderPizza("cheese");*/

	std::shared_ptr<PizzaIngredientFactory> ingredient_factory = std::make_shared<ChicagoPizzaIngredientFactory>();
	std::shared_ptr<PizzaIngredientFactory> NY_ingredient_factory = std::make_shared<NYPizzaIngredientFactory>();
	auto pizza_store = std::make_shared<PizzaStoreAbstractFactory>(ingredient_factory);
	pizza_store->orderPizza("cheese");

	pizza_store = std::make_shared<PizzaStoreAbstractFactory>(NY_ingredient_factory);
	pizza_store->orderPizza("cheese");
}




