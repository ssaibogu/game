// ConsoleApplication14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
    srand(time(NULL));
    std::string user;
    std::string bot[3]{ "rock","paper","scissors" };
    for (int i = 0; i < 3;) {
            int b = rand() % 3;
            std::cin >> user;
        if (user == "scissors" && bot[b] == "paper" || user == "rock" && bot[b] == "scissors" || user == "paper" && bot[b] == "rock")
        {
            std::cout << "You Won!" << std::endl;
            i++;
        }
        else if (user == bot[b])
        {
            std::cout << "Draw." << std::endl;
        }
        else 
        {
            std::cout << "You Lost ;(" << std::endl;
        }
        std::cout << bot[b] << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
