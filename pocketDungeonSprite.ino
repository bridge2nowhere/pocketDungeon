#include "Arduino.h"  
#include "Monster.h"
#include <Arduboy2.h>

Arduboy2 arduboy;

//Images
const uint8_t jellySprite[] PROGMEM = {0x83, 0xee, 0xf8, 0xf8, 0xfc, 0xf4, 0xf6, 0xc0}; 
const uint8_t jeffSprite[]  PROGMEM = {0x00, 0x1f, 0x88, 0xeb, 0x3f, 0xe0, 0x80, 0x00};

//Allow for switching between screen modes:
//0 is splashScreen
//1 is map
//2 is combat
byte screenMode = 0;

//Create Monsters (and hero is is the real monster, am I right)
Monster jelly1(45,2,8,8,8,8,jellySprite);
Monster jelly2(45,2,8,8,24,8,jellySprite);
Monster jeff(30,1,10,96,32,8,jeffSprite);

//pointer to active monster
Monster * activeMonster = &jelly1;


void setup() {
  arduboy.begin();
  arduboy.setFrameRate(30);
  arduboy.clear();
  //calls cave functions to create random cave walls
  makeCaveTop();
  makeCaveLeft();
  makeCaveRight();
}

void loop() {
  arduboy.clear();
  if (!(arduboy.nextFrame()))
    return;
  //check screen mode and display splashScreen of move on
  if (screenMode == 0) splashScreen();
  else {
    //draws the cave walls, checks for movement, then draws the sprites
    drawCave();
    checkButtons();
    arduboy.drawBitmap(jelly1.posnX,jelly1.posnY,jelly1.pointerToMySprite,8,8, WHITE);
    arduboy.drawBitmap(jelly2.posnX,jelly2.posnY,jelly2.pointerToMySprite,8,8, WHITE);
    arduboy.drawBitmap(96,32,jeff.pointerToMySprite,8,8,WHITE);
    arduboy.setCursor(0,56);
    arduboy.print("A to switch between Jellies");
    //arduboy.print("j1 hp=");
    //arduboy.print(jelly1.hp);
    //arduboy.print("  j2 hp=");
    //arduboy.print(jelly2.hp);
    arduboy.display();
  }

}

void splashScreen()
{
  //shows splash screen then moves on
  bool moveOn = false;
  arduboy.setCursor(0,0);
  arduboy.setTextSize(2);
  arduboy.println("Pocket");
  arduboy.println("Dungeon");
  arduboy.setTextSize(1);
  arduboy.println("by Andrew Woodbridge");
  arduboy.println();
  arduboy.println();
  arduboy.println("Press A to Continue");
  arduboy.display();
  while (!moveOn) {
   arduboy.pollButtons();
   if(arduboy.justPressed(A_BUTTON)){
      moveOn = true;
      screenMode ++; 
   }
  }  
}

void switchActiveMonster()
{
  //switches between the two jellies
  if (activeMonster == &jelly1) activeMonster = &jelly2;
  else if (activeMonster == &jelly2) activeMonster = &jelly1;
  }

void checkButtons(){
  //polls the buttons during the gameplay
  arduboy.pollButtons();
  if(arduboy.justPressed(A_BUTTON)) {
    switchActiveMonster();
  }
  if(arduboy.justPressed(LEFT_BUTTON)) {
    activeMonster->monsterMove('l');
  }
  else if(arduboy.justPressed(RIGHT_BUTTON)) {
    activeMonster->monsterMove('r');
  }
  else if(arduboy.justPressed(UP_BUTTON)) {
    activeMonster->monsterMove('u');
  }
  else if(arduboy.justPressed(DOWN_BUTTON)) {
    activeMonster->monsterMove('d');
  }
}
