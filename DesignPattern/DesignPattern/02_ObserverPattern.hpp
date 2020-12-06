#pragma once

// �۲���ģʽ��������������ݸı�ʱ���Զ�֪ͨ�����£����й۲��߶��󣬿�ʵ���Զ���ɾ�۲���

#include <iostream>
#include <list>


// ======= �۲��߽ӿ� ==========
class Observer
{
public:
	Observer() {};
	virtual ~Observer() { std::cout << "delete Observer \n"; };

	// ������������ʱ���������й۲�������
	virtual void update(double temp, double humidity, double pressure) = 0;

private:

};



// =========== ��ʾ�ӿ� ============
class DisplayElement
{
public:
	DisplayElement() {};
	virtual ~DisplayElement() { std::cout << "delete DisplayElement \n"; };

	// �ڲ��������ʾ
	virtual void display() = 0;

private:

};



// ========= ����ӿ� ===============
class Subject
{
public:
	Subject() {};
	virtual ~Subject() { std::cout << "delete Subject \n"; };

	// ��ӹ۲��߶���
	virtual void registerObserver(Observer *O) = 0;

	// ɾ���۲��߶���
	virtual void removeObserver(Observer *O) = 0;

	// ֪ͨ���й۲��߶���
	virtual void notifyObservers() = 0;

	void setChanged(bool T)
	{
		changed = T;
	}

	bool getChanged()
	{
		return changed;
	}

private:
	bool changed;
};


// �������ݶ���
class WeatherData : public Subject
{
public:
	WeatherData() {};
	~WeatherData() { std::cout << "delete WeatherData \n"; };

	void registerObserver(Observer *O)
	{
		_observers.push_back(O);
	}

	void removeObserver(Observer *O)
	{
		_observers.remove(O);
	}

	void notifyObservers()
	{
		if (getChanged())
		{
			for (auto iter = _observers.begin(); iter != _observers.end(); ++iter)
			{
				(*iter)->update(temperature_, humidity_, pressure_);
			}
		}
	}

	void measurementsChanged()
	{
		setChanged(true);
		notifyObservers();
	}

	void setMeasurements(double temp, double humidity, double pressure)
	{
		temperature_ = temp;
		humidity_ = humidity;
		pressure_ = pressure;
		measurementsChanged();
	}

	double getTemperature()
	{
		return temperature_;
	}

	double getHumidity()
	{
		return humidity_;
	}

	double getPressure()
	{
		return pressure_;
	}

private:
	std::list< Observer * > _observers;
	double temperature_;
	double humidity_;
	double pressure_;

};






// ��ǰ״�������
class CurrentConditionsDisplay : public Observer, public DisplayElement
{
public:
	CurrentConditionsDisplay(std::shared_ptr<Subject> subject)
	{
		_subject = subject;
		subject->registerObserver(this);
	};
	~CurrentConditionsDisplay() { std::cout << "delete CurrentConditionsDisplay \n"; };

	void update(double temp, double humidity, double pressure)
	{
		temperature_ = temp;
		humidity_ = humidity;
		pressure_ = pressure;
		display();
	}

	void display()
	{
		std::cout << "Current conditions: "
			<< "\n  temperature: " << temperature_
			<< "\n  humidity: " << humidity_
			<< "\n  pressure: " << pressure_ << "\n\n\n";
	}

private:
	std::shared_ptr<Subject> _subject;
	double temperature_;
	double humidity_;
	double pressure_;
};



// ����ͳ�Ʋ����
class StatisticsDisplay : public Observer, public DisplayElement
{
public:
	StatisticsDisplay(std::shared_ptr<Subject> subject)
	{
		_subject = subject;
		subject->registerObserver(this);
	};
	~StatisticsDisplay() { std::cout << "delete StatisticsDisplay \n"; };

	void update(double temp, double humidity, double pressure)
	{
		temperature_ = temp;
		humidity_ = humidity;
		pressure_ = pressure;
		display();
	}

	void display()
	{
		std::cout << "StatisticsDisplay conditions: "
			<< "\n  avg temperature: " << temperature_
			<< "\n  max temperature: " << humidity_
			<< "\n  min temperature: " << pressure_ << "\n\n\n";
	}

private:
	std::shared_ptr<Subject> _subject;
	double temperature_;
	double humidity_;
	double pressure_;
};


// ����Ԥ�������









void observerPatternTest()
{
	std::shared_ptr<WeatherData> wd = std::make_shared<WeatherData>();
	CurrentConditionsDisplay *ccd = new CurrentConditionsDisplay(wd);
	std::shared_ptr<CurrentConditionsDisplay> ccd_p(ccd);
	//CurrentConditionsDisplay *ccd2 = new CurrentConditionsDisplay(wd);
	//std::shared_ptr<CurrentConditionsDisplay> ccd_p2(ccd2);
	//CurrentConditionsDisplay ccd(wd);
	StatisticsDisplay sd(wd);
	wd->setMeasurements(80, 21, 30.4);
	wd->setMeasurements(82, 26, 29.2);
	wd->removeObserver(ccd);
	wd->setMeasurements(78, 30, 29.2);
	
}