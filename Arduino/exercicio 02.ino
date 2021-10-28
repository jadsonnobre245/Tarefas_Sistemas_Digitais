const byte pinLED = 7;
const byte pinbutton = 2;
const unsigned int desvio_luz = 100;
const unsigned int periodo = 200;
unsigned int luz_incidente=0;
unsigned long tempoAtual, tempoAnterior;
boolean estadoLED = 0;
boolean ativo=0, desativo=0;

void inverter(){
  
}
void interruptor(){
desativo = 1;
estadoLED=0;
digitalWrite(pinLED, estadoLED);

}
void setup() {
pinMode(pinLED, OUTPUT);
pinMode(pinbutton, INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(2), interruptor, FALLING);
tempoAnterior = millis();
Serial.begin(9600);
}

void loop() {
  tempoAtual = millis();
  luz_incidente = analogRead(A1);
  Serial.print(luz_incidente);
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
