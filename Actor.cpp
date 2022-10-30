//============================================================================
// Name        : Actor.cpp
// Author      : Tyler Nguyen
// Version     : 11/20/20
// Description : Program 3
//============================================================================
#include "Actor.hpp"
#include <iostream>
using namespace std;

void Actor::DoMove(CommandManager& mgr, MoveType moveType, Actor* other) {
	string MoveTypeStrings[5] = { "Spell", "Curse", "Sword", "Melee", "Heal" };
	cout << this->getName() << " used: " << MoveTypeStrings[static_cast<int>(moveType)] << endl;
	mgr.Execute(MoveFactory::BuildMove(moveType, this, other), this, other);
}

void Actor::Hit(int damage) {
	cout << this->getName() << ", (" << this->getHealth() << ") is hit with " << damage << " damage.\n";
	this->Health -= damage;
}

void Actor::Heal(int amount) {
	cout << this->getName() << ", (" << this->getHealth() << ") is healed by " << amount << " hp.\n";
	this->Health += amount;
}

const vector<MoveType> Actor::GetMoves() {
	return this->moves;
}

bool Actor::IsDead() {
	return this->Health <= 0;
}