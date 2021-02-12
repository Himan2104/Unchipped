#pragma once
#include<SFML/Graphics.hpp>
#include<stack>
#include<memory>
#include"State.hpp"

class StateMachine : sf::NonCopyable
{
public:
	StateMachine();
	~StateMachine();

	static StateMachine* access();

	void changeState(State* newState);
	State* &getActiveState();

private:
	State* currentState;
};

