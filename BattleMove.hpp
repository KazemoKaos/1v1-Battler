//============================================================================
// Name        : BattleMove.hpp
// Author      : Tyler Nguyen
// Version     : 11/20/20
// Description : Program 3
//============================================================================
#pragma once
#ifndef BattleMove_hpp
#define BattleMove_hpp
#include "UndoableCommand.hpp"
using namespace std;

class Actor;

class BattleMove : public UndoableCommand {
public:
	BattleMove() {}
	void Execute() {}
	void Undo() {}
protected:
	Actor* self;
	Actor* other;
};

class SpellAttack : public BattleMove {
public:
	SpellAttack(Actor* self, Actor* other);
	void Execute();
	void Undo();
private:
	int DamageAmount;
};

class CurseAttack : public BattleMove {
public:
	CurseAttack(Actor* self, Actor* other);
	void Execute();
	void Undo();
private:
	int DamageAmount;
};

class SwordAttack : public BattleMove {
public:
	SwordAttack(Actor* self, Actor* other);
	void Execute();
	void Undo();
private:
	int DamageAmount;
};

class MeleeAttack : public BattleMove {
public:
	MeleeAttack(Actor* self, Actor* other);
	void Execute();
	void Undo();
private:
	int DamageAmount;
};

#endif /* BattleMove_hpp */