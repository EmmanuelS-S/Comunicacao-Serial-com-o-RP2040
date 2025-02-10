### Resumo da Atividade

Esta atividade visa consolidar o conhecimento sobre interfaces de comunicação serial e a utilização de diferentes componentes de hardware na placa BitDogLab 
com o microcontrolador RP2040. O objetivo é aplicar conceitos de UART, I2C, controle de LEDs e botões, além de manipular interrupções e debouncing.

#### Objetivos Principais:
- Compreender a comunicação serial em microcontroladores.
- Aplicar conceitos de UART e I2C.
- Controlar LEDs comuns e WS2812.(Não foi possível alcançar infelizmente)
- Utilizar botões de acionamento com interrupções e debouncing.
- Desenvolver um projeto funcional que combine hardware e software.

#### Componentes Utilizados:
- Matriz 5x5 de LEDs WS2812 (GPIO 7).
- LED RGB (GPIO 11, 12 e 13).
- Botões A e B (GPIO 5 e 6).
- Display SSD1306 (via I2C, GPIO 14 e 15).

#### Funcionalidades do Projeto:
1. Modificação da Biblioteca Font.h: Adicionar caracteres minúsculos.
2. Entrada de Caracteres via PC: Enviar caracteres via Serial Monitor e exibir no display SSD1306.
3. Botão A: Alternar o estado do LED RGB verde e registrar a operação no display e Serial Monitor.
4. Botão B: Alternar o estado do LED RGB azul e registrar a operação no display e Serial Monitor.

#### Requisitos:
- Interrupções: Funcionalidades dos botões implementadas com interrupções.
- Debouncing: Implementação de software para debouncing dos botões.
- Controle de LEDs: Uso de LEDs comuns e WS2812.
- Display SSD1306: Manipulação do display 128x64 via I2C.
- Comunicação Serial: Envio de informações via UART.
- Organização do Código: O código deve ser bem estruturado e comentado.



[🔗 Link para o vídeo do ensaio (duração máx. de 3 minutos)](https://drive.google.com/file/d/1zjNEiqAOYAcEgrUxBMav3noljQbGEE5J/view?usp=drive_link)


Essa atividade proporciona a integração entre conceitos de hardware e software, permitindo a prática de comunicações seriais, controle de dispositivos, 
e manipulação de interrupções e debouncing.
