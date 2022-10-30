//============================================================================
// Name        : Utils.hpp
// Author      : Tyler Nguyen
// Version     : 11/20/20
// Description : Program 3
//============================================================================
#pragma once
#ifndef Utils_hpp
#define Utils_hpp
#include <stdlib.h>
#include "enums.hpp"
#include <map>
#include <string>
using namespace std;

class Utils {
public:
	static map<ActorType, string> actorDisplayName;
};

#endif /* Utils_hpp */