/*
Title: Game.cpp
Author: Abel Bekele
Date: 11/15/23
Description: Implementation of the Game.h file. 
Brings the program all togehter. 
*/
#include "Game.h"

// Name: Game(string filename) - Overloaded Constructor
// Description: Creates a new Game
// Preconditions: None
// Postconditions: Initializes all game variables to defaults (constants)
// including m_myHero (null), m_curEnemy (null), filename (passed value),
// and starting area (START_AREA)
Game::Game(string filename){
    m_filename = filename;
    m_myHero = nullptr;
    m_curEnemy = nullptr;
    m_curArea = START_AREA;
}
// Name: ~Game
// Description: Destructor
// Preconditions: None
// Postconditions: Deallocates anything dynamically allocated
//                 in Game (weapons, enemies, and map)
Game::~Game(){

    // deallocating everything
    delete m_myHero;
    m_myHero = nullptr;
    delete m_curEnemy;
    m_curEnemy = nullptr;
    for(unsigned int i = 0; i < m_myMap.size(); i++){
        delete m_myMap.at(i);
        m_myMap.at(i) = nullptr;
    }
    m_myMap.resize(0);
}
// Name: LoadMap()
// Description: Dynamically creates areas and inserts them into
//              the m_myMap vector
// Note: the size of the map is not known - you should not use constants
//       Also, you can use stoi to convert strings to integers
// Precondition: m_filename is populated
// Postcondition: Map is populated with area objects.
void Game::LoadMap(){
    string id, name, desc, north, east, south, west;
    ifstream file(m_filename);

    if(!file.is_open()){
        cout<< "file isn't open." << endl;
    } else{

        // getting all the files lines
        while(getline(file, id, DELIMITER) && getline(file, name, DELIMITER) &&
        getline(file, desc, DELIMITER) && getline(file, north, DELIMITER) &&
        getline(file, east, DELIMITER) && getline(file, south, DELIMITER) &&
        getline(file, west, DELIMITER)){
            
            // converting the strings to ints
            int nID = stoi(id);
            int nNorth = stoi(north);
            int nEast = stoi(east);
            int nSouth = stoi(south);
            int nWest = stoi(west);

            Area* area = new Area(nID,name,desc,nNorth,nEast,nSouth,nWest);

            m_myMap.push_back(area);             
        }
    }

}
// Name: HeroCreation()
// Description: Populates m_myHero and asks name
// Preconditions: None
// Postconditions: m_myHero is populated (and m_name in m_myHero)
void Game::HeroCreation(){
    string name;
    cout << "Hero name:" << endl; 
    cin >> name;
    m_myHero = new Hero(name, HERO_HEALTH); // assigns the name to user input
    m_myHero->RandomWeapon();
}
// Name: Look()
// Description: Displays the current area's description and
//              the current enemy's desc (if there is one) otherwise, says
//              "It is peaceful here."
// Preconditions: None
// Postconditions: None
void Game::Look(){
    cout<<endl;
    m_myMap.at(m_curArea) -> PrintArea();
    cout<<endl;

    if(m_curEnemy == nullptr){ // if no enemy
        cout << "It is peaceful here" << endl;
    } else { 
        cout << m_curEnemy -> GetDesc() << endl;
    }
}
// Name: StartGame()
// Description: Welcomes the player to the game. Calls LoadMap, HeroCreation,
//              Randomizes an enemy, Look, and Action
// Preconditions: Input file must exist
// Postconditions: Map is loaded, User has chosen a hero to play with,
//                 prints the starting area, chooses a random enemy
//                 and calls action
void Game::StartGame(){
    // bringing the game together
    int input;
    LoadMap();
    cout << "Welcome to Zelda!" << endl;
    HeroCreation(); // creates hero
    RandomEnemy(); // spawns enemy
    Look();
    do{
        Action(); // outputs menu
        cin >> input;
        switch(input){
            case 1:
                Look();
                break;
            case 2:
                Move();
                break;
            case 3:
                Attack();
                break;
            case 4:
                ImproveWeapon();
                break;
            case 5:
                Stats();
                break;
        }

    } while((input != 6) && (m_myHero->GetHealth() > 0));
    cout<<"Good bye!" << endl;

}
// Name: Action()
// Description: Menu for game. Displays menu.
//              Player can look, move, attack, improve weapon, stats, or quit
//              Can only attack if there is actually a enemy in this area
// Preconditions: Everything in start has been completed
// Postconditions: Game continues until quit or player dies
void Game::Action(){
    cout << "What would you like to do?" << endl;
    cout<< "1. Look" << endl;
    cout << "2. Move" << endl;
    cout<< "3. Attack Enemy" << endl;
    cout<< "4. Improve Weapon" << endl;
    cout << "5. Check Stats" << endl;
    cout << "6. Quit" << endl;
}
// Name: RandomEnemy()
// Description: Used to dynamically allocated a random enemy
//              (25% chance of nothing, 25% chance of Armos, 25% of Moblin, and
//               25% of Peahat.)
// Preconditions: None
// Postconditions: Populates m_curEnemy (sets to nullptr if nothing)
void Game::RandomEnemy(){
    int randNum = rand() % 100;

    if(randNum < 25) { // 1/4 chance of no enemy
        m_curEnemy = nullptr;
    } else if(randNum < 50) {
        m_curEnemy = new Armos(ARMOS_NAME,ARMOS_HEALTH,ARMOS_DAMAGE,ARMOS_DESC);
    } else if(randNum < 75){
        m_curEnemy = new Moblin(MOBLIN_NAME,MOBLIN_HEALTH,MOBLIN_DAMAGE,MOBLIN_DESC);
    } else {
        m_curEnemy = new Peahat(PEAHAT_NAME,PEAHAT_HEALTH,PEAHAT_DAMAGE,PEAHAT_DESC);
    }
}
// Name: ImproveWeapon
// Description: Allows user to improve their weapon
// Preconditions: For each COST_IMPROVEMENT, damage in the weapon increases
//                by one.
// Postconditions: m_curHero's weapon is improved
void Game::ImproveWeapon(){
    int input;
    if(m_myHero->GetRupee() >= COST_IMPROVEMENT){ // if user has enough rupees

        // how many times user can improve weapon
        int var = (m_myHero -> GetRupee()) / COST_IMPROVEMENT; 

        do {
        cout << "How much would you like to improve your weapon? (max " << var << ")." << endl;
        cin >> input;
        } while((input < 1) || (input > var)); // input validation

        m_myHero->ImproveWeapon(input); // improves weapon by damage user wants
        cout << "You have improved your weapon by " << input << " damage." << endl;

        int inc = m_myHero -> GetRupee() - (COST_IMPROVEMENT * input);
        m_myHero-> SetRupee(inc); // sets hero's rupees after how much he paid for

    } else { // user doesn't have enough
        cout << "You don't have enough money to improve your weapon." <<endl;
    }
}
// Name: Move
// Description: Asks a player which direction they would like to move.
//              Moves player from one area to another (updates m_curArea)
//              Once successfully moved, chooses a new random enemy and
//              Calls Look
// Preconditions: Must be valid move (area must exist)
// Postconditions: Displays area information and new monster
void Game::Move(){
    int newArea = 0;
    do{
        char input;
        cout << "Which direction? (N E S W)" << endl;
        cin >> input;
        newArea = m_myMap.at(m_curArea)->CheckDirection(input);
    } while(newArea == -1); //allows user to move in direction
    // Valid move
    m_curArea = newArea;
    delete m_curEnemy; // deleting enemy to prevent leaks before moving
    m_curEnemy = nullptr;
    RandomEnemy(); // Choose a new random enemy for the new area
    Look(); // Display area information and new enemy
    } 
 
// Name: Attack
// Description: Allows player to attack an enemy.
// Preconditions: Must have enemy Enemy in current area
// Postconditions: Checks to make sure that there is an enemy to fight.
//                 Asks the user if they want to use a normal or special attack
//                 Updates health(hp) as battle continues.
//                 Both Hero and Enemy attack every round until
//                 one or more has <= 0 health
//                 May need to deallocate enemy Enemy to prevent memory leaks.
//                 When either Enemy or Hero <= 0 health, calls ProcessBattle
void Game::Attack(){

    int input;
    if (m_curEnemy != nullptr) { // if enemy exists

        // while both are alive
        while (m_myHero->GetHealth() > 0 && m_curEnemy->GetHealth() > 0) {
            cout << "1. Normal Attack" << endl;
            cout << "2. Special Attack" << endl;
            cin >> input;

            if (input == 1 || input == 2) {
                int heroAttack, enemyAttack;

                if (input == 1) { // if user wants regular attack
                    heroAttack = m_myHero->Attack();
                } else { // if user wants a special attack
                    heroAttack = m_myHero->SpecialAttack();
                }

                int random = rand() % 100;

                if(random < 25){ //25% chance of special attack
                    enemyAttack = m_curEnemy->SpecialAttack();
                } else{ 
                    enemyAttack = m_curEnemy->Attack();
                }

                int heroHealth = m_myHero->GetHealth();
                int enemyHealth = m_curEnemy->GetHealth();

                // loss of health from attack
                m_myHero->SetHealth(heroHealth - enemyAttack); 
                m_curEnemy->SetHealth(enemyHealth - heroAttack);

                // Output stats only if the battle is ongoing
                if (m_myHero->GetHealth() > 0 && m_curEnemy->GetHealth() > 0) {
                    cout << *m_myHero << endl;
                    cout << *m_curEnemy << endl;
                }
            } else {
                cout << "Invalid choice, try again." << endl;
            }
        }

        // displaying the final outcome of the battle
        ProcessBattle(m_curEnemy->GetHealth() > 0, m_myHero->GetHealth() > 0);
        delete m_curEnemy;
        m_curEnemy = nullptr;
    } else {
        cout << "No enemy in the area to fight." << endl;
    }
}

// Name: Stats()
// Description: Displays the information about the hero (name, health, rupees)
// Preconditions: None
// Postconditions: None
void Game::Stats(){
    cout << "Name: " << m_myHero -> GetName() << endl;
    cout << "HP: " << m_myHero -> GetHealth() << endl;
    cout << "Rupees: " << m_myHero -> GetRupee() << endl;
}
// Name: ProcessBattle
// Description: Called when either the enemy or hero have no health left
//       Displays who won (Enemy, Hero, mutual destruction)
//       If hero wins, gives RUPEES_WIN and resets health to starting value
// Preconditions: Enemy or hero are <= 0 health
// Postconditions: 
void Game::ProcessBattle(bool enemyAlive, bool alive){
    if (!alive && enemyAlive) {
        // if the hero lost the battle
        cout << "You have been defeated by the " << m_curEnemy -> GetName() << "." << endl;
        
    } else if (alive && !enemyAlive) {
        // if the hero won the battle
        cout << "You have defeated the " << m_curEnemy->GetName() << "." << endl;
        cout << "You earned " << RUPEES_WIN << " rupees!" << endl;
        int inc = (m_myHero -> GetRupee()) + RUPEES_WIN;
        m_myHero->SetRupee(inc); // gives hero rupees
        m_myHero->SetHealth(HERO_HEALTH); // Reset hero's health to starting value
    } else {
        // if it's a mutual destruction
        cout << "It's a draw! It's a mutual destruction." << endl;
    }
}