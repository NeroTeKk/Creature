#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>

class Creature {
private:
    std::string name;
    int lifePoint;
    int attack;

public:
    Creature();
    Creature(std::string n, int hp);
    Creature(std::string n, int hp, int atk);

    std::string getName();
    void setName(std::string n);

    int getLifePoint();
    void setLifePoint(int hp);

    int getAttack();
    void setAttack(int atk);

    void showInfos();
    void showInfosWithNumber(int number);
    void attackCreature(Creature& other);
};

#endif // CREATURE_H
