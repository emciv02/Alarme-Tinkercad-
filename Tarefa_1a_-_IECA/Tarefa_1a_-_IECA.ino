const int botao = 2; //definindo pino do botao
const int LEDg = 5; //definindo pino do LED verde
const int LEDy = 6; //definindo pino do LED amarelo
const int LEDr = 7; //definindo pino do LED vermelho

int modo = 1; //começa ligado

void setup() {
  pinMode(botao,INPUT);                             
  pinMode(LEDg,OUTPUT);
  pinMode(LEDy,OUTPUT);
  pinMode(LEDr,OUTPUT);
}
 
void loop() {
 if (modo == 1)                                   
{
  digitalWrite(LEDg,HIGH);                        
  digitalWrite(LEDy,LOW);
  digitalWrite(LEDr,LOW);
}

if (modo == 2)
{
  digitalWrite(LEDg,LOW);
  digitalWrite(LEDy,HIGH);
  digitalWrite(LEDr,LOW); 
}

if (modo == 3)
{
  digitalWrite(LEDg,LOW);
  digitalWrite(LEDy,LOW);
  digitalWrite(LEDr,HIGH);
}
//
if ((digitalRead(botao) == HIGH) && (modo == 1)) //se estiver no modo ligado e apertar o botão...
{
  while (digitalRead(botao) == HIGH)            //enquanto o botão estiver pressionado nada acontece.
  {
    }
   modo = 2;                                   //o modo muda para alerta.
}
if ((digitalRead(botao) == HIGH) && (modo == 2)) // se estiver no modo alerta e apertar o botão...
{
  while (digitalRead(botao) == HIGH)            //enquanto estiver pressionando o botão nada acontece
  {
      }
  modo = 3;                                     //o modo muda para desligado
  }
if (digitalRead(botao) == HIGH && (modo == 3)) //se estiver no modo desligado e apertar o botao...
{
  while (digitalRead(botao) == HIGH)           //enquanto estiver com o botao apertado nada acotece.
  {    
      }
  modo = 1;                                   //o modo muda para 1 para voltar ao modo ligado
}
  
}
