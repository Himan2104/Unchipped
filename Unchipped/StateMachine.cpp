#include "StateMachine.hpp"
#include<iostream>

StateMachine::StateMachine()
{
	currentState = nullptr;
}

StateMachine::~StateMachine()
{
}

StateMachine* StateMachine::access()
{
	static StateMachine SM;
	return &SM;
}

void StateMachine::changeState(State* newState)
{
	State* temp = currentState;
	currentState = newState;
	currentState->initialize();
	delete[] temp;
}

State* &StateMachine::getActiveState()
{
	return currentState;
}
