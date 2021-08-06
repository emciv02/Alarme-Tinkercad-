const int botao = 2; 
const int LEDg = 5; 
const int LEDy = 6; 
const int LEDr = 7; 
const int SPP = 9; 
const int SPJ = 10; 
const int buzzer = 3; 

int modo = 1;  // Começa ligado o modo do LED

void setup() {
  pinMode(botao,INPUT);
  pinMode(SPP,INPUT);
  pinMode(SPJ,INPUT);                             
  pinMode(LEDg,OUTPUT);
  pinMode(LEDy,OUTPUT);
  pinMode(LEDr,OUTPUT);
  pinMode(buzzer,OUTPUT);
}
 
void loop() {
 if (modo == 1) // Modo ligado                        
{
  digitalWrite(LEDg,HIGH);                        
  digitalWrite(LEDy,LOW);
  digitalWrite(LEDr,LOW);
  if ((digitalRead(SPP) == HIGH) || (digitalRead(SPJ) == HIGH))
  {
    modo = 2;
  }
}

if (modo == 2) // Modo alerta
{
  digitalWrite(LEDg,LOW);
  digitalWrite(LEDy,HIGH);
  digitalWrite(LEDr,LOW); 
  tone(buzzer,1500);
  delay(500);
  noTone(buzzer);
  delay(500);
}

if (modo == 3)
{
  digitalWrite(LEDg,LOW);
  digitalWrite(LEDy,LOW);
  digitalWrite(LEDr,HIGH);
}

// 

if ((digitalRead(botao) == HIGH) && (modo == 2)) // Se estiver no modo alerta e apertar o botão...
{
  while (digitalRead(botao) == HIGH)            // Enquanto estiver pressionando o botão nada acontece
  {
      }
  modo = 3;                                     // O modo muda para desligado
}
  
if (digitalRead(botao) == HIGH && (modo == 3)) // Se estiver no modo desligado e apertar o botao...
{
  while (digitalRead(botao) == HIGH)           //enquanto estiver com o botao apertado nada acontece.
  {    
      }
  modo = 1;                                   // O modo muda para 1 para voltar ao modo ligado
}

if (digitalRead(botao) == HIGH && (modo == 1)) // Se estiver no modo ligado e apertar o botao...
{
  while (digitalRead(botao) == HIGH)           //enquanto estiver com o botao apertado nada acontece.
  {    
      }
  modo = 3;                                   // O modo muda para 3, desligado, caso queira desligar o alarme
}

}
