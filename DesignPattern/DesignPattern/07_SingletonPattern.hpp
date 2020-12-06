#pragma once

#include <iostream>

// 饿汉模式
class Singleton1
{
private:
	Singleton1() { std::cout << "An instance of Singleton1 is created." << std::endl; }
	Singleton1(const Singleton1&);

	static Singleton1 m_instance;

public:
	static Singleton1* getInstance()	// 创建并访问单例实例
	{
		return &m_instance;
	}

	void print() { std::cout << "Singleton1 Print" << std::endl; }
};

Singleton1 Singleton1::m_instance;	// 需要在cpp中或类定义体外定义单例实例



// 懒汉模式（全局静态变量-粗糙版）
class Singleton2
{
private:
	Singleton2() { std::cout << "An instance of Singleton2 is created." << std::endl; }
	Singleton2(const Singleton2&);

	static Singleton2 *m_instance;

public:
	static Singleton2* getInstance()	// 创建并访问单例实例
	{
		if (nullptr == m_instance)
		{
			//Lock();//借用其它类来实现，如boost
			if (nullptr == m_instance)
			{
				m_instance = new Singleton2;
			}
			//UnLock();
		}
		return m_instance;
	}

	static void destroy()	// 释放单例实例
	{
		if (nullptr != m_instance)
		{
			delete m_instance;
			m_instance = nullptr;
		}
	}

	void print() { std::cout << "Singleton2 Print" << std::endl; }
};

Singleton2 *Singleton2::m_instance = nullptr;	// 需要在cpp中或类定义体外定义单例实例



// 懒汉模式（局部静态变量-优化版）
class Singleton3
{
private:
	Singleton3() { std::cout << "An instance of Singleton3 is created." << std::endl; }
	Singleton3(const Singleton3&);
	Singleton3& operator=(const Singleton3&);

public:
	static Singleton3& getInstance()	// 创建并访问单例实例
	{
		static Singleton3 m_instance;
		return m_instance;
	}

	void print() { std::cout << "Singleton3 Print" << std::endl; }
};

void singletonPatternTest()
{
	Singleton1::getInstance()->print();
	Singleton2::getInstance()->print();
	Singleton3::getInstance().print();
}
