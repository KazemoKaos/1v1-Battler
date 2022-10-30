//============================================================================
// Name        : MenuRunner.cpp
// Author      : Tyler Nguyen
// Version     : 11/20/20
// Description : Program 3
//============================================================================
#include "MenuRunner.hpp"
#include "ActorFactory.hpp"
#include "ActorFactory.hpp"
#include "Actor.hpp"
#include "Utils.hpp"
#include <string>
using namespace std;

void MenuRunner::displayMenu () {
    vector<Actor*> actors;
    CommandManager mgr;
    int play;

    cout << "Welcome to Battle Game!\n";
    cout << "Choose:\n 1) Battle!\n 2) Quit\n";
    cin >> play;

    switch (play) {

    case 1:

        while (actors.size() != 2) {
            if (actors.size() == 0) {
                cout << "Choose your character\n 1) Ghost\n 2) Knight\n";
            }
            else
            {
                cout << "Choose opponent character\n 1) Ghost\n 2) Knight\n";
            }

            int choice;
            cin >> choice;
            switch ((ActorType)choice) {
            case ActorType::Ghost1:
                actors.push_back(new Ghost("Ghost", 100));
                break;
            case ActorType::Knight1:
                actors.push_back(new Knight("Knight", 100));
                break;
            }
        }
        cout << "Starting Battle: \n" << endl;
        cout << "------------------------------------" << endl;
        cout << actors[0]->getName() << ", (" << actors[0]->getHealth() << "), ";
        cout << actors[1]->getName() << ", (" << actors[1]->getHealth() << ")\n";

        while (!actors[0]->IsDead() && !actors[1]->IsDead()) {

            auto GhostPlayer = Utils::actorDisplayName[ActorType::Ghost1];
            auto KnightPlayer = Utils::actorDisplayName[ActorType::Knight1];

            if (actors[0]->getName() == GhostPlayer) {

                int choice;
                cout << "Choose your move" << endl;
                cout << " 1) Spell\n 2) Curse\n 3) Undo\n";
                cin >> choice;

                switch (choice) {
                case 1: // Spell
                    actors[0]->DoMove(mgr, actors[0]->GetMoves()[0], actors[1]);
                    actors[1]->DoMove(mgr, actors[1]->GetMoves()[1], actors[0]);
                    break;
                case 2: // Curse
                    actors[0]->DoMove(mgr, actors[0]->GetMoves()[1], actors[1]);
                    actors[1]->DoMove(mgr, actors[1]->GetMoves()[0], actors[0]);
                    break;
                case 3:
                    mgr.Undo();
                    break;
                }

                cout << "[Player: " << actors[0]->getName() << ", (" << actors[0]->getHealth() << ")][Opponent: " << actors[1]->getName() << ", (" << actors[1]->getHealth() << ")]\n";
                if (actors[0]->IsDead()){
                    cout << "Winner is: " << (actors[1]->getName()) << endl;
                }
                else if (actors[1]->IsDead()) {
                    cout << "Winner is: " << (actors[0]->getName()) << endl;
                }
            }
            else if (actors[0]->getName() == KnightPlayer) {
                int choice;
                cout << "Choose your move" << endl;
                cout << " 1) Sword\n 2) Melee\n 3) Undo\n";
                cin >> choice;

                switch (choice) {
                case 1: // Sword
                    actors[0]->DoMove(mgr, actors[0]->GetMoves()[0], actors[1]);
                    actors[1]->DoMove(mgr, actors[1]->GetMoves()[1], actors[0]);
                    break;
                case 2: // Melee
                    actors[0]->DoMove(mgr, actors[0]->GetMoves()[1], actors[1]);
                    actors[1]->DoMove(mgr, actors[1]->GetMoves()[0], actors[0]);
                    break;
                case 3:
                    mgr.Undo();
                    break;
                }

                cout << "[Player: " << actors[0]->getName() << ", (" << actors[0]->getHealth() << ")][Opponent: " << actors[1]->getName() << ", (" << actors[1]->getHealth() << ")]\n";
                if (actors[0]->IsDead()) {
                    cout << "Winner is: " << (actors[1]->getName()) << endl;
                }
                else if (actors[1]->IsDead()) {
                    cout << "Winner is: " << (actors[0]->getName()) << endl;
                }
            }
        }

    case 2:
        break;
    }
  }


