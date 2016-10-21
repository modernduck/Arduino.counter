#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

long timer;
long tidTimer;
long counter;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  //millis() เวลาตั้งแต่เปิดเครื่อง x 1000
  timer = millis() / 1000;
  tidTimer = millis() / 500;
  counter = 20 - timer; // 20 - 0, 20 - 1, 20 - 2
  //timer จะได้เลข 0,1,2,3,4,5,6,7,8,9
  lcd.setCursor(0,0);
  if(counter < 10) {
    lcd.print(0);
  }

  //อยากให้พิมพ์เมื่อ counter >= 0
  if(counter > 0){
    lcd.print(counter);
  }else {
    //เลข 0 ลงไป
    lcd.setCursor(0,0);
    lcd.print("BOOOOOOOM!");
  }
  
  //แสดง tidTimer()
  lcd.setCursor(0,1);
  //tidTimer หารสองได้ เศษ 0 แปลว่าเป็นเลขคู่
  if(tidTimer % 2 == 0)
  {
    tone(10, 50);
  }else
  {
    //เป็นเลขคี่
    noTone(10);
  }
  lcd.print(tidTimer);
  
   
}
