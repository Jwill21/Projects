// guessing game program

// 1. ask for the name 
// 2. allow the user to enter 2 numbers to act as the range of numbers / should be able to handle in reverse order 
// 3. generate random number in that range 
// 4. ask the user by name, to guess a number in the range
// 5. give 5 tries to guess
// 6. provide feedback "too high" or "too low"
// 7. if they don't guess the number, show the user the number
// 8. ask if they want to play again, if so, run it back

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

bool play(bool);
bool getNums(int, int, bool, string);

int main(){
    bool on=true;
    unsigned seed = time(0);
    srand(seed);

    while(on==true){
        on=play(on);
    }
    return 0;
}

bool play(bool on){
    string name;
    int min;
    int max;
    
    cout << "Enter your name: " << endl;
    cin >> name;
    cout <<"Please enter the min... " << endl;
    cin >> min;
    cout << "Please enter the max..." << endl;
    cin >> max;

    on = getNums(min, max, on, name);
    return on;
}

bool getNums(int min, int max, bool on, string name){
    int guess;
    int rand();
    int num;
    char response;

    num = (rand() % (max - min + 1)) + min;

    for(int i=0; i < 5; i++){
    cout << "Enter a guess" << endl;
    cin >> guess;

    while (guess < min || guess > max){
    cout << "Sorry " << name << ", outside the range. Please re-enter your guess." << endl;
    cin >> guess;
   }

    if(guess > num)
      cout << "Too high." << endl;
 
    if(guess < num)
      cout << "Too low." << endl;

    if(guess == num) {
                cout << "Correct. Play again? (Y or N)" << endl;
                cin >> response;

                if (response == 'N'){
                    on = false;
                }
                if (response == 'Y'){
                    on = true;
                }
            }
        }

         if(guess!= num)
            {
            cout << "Sorry!" << name <<  ", the number was " << num << ". Play again?" << endl;
            cin >> response;

            if(response == 'N'){
                    on=false;
                }
            if(response == 'Y'){
                    on=true;
                }
            }
    return on;
}
