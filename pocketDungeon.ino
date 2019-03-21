#include "Arduino.h"  
#include "Monster.h"
#include <Arduboy2.h>

Arduboy2 arduboy;

//Images
const uint8_t jellySprite[] PROGMEM = {0x83, 0xee, 0xf8, 0xf8, 0xfc, 0xf4, 0xf6, 0xc0}; 
const uint8_t jeffSprite[]  PROGMEM = {0x00, 0x1f, 0x88, 0xeb, 0x3f, 0xe0, 0x80, 0x00};

\
//Monster(byte health, byte att, byte def
Monster jelly(45,2,8,8);
Monster jeff(30,1,10,8);

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(30);
  arduboy.clear();
  makeCaveTop();
  makeCaveLeft();
  makeCaveRight();
}

void loop() {
  arduboy.clear();
  if (!(arduboy.nextFrame()))
    return;
  drawCave();
  checkButtons();
  arduboy.drawBitmap(jelly.posnX,jelly.posnY,jellySprite,8,8, WHITE);
  arduboy.drawBitmap(96,32,jeffSprite,8,8,WHITE);
  arduboy.setCursor(16,56);
  arduboy.print("Jelly hp=");
  arduboy.print(jelly.hp);
  arduboy.display();

}

void checkButtons(){
  arduboy.pollButtons();
  if(arduboy.justPressed(LEFT_BUTTON)) {
    jelly.monsterMove('l');
   }
  if(arduboy.justPressed(RIGHT_BUTTON)) {
    jelly.monsterMove('r');
  }
  if(arduboy.justPressed(UP_BUTTON)) {
    jelly.monsterMove('u');
  }
  if(arduboy.justPressed(DOWN_BUTTON)) {
    jelly.monsterMove('d');
  }
}
