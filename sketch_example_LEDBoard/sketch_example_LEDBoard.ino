#define LED_SIN_1 2
#define LED_SIN_2 3
#define LED_SIN_3 4
#define LED_CLOCK 5
#define LED_LATCH 6
#define LED_STROBE 7

int const LED_SW = 49;

unsigned long bitmap[16] ; //画面出力用データ

void setup() {
  pinMode(LED_SIN_1, OUTPUT) ;
  pinMode(LED_SIN_2, OUTPUT) ;
  pinMode(LED_SIN_3, OUTPUT) ;
  pinMode(LED_CLOCK, OUTPUT) ;
  pinMode(LED_LATCH, OUTPUT) ;
  pinMode(LED_STROBE, OUTPUT) ;
  
  digitalWrite(LED_SIN_1, LOW) ;
  digitalWrite(LED_SIN_2, LOW) ;
  digitalWrite(LED_SIN_3, LOW) ;
  digitalWrite(LED_CLOCK, LOW) ;
  digitalWrite(LED_LATCH, HIGH) ;
  digitalWrite(LED_STROBE, LOW) ;
  
  digitalWrite(LED_SW, INPUT_PULLUP) ;
  clearBitmap() ;
}

void clearBitmap(){
  memset(bitmap, 0, sizeof(bitmap)); 
}

void setDot(int x, int y, int color){
  if( (x >= 0)&&(x <= 31) && (y >= 0) && (y <= 15) ){
    if( !color ){
      bitmap[y] &= ~( (unsigned long)1 << x ) ;
    }
    else{
      bitmap[y] |= (unsigned long)1 << x ;
    }
  }
}

void updateLed(){
  int x ;
  int y ;
  
  for(y = 0; y <= 15; y++){
    for(x = 0; x <= 15; x++){
      
      if( y == x ){
        digitalWrite(LED_SIN_1, HIGH) ;
      }
      else{
        digitalWrite(LED_SIN_1, LOW) ;
      }
      digitalWrite(LED_SIN_2, (bitmap[y] >> 15 - x) & 0x01) ;
      digitalWrite(LED_SIN_3, (bitmap[y] >> (15 - x + 16)) & 0x01) ;
      
      digitalWrite(LED_CLOCK, HIGH) ;
      delayMicroseconds(2) ;
      digitalWrite(LED_CLOCK, LOW) ;
      delayMicroseconds(2) ;
    }
    
    digitalWrite(LED_LATCH, LOW) ;
    delayMicroseconds(2) ;
    digitalWrite(LED_LATCH, HIGH) ;
  }
  
}

void loop() {
  static float r ;
  int x ;
  int y ;
  
//  x = cos(r) * 12 ;
//  y = sin(r) * 7 ;
  clearBitmap() ;
  if( digitalRead(LED_SW) == LOW){
    //----------H------------//
    setDot(x + 4, y, 1) ;
    setDot(x + 4, y + 1, 1) ;
    setDot(x + 4, y + 2, 1) ;
    setDot(x + 4, y + 3, 1) ;
    setDot(x + 4, y + 4, 1) ;
    setDot(x + 6, y, 1) ;
    setDot(x + 6, y + 1, 1) ;
    setDot(x + 6, y + 2, 1) ;
    setDot(x + 6, y + 3, 1) ;
    setDot(x + 6, y + 4, 1) ;
    setDot(x + 5, y + 2, 1) ;
    //-----------------------//
    
    //----------E------------//
    setDot(x + 8, y, 1) ;
    setDot(x + 9, y, 1) ;
    setDot(x + 10, y, 1) ;
    setDot(x + 8, y + 1, 1) ;
    setDot(x + 8, y + 2, 1) ;
    setDot(x + 9, y + 2, 1) ;
    setDot(x + 10, y + 2, 1) ;
    setDot(x + 8, y + 3, 1) ;
    setDot(x + 8, y + 4, 1) ;
    setDot(x + 9, y + 4, 1) ;
    setDot(x + 10, y + 4, 1) ;
    //-----------------------//
    
    //----------L------------//
    setDot(x + 12, y, 1) ;
    setDot(x + 12, y + 1, 1) ;
    setDot(x + 12, y + 2, 1) ;
    setDot(x + 12, y + 3, 1) ;
    setDot(x + 12, y + 4, 1) ;
    setDot(x + 13, y + 4, 1) ;
    setDot(x + 14, y + 4, 1) ;
    //-----------------------//
    
    //----------L------------//
    setDot(x + 16, y, 1) ;
    setDot(x + 16, y + 1, 1) ;
    setDot(x + 16, y + 2, 1) ;
    setDot(x + 16, y + 3, 1) ;
    setDot(x + 16, y + 4, 1) ;
    setDot(x + 17, y + 4, 1) ;
    setDot(x + 18, y + 4, 1) ;
    //-----------------------//
    
    //----------O------------//
    setDot(x + 21, y, 1) ;
    setDot(x + 22, y, 1) ;
    setDot(x + 20, y + 1, 1) ;
    setDot(x + 20, y + 2, 1) ;
    setDot(x + 20, y + 3, 1) ;
    setDot(x + 21, y + 4, 1) ;
    setDot(x + 22, y + 4, 1) ;
    setDot(x + 23, y + 1, 1) ;
    setDot(x + 23, y + 2, 1) ;
    setDot(x + 23, y + 3, 1) ;
    //-----------------------//
  }
  updateLed() ;
//  r += 0.1 ;
}
