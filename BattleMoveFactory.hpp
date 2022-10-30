//============================================================================
// Name        : BattleMoveFactory.hpp
// Author      : Tyler Nguyen
// Version     : 11/20/20
// Description : Program 3
//============================================================================
#pragma once
#ifndef BattleMoveFactory_hpp
#define BattleMoveFactory_hpp
#include "enums.hpp"
#include "Actor.hpp"
#include "BattleMove.hpp"
using namespace std;

class MoveFactory {
public:
    static BattleMove* BuildMove(MoveType type, Actor* self, Actor* target) {
        BattleMove* battleMove = nullptr;
        switch (type) {
        case MoveType::Spell:
            battleMove = new SpellAttack(self, target);
            break;
        case MoveType::Curse:
            battleMove = new CurseAttack(self, target);
            break;
        case MoveType::Sword:
            battleMove = new SwordAttack(self, target);
            break;
        case MoveType::Melee:
            battleMove = new MeleeAttack(self, target);
            break;
        }
        return battleMove;
    }
};

#endif /* BattleMoveFactory_hpp */