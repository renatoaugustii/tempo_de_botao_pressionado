/*
   CONTADOR DE TEMPO DE ACIONAMENTO DO BOTÃO
   
   Author: Eng. Renato Augusto
    
   OBJETIVO: O programa foi desenvolvido com o intuito de desenvolver um método que conta quanto tempo o botão ficou pressionado. Essa função poderá ser usada para entradas em menus,
   lógicas temporais ou qualquer outra. No código foi desenvolvido para que quando acionado por 3 segundos o Led na porta 13 irá ficar ligado por 5 Segundos. 
   
   Github: https://github.com/renatoaugustii
   
   **  CONTROLE DE VERSÕES **
   Versão: 1.0 - Por Renato Augusto
   Data: 04/03/2021
   Belo Horizonte - MG / Brasil 
   
   Qualquer dúvida ou sujestão entre em contato:
   renato.augusto.correa@outlook.com
   
*/

/**DEFINIÇÃO DE PINAGENS**/
#define BTN 6
#define LED 13

/**ESCOBO DE DECLARAÇÃO DE VARIÁVEIS**/
bool btn_flag = false; // FLAG AUXILIAR PARA CONTAGEMD E TEMPO DE BOTÃO
bool led_flag = false; // FLAG AUXILIAR PARA LIGAR O LED POR UM PERIODO DETERMINADO
bool flag_led_tempo = 0; // DECLARAÇÃO DE VARIÁVEL PARA CALCULO DE LED LIGADO

long tempo_inicial = 0; // DECLARAÇÃO DE VARIÁVEL DO CÁLCULO DE TEMPO
long tempo_inicial_led = 0; // DECLARAÇÃO DE VÁRIÁVEL PARA CÁLCULO TEMPO DO LED

void setup() {
  pinMode(BTN,INPUT); // BOTÃO CONFIGURADO COMO ENTRADA DIGITAL
  pinMode(LED,OUTPUT); // SAÍDA DIGITAL NO PINO SELECIONADO
  //tempo_inicial = millis(); //GUARDA VALOR INICIAL DE PROCESSAMENTO
  Serial.begin(9600);
}

void loop() {

  bool botao_on = digitalRead(BTN);
  if (botao_on == true){
      if (btn_flag == false){
        tempo_inicial = millis();
        btn_flag = 1; 
      } // compara se o botão já havia sido pressionado, caso não tenha ainda, inicia o contador e marca a flag de acionamento.

      // Condicional para comparação de tempo decorrido
      if ((millis()-tempo_inicial)>=3000){led_flag = true;}// aciona o led caso o botão esteja pressionado a pelo menos 3segundos
    }
  else
     {
       btn_flag = 0; // DESMARCA A FLAG DE BOTÃO PRESSIONADO PARA NÃO ENTRAR NOVAMENTE NO LOOP.
      }  

  if (led_flag == true) {
      if (flag_led_tempo == false){ tempo_inicial_led = millis(); flag_led_tempo = true;}
      
      //condicional de comparação de tempo decorrido do led ligado
      if ((millis()-tempo_inicial_led)>=5000){digitalWrite(LED,LOW);led_flag = false;flag_led_tempo = false;} // DESLIGA O LED CASO ELE JÁ ESTEJA LIGADO POR 5 SEGUNDOS OU MAIS 
      else
      {digitalWrite(LED,HIGH);} // LIGA O LED SE A FLAG FOR VERDADEIRA
    }
}
 
