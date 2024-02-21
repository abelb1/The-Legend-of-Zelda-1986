/*
Title: Armos.cpp
Author: Abel Bekele
Date: 11/15/23
Description: Implementation of the Armos.h file. 
*/
#include "Armos.h"

// Name: Armos(string name, int health, int damage, string desc)
// Description: Creates a new Armos
// Preconditions: None
// Postconditions: Creates a new Armos
Armos::Armos(string name, int health, int damage, string desc):
Enemy(name, health, damage, desc){}
// Name: SpecialAttack
// Description: Defines the Armos's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Armos::SpecialAttack(){

    // m_damage + 2
    int dam = Enemy::GetDamage() + ARMOS_SPECIAL;
    cout << "The armos smashes you!" << endl;
    cout << "You take " << dam << " points of damage" << endl;
    return dam;
}
