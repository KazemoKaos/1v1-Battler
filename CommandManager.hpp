//============================================================================
// Name        : CommandManager.hpp
// Author      : Tyler Nguyen
// Version     : 11/20/20
// Description : Program 3
//============================================================================
#pragma once
#ifndef CommandManager_hpp
#define CommandManager_hpp
#include <iostream>
#include "Stack.hpp"
#include "BattleMove.hpp"
using namespace std;

class CommandManager {
private:
    Stack<BattleMove*> stack;
public:
    CommandManager() : stack{ Stack<BattleMove*>() } {}

    void Execute(BattleMove* cmd, Actor* self, Actor* other) {
        cmd->Execute();
        stack.Push(cmd);
    }

    void Undo() {
        if (stack.IsEmpty()) {
            cout << "Nothing to undo." << endl;
            return;
        }
        BattleMove* cmd = stack.Top();
        cmd->Undo();
        delete stack.Top();
        stack.Pop();
    }

    ~CommandManager() {
        while (!stack.IsEmpty()) {
            delete stack.Top();
            stack.Pop();
        }
    }
};

#endif /* CommandManager_hpp */