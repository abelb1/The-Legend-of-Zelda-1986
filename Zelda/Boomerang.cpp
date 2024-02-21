/*
Title: Boomerang.cpp
Author: Abel Bekele
Date: 11/15/23
Description: Implementation of the Boomerang.h file. 
*/
#include "Boomerang.h"

// Name: Boomerang(int damage)
// Description: Creates a new Boomerang
// Preconditions: None
// Postconditions: Can create a Boomerang
Boomerang::Boomerang(int damage):Weapon(damage){}
// Name: SpecialAttack
// Description: Defines the Boomerang's special attack
// Chooses a random number between 1 and m_damage once then returns result*2
// If m_damage is 6, it would do two times between 1 and 6 so maybe 4 * 2
// Preconditions: None
// Postconditions: Returns damage from special attack
int Boomerang::SpecialAttack(){

    // Does between 1 and m_damage twice (once out and once back)
    int dam = rand() % Weapon::GetDamage() + 1;
    cout << "You throw a boomerang and it does "
    << dam << " damage on the way out and " <<
    dam << " damage on the way back!" << endl;
    return dam * 2;
}