/*
Title: Sword.cpp
Author: Abel Bekele
Date: 11/15/23
Description: Implementation of the Sword.h file. 
*/
#include "Sword.h"

// Name: Sword(int damage)
// Description: Creates a new Sword
// Preconditions: None
// Postconditions: Can create a Sword
Sword::Sword(int damage):Weapon(damage) {}
// Name: SpecialAttack
// Description: Defines the Sword's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Sword::SpecialAttack(){

    // rand between (1 and m_damage) * 2
    int dam = (rand() % Weapon::GetDamage() + 1) * 2; 
    cout << "You slash twice with a sword!" << endl;
    cout << "You do " << dam << " points of damage"
    << endl;
    return dam;
}