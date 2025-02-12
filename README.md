# Atividade: Controle de Servo com PWM

Este projeto utiliza um servo motor controlado por PWM na GPIO 22 e LEDs RGB na GPIO 12 para simulação e análise.

## Descrição do Projeto
O código implementa os seguintes requisitos:

1. **Frequência de PWM:** Definida para 50Hz, correspondente a um período de 20ms.
2. **Posição de 180 graus:** PWM com ciclo ativo de 2.400µs (12%) e espera de 5 segundos.
3. **Posição de 90 graus:** PWM com ciclo ativo de 1.470µs (7,35%) e espera de 5 segundos.
4. **Posição de 0 graus:** PWM com ciclo ativo de 500µs (2,5%) e espera de 5 segundos.
5. **Movimentação Suave:** Movimentação periódica do servo entre 0 e 180 graus, com incremento de ±5µs e atraso de 10ms para ajuste suave.
6. **Experimento com LED RGB:** Utilização da ferramenta BitDogLab para observar o comportamento do LED RGB controlado pela GPIO 12.

## Requisitos
- Ambiente de desenvolvimento: VS Code com Pico SDK e simulador Wokwi.
- Hardware: Servo motor, LED RGB, GPIOs 22 e 12 configurados.

## Instalação
1. Clone este repositório para o seu ambiente local.
2. Configure o ambiente de desenvolvimento conforme as instruções do Pico SDK.

## Como Executar
1. Conecte o hardware ao microcontrolador.
2. Carregue o código no microcontrolador usando o VS Code.
3. Observe o comportamento do servo e do LED RGB.

## Experimento com LED RGB
Durante o experimento, foi observado que a iluminação do LED RGB variava conforme os sinais de PWM aplicados. Este comportamento reflete as mudanças de tensão nos pinos de controle.

## Demonstração em Vídeo
Confira o vídeo explicativo sobre a implementação deste projeto no link abaixo:

[Assista ao vídeo explicativo](https://drive.google.com/file/d/1bwOhAkmvrByAVeMtxrDYyQRZaLIajiAs/view?usp=sharing)



## Autor
Gabriel Santos dos Santos

---

Se houver dúvidas ou sugestões, fique à vontade para entrar em contato!
