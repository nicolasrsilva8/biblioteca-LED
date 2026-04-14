/**
 * @class LED
 * @brief Classe para controle não bloqueante de um LED.
 * permite ligar, desligar, ligar por tempo determinado,
 * piscar continuamente e piscar por quantidade definida
 * 
 * @note O método update() deve ser chamado continuamente dentro do loop().
 * 
 */
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

    /**
     * @brief processa a lógicade piscada do LED.
     */
    void funcaoPiscar();
    /**
     * @brief processa o desligamento temporizado.
     */
    void funcaoDesligamento();

    void funcaoPiscar();

    public:  


    /**
     * @brief Constroi um objeto LED.
     * @param pin Número do pino digital onde o LED está conectado.
     */
    LED(uint8_t pin);  


    /**
     * @brief Liga o LED continuamente.
     */
    void ligar();

    /**
     * @brief Liga o LED por um tempo determinado.
     * @param tempoligado_ms Tempo, em milissegundos, que o LED ficará ligado.
     */
    void ligar(uint32_t tempoLigado_ms);

    /**
     * @brief Desliga o LED e cancela os modos automáticos.
     */
    void desligar();

    /**
     * @brief Inicia a piscada continua em 1 Hz.
     */
    void piscar();

    /**
     * @brief Pisca o LED numa frequência definida em Hz.
     * @param frequencia Frequência da piscada em Hz.
     */
    void piscar(float frequencia);

    /**
     * @brief Pisca o LED uma quantidade definida de vezes.
     * @param frequencia Frequência da piscada em Hz.
     * @param repeticoes Quantidade d e piscadas completas.
     */
    void piscar(uint8_t frequencia, uint16_t repeticoes);

    /**
     * @brief define o estado inicial do LED.
     */
    bool getEstado(); 

    /**
     * @brief define o estado Inicial do pino
     */
    uint8_t getPino(); 
    
    /**
     *@brief Define manualmente o estado do LED.
     *@param estado Estado no qual o LED se encontra.
     */
    void setEstado(bool estado);

    /**
     * @brief Alterna o estado do LED.
     * se estado = true, HIGH - estado = false, LOW.
     * se estado = false, LOW - estado = true, HIGH.
     */
    void alternar(); 

    /**
     * @brief atualiza continuamente para 
     * verificar o estado atual do LED.
     */
    void update(); 


};

#endif // final do objeto