/*
Title: Peahat.cpp
Author: Abel Bekele
Date: 11/15/23
Description: Implementation of the Peahat.h file. 
*/
#include "Peahat.h"

// Name: Peahat(string name, int health, int damage, string desc)
// Description: Creates a new Peahat
// Preconditions: None
// Postconditions: Can create a Peahat
Peahat::Peahat(string name, int health, int damage, string desc):
Enemy(name, health, damage, desc){}
// Name: SpecialAttack
// Description: Defines the Peahat's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Peahat::SpecialAttack(){
    cout << "A Peahat whips at you ferousciously" << endl;
    cout << "You take " << PEAHAT_SPECIAL << 
    " points of damage" << endl;
    return PEAHAT_SPECIAL;
    }