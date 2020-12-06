#pragma once

#include <iostream>

// ����ģʽ
class Singleton1
{
private:
	Singleton1() { std::cout << "An instance of Singleton1 is created." << std::endl; }
	Singleton1(const Singleton1&);

	static Singleton1 m_instance;

public:
	static Singleton1* getInstance()	// ���������ʵ���ʵ��
	{
		return &m_instance;
	}

	void print() { std::cout << "Singleton1 Print" << std::endl; }
};

Singleton1 Singleton1::m_instance;	// ��Ҫ��cpp�л��ඨ�����ⶨ�嵥��ʵ��



// ����ģʽ��ȫ�־�̬����-�ֲڰ棩
class Singleton2
{
private:
	Singleton2() { std::cout << "An instance of Singleton2 is created." << std::endl; }
	Singleton2(const Singleton2&);

	static Singleton2 *m_instance;

public:
	static Singleton2* getInstance()	// ���������ʵ���ʵ��
	{
		if (nullptr == m_instance)
		{
			//Lock();//������������ʵ�֣���boost
			if (nullptr == m_instance)
			{
				m_instance = new Singleton2;
			}
			//UnLock();
		}
		return m_instance;
	}

	static void destroy()	// �ͷŵ���ʵ��
	{
		if (nullptr != m_instance)
		{
			delete m_instance;
			m_instance = nullptr;
		}
	}

	void print() { std::cout << "Singleton2 Print" << std::endl; }
};

Singleton2 *Singleton2::m_instance = nullptr;	// ��Ҫ��cpp�л��ඨ�����ⶨ�嵥��ʵ��



// ����ģʽ���ֲ���̬����-�Ż��棩
class Singleton3
{
private:
	Singleton3() { std::cout << "An instance of Singleton3 is created." << std::endl; }
	Singleton3(const Singleton3&);
	Singleton3& operator=(const Singleton3&);

public:
	static Singleton3& getInstance()	// ���������ʵ���ʵ��
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
