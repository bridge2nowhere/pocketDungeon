/*
 * Monster Class for Pocket Dungeon Game
 * Created by Andrew Woodbridge March 2019.
 */


#include "Arduino.h"
#include "Monster.h"

Monster::Monster(byte health, byte att, byte def, byte imgSize)
{
  hp = health;
  attMod = att;
  ac = def;
  spriteSize = imgSize;
  posnX = 8;
  posnY = 8;
};

 void Monster::takeHit(byte toHit,byte damage)
 {
  if(toHit <= ac) hp -= damage;
 }

void Monster::monsterMove(char card)
{
  switch(card) {
    case 'u':
      posnY -= spriteSize;
      break;
     case 'd':
      posnY += spriteSize;
      break;
     case 'l':
      posnX -= spriteSize;
      break;
     case 'r':
      posnX += spriteSize;
      break;
  }
}
