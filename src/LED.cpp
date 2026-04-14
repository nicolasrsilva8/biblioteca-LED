#include <LED.h>

LED::LED(uint8_t pin) : //lista 
      pino(pin),
      estado(LOW),
      desligarPorTempo(false),
      desligarNoMomento(0),
      tempoAnteriorPiscar(0),
      tempoEspera(0),
      estadoPiscar(false),
      repeticoes(0)
{  
      pinMode(pino, OUTPUT);
}
 void LED::ligar() // liga o led
 {
      estado = HIGH; 
      desligarPorTempo = false;
      estadoPiscar = false;
 }

 void LED::ligar(uint32_t tempoligado_ms) // lig o led, depois de um tempo, ele desliga
 {
      estado = HIGH;
      desligarPorTempo = true;
      desligarNoMomento = millis() + tempoligado_ms;
      estadoPiscar = false; 
 }

 void LED::desligar() // desliga o led
 {
      estado = LOW;
      estadoPiscar = false;  
 }

 void LED::alternar() // alterna o estado do led
 {
      estado = !estado;     
 }

 void LED::update()  // atualiza o estado do led
 {
      if(desligarPorTempo) funcaoDesligamento();
      if(estadoPiscar) funcaoPiscar();

      digitalWrite(pino, estado);
 }

 bool LED::getEstado() // retorna ao estado inicial
 {
      return estado;
 }

uint8_t LED::getPino() // retorna ao pino inicial
{
      return pino;
}

void LED::setEstado(bool estado) // define o estado do led
{
      this-> estado = estado;
      desligarPorTempo = false;
      estadoPiscar =false; 
}

void LED::piscar()  //pisca o led infinitamente
{
      estadoPiscar = true;
      tempoEspera = 500;
      tempoAnteriorPiscar = millis();
      estado = HIGH;
      desligarPorTempo = false;
}

void LED::piscar(float frequencia) // pisca o led na frequencia desejada
{
      estadoPiscar = true;
      tempoEspera = (1000.0f / (2.0f *frequencia));
      tempoAnteriorPiscar = millis();
      estado = HIGH;
      desligarPorTempo = false;
}

void LED::piscar(uint8_t frequencia, uint16_t repeticoes) // pisca o led na frequencia desejada
                                                          //e a quantidade de vezes que o led vai piscar
{
      estadoPiscar = true;
      tempoEspera = (1000.0f / 2.0f *frequencia);
      tempoAnteriorPiscar = millis();
      estado = HIGH;
      this->repeticoes = repeticoes;
      desligarPorTempo = false; 
}

void LED::funcaoPiscar() // define a funccao de piscar
{
     if(millis() - tempoAnteriorPiscar >= tempoEspera)
     {
          estado = !estado;
          tempoAnteriorPiscar = millis();

     if(repeticoes > 0)
     {
          repeticoes--;
          if (repeticoes==0)
          {
               estadoPiscar = false;
               estado = LOW;
          }
     }
     }

}

void LED::funcaoDesligamento() // define a funcao de desligar
{
  if(millis()>= desligarNoMomento)
          {
            estado = LOW;
            desligarPorTempo = false;   
          }
}