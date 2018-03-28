#ifndef GAME_H
#define GAME_H

#include <iostream>
using namespace std;

class game
{
	
	private:
		int whichgame;
		string name;
	  int randnum(int, int);
		void numgame();
		void lettergame();
		void bothgames();
		void menu();
	public:
		void start();
	
};

#endif