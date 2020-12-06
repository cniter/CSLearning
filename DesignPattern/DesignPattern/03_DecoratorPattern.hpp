#pragma once

// 装饰者模式：饮料——配料模式，善用组合，不断给饮料添加新的配料，从而形成新的饮料。
// 具体实现方式为：使用调料对饮料一层层包裹，逐级增加调料，直到所有调料加完。

#include <iostream>
#include <string>

// ========== 公共饮料基类 ================
class Beverage
{
public:
	Beverage() : description("Unknown Beverage"), size(1) {};
	virtual ~Beverage() { std::cout << "delete Beverage \n"; };

	virtual std::string getDescription()
	{
		return description;
	}

	virtual double cost() = 0;

	virtual int getSize()
	{
		return size;
	}

	virtual void setSize(int s)
	{
		size = s;
	}

protected:
	std::string description;
	int size;

private:

};

// ======== 浓缩咖啡 ======================
class Espresso : public Beverage
{
public:
	Espresso() 
	{
		description = "Espresso";
	};
	~Espresso() { std::cout << "delete Espresso \n"; };

	double cost()
	{
		return 1.99;
	}

private:

};

// ======== 混合咖啡 ======================
class HouseBlend : public Beverage
{
public:
	HouseBlend()
	{
		description = "House Blend Coffee";
	};
	~HouseBlend() { std::cout << "delete HouseBlend \n"; };

	double cost()
	{
		return 0.89;
	}

private:

};


// ======== 所有的调料装饰者基类 =============
class CondimentDecorator : public Beverage
{
public:
	CondimentDecorator() {};
	~CondimentDecorator() { std::cout << "delete CondimentDecorator \n"; };

	virtual std::string getDescription() = 0;

	//virtual int getSize() = 0;
	//virtual void setSize(int s) = 0;

private:

};

// =========== 摩卡调料 ===============
class Mocha : public CondimentDecorator
{
public:
	Mocha(std::shared_ptr<Beverage> bvr)
	{
		beverage = bvr;
	};
	~Mocha() { std::cout << "delete Mocha \n"; };


	std::string getDescription() 
	{
		return beverage->getDescription() + ", Mocha";
	}

	double cost() 
	{
		return 0.2 + beverage->cost();
	}

protected:
	std::shared_ptr<Beverage> beverage;

private:

};

// =========== 奶泡调料 ===============
class Whip : public CondimentDecorator
{
public:
	Whip(std::shared_ptr<Beverage> bvr)
	{
		beverage = bvr;
	};
	~Whip() { std::cout << "delete Whip \n"; };


	std::string getDescription()
	{
		return beverage->getDescription() + ", Whip";
	}

	double cost()
	{
		return 0.1 + beverage->cost();
	}

protected:
	std::shared_ptr<Beverage> beverage;

private:

};

// =========== 豆浆调料 ===============
class Soy : public CondimentDecorator
{
public:
	Soy(std::shared_ptr<Beverage> bvr)
	{
		beverage = bvr;
	};
	~Soy() { std::cout << "delete Soy \n"; };


	std::string getDescription()
	{
		if (getSize() == 0)
		{
			return beverage->getDescription() + ", Soy(small)";
		}
		else if (getSize() == 1)
		{
			return beverage->getDescription() + ", Soy(middle)";
		}
		else //if (getSize() == 2)
		{
			return beverage->getDescription() + ", Soy(big)";
		}
		
	}

	double cost()
	{
		if (getSize() == 0)
		{
			return 0.10 + beverage->cost();
		}
		else if (getSize() == 1)
		{
			return 0.15 + beverage->cost();
		}
		else //if (getSize() == 2)
		{
			return 0.20 + beverage->cost();
		}
	}

protected:
	std::shared_ptr<Beverage> beverage;

private:

};


void decoratorPatternTest()
{
	std::shared_ptr<Beverage> es = std::make_shared<Espresso>();
	std::cout << es->getDescription() << " $" << es->cost() << std::endl;

	std::shared_ptr<Beverage> hb = std::make_shared<HouseBlend>();
	hb = std::make_shared<Soy>(hb);
	hb->setSize(2);
	hb = std::make_shared<Mocha>(hb);
	hb = std::make_shared<Soy>(hb);
	hb = std::make_shared<Whip>(hb);
	hb = std::make_shared<Mocha>(hb);
	std::cout << hb->getDescription() << " $" << hb->cost() << std::endl;
}