const byte pin_LED = 13;
const byte pin_AMR = 12;
const byte pin_VERD = 11;
const byte pinbutton = 2;
boolean pront_conf = 0,estadoLED = 0, pisca = 0,ativo = 0;
const unsigned int periodo = 200;
unsigned long tempoAtual, tempoAnterior;
unsigned int luz_incidente,cont_button,escuro; 


void interruptor(){
pront_conf = 1;
pisca = 1;
cont_button = 1;
if(cont_button < 1){
  ativo = 0 ;
 }
}

void setup() {
 pinMode(pin_LED, OUTPUT);
 pinMode(pin_AMR, OUTPUT);
 pinMode(pin_VERD, OUTPUT);
 pinMode(pinbutton, INPUT_PULLUP);
 attachInterrupt(digitalPinToInterrupt(2), interruptor, FALLING);
 Serial.begin(9600); 
 tempoAnterior = millis();
}

void loop() {
 tempoAtual = millis();
 digitalWrite(pin_AMR, HIGH);
 Serial.println("bem vindo ao sistema de alarme detector de escuridão");
 if(pisca == 1){
    digitalWrite(pin_AMR, LOW);
    if((tempoAtual-tempoAnterior)>= periodo){
      estadoLED ^= 1; // or exclusivo 
      digitalWrite(pin_VERD,estadoLED);
      tempoAnterior = tempoAtual; 
      }
    }

 if(pront_conf == 1){
    Serial.println("informe o valor da intesidade da escuridão");
    if(Serial.available()){
     escuro = Serial.read();
      pront_conf = 0;
    }
    pisca = 0;
    digitalWrite(pin_VERD, HIGH);  
  }

 luz_incidente = analogRead(A1);
 if(luz_incidente <= escuro){
    ativo = 1;
 }
 if(ativo == 1){
  if((tempoAtual-tempoAnterior)>= periodo){
    estadoLED ^= 1; // or exclusivo 
    digitalWrite(pin_LED,estadoLED);
    tempoAnterior = tempoAtual;
  }
 }
}
