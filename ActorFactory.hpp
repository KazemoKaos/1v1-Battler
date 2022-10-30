//============================================================================
// Name        : ActorFactory.hpp
// Author      : Tyler Nguyen
// Version     : 11/20/20
// Description : Program 3
//============================================================================
#pragma once
#ifndef ActorFactory_hpp
#define ActorFactory_hpp
#include "Actor.hpp"
#include "BattleMove.hpp"
#include "BattleMoveFactory.hpp"
#include "enums.hpp"
using namespace std;

class ActorFactory {
public:
    static Actor* CreateActor(ActorType actorType) {
        switch (actorType) {
        case ActorType::Ghost1:
            return new Ghost::Actor(100, "Ghost");
        case ActorType::Knight1:
            return new Knight::Actor(100, "Knight");
        }
    }
};
#endif /* Actor_Factory */