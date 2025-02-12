#include <stdio.h>
#include "pico/stdlib.h"
#include "include/pwm.h"

#define GPIOSERVO 22 // 22 para servo e 12 para led
#define FREQUENCIA_PWM 50 // Frequência do PWM (50 Hz para servos)
#define PERIODO_PWM_US 20000 // Período em microssegundos (1 / 50 Hz)

uint slice; // Variável de propriedades PWM
uint16_t wrap[] = {2400, 1470, 500}; // duty_cycle = wrap / 20000
int i = 0;

// Função para mover o servo suavemente entre dois valores
void mover_suave(uint slice, uint16_t inicio, uint16_t fim, int passos, int intervalo_ms) {
    if (inicio < fim) {
        for (uint16_t nivel = inicio; nivel <= fim; nivel += (fim - inicio) / passos) {
            pwm_set_chan_level(slice, PWM_CHAN_A, nivel);
            sleep_ms(intervalo_ms);
        }
    } else {
        for (uint16_t nivel = inicio; nivel >= fim; nivel -= (inicio - fim) / passos) {
            pwm_set_chan_level(slice, PWM_CHAN_A, nivel);
            sleep_ms(intervalo_ms);
        }
    }
}

int main() {
    stdio_init_all();

    // Configuração do PWM
    gpio_set_function(GPIOSERVO, GPIO_FUNC_PWM);
    slice = pwm_gpio_to_slice_num(GPIOSERVO);
    pwm_set_clkdiv(slice, 125.0f); // (125MHz / (50Hz * 20000) = 125)
    pwm_set_wrap(slice, 20000);    // 1 wrap = 1us 
    pwm_set_enabled(slice, true);  // Habilita o PWM 

    while (true) {
        int j = (i + 1) % 3;
        mover_suave(slice, wrap[i], wrap[j], 20, 20); // 20 passos, 10ms entre cada passo
        i = j;
        sleep_ms(5000); // Aguarda 5 segundos antes da próxima movimentação
    }

    return 0;
}
