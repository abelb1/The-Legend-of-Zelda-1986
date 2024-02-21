CXX = g++
CXXFLAGS = -Wall

proj4: Area.o Hero.o Enemy.o Armos.o Moblin.o Peahat.o Weapon.o Sword.o Bomb.o\
 Boomerang.o Game.o proj4.cpp
	$(CXX) $(CXXFLAGS) Area.o Hero.o Enemy.o Armos.o Moblin.o Peahat.o Weapon.o Sword.o Bomb.o\
 Boomerang.o Game.o proj4.cpp -o proj4

Game.o: Area.o Hero.o Enemy.o Armos.o Moblin.o Peahat.o Weapon.o Sword.o Bomb.o Boomerang.o Game.cpp Game.h
	$(CXX) $(CXXFLAGS) -c Game.cpp

Area.o: Area.cpp Area.h
	$(CXX) $(CXXFLAGS) -c Area.cpp

Hero.o: Weapon.o Sword.o Boomerang.o Bomb.o Hero.cpp Hero.h
	$(CXX) $(CXXFLAGS) -c Hero.cpp

Bomb.o: Weapon.o Sword.o Boomerang.o Bomb.cpp Bomb.h
	$(CXX) $(CXXFLAGS) -c Bomb.cpp

Boomerang.o: Weapon.o Sword.o Boomerang.cpp Boomerang.h
	$(CXX) $(CXXFLAGS) -c Boomerang.cpp

Sword.o: Weapon.o Sword.cpp Sword.h
	$(CXX) $(CXXFLAGS) -c Sword.cpp

Weapon.o: Weapon.cpp Weapon.h
	$(CXX) $(CXXFLAGS) -c Weapon.cpp

Peahat.o: Enemy.o Armos.o Moblin.o Peahat.cpp Peahat.h
	$(CXX) $(CXXFLAGS) -c Peahat.cpp

Moblin.o: Enemy.o Armos.o Moblin.cpp Moblin.h
	$(CXX) $(CXXFLAGS) -c Moblin.cpp

Armos.o: Enemy.o Armos.cpp Armos.h
	$(CXX) $(CXXFLAGS) -c Armos.cpp

Enemy.o: Enemy.cpp Enemy.h
	$(CXX) $(CXXFLAGS) -c Enemy.cpp

run1:
	./proj4 proj4_map1.txt

run2:
	./proj4 proj4_map2.txt

val1:
	valgrind ./proj4 proj4_map1.txt

val2:
	valgrind ./proj4 proj4_map2.txt

submit:
	cp Game.h Game.cpp Enemy.h Enemy.cpp Armos.h Armos.cpp Moblin.h Moblin.cpp Peahat.h Peahat.cpp Hero.h Hero.cpp Weapon.h Weapon.cpp Sword.h Sword.cpp Bomb.h Bomb.cpp Boomerang.h Boomerang.cpp Area.h Area.cpp proj4.cpp ~/cs202proj/proj4
