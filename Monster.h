/*
 * Monster Class for Pocket Dungeon Game
 * Created by Andrew Woodbridge March 2019.
 */

#ifndef Monster_h
#define Monster_h

#include "Arduino.h"

class Monster {
  public:
    Monster(byte health, byte attMod, byte def, byte imgSize);
    byte hp;
    byte attMod;
    byte ac;
    byte posnX;
    byte posnY;
    byte spriteSize;

    byte attack();
    void takeHit(byte toHit,byte damage);
    void monsterMove(char card);
};

#endif
