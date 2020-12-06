#pragma once

#include <iostream>
#include <string>

// 适配器模式：转换接口

class DuckInterface
{
public:
	DuckInterface() {};
	virtual ~DuckInterface() {};

	virtual void quack() = 0;
	virtual void fly() = 0;

private:

};

class GreenHeadDuck : public DuckInterface
{
public:
	GreenHeadDuck() {};
	~GreenHeadDuck() {};

	void quack()
	{
		std::cout << "quack!!!\n";
	}

	void fly()
	{
		std::cout << "flying!!!\n";
	}

private:

};

class TurkeyInterface
{
public:
	TurkeyInterface() {};
	virtual ~TurkeyInterface() {};

	virtual void gobble() = 0;
	virtual void fly() = 0;

private:

};

class WildTurkey : public TurkeyInterface
{
public:
	WildTurkey() {};
	~WildTurkey() {};

	void gobble()
	{
		std::cout << "gobble!!!\n";
	}

	void fly()
	{
		std::cout << "flying a short distance!!!\n";
	}

private:

};

class TurkeyAdapter : public DuckInterface
{
public:
	TurkeyAdapter(std::shared_ptr<TurkeyInterface> turkey) 
	{
		this->turkey = turkey;
	};
	~TurkeyAdapter() {};

	void quack()
	{
		turkey->gobble();
	}

	void fly()
	{
		for (int i = 0; i < 5; ++i)
		{
			turkey->fly();
		}
	}

private:
	std::shared_ptr<TurkeyInterface> turkey;
};

class TurkeyDuckAdapter : public DuckInterface, public TurkeyInterface
{
public:
	TurkeyDuckAdapter() {};
	~TurkeyDuckAdapter() {};

	void gobble()
	{
		std::cout << "gobble!!!\n";
	}

	void quack()
	{
		gobble();
	}

	void fly()
	{
		std::cout << "flying!!!\n";
	}
};

void adapterPatternTest()
{
	GreenHeadDuck green_head_duck;
	TurkeyDuckAdapter turkey2duck;

	std::shared_ptr<TurkeyInterface> turkey = std::make_shared<WildTurkey>();
	std::shared_ptr<DuckInterface> duck = std::make_shared<TurkeyAdapter>(turkey);

	green_head_duck.fly();
	green_head_duck.quack();

	duck->quack();
	duck->fly();

	turkey2duck.fly();
	turkey2duck.quack();
}
