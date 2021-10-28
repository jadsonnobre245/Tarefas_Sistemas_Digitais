const byte pinLED = 7;
const byte pinbutton = 2;

const unsigned int desvio_luz = 100;
const unsigned int periodo = 200;
const unsigned int tempo_min = 10000;
unsigned int luz_incidente;

unsigned long tempoAtual, tempoAnterior;
unsigned long tempo_h; 

boolean estadoLED = 0;
boolean ativo=0, desativo=0;

void interruptor(){
tempo_h = millis();
if(tempo_h <= tempo_min){
  desativo = 1;
  estadoLED=0;
  digitalWrite(pinLED, estadoLED);
  }
}

void setup() {
  pinMode(pinLED, OUTPUT);
  pinMode(pinbutton, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), interruptor, FALLING);
  tempoAnterior = millis();
}

void loop() {
  tempoAtual = millis();
  luz_incidente = analogRead(A1);
  if(luz_incidente <= desvio_luz){
    ativo =1;
  }
  if(ativo == 1 && desativo==0){
    if((tempoAtual-tempoAnterior)>= periodo){
      estadoLED ^= 1;
      digitalWrite(pinLED, estadoLED);
      tempoAnterior = tempoAtual;
    }
  }
}
