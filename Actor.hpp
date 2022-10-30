//============================================================================
// Name        : Actor.hpp
// Author      : Tyler Nguyen
// Version     : 11/20/20
// Description : Program 3
//============================================================================
#pragma once
#ifndef Actor_hpp
#define Actor_hpp
#include <iostream>
#include <vector>
#include <string>
#include "enums.hpp"
#include "CommandManager.hpp"
#include "BattleMoveFactory.hpp"
using namespace std;

class Actor {
private:
    string Name;
    int Health;
    vector<MoveType> moves;

protected:
    void addMove(MoveType move) { moves.push_back(move); }

public:
    Actor(int health, string name )
        : Health(health), Name(name)
    { }
    virtual void Hit(int damage);
    virtual void Heal(int amount);
    const vector<MoveType> GetMoves();
    bool IsDead();
    auto getName() const -> string { return this->Name; }
    auto getHealth() const -> int { return this->Health; }
    void DoMove(CommandManager& mgr, MoveType, Actor* other);
};

class Ghost : public Actor {
public:
    Ghost(string name, int health)
        : Actor(health, name)
    {
        addMove(MoveType::Spell);
        addMove(MoveType::Curse);
    }
};

class Knight : public Actor {
public:
    Knight(string name, int health)
        : Actor(health, name)
    {
        addMove(MoveType::Sword);
        addMove(MoveType::Melee);
    }
};

#endif /* Actor_hpp */
