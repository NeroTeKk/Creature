#include "Creature.h"

Creature::Creature() : name("Default"), lifePoint(100), attack(50) {}

Creature::Creature(std::string n, int hp) : name(n), lifePoint(hp), attack(50) {}

Creature::Creature(std::string n, int hp, int atk) : name(n), lifePoint(hp), attack(atk) {}

std::string Creature::getName() {
    return name;
}

void Creature::setName(std::string n) {
    if (n.empty()) {
        std::cout << "Error: Empty name! " << std::endl;
        name = "Default";
    }
    else {
        name = n;
    }
}

int Creature::getLifePoint() {
    return lifePoint;
}

void Creature::setLifePoint(int hp) {
    if (hp > 100) {
        std::cout << "Too many life points, the creature is dead! " << std::endl;
        lifePoint = 100;
    }
    else if (hp <= 0) {
        std::cout << "Not enough life points, the creature is dead! " << std::endl;
        lifePoint = 100;
    }
    else {
        lifePoint = hp;
    }
}

int Creature::getAttack() {
    return attack;
}

void Creature::setAttack(int atk) {
    if (atk > 50) {
        std::cout << "Attack too powerful, the creature is dead! " << std::endl;
        attack = 50;
    }
    else if (atk <= 0) {
        std::cout << "Attack too weak, the creature is dead! " << std::endl;
        attack = 50;
    }
    else {
        attack = atk;
    }
}

void Creature::showInfos() {
    std::cout << "Name: " << name << ", Life Points: " << lifePoint << ", Attack: " << attack << std::endl;
}

void Creature::showInfosWithNumber(int number) {
    std::cout << "[" << number << "] Name: " << name << ", Life Points: " << lifePoint << ", Attack: " << attack << std::endl;
}

void Creature::attackCreature(Creature& other) {
    std::cout << name << " attacks " << other.getName() << " !" << std::endl;
    int damage = attack;
    other.setLifePoint(other.getLifePoint() - damage);

    if (other.getLifePoint() <= 0) {
        std::cout << other.getName() << " has been defeated!" << std::endl;
    }
    else {
        std::cout << other.getName() << " now has " << other.getLifePoint() << " remaining life points." << std::endl;
    }
}
