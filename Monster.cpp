/*
 * Monster Class for Pocket Dungeon Game
 * Created by Andrew Woodbridge March 2019.
 */


#include "Arduino.h"
#include "Monster.h"
#include <Arduboy2.h>

Monster::Monster(byte health, byte att, byte def, byte startX, byte startY, byte imgSize, const uint8_t * sprite)
{
  hp = health;
  attMod = att;
  ac = def;
  spriteSize = imgSize;
  posnX = startX;
  posnY = startY;
  pointerToMySprite = sprite;
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
      if (posnY < 8) posnY = 8;
      break;
     case 'd':
      posnY += spriteSize;
      if (posnY > 55 - spriteSize) posnY = 55 - spriteSize;
      break;
     case 'l':
      posnX -= spriteSize;
      if (posnX < 8) posnX = 8;
      break;
     case 'r':
      posnX += spriteSize;
      if (posnX > 119 - spriteSize) posnX = 119 - spriteSize;
      break;
  }
}
