
int d[] = {44,45,46,2};   // 세그먼트 자릿수
int segment_pin[] = {3,4,5,6,7,8,9,10};   // 세그먼트 A~G, dp
int temp_in = 54;  // 온도 핀
//RGB 핀
int RED = 13;
int GREEN = 12;
int BLUE = 11;

void setup(){
    // 세그먼트 제어 핀을 출력으로 설정
    for(int i=0; i<8; i++){
        pinMode(segment_pin[i], OUTPUT);
    }
    // 자릿수 선택 핀을 출력으로 설정
    for(int i=0; i<4; i++){
        pinMode(d[i], OUTPUT);
    }
    // 아날로그 값 읽을 핀을 입력으로 설정
    pinMode(temp_in, INPUT);
    Serial.begin(9600);
}

void loop(){
    // 섭씨온도 구하기
    int reading = analogRead(temp_in); 
    float voltage = reading*5.0/1024.0;
    float temp = voltage*100;

    // temp 각 자릿수 구하기
    int tempint = temp*10;
    int FirstDigit = (tempint%1000)/100;
    int SecondDigit = (tempint%100)/10;
    int ThirdDigit = (tempint%10)/1;
    int C = 10;

    set_segment(0, FirstDigit);//1자리 숫자 표현
    set_segment(1, SecondDigit); //2자리 숫자 표현 
    set_segment(2, ThirdDigit); //3자리 숫자 표현
    set_segment(3,C); //4자리 C 표현

    if(temp>=27){ //27도 이상이면 RED
        analogWrite(RED,0);
        analogWrite(GREEN,255);
        analogWrite(BLUE,255);
    }
    else if(temp<=20){ //20도 이하면 BLUE
        analogWrite(RED,255);
        analogWrite(GREEN,255); 
        analogWrite(BLUE,0);
    }
    else{ //21~26도 사이면 GREEN
        analogWrite(RED,255);
        analogWrite(GREEN,0);
        analogWrite(BLUE,255);
        }
    Serial.print(temp);
    Serial.print("C\n");
    delay(1);
}

// 세그먼트 원하는 자리에 표현하는 함수
void set_pos(int pos){
  for(int i = 0; i < 4; i++) {
    if(i == pos){
      digitalWrite(d[i], LOW);
    } else {
      digitalWrite(d[i], HIGH);
    }
  }
}

// 함수 인자 값에 따른 숫자 표현
void set_num(int num){
   switch(num){
    case 0:
    digitalWrite(segment_pin[0], HIGH); //A
    digitalWrite(segment_pin[1], HIGH); //B
    digitalWrite(segment_pin[2], HIGH); //C
    digitalWrite(segment_pin[3], HIGH); //D
    digitalWrite(segment_pin[4], HIGH); //E
    digitalWrite(segment_pin[5], HIGH); //F
    digitalWrite(segment_pin[6], LOW); //G
    digitalWrite(segment_pin[7], LOW); //dp
    delay(1);
    break;
 case 1: 
    digitalWrite(segment_pin[0], LOW); //A
    digitalWrite(segment_pin[1], HIGH); //B
    digitalWrite(segment_pin[2], HIGH); //C
    digitalWrite(segment_pin[3], LOW); //D
    digitalWrite(segment_pin[4], LOW); //E
    digitalWrite(segment_pin[5], LOW); //F
    digitalWrite(segment_pin[6], LOW); //G
    digitalWrite(segment_pin[7], LOW); //dp
    break;
    
    case 2:
    digitalWrite(segment_pin[0], HIGH); //A
    digitalWrite(segment_pin[1], HIGH); //B
    digitalWrite(segment_pin[2], LOW); //C
    digitalWrite(segment_pin[3], HIGH); //D
    digitalWrite(segment_pin[4], HIGH); //E
    digitalWrite(segment_pin[5], LOW); //F
    digitalWrite(segment_pin[6], HIGH); //G
    digitalWrite(segment_pin[7], LOW); //dp 
    break;
    
    case 3:
    digitalWrite(segment_pin[0], HIGH); //A
    digitalWrite(segment_pin[1], HIGH); //B
    digitalWrite(segment_pin[2], HIGH); //C
    digitalWrite(segment_pin[3], HIGH); //D
    digitalWrite(segment_pin[4], LOW); //E
    digitalWrite(segment_pin[5], LOW); //F
    digitalWrite(segment_pin[6], HIGH); //G
    digitalWrite(segment_pin[7], LOW); //dp    
    break;
    
    case 4:
    digitalWrite(segment_pin[0], LOW); //A
    digitalWrite(segment_pin[1], HIGH); //B
    digitalWrite(segment_pin[2], HIGH); //C
    digitalWrite(segment_pin[3], LOW); //D
    digitalWrite(segment_pin[4], LOW); //E
    digitalWrite(segment_pin[5], HIGH); //F
    digitalWrite(segment_pin[6], HIGH); //G
    digitalWrite(segment_pin[7], LOW); //dp 
    break;
    
    case 5:
    digitalWrite(segment_pin[0], HIGH); //A
    digitalWrite(segment_pin[1], LOW); //B
    digitalWrite(segment_pin[2], HIGH); //C
    digitalWrite(segment_pin[3], HIGH); //D
    digitalWrite(segment_pin[4], LOW); //E
    digitalWrite(segment_pin[5], HIGH); //F
    digitalWrite(segment_pin[6], HIGH); //G
    digitalWrite(segment_pin[7], LOW); //dp 
    break;
    
    case 6:
    digitalWrite(segment_pin[0], HIGH); //A
    digitalWrite(segment_pin[1], LOW); //B
    digitalWrite(segment_pin[2], HIGH); //C
    digitalWrite(segment_pin[3], HIGH); //D
    digitalWrite(segment_pin[4], HIGH); //E
    digitalWrite(segment_pin[5], HIGH); //F
    digitalWrite(segment_pin[6], HIGH); //G
    digitalWrite(segment_pin[7], LOW); //dp 
    break;
    
    case 7:
    digitalWrite(segment_pin[0], HIGH); //A
    digitalWrite(segment_pin[1], HIGH); //B
    digitalWrite(segment_pin[2], HIGH); //C
    digitalWrite(segment_pin[3], LOW); //D
    digitalWrite(segment_pin[4], LOW); //E
    digitalWrite(segment_pin[5], LOW); //F
    digitalWrite(segment_pin[6], LOW); //G
    digitalWrite(segment_pin[7], LOW); //dp 
    break;
    
    case 8:
    digitalWrite(segment_pin[0], HIGH); //A
    digitalWrite(segment_pin[1], HIGH); //B
    digitalWrite(segment_pin[2], HIGH); //C
    digitalWrite(segment_pin[3], HIGH); //D
    digitalWrite(segment_pin[4], HIGH); //E
    digitalWrite(segment_pin[5], HIGH); //F
    digitalWrite(segment_pin[6], HIGH); //G
    digitalWrite(segment_pin[7], LOW); //dp 
    break;
    case 9:
    digitalWrite(segment_pin[0], HIGH); //A
    digitalWrite(segment_pin[1], HIGH); //B
    digitalWrite(segment_pin[2], HIGH); //C
    digitalWrite(segment_pin[3], HIGH); //D
    digitalWrite(segment_pin[4], LOW); //E
    digitalWrite(segment_pin[5], HIGH); //F
    digitalWrite(segment_pin[6], HIGH); //G
    digitalWrite(segment_pin[7], LOW); //dp   
    break;
    
    case 10: // C
    digitalWrite(segment_pin[0], HIGH); //A
    digitalWrite(segment_pin[1], LOW); //B
    digitalWrite(segment_pin[2], LOW); //C
    digitalWrite(segment_pin[3], HIGH); //D
    digitalWrite(segment_pin[4], HIGH); //E
    digitalWrite(segment_pin[5], HIGH); //F
    digitalWrite(segment_pin[6], LOW); //G
    digitalWrite(segment_pin[7], LOW); //dp  
    break;
  }
}

// 원하는 위치에 원하는 숫자 표시하는 함수
void set_segment(int pos, int num){
  set_pos(pos);
  set_num(num);
  if(num==10){
    digitalWrite(segment_pin[0], HIGH); //A
    digitalWrite(segment_pin[1], LOW); //B
    digitalWrite(segment_pin[2], LOW); //C
    digitalWrite(segment_pin[3], HIGH); //D
    digitalWrite(segment_pin[4], HIGH); //E
    digitalWrite(segment_pin[5], HIGH); //F
    digitalWrite(segment_pin[6], LOW); //G
    }
  if(pos==1){
    digitalWrite(segment_pin[7], HIGH); //dp   
   }
  delay(1);
}