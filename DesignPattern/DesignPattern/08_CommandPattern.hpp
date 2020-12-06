#pragma once

// 命令模式：封装调用，常见使用场景：撤销重做操作

#include <iostream>
#include <string>
#include <vector>

// 命令接口
class Command
{
public:
	Command() {};
	virtual ~Command() {};

	virtual void execute() = 0;
	virtual void undo() = 0;

private:

};

class EmptyCommand : public Command
{
public:
	EmptyCommand() {};
	~EmptyCommand() {};

	void execute() {};
	void undo() {};

private:

};

class OnOffCommand
{
public:
	OnOffCommand() {};
	virtual ~OnOffCommand() {};

	virtual void on() = 0;
	virtual void off() = 0;
private:

};

// 封装一条打开灯泡命令
class LightOnCommand : public Command
{
public:
	LightOnCommand() {};
	~LightOnCommand() {};

	LightOnCommand(std::shared_ptr<OnOffCommand> light)
	{
		this->onOffCommand = light;
	}

	void execute()
	{
		onOffCommand->on();
	}

	void undo()
	{
		onOffCommand->off();
	}

private:
	std::shared_ptr<OnOffCommand> onOffCommand;
};

class LightOffCommand : public Command
{
public:
	LightOffCommand() {};
	~LightOffCommand() {};

	LightOffCommand(std::shared_ptr<OnOffCommand> light)
	{
		this->onOffCommand = light;
	}

	void execute()
	{
		onOffCommand->off();
	}

	void undo()
	{
		onOffCommand->on();
	}

private:
	std::shared_ptr<OnOffCommand> onOffCommand;
};

class LivingRoomLight : public OnOffCommand
{
public:
	LivingRoomLight() {};
	~LivingRoomLight() {};

	void on() { std::cout << (std::string)(typeid(*this).name()) + " is On!\n"; };
	void off() { std::cout << (std::string)(typeid(*this).name()) + " is Off!\n"; };

private:

};

class KitchenLight : public OnOffCommand
{
public:
	KitchenLight() {};
	~KitchenLight() {};

	void on() { std::cout << (std::string)(typeid(*this).name()) + " is On!\n"; };
	void off() { std::cout << (std::string)(typeid(*this).name()) + " is Off!\n"; };

private:

};

class SimpleRemoteControl
{
public:
	SimpleRemoteControl() {};
	~SimpleRemoteControl() {};

	SimpleRemoteControl(std::shared_ptr<Command> command)
	{
		slot = command;
	}

	void setCommand(std::shared_ptr<Command> command)
	{
		slot = command;
	}

	void buttonWasPressed()
	{
		slot->execute();
	}

private:
	std::shared_ptr<Command> slot;
};

class RemoteControl
{
public:
	RemoteControl() 
	{
		onCommand.resize(2);
		offCommand.resize(2);
		for (size_t i = 0; i < onCommand.size(); i++)
		{
			onCommand[i] = std::make_shared<EmptyCommand>();
			offCommand[i] = std::make_shared<EmptyCommand>();
		}
	};
	~RemoteControl() {};

	void setCommand(int slot, std::shared_ptr<Command> on_command, std::shared_ptr<Command> off_command)
	{
		onCommand[slot] = on_command;
		offCommand[slot] = off_command;
	}

	void onButtonWasPushed(int slot)
	{
		onCommand[slot]->execute();
	}

	void offButtonWasPushed(int slot)
	{
		offCommand[slot]->execute();
	}

private:
	std::vector<std::shared_ptr<Command>> onCommand;
	std::vector<std::shared_ptr<Command>> offCommand;
};

class RemoteControlWithUndo
{
public:
	RemoteControlWithUndo()
	{
		onCommand.reserve(2);
		offCommand.reserve(2);
		std::shared_ptr<Command> empty_command = std::make_shared<EmptyCommand>();
		for (size_t i = 0; i < onCommand.capacity(); i++)
		{
			onCommand.push_back(empty_command);
			offCommand.push_back(empty_command);
		}
		undo_index = -1;
		undo_index_max = -1;
	};
	~RemoteControlWithUndo() {};

	void setCommand(int slot, std::shared_ptr<Command> on_command, std::shared_ptr<Command> off_command)
	{
		onCommand[slot] = on_command;
		offCommand[slot] = off_command;
	}

	void onButtonWasPushed(int slot)
	{
		onCommand[slot]->execute();

		undoFull();
		undoCommand[++undo_index] = onCommand[slot];
		++undo_index_max;
	}

	void offButtonWasPushed(int slot)
	{
		offCommand[slot]->execute();

		undoFull();
		undoCommand[++undo_index] = offCommand[slot];
		++undo_index_max;
	}

	void undoButtonWasPushed()
	{
		if (undo_index < 0)	return;
		undoCommand[undo_index--]->undo();
	}

	void redoButtonWasPushed()
	{
		if (undo_index >= undo_index_max) return;
		undoCommand[++undo_index]->execute();
	}

private:
	void undoFull()
	{
		if (undo_index >= undo_count-1)
		{
			for (int i = 1; i < undo_count; ++i)
			{
				undoCommand[i - 1] = undoCommand[i];
			}
			undo_index = undo_count-2;
			undo_index_max = undo_count - 2;
		}
	}

private:
	const static int undo_count = 1;
	std::vector<std::shared_ptr<Command>> onCommand;
	std::vector<std::shared_ptr<Command>> offCommand;
	std::shared_ptr<Command> undoCommand[undo_count];
	int undo_index;
	int undo_index_max;
};

void commandPatternTest()
{
	SimpleRemoteControl src(std::make_shared<LightOffCommand>(std::make_shared<KitchenLight>()));
	//src.buttonWasPressed();

	//RemoteControl rc;
	RemoteControlWithUndo rc;
	std::shared_ptr<OnOffCommand> living_room_light = std::make_shared<LivingRoomLight>();
	std::shared_ptr<OnOffCommand> kitchen_light = std::make_shared<KitchenLight>();
	rc.setCommand(0
		, std::make_shared<LightOnCommand>(living_room_light)
		, std::make_shared<LightOffCommand>(living_room_light));
	rc.setCommand(1
		, std::make_shared<LightOnCommand>(kitchen_light)
		, std::make_shared<LightOffCommand>(kitchen_light));
	rc.onButtonWasPushed(0);
	rc.offButtonWasPushed(0);
	rc.undoButtonWasPushed();
	rc.undoButtonWasPushed();
	rc.undoButtonWasPushed();
	rc.undoButtonWasPushed();
	rc.redoButtonWasPushed();
	rc.redoButtonWasPushed();
	rc.redoButtonWasPushed();
	rc.redoButtonWasPushed();
	rc.redoButtonWasPushed();
	rc.onButtonWasPushed(1);
	rc.undoButtonWasPushed();
	rc.offButtonWasPushed(1);
	
}