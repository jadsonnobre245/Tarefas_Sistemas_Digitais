const byte pinLED = 7;
const byte pinbutton = 2;

const unsigned int claro = 500;
const unsigned int escuro = 400;
const unsigned int periodo = 200;
const unsigned int tempo_min = 10000;
unsigned int luz_incidente;

unsigned long tempoAtual, tempoAnterior;


boolean estadoLED = 0;
boolean ativo=0;

void interruptor(){
  estadoLED=0;
  digitalWrite(pinLED, estadoLED);
}

void setup() {
  pinMode(pinLED, OUTPUT);
  pinMode(pinbutton, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), interruptor, FALLING);
  tempoAnterior = millis();
}

void loop() {

  luz_incidente = analogRead(A1);  

  tempoAtual = millis();
  if(luz_incidente<=escuro){
    ativo = 1;
    
}else{
    digitalWrite(pinLED, LOW);
    ativo = 0;
    delay(10000);
 }
 if(ativo == 1){
  if((tempoAtual-tempoAnterior)>=periodo){
  estadoLED ^= 1; // or exclusivo 
  digitalWrite(pinLED,estadoLED);
  tempoAnterior = tempoAtual; 
  }
 }

 
}
 
