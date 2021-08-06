// Tarefa 1C experimento 3 IECA
// Aluna Victória Clelia de Medeiros

// Definindo as constantes (pinos do arduino)
const int botao = 2; 
const int LEDg = 5; 
const int LEDy = 6; 
const int LEDr = 7; 
const int SPP = 9; 
const int SPJ = 10; 
const int buzzer = 3; 

// Definindo as variáveis
int modo = 1; // Começa ligado o modo do LED
float tempoa = millis(); // Começa o tempo em que o arduino liga
float tempob; // Apenas declarando tempob   

// Definindo entradas e saídas
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
 if (modo == 1) // Se o modo estiver ligado                        
{
  digitalWrite(LEDg,HIGH); // LED verde aceso                       
  digitalWrite(LEDy,LOW);
  digitalWrite(LEDr,LOW);
   
  if (digitalRead(SPJ) == HIGH) // Se o sensor da janela foi acionado
  { 
    modo = 2; // Vai para o modo alerta diretamente.
  }
  
  if ((digitalRead(SPP) == HIGH) && (digitalRead(botao) == LOW))  // Se o sensor da porta for acionado e o botão desliga não for pressionado ...
    {
      tempob = (millis() - tempoa); // Tempob vai ser a diferença do tempo a partir desse ponto e o inicial
      while (millis() - tempob < 3000) // Enquanto o tempo desde que o sensor da porta foi acionado e o botão desliga não foi pressionado for menor que 3s...
      { 
          if ((digitalRead(SPJ) == HIGH))// Se o sensor da janela for acionado
              {
                modo = 2;// Vai para o modo alerta, independentemente se o sensor da porta estiver acionado durantes esses 3s
              break; // Força a saída do modo alerta do sensor da janela do while
              }
      }
      modo = 2; // Quando o tempo de não pressionar o botão desliga e o sensor da porta acionado for maior que 3s ele passa ao modo alerta.
    }
 }

if (modo == 2)// Se estiver no modo alerta
{
  digitalWrite(LEDg,LOW);
  digitalWrite(LEDy,HIGH); // LED amarelo ligado
  digitalWrite(LEDr,LOW); 
  tone(buzzer,1500); // Define o buzzer no modo alerta
  delay(500);
  noTone(buzzer);
  delay(500);
}

if (modo == 3)// Se o modo desligado
{
  digitalWrite(LEDg,LOW);
  digitalWrite(LEDy,LOW);
  digitalWrite(LEDr,HIGH); // LED vermelho ligado
}

// A partir daqui é a configuração da mudança de modos conforme botão LIGA/DESLIGA é apertado

if ((digitalRead(botao) == HIGH) && (modo == 2)) // Se estiver no modo alerta e apertar o botão...
{
  while (digitalRead(botao) == HIGH)// Enquanto estiver pressionando o botão nada acontece
  {
      }
  modo = 3; // O modo muda para desligado
}
  
if (digitalRead(botao) == HIGH && (modo == 3)) // Se estiver no modo desligado e apertar o botao...
{
  while (digitalRead(botao) == HIGH) // Enquanto estiver com o botao apertado nada acontece.
  {    
      }
  modo = 1; // O modo muda para 1 para voltar ao modo ligado
}

if (digitalRead(botao) == HIGH && (modo == 1)) // Se estiver no modo ligado e apertar o botao...
{
  while (digitalRead(botao) == HIGH) // Enquanto estiver com o botao apertado nada acontece.
  {    
      }
  modo = 3; // O modo muda para 3, desligado, caso queira desligar o alarme
}

}
