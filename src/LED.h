#ifndef LED_h // inicio do objeto
#define LED_h

#include <Arduino.h>


class LED
{
private: // apenas o desenvolvedor tem acesso
    uint8_t pino;
    bool estado;
    bool desligarPorTempo;
    uint32_t desligarNoMomento;

    uint32_t tempoAnteriorPiscar;
    uint32_t tempoEspera;
    bool estadoPiscar;
    uint16_t repeticoes;

    void funcaoPiscar();
    void funcaoDesligamento();

    void funcaoPiscar();

public:    // acesso publico
    LED(uint8_t pin);  
    
    void ligar(); //ok
    void ligar(uint32_t tempoLigado_ms);

    void desligar(); //ok

    void piscar();
    void piscar(float frequencia);
    void piscar(uint8_t frequencia, uint16_t repeticoes);

    bool getEstado(); //ok
    uint8_t getPino(); //ok

    void setEstado(bool estado); //ok

    void alternar(); //ok

    void update(); //ok


};

#endif // final do objeto