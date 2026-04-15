/*
Autor: Nicolas Rodrigo
programa: Multi pisca-LED 
Descrição: demonstração do funcionamento do comando "void piscar(float frequencia)".
Data: 15/04/26
Versão: 1.1.0

/**
 * Exemplo 1 - Multi pisca-LED.
 * 
 * Neste exemplo, será demonstrado o funcionamento da função "void piscar(float frequencia)".
 * Veja abaixo como esta função pode ser utilizada: 
 */

#include <Arduino.h>
#include <LED.h>

// Aqui está a definição dos pinos dos LEDs
LED ledAmarelo(45); 
LED ledVermelho(35);
LED ledVerde(37);

void setup() // Aqui é onde nós utilizaremos esta função:
{
 // Aqui, a frequência está definida como 1Hz, fazendo com que o LED pisque mais rápido.
 ledAmarelo.piscar(1);
 // Aqui, a frequência está definida como 2Hz, o dobro da frequência do LED acima.
 ledVermelho.piscar(2);
 // Aqui, a frequência está definida como 3Hz, o dobro da frequencia acima, sendo o LED que pisca mais devagar
 ledVerde.piscar(3);
}

void loop() 
{

 //O comando void update() é utilizado para ativar e atualizar todas as funções acima, sendo essencial para qualquer comando.
 //Lembre-se sempre de utilizar o .update() quando for utilizar os códigos da biblioteca.
 ledAmarelo.update();
 ledVermelho.update();
 ledVerde.update();
}

/**
 * Teste você mesmo este exemplo, e veja como a alernância das piscadas dos 3 leds é 1, 1/2, e 1/4.
 * 
 * FIM DO EXEMPLO 1!
 */


