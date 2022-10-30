//============================================================================
// Name        : BattleMove.cpp
// Author      : Tyler Nguyen
// Version     : 11/20/20
// Description : Program 3
//============================================================================
#include "Actor.hpp"
using namespace std;

SpellAttack::SpellAttack(Actor* self, Actor* other) {
	this->self = self;
	this->other = other;
}
void SpellAttack::Execute() {
	srand((unsigned int)time(NULL));
	int damage = rand() % 20 + 0;
	this->DamageAmount = damage;
	this->other->Hit(damage);
}
void SpellAttack::Undo() {
	this->other->Heal(DamageAmount);
}


CurseAttack::CurseAttack(Actor* self, Actor* other) {
	this->self = self;
	this->other = other;
}
void CurseAttack::Execute() {
	srand((unsigned int)time(NULL));
	int damage = rand() % 15 + 5;
	this->DamageAmount = damage;
	this->other->Hit(damage);
}
void CurseAttack::Undo() {
	this->other->Heal(DamageAmount);
}


SwordAttack::SwordAttack(Actor* self, Actor* other) {
	this->self = self;
	this->other = other;
}
void SwordAttack::Execute() {
	srand((unsigned int)time(NULL));
	int damage = rand() % 20 + 0;
	this->DamageAmount = damage;
	this->other->Hit(damage);
}
void SwordAttack::Undo() {
	this->other->Heal(DamageAmount);
}


MeleeAttack::MeleeAttack(Actor* self, Actor* other) {
	this->self = self;
	this->other = other;
}
void MeleeAttack::Execute() {
	srand((unsigned int)time(NULL));
	int damage = rand() % 15 + 5;
	this->DamageAmount = damage;
	this->other->Hit(damage);
}
void MeleeAttack::Undo() {
	this->other->Heal(DamageAmount);
}
