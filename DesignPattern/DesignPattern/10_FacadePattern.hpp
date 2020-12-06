#pragma once

// ���ģʽ����װ���ӵĵײ�������򻯽ӿڣ��ýӿڸ��Ѻã���������ԭ��

// ���Ż�
class Amplifier
{
public:
	void on() { printf("the amp is on! \n"); }
	void setDvd(std::string dvd) { printf("the amp is %s mode! \n", dvd.c_str()); }
	void setSurroundSound() { printf("the amp is SurroundSound! \n"); }
	void setVolume(int volume) { printf("the amp'volum is %d! \n", volume); }
	void off() { printf("the amp is off! \n"); }
private:
};

// ����
class Tuner
{
public:

private:
};
// DVD������
class DvdPlayer
{
public:
	void on() { printf("the dvd is on! \n"); }
	void play(std::string movie) { printf("the dvd is playing %s! \n", movie.c_str()); }
	void stop() { printf("the dvd is stoped! \n"); }
	void eject() { printf("the dvd is ejected! \n"); }
	void off() { printf("the dvd is off! \n"); }
private:
};
// CD������
class CdPlayer
{
public:

private:
};
// ͶӰ��
class Projector
{
public:
	void on() { printf("the projector is on! \n"); }
	void wideScreenMode() { printf("the screen is wideScreenMode! \n"); }
	void off() { printf("the projector is off! \n"); }
private:
};
// ӰԺ�ƹ�
class TheaterLights
{
public:
	void dim(int percent) { printf("dim the lights %d \n", percent); }
	void on() { printf("the lights is on! \n"); }
private:
};
// ��Ļ
class Screen
{
public:
	void down() { printf("the screen is down! \n"); }
	void up() { printf("the screen is up! \n"); }
private:
};
// ���׻���
class PopcornPopper
{
public:
	void on() { std::cout << "the popper is on! \n"; }
	void pop() { std::cout << "the popper is starting pop! \n"; }
	void off() { std::cout << "the popper is off! \n"; }
private:
};

// ��ͥӰԺ���
class HomeTheaterFacade
{
public:
	HomeTheaterFacade(Amplifier amp
		, Tuner tuner
		, DvdPlayer dvd
		, CdPlayer cd
		, Projector projector
		, Screen screen
		, TheaterLights lights
		, PopcornPopper popper)
	{
		amp_ = amp;
		tuner_ = tuner;
		dvd_ = dvd;
		cd_ = cd;
		projector_ = projector;
		screen_ = screen;
		lights_ = lights;
		popper_ = popper;
	}

	~HomeTheaterFacade() {};

	void watchMovie(std::string movie)
	{
		printf("Get ready to watch a movie... \n"); 
		popper_.on();
		lights_.dim(10);
		screen_.down();
		projector_.on();
		projector_.wideScreenMode();
		amp_.on();
		amp_.setDvd("dvd");
		amp_.setSurroundSound();
		amp_.setVolume(5);
		dvd_.on();
		dvd_.play(movie);
	}

	void endMovie()
	{
		printf("Shutting movie theater down... \n");
		popper_.off();
		lights_.on();
		screen_.up();
		projector_.off();
		amp_.off();
		dvd_.eject();
		dvd_.off();
	}

private:
	Amplifier amp_;
	Tuner tuner_;
	DvdPlayer dvd_;
	CdPlayer cd_;
	Projector projector_;
	Screen screen_;
	TheaterLights lights_;
	PopcornPopper popper_;
};

void facadePatternTest()
{
	Amplifier amp;
	Tuner tuner;
	DvdPlayer dvd;
	CdPlayer cd;
	Projector projector;
	Screen screen;
	TheaterLights lights;
	PopcornPopper popper;
	HomeTheaterFacade a(amp, tuner, dvd, cd, projector, screen, lights, popper);
	a.watchMovie("Raiders of the lost Ark");
	a.endMovie();
}
