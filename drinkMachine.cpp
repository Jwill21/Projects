#include <iostream>
#include <string>
using namespace std;

struct drinkMachine {
    
    string name;
    float cost;
    int numDrinks;
};

int main (){
    int total = 0;
    string x;
    float change;
    int numDrinks;
    
    drinkMachine * nick = new drinkMachine[5];
    
    nick->name = "Cola";
    nick->cost = 0.75;
    nick->numDrinks = 20;
    (nick+1)->name = "Root Beer";
    (nick+1)->cost = 0.75;
    (nick+1)->numDrinks = 20;
    (nick+2)->name = "Lemon Lime";
    (nick+2)->cost = 0.75;
    (nick+2)->numDrinks = 20;
    (nick+3)->name = "Grape Soda";
    (nick+3)->cost = 0.80;
    (nick+3)->numDrinks = 20;
    (nick+4)->name = "Cream Soda";
    (nick+4)->cost = 0.80;
    (nick+4)->numDrinks = 20;

    while (x != "quit"){

        cout << nick->name << endl;
        cout << (nick+1)->name << endl;
        cout << (nick+2)->name << endl;
        cout << (nick+3)->name << endl;
        cout << (nick+4)->name << endl;
        cout << "Select a drink or type 'quit' to quit;" << endl;
        getline(cin, x);
        if (x == "quit"){
          break;
        }
    
     if (x == "Cola" || x == "Root Beer" || x == "Lemon Lime" || x== "Grape Soda" || x == "Cream Soda"){
      cout << "Enter amount of money";
      cin >> change;
    }   if (change > 1.00){
      cout << "Too much money, please insert $1.00";
      cin >> change;
    }
     if (x == "Cola" || x == "Root Beer" || x == "Lemon Lime"){
       cout << "Your change is 25 cents" << endl;;
       if (x == "Cola"){
         nick->numDrinks--;
         total = total + 1;
       }
       if (x == "Root Beer"){
         (nick+1)->numDrinks--;
          total = total + 1;
       }
       if (x == "Lemon Lime"){
         (nick+2)->numDrinks--;
          total = total + 1;
       }
     }
     if (x == "Grape Soda" || x == "Cream Soda"){
       cout << "Your change is 20 cents" << endl;;
     }
       if (x == "Grape Soda"){
         (nick+3)->numDrinks--;
          total = total + 1;
       }
       if (x == "Cream Soda"){
         (nick+4)->numDrinks--;
          total = total + 1;
       }
       if (nick->numDrinks == 0) {
         cout << "Sorry, we're sold out" << endl;
       }
       while (x == "Cola" || x == "Root Beer" || x == "Lemon Lime" || x== "Grape Soda" || x == "Cream Soda" || x == "Cola" || x == "Root Beer" || x == "Lemon Lime"){
         cout << "Would you like to make another selection?" << endl;
         cin >> x;
      
      } }
      cout << "The total made is $" << total << ", " << "thank you!";
    
    return 0;
} 
