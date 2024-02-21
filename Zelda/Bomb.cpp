/*
Title: Bomb.cpp
Author: Abel Bekele
Date: 11/15/23
Description: Implementation of the Bomb.h file. 
*/
#include "Bomb.h"

// Name: Bomb(int damage)
// Description: Creates a new Bomb
// Preconditions: None
// Postconditions: Can create a Bomb
Bomb::Bomb(int damage):Weapon(damage){}
// Name: SpecialAttack
// Description: Defines the Bomb's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Bomb::SpecialAttack(){

    // between half m_damage and double m_damage
    int half = (Weapon::GetDamage()) / 2;
    int twice = (Weapon::GetDamage()) * 2;
    int random = rand() % twice + half;
    
    cout << "You throw a bomb and it explodes!"
    << endl;
    cout << "You do " << random << " points of damage" 
    << endl;
    return random;
}