/*
Title: Area.cpp
Author: Abel Bekele
Date: 11/15/23
Description: Implementation of the Area.h file. 
Brings the program all togehter. 
*/
#include "Area.h"

//Name: Area (Overloaded Constructor)
//Precondition: Must have valid input for each part of a area
// First int is the unique identifier for this particular area.
// The first string is the name of the area
// The second string is the description of the area
// The last four ints are the unique identifier for adjacent areas
//     (-1 = no path)
// North, East, South, and West
//Postcondition: Creates a new area
Area::Area(int id, string name, string desc, int north, int east, int south, int west){
    m_ID = id;
    m_name = name;
    m_desc = desc;
    m_direction[N] = north;
    m_direction[E] = east;
    m_direction[S] = south;
    m_direction[W] = west;
}
//Name: GetName
//Precondition: Must have valid area
//Postcondition: Returns area name as string
string Area::GetName(){return m_name;}
//Name: GetID
//Precondition: Must have valid area
//Postcondition: Returns area id as int
int Area::GetID(){return m_ID;}
//Name: GetDesc
//Precondition: Must have valid area
//Postcondition: Returns area desc as string
string Area::GetDesc(){return m_desc;}
//Name: CheckDirection
//Precondition: Must have valid area
//You pass it a char (N/n, E/e, S/s, or W/w) and if that is a valid exit it
//returns the ID of the area in that direction
//Postcondition: Returns id of area in that direction if the exit exists
//If there is no exit in that direction, returns -1
int Area::CheckDirection(char myDirection){
    switch(myDirection){ 
        case 'N':
        case 'n':
            return m_direction[N]; // returns north
            break;
        case 'E':
        case 'e':
            return m_direction[E]; // returns east
            break;
        case 'S':
        case 's':
            return m_direction[S]; // returns south
            break;
        case 'W':
        case 'w':
            return m_direction[W]; // returns west
            break;
        default:
            return -1; // if there's no exit
            break;
    }
}
//Name: PrintArea
//Precondition: Area must be complete
//Postcondition: Outputs the area name, area desc, then possible exits
void Area::PrintArea(){
    cout << m_name << endl << m_desc << endl;
    cout << "Possible exits: ";
    if (m_direction[N] != -1) { // if north
        cout << "N ";
    }
    if (m_direction[E] != -1) { // if east
        cout << "E ";
    }
    if (m_direction[S] != -1) { // if south
        cout << "S ";
    }
    if (m_direction[W] != -1) { // if west
        cout<< "W ";
    }
}