byte caveTopX[30];
byte caveTopY[30];
byte caveTopCount = 0;

byte caveLeftX[30];
byte caveLeftY[30];
byte caveLeftCount = 0;

byte caveRightX[30];
byte caveRightY[30];
byte caveRightCount = 0;



void findChest(){
  chestPosnX = (random(1,13) * 8) + 8;
  chestPosnY = (random(1,7) * 8) + 8;
}

void makeCaveTop(){
  byte oldPosnX = 4;
  byte oldPosnY = 4;
  byte newPosnX;
  byte newPosnY;
  caveTopX[0] = 4;
  caveTopY[0] = 4;
  caveTopCount ++;
  
  while (oldPosnX < 120) {
    newPosnX = oldPosnX + random(2,8);
    newPosnY = random(0,8);
    caveTopX[caveTopCount] = newPosnX;
    caveTopY[caveTopCount] = newPosnY;
    oldPosnX = newPosnX;
    oldPosnY = newPosnY; 
    caveTopCount ++;
  }
  caveTopX[caveTopCount] = 124;
  caveTopY[caveTopCount] = 4;
}

void makeCaveLeft(){
  byte oldPosnX = 4;
  byte oldPosnY = 4;
  byte newPosnX;
  byte newPosnY;
  caveLeftX[0] = 4;
  caveLeftY[0] = 4;
  caveLeftCount ++;
  while (oldPosnY < 60) {
    newPosnX = random(0,8);
    newPosnY = oldPosnY + random(2,8);
    caveLeftX[caveLeftCount] = newPosnX;
    caveLeftY[caveLeftCount] = newPosnY;
    oldPosnX = newPosnX;
    oldPosnY = newPosnY; 
    caveLeftCount ++;
  }
  caveLeftX[caveLeftCount] = 4;
  caveLeftY[caveLeftCount] = 60;
}

void makeCaveRight(){
  byte oldPosnX = 124;
  byte oldPosnY = 4;
  byte newPosnX;
  byte newPosnY;
  caveRightX[0] = 124;
  caveRightY[0] = 4;
  caveRightCount ++;
  while (oldPosnY < 60) {
    newPosnX = random(120,127);
    newPosnY = oldPosnY + random(2,8);
    caveRightX[caveRightCount] = newPosnX;
    caveRightY[caveRightCount] = newPosnY;
    oldPosnX = newPosnX;
    oldPosnY = newPosnY; 
    caveRightCount ++;
  }
  caveRightX[caveRightCount] = 124;
  caveRightY[caveRightCount] = 60;
}



void drawCave(){
  for(byte i = 1; i <= caveTopCount; i++)
  {
    arduboy.drawLine(caveTopX[i-1],caveTopY[i-1],caveTopX[i],caveTopY[i],WHITE);
  }
  for(byte i = 1; i <= caveLeftCount; i++)
  {
    arduboy.drawLine(caveLeftX[i-1],caveLeftY[i-1],caveLeftX[i],caveLeftY[i],WHITE);
  }
    for(byte i = 1; i <= caveRightCount; i++)
  {
    arduboy.drawLine(caveRightX[i-1],caveRightY[i-1],caveRightX[i],caveRightY[i],WHITE);
  }
}
