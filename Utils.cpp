//============================================================================
// Name        : Utils.cpp
// Author      : Tyler Nguyen
// Version     : 11/20/20
// Description : Program 3
//============================================================================
#include "Utils.hpp"
#include "Actor.hpp"
using namespace std;

map<ActorType, string> Utils::actorDisplayName{
   {ActorType::Ghost1, "Ghost"},
   {ActorType::Knight1, "Knight"},
};
