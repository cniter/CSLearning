#pragma once

// ���ģʽ���Բ���Ӧ��䣬����仯�Ĳ�����Ϊ�ӿڣ�����ӿڱ�̣�����ʹ����ϣ�ʹ�ö�̬���ò�ͬ�Ľӿ�

// ����ģʽ������仯�Ĳ�����Ϊһ�������ӿڣ�ÿһ���仯����Ϊ����Ϊһ���������࣬��������ɾ�仯����Ϊ����̬ʵ���໥�滻�仯��Ϊ
// ʹ�ó���������ѡ���ʹ����һ���㷨ʱ

#include <iostream>

// ========== �ɵ���Ϊ�ӿڣ��������� ===============
class FlyBehavior
{
public:
	FlyBehavior() {};
	virtual ~FlyBehavior() {};

	virtual void fly() = 0;

private:

};

// ���
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

// �����
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

// ���
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



// ========== �е���Ϊ�ӿ� =================
class QuackBehavior
{
public:
	QuackBehavior() {};
	virtual ~QuackBehavior() {};

	virtual void quack() = 0;

private:

};

// ���ɽ�
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

// ֨֨��
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

// �����
class MuteQuack : public QuackBehavior
{
public:
	MuteQuack() {};
	~MuteQuack() {};

	void quack()
	{
		std::cout << "quite������" << std::endl;
	}

private:

};



//  =========== Ѽ���� ======================
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

	std::shared_ptr<FlyBehavior> _fly_behavior;	// ������ϣ����ü̳�
	std::shared_ptr<QuackBehavior> _quack_behavior;

private:

};

// ��ͷѼ����ͷ����ɣ����ɽ�
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

// ��ͷѼ����ͷ����ɣ����ɽ�
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

// ��ƤѼ����ͷ������ɣ�֨֨��
class RubberDuck : public Duck
{
public:
	RubberDuck() { std::cout << "this is rubber duck." << std::endl; };
	~RubberDuck() {};

private:

};

// �ն�Ѽ��ľͷ������ɣ������
class DecoyDuck : public Duck
{
public:
	DecoyDuck() { std::cout << "this is decoy duck." << std::endl; };
	~DecoyDuck() {};

private:

};

// ģ��Ѽ����ʼ����ɣ����ϻ������
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

// Ѽ����
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
	mdd.setFlyBehavior(new FlyWithRocket);	// ��̬�ı���з�ʽ
	mdd.performFly();

	DuckCall dc;
	dc.performFly();
	dc.performQuack();
}

