#include <NewPing.h>
#include <NewTone.h>
 
// Selecione quais pinos compatíveis com PWM devem ser usados.
#define RED_PIN 10
#define GREEN_PIN 11
#define BLUE_PIN 9
 
#define TRIGGER_PIN 6 // Pino Arduino preso ao gatilho no sensor ultrassônico.
#define ECHO_PIN 7 // Pino Arduino preso ao pino de eco no sensor ultrassônico.
#define MAX_DISTANCE 200 // Distância máxima que queremos fazer ping para (em centímetros).
 
Sonar NewPing ( TRIGGER_PIN , ECHO_PIN , MAX_DISTANCE ) ; // NewPing configuração de pinos e distância máxima.
booleano acionado = falso ;
 
 
#define ALARM 3
float sinVal ;
int toneVal ;
 
void setup ( ) {
   
 // set pinModes para tira RGB
   pinMode ( RED_PIN , OUTPUT ) ;
   pinMode ( BLUE_PIN , OUTPUT ) ;
   pinMode ( GREEN_PIN , OUTPUT ) ;
   
   pinMode ( ALARM , OUTPUT ) ;
 
   // reset lights
   analogWrite ( RED_PIN , 0 ) ;
   analogWrite ( BLUE_PIN , 0 ) ;
   analogWrite ( RED_PIN , 0 ) ;
 
  atraso ( 5000 ) ;
Serial. begin ( 115200 ) ; // Abra o monitor serial a 115200 baud para ver os resultados do ping.  
 
 
}
 
void loop ( ) {
    if ( acionado == verdadeiro ) {
      alarme ( ) ;
    }
    mais {
      atraso ( 50 ) ; // Aguarde 50 ms entre pings (cerca de 20 pings / seg). 29ms deve ser o menor atraso entre os pings.
      unsigned int uS = sonar. ping ( ) ; // Envie ping, obtenha o tempo de ping em microssegundos (uS).
      distância int não assinada = uS / US_ROUNDTRIP_CM ;
      Serial. println ( distância ) ;
      if ( distance < 50 ) {
         triggered = true ;
      }
   }
}
 
void alarm ( ) {
   cor ( 255 , 0 , 0 ) ; //vermelho
   atraso ( 100 ) ;
   cor ( 255 , 255 , 0 ) ; // yelow
   atraso ( 100 ) ;
   
   para ( int x = 0 ; x < 180 ; x ++ ) {
    // converte graus em radianos e obtém o valor de sin
    sinVal = ( sin ( x * ( 3,1412 / 180 ) ) ) ;
    // gera uma frequência do valor de pecado
    toneVal = 2000 + ( int ( sinVal * 1000 ) ) ;
    NewTone ( ALARM , toneVal ) ;
  }
}
 
// função auxiliar que nos permite enviar uma cor em um comando
cor vazia ( unsigned char vermelho , unsigned char verde , unsigned char blue )     // a função de geração de cor
{    
    analogWrite ( RED_PIN , vermelho ) ;    
    analogWrite ( BLUE_PIN , blue ) ;
    analogWrite ( GREEN_PIN , verde ) ;
}
