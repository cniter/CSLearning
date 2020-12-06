#pragma once

// 设计模式：以不变应万变，抽出变化的部分作为接口，面向接口编程，尽量使用组合，使用多态调用不同的接口

// 策略模式：抽出变化的部分作为一个公共接口，每一个变化的行为都作为一个单独的类，可随意增删变化的行为，动态实现相互替换变化行为
// 使用场景：下拉选择框使用另一种算法时

#include <iostream>

// ========== 飞的行为接口，即抽象类 ===============
class FlyBehavior
{
public:
	FlyBehavior() {};
	virtual ~FlyBehavior() {};

	virtual void fly() = 0;

private:

};

// 会飞
class FlyWithWings : public FlyBehavior
{
public:
	FlyWithWings() {};
	virtual ~FlyWithWings() {};

	void fly()
	{
		std::cout << "fly with wings!!!" << std::endl;
	}

private:

};

// 不会飞
class FlyNoWay : public FlyBehavior
{
public:
	FlyNoWay() {};
	~FlyNoWay() {};

	void fly()
	{
		std::cout << "fly no way!!!" << std::endl;
	}

private:

};

// 火箭
class FlyWithRocket : public FlyBehavior
{
public:
	FlyWithRocket() {};
	~FlyWithRocket() {};

	void fly()
	{
		std::cout << "fly with rocket!!!" << std::endl;
	}

private:

};



// ========== 叫的行为接口 =================
class QuackBehavior
{
public:
	QuackBehavior() {};
	virtual ~QuackBehavior() {};

	virtual void quack() = 0;

private:

};

// 呱呱叫
class Quack : public QuackBehavior
{
public:
	Quack() {};
	~Quack() {};

	void quack()
	{
		std::cout << "gua gua gua ~~~" << std::endl;
	}

private:

};

// 吱吱叫
class Squeak : public QuackBehavior
{
public:
	Squeak() {};
	~Squeak() {};

	void quack()
	{
		std::cout << "zhi zhi zhi ~~~" << std::endl;
	}

private:

};

// 不会叫
class MuteQuack : public QuackBehavior
{
public:
	MuteQuack() {};
	~MuteQuack() {};

	void quack()
	{
		std::cout << "quite！！！" << std::endl;
	}

private:

};



//  =========== 鸭基类 ======================
class Duck
{
public:
	Duck() {};
	virtual ~Duck() {};

	void setQuackBehavior(QuackBehavior *qb)
	{
		std::shared_ptr<QuackBehavior> quack_behavior(qb);
		_quack_behavior = quack_behavior;
	}

	void setFlyBehavior(FlyBehavior *fb)
	{
		std::shared_ptr<FlyBehavior> fly_behavior(fb);
		_fly_behavior = fly_behavior;
	}

	void performQuack()
	{
		_quack_behavior->quack();
	}

	void performFly()
	{
		_fly_behavior->fly();
	}

	std::shared_ptr<FlyBehavior> _fly_behavior;	// 多用组合，少用继承
	std::shared_ptr<QuackBehavior> _quack_behavior;

private:

};

// 绿头鸭，绿头，会飞，呱呱叫
class MallardDuck : public Duck
{
public:
	MallardDuck() 
	{
		std::cout << "this is mallard duck." << std::endl;
		std::shared_ptr<FlyWithWings> fly_behavior(new FlyWithWings());
		_fly_behavior = fly_behavior;
	};
	~MallardDuck() {};


private:
	
};

// 红头鸭，红头，会飞，呱呱叫
class RedHeadDuck : public Duck
{
public:
	RedHeadDuck() 
	{
		std::cout << "this is red head duck." << std::endl;
		std::shared_ptr<QuackBehavior> quack_behavior(new Quack());
		_quack_behavior = quack_behavior;
	};
	~RedHeadDuck() {};

private:

};

// 橡皮鸭，黄头，不会飞，吱吱叫
class RubberDuck : public Duck
{
public:
	RubberDuck() { std::cout << "this is rubber duck." << std::endl; };
	~RubberDuck() {};

private:

};

// 诱饵鸭，木头，不会飞，不会叫
class DecoyDuck : public Duck
{
public:
	DecoyDuck() { std::cout << "this is decoy duck." << std::endl; };
	~DecoyDuck() {};

private:

};

// 模型鸭，开始不会飞，加上火箭后会飞
class ModelDuck : public Duck
{
public:
	ModelDuck() 
	{
		std::cout << "this is model duck." << std::endl;
		std::shared_ptr<FlyNoWay> fly_behavior(new FlyNoWay());
		_fly_behavior = fly_behavior;
	};
	~ModelDuck() {};

private:

};

// 鸭鸣器
class DuckCall
{
public:
	DuckCall() 
	{
		std::cout << "this is duck call." << std::endl;
		std::shared_ptr<FlyNoWay> fly_behavior(new FlyNoWay());
		_fly_behavior = fly_behavior;

		std::shared_ptr<QuackBehavior> quack_behavior(new Quack());
		_quack_behavior = quack_behavior;
	};
	~DuckCall() {};

	void setQuackBehavior(QuackBehavior *qb)
	{
		std::shared_ptr<QuackBehavior> quack_behavior(qb);
		_quack_behavior = quack_behavior;
	}

	void setFlyBehavior(FlyBehavior *fb)
	{
		std::shared_ptr<FlyBehavior> fly_behavior(fb);
		_fly_behavior = fly_behavior;
	}

	void performQuack()
	{
		_quack_behavior->quack();
	}

	void performFly()
	{
		_fly_behavior->fly();
	}

private:
	std::shared_ptr<FlyBehavior> _fly_behavior;
	std::shared_ptr<QuackBehavior> _quack_behavior;
};



void strategyPatternTest()
{
	MallardDuck md;
	md.setFlyBehavior(new FlyWithWings);
	md.performFly();
	md.setQuackBehavior(new Quack);
	md.performQuack();

	RedHeadDuck rhd;
	rhd.setFlyBehavior(new FlyWithWings);
	rhd.performFly();
	rhd.setQuackBehavior(new Quack);
	rhd.performQuack();

	RubberDuck rd;
	rd.setFlyBehavior(new FlyNoWay);
	rd.performFly();
	rd.setQuackBehavior(new Squeak);
	rd.performQuack();
	
	DecoyDuck dd;
	dd.setFlyBehavior(new FlyNoWay);
	dd.performFly();
	dd.setQuackBehavior(new MuteQuack);
	dd.performQuack();

	ModelDuck mdd;
	mdd.performFly();
	mdd.setFlyBehavior(new FlyWithRocket);	// 动态改变飞行方式
	mdd.performFly();

	DuckCall dc;
	dc.performFly();
	dc.performQuack();
}

