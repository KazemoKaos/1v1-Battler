//============================================================================
// Name        : UndoableCommand.hpp
// Author      : Tyler Nguyen
// Version     : 11/20/20
// Description : Program 3
//============================================================================
#pragma once
#ifndef UndoableCommand_hpp
#define UndoableCommand_hpp

class UndoableCommand {
public:
	void virtual Execute() = 0;
	void virtual Undo() = 0;
	virtual ~UndoableCommand() {};
};

#endif /* UndoableCommand_hpp */