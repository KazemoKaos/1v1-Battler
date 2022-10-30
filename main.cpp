//============================================================================
// Name        : main.cpp
// Author      : Tyler Nguyen
// Version     : 11/20/20
// Description : Program 3
//============================================================================
#include <iostream>
#include "MenuRunner.hpp"
using namespace std;

int main(int argc, const char* argv[]) {
	MenuRunner* run = new MenuRunner;
	run->displayMenu();
	delete run;
	return 0;
}