#include <iostream>
#include <cstdlib> 
#include <ctime>    

using namespace std;

int main() 
{
   
    srand(time(0));
    

    int numberToGuess = rand() % 100 + 1;
    int playerGuess = 0;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << endl;
    cout << "I have selected a number between 1 and 100." << endl;


    while (playerGuess != numberToGuess) 
	{
        cout << "Enter your guess: ";
        cin >> playerGuess;
        attempts++;

        if (playerGuess > numberToGuess) 
		{
            cout << "Too high!" << endl;
        } 
		else if (playerGuess < numberToGuess) 
		{
            cout << "Too low!" << endl;
        } 
		else 
		{
            cout << "Congratulations! You guessed the number in " << attempts << " attempts!" << endl;
        }
    }

    return 0;
}

