const byte pinLED = 7, BOTAO = 2;
volatile boolean estadoLed = 0;
int cont=0;

void inverte (){
  estadoLed ^= 1;
  cont=0;
}

void setup()
{
  pinMode(7, OUTPUT);
  pinMode (BOTAO,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), inverte, FALLING);
}

void loop()
{
   if(cont==10){
    digitalWrite(pinLED, LOW);
    estadoLed=0; 
  }
  
  if(estadoLed == 1) {
  digitalWrite(pinLED, HIGH);   
  delay(500); 
  digitalWrite(pinLED, LOW);    
  delay(500); 
   cont++; 
    
  }else{ 
  digitalWrite(pinLED, LOW);
    
  }
 
}
