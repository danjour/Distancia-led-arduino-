#include "Ultrasonic.h" //INCLUSÃO DA BIBLIOTECA NECESSÁRIA PARA FUNCIONAMENTO DO CÓDIGO

const int echoPin = 11; //PINO DIGITAL UTILIZADO PELO HC-SR04 ECHO(RECEBE)
const int trigPin = 10; //PINO DIGITAL UTILIZADO PELO HC-SR04 TRIG(ENVIA)
#define tmp 1000
int cont=0;

int disp_pinos[8]={2,3,4,5,6,7,8,9};
int digitos[11][8] = { // 11 linhas, 8 colunas
 { 1,1,1,1,1,1,0,0 }, //0
 { 0,1,1,0,0,0,0,0 }, //1
 { 1,1,0,1,1,0,1,0 }, //2
 { 1,1,1,1,0,0,1,0 }, //3
 { 0,1,1,0,0,1,1,0 }, //4
 { 1,0,1,1,0,1,1,0 }, //5
 { 0,0,1,1,1,1,1,0 }, //6
 { 1,1,1,0,0,0,0,0 }, //7
 { 1,1,1,1,1,1,1,0 }, //8
 { 1,1,1,0,0,1,1,0 }, //9
 { 0,0,0,0,0,0,0,1 } //ponto decimal
};



Ultrasonic ultrasonic(trigPin,echoPin); //INICIALIZANDO OS PINOS DO ARDUINO

float distancia; //VARIÁVEL DO TIPO INTEIRO
String result; //VARIÁVEL DO TIPO STRING

void setup(){
  pinMode(echoPin, INPUT); //DEFINE O PINO COMO ENTRADA (RECEBE)
  pinMode(trigPin, OUTPUT); //DEFINE O PINO COMO SAIDA (ENVIA)
  Serial.begin(9600); //INICIALIZA A PORTA SERIAL
  for(int i=0;i<8;i++){
    pinMode(disp_pinos[i],OUTPUT);
    }
  }
void loop(){
  
  hcsr04(); // FAZ A CHAMADA DO MÉTODO "hcsr04()"
  Serial.print("Distancia "); //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.print(result); ////IMPRIME NO MONITOR SERIAL A DISTÂNCIA MEDIDA
  Serial.println("cm"); //IMPRIME O TEXTO NO MONITOR SERIAL
  
}
//MÉTODO RESPONSÁVEL POR CALCULAR A DISTÂNCIA
void hcsr04(){
    digitalWrite(trigPin, LOW); //SETA O PINO 6 COM UM PULSO BAIXO "LOW"
    delayMicroseconds(2); //INTERVALO DE 2 MICROSSEGUNDOS
    digitalWrite(trigPin, HIGH); //SETA O PINO 6 COM PULSO ALTO "HIGH"
    delayMicroseconds(10); //INTERVALO DE 10 MICROSSEGUNDOS
    digitalWrite(trigPin, LOW); //SETA O PINO 6 COM PULSO BAIXO "LOW" NOVAMENTE
    //FUNÇÃO RANGING, FAZ A CONVERSÃO DO TEMPO DE
    //RESPOSTA DO ECHO EM CENTIMETROS, E ARMAZENA
    //NA VARIAVEL "distancia"
    distancia = (ultrasonic.Ranging(CM)); //VARIÁVEL GLOBAL RECEBE O VALOR DA DISTÂNCIA MEDIDA
    if(distancia>=100){
      void led();{
        for(int i=0;i<8;i++){
          digitalWrite(disp_pinos[i],digitos[10][i]);
          }
        }
    }
    if(distancia>=90 && distancia<99 ){
      void led();{
        for(int i=0;i<8;i++){
          digitalWrite(disp_pinos[i],digitos[9][i]);
          }
        }
    }
    if(distancia>=80 && distancia<89 ){
      void led();{
        for(int i=0;i<8;i++){
          digitalWrite(disp_pinos[i],digitos[8][i]);
          }
        }
    }
    if(distancia>=70 && distancia<79 ){
      void led();{
        for(int i=0;i<8;i++){
          digitalWrite(disp_pinos[i],digitos[7][i]);
          }
        }
    }
    if(distancia>=60 && distancia<69 ){
      void led();{
        for(int i=0;i<8;i++){
          digitalWrite(disp_pinos[i],digitos[6][i]);
          }
        }
    }
    if(distancia>=50 && distancia<59 ){
      void led();{
        for(int i=0;i<8;i++){
          digitalWrite(disp_pinos[i],digitos[5][i]);
          }
        }
    }
    if(distancia>=40 && distancia<49 ){
      void led();{
        for(int i=0;i<8;i++){
          digitalWrite(disp_pinos[i],digitos[4][i]);
          }
        }
    }
    if(distancia>=30 && distancia<39 ){
      void led();{
        for(int i=0;i<8;i++){
          digitalWrite(disp_pinos[i],digitos[3][i]);
          }
        }
    }
    if(distancia>=20 && distancia<29 ){
      void led();{
        for(int i=0;i<8;i++){
          digitalWrite(disp_pinos[i],digitos[2][i]);
          }
        }
    }
    if(distancia>=10 && distancia<19 ){
      void led();{
        for(int i=0;i<8;i++){
          digitalWrite(disp_pinos[i],digitos[1][i]);
          }
        }
    }
    result = String(distancia); //VARIÁVEL GLOBAL DO TIPO STRING RECEBE A DISTÂNCIA(CONVERTIDO DE INTEIRO PARA STRING)
    delay(400); //INTERVALO DE 500 MILISSEGUNDOS
 }
