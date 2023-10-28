#define m1 3
#define m2 5
#define m3 9
#define m4 10

int arrow =0;
int a=0;
int b=0;
void setup() {

pinMode(m1,OUTPUT);
pinMode(m2,OUTPUT);
pinMode(m3,OUTPUT);
pinMode(m4,OUTPUT);
pinMode(12,INPUT);
pinMode(13,INPUT);
//serial.begin(9600);
}

void lopp(){

  // dynamic line follower code

int lsensor=digitalRead(12);
int rsensor=digitalRead(13);

if((lsensor ==LOW)&&(rsensor ==HIGH))
{
  // belok kanan
  motorOut(100,75,2);
  a=1;
}
if((lsensor ==HIGH)&&(rsensor ==LOW))
{
  // belok kiri
   motorOut(75,100,2);
   a=2;
}
if((lsensor ==HIGH)&&(rsensor ==HIGH))
{
  motorOut(100,100,2); 
  //maju 
}
if((lsensor ==LOW)&&(rsensor ==LOW))
{
 if(a==1){ 
  motorOut(100,0,2); }
  if(a==2){
  motorOut(0,100,2);  }
}
}

void motorOut(unsigned char lpwn, unsigned rpwn, int arrow){
  //arrow =1 mundur , 2 maju,
  if(arrow==1){
    digitalWrite(m3,HIGH);
    digitalWrite(m1,LOW);
    analogWrite (m4,255-lpwn);
    analogWrite (m2,rpwn);   
  }
  else if (arrow==2){
    digitalWrite(m3,LOW);
    digitalWrite(m1,HIGH);
    analogWrite (m4,lpwn);
    analogWrite (m2,255-rpwn);
  }
  
  
}
