#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<ios>     // for <streamsize>
#include<limits>  // for numeric_limits
#include "game.h"

using namespace std;


void game::menu()
{
	
	
	cout << "-------------------" << endl;
	cout << "(1) Guess Number" << endl;
	cout << "(2) Guess Letter " << endl;
	cout << "(3) Guess Number and Letter" << endl;
	cout << "(4) Quit" << endl;
	cout << "-------------------" << endl;
	cout << name << " please select a game: ";
	cin >> whichgame;
	system("clear");
}

void game::start()
{
	  cout << "Please enter your name: ";
    getline(cin,name);
		
	
	 do{
		menu();
		switch (whichgame)
		{
			case 1:
				numgame();
				break;
			case 2:
				lettergame();
				break;
			case 3:
				bothgames();
				break;
			case 4:
				break;
			default:
				cout << "Bad selection." << endl;
		}
	 
	 }while (whichgame != 4);
	
	
}



int game::randnum(int maxv, int minv)
{
    int y;
    unsigned seed = time(0);
    srand(seed);
    y = rand() % (maxv - minv + 1) + minv;
    return y;

}


void game::bothgames()
{
	
	char letter, guess_letter;
	int num, guess_num;
	letter = char(randnum('z','a'));
	num = randnum(100,0);
	bool won = false;
	
	for (int i=0; i < 5; i++)
	{
		
		cout << "Guess a lower case letter (from  a to z) and Guess a number (from 0 to 100): ";
		cin >> guess_letter >> guess_num;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		if (guess_letter == letter && guess_num == num)
		{
			 cout << "Hi " << name <<", you are correct.\n";
			 won = true;
       break;
		}
		else {
			
			 cout << "Hi " << name <<", ";
			
			 if (guess_letter == letter)
          cout << "the letter is correct, but ";
       else if (guess_letter < letter)
          cout << "the letter is too low, and ";
       else
          cout << "the letter is too hight, and ";
			
		   if (guess_num == num)
					cout << "the number is correct." << endl;
			 else if (guess_num < num)
				  cout << "the number is too low." << endl;
			 else
					cout << "the number is too high." << endl;				
			
		}
		
	}
	
	 
	 if (!won) 
	 	{ 
		 cout << "Hi " << name <<", you lost. The letter is (" << letter;
		 cout << ") and the number is (" << num <<")." << endl;
	  }
	
	
}

void game::lettergame()
{
	char letter, g;
	letter = char(randnum('z','a'));
	for (int i = 0; i <= 4; i++)
    {
        cout << "Guess a lower case letter from  a to z: ";
				cin >> g;

        cin.ignore(); // skips newline char from Keyboard buffer

        if (g == letter)
        {
            cout << "Hi " << name <<", you are correct.\n";
            break;
        }
        else if (g < letter)
        {
            cout << "Hi " << name << ", you are too low. \n ";
        }
        else
        {

            cout << "Hi " << name << ", you are too hight. \n";
        }
    }

  
	 if (g != letter) { cout << "Hi " << name <<", the answer is " << letter << endl;}
	
}

void game::numgame()
{
	  int num, g, i, s, e, a, b;
		
		s = 100;
		e = 0;
	
    if (s > e)
    	{a = e; b = s;}
		else
			{a = s; b = e;}
	
		num = randnum(b,a);
	   
	 for (i = 0; i <= 4; i++)
    {
        cout << "Guess a whole number between " << a << " and " << b << ": ";
        cin >> g;

        cin.ignore(); // skips newline char from Keyboard buffer

        if (g == num)
        {
            cout << "Hi " << name <<", you are correct.\n";
            break;
        }
        else if (g < num)
        {
            cout << "Hi " << name << ", you are too low. \n ";
        }
        else
        {

            cout << "Hi " << name << ", you are too hight. \n";
        }
    }

   if (g != num) { cout << "Hi " << name <<", the answer is " << num << endl;}
	
}


