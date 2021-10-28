const byte verm1=6,amarelo=7,verd1=8,verd2=9,verm2=11,botao=2;
int cont=0; 

void setup()
{    
  pinMode(verm1,OUTPUT);
  pinMode(amarelo,OUTPUT);  
  pinMode(verd1,OUTPUT);
  pinMode(verd2,OUTPUT);
  pinMode(verm2,OUTPUT);
  pinMode(botao, INPUT_PULLUP);
  int i=0;
}

void loop(){
  if (cont!=0){
    digitalWrite(verd1, HIGH);
  digitalWrite(verm2, HIGH);
    delay(3000);
    cont=0;
  } 
  while(digitalRead(botao)){
   digitalWrite(verd1, HIGH);
  digitalWrite(verm2, HIGH); 
  }
  digitalWrite(verd1, LOW);
  digitalWrite(amarelo, HIGH);
  delay(3000); 
  digitalWrite(amarelo, LOW);
  delay(1000);
  digitalWrite(verm1, HIGH);
  digitalWrite(verm2, LOW);
  digitalWrite(verd2, HIGH);
  delay(3000);
  for(int i=0; i<=3; i++){
   digitalWrite(verm1, HIGH);
   delay(300); 
   digitalWrite(verm1, LOW);
   delay(300); 
  }
  digitalWrite(verd2, LOW);
  digitalWrite(verm1, LOW);
  cont++;
  
} 