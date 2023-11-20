#include "Creature.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

bool isYesOrNo(const std::string& response) {
    return response == "yes" || response == "no";
}

int main() {
    std::string userInput;
    bool createNewCreature = true;
    std::vector<Creature> creatures;

    std::cout << "Welcome to the creature creation lab Dr.Crazy !\n\n";

    while (createNewCreature) {
        std::cout << "Enter the name of the new creature : ";
        std::string userInputName;
        std::getline(std::cin, userInputName);

        int userInputLifePoints;
        do {
            std::cout << "Enter the new creature's health points (between 1 and 100): ";
            std::cin >> userInputLifePoints;
            if (std::cin.fail() || userInputLifePoints < 1 || userInputLifePoints > 100) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Error: Please enter a number between 1 and 100." << std::endl;
            }
            else {
                break;
            }
        } while (true);

        int userInputAttack;
        do {
            std::cout << "Enter the new creature's attack (between 1 and 50): ";
            std::cin >> userInputAttack;
            if (std::cin.fail() || userInputAttack < 1 || userInputAttack > 50) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Error: Please enter a number between 1 and 50." << std::endl;
            }
            else {
                break;
            }
        } while (true);

        Creature newCreature(userInputName, userInputLifePoints, userInputAttack);
        creatures.push_back(newCreature);

        std::cout << "\nNew monster infos ";
        newCreature.showInfos();

        do {
            std::cout << "\nDo you want to create another creature dr.Crazy ? (Yes/No): ";
            std::cin.ignore();
            std::getline(std::cin, userInput);
            std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

            if (!isYesOrNo(userInput)) {
                std::cout << "Error: Please enter 'Yes' or 'No'." << std::endl;
            }
            else {
                break;
            }

        } while (true);

        if (userInput == "no") {
            system("cls");

            if (creatures.size() == 1) {
                std::cout << "There is only one creature. Do you want to send this creature to destroy the city ? (Yes/No) : ";
                std::getline(std::cin, userInput);
                std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

                if (userInput == "yes") {
                    std::cout << "The creature has destroyed the city! End of program." << std::endl;
                    createNewCreature = false;
                }
                else {
                    std::cout << "The creature was spared. End of program." << std::endl;
                    createNewCreature = false;
                }
            }
            else if (creatures.size() > 1) {
                system("cls");

                std::cout << "List of available creatures:\n";
                for (size_t i = 0; i < creatures.size(); ++i) {
                    creatures[i].showInfosWithNumber(i + 1);
                }

                int creatureIndex;
                do {
                    std::cout << "Please enter the number of the creature to be cast on the city: ";
                    std::cin >> creatureIndex;
                    if (std::cin.fail() || creatureIndex < 1 || creatureIndex > static_cast<int>(creatures.size())) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Error: Please enter a valid number." << std::endl;
                    }
                    else {
                        break;
                    }
                } while (true);

                std::cout << "You chose to send the creature " << creatureIndex << " destroy the city!\n";
                std::cout << "Congrats' Dr.Crazy The city is destroyed! End of program." << std::endl;
                createNewCreature = false;
            }
        }
    }

    return 0;
}
