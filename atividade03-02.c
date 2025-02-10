
#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/timer.h"
#include "ws2812.pio.h"
#include "inc/ssd1306.h"
#include "inc/font.h"
#include "hardware/i2c.h"

#define LED_RED 13
#define LED_GREEN 11
#define LED_BLUE 12
#define BUTTON_A 5 //GREEN
#define BUTTON_B 6 //BLUE
#define MATRIZ 7
#define NUM_PIXELS 25
#define IS_RGBW false 

static volatile uint32_t last_time = 0; // Armazena o tempo do último evento (em microssegundos)
//static volatile uint32_t cont = 0;
volatile bool led_update_flag = true; // Variável de controle para a atualização do buffer(Ajustar pois estava usando par a matrz)
volatile bool estate_A = 0;
volatile bool estate_B = 0;

// Buffer para armazenar quais LEDs estão ligados na matriz 5x5
bool led_buffer[NUM_PIXELS] = {
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0
};



void setup(){
    gpio_init(LED_BLUE);
    gpio_init(LED_GREEN);
    gpio_init(BUTTON_A);
    gpio_init(BUTTON_B);
    gpio_init(MATRIZ);

    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_set_dir(MATRIZ, GPIO_OUT);

    gpio_pull_up(BUTTON_A);
    gpio_pull_up(BUTTON_B);

    gpio_put(LED_BLUE, 0);
    gpio_put(LED_GREEN, 0);



}


// Função para mostrar o número na matriz (modificando o buffer)
void show_number(bool led_buffer[NUM_PIXELS], char cont) {
    switch (cont) {
        case '0':
            printf("\n Exibindo 0\n");
            bool matriz_0[NUM_PIXELS] = {
                0, 1, 1, 1, 0,
                0, 1, 0, 1, 0,
                0, 1, 0, 1, 0,
                0, 1, 0, 1, 0,
                0, 1, 1, 1, 0
            };
            for (int i = 0; i < NUM_PIXELS; i++) {
                led_buffer[i] = matriz_0[i];
            }
            break;

        case '1':
            printf("\n Exibindo 1\n");
            bool matriz_1[NUM_PIXELS] = {
                0, 1, 1, 1, 0,
                0, 0, 1, 0, 0,
                0, 0, 1, 0, 0,
                0, 1, 1, 0, 0,
                0, 0, 1, 0, 0
            };
            for (int i = 0; i < NUM_PIXELS; i++) {
                led_buffer[i] = matriz_1[i];
            }
            break;

        case '2':
            printf("\n Exibindo 2\n");
            bool matriz_2[NUM_PIXELS] = {
                0, 1, 1, 1, 0,
                0, 1, 0, 0, 0,
                0, 1, 1, 1, 0,
                0, 0, 0, 1, 0,
                0, 1, 1, 1, 0
            };
            for (int i = 0; i < NUM_PIXELS; i++) {
                led_buffer[i] = matriz_2[i];
            }
            break;

        case '3':
            printf("\n Exibindo 3\n");
            bool matriz_3[NUM_PIXELS] = {
                0, 1, 1, 1, 0,
                0, 0, 0, 1, 0,
                0, 1, 1, 1, 0,
                0, 0, 0, 1, 0,
                0, 1, 1, 1, 0
            };
            for (int i = 0; i < NUM_PIXELS; i++) {
                led_buffer[i] = matriz_3[i];
            }
            break;

        case '4':
            printf("\n Exibindo 4\n");
            bool matriz_4[NUM_PIXELS] = {
                0, 1, 0, 0, 0,
                0, 0, 0, 1, 0,
                0, 1, 1, 1, 0,
                0, 1, 0, 1, 0,
                0, 1, 0, 1, 0
            };
            for (int i = 0; i < NUM_PIXELS; i++) {
                led_buffer[i] = matriz_4[i];
            }
            break;

        case '5':
            printf("\n Exibindo 5\n");
            bool matriz_5[NUM_PIXELS] = {
                0, 1, 1, 1, 0,
                0, 0, 0, 1, 0,
                0, 1, 1, 1, 0,
                0, 1, 0, 0, 0,
                0, 1, 1, 1, 0
            };
            for (int i = 0; i < NUM_PIXELS; i++) {
                led_buffer[i] = matriz_5[i];
            }
            break;

        case '6':
            printf("\n Exibindo 6\n");
            bool matriz_6[NUM_PIXELS] = {
                0, 1, 1, 1, 0,
                0, 1, 0, 1, 0,
                0, 1, 1, 1, 0,
                0, 1, 0, 0, 0,
                0, 1, 1, 1, 0
            };
            for (int i = 0; i < NUM_PIXELS; i++) {
                led_buffer[i] = matriz_6[i];
            }
            break;

        case '7':
            printf("\n Exibindo 7\n");
            bool matriz_7[NUM_PIXELS] = {
                0, 1, 0, 0, 0,
                0, 0, 0, 1, 0,
                0, 1, 1, 0, 0,
                0, 0, 0, 1, 0,
                0, 1, 1, 1, 0
            };
            for (int i = 0; i < NUM_PIXELS; i++) {
                led_buffer[i] = matriz_7[i];
            }
            break;

        case '8':
            printf("\n Exibindo 8\n");
            bool matriz_8[NUM_PIXELS] = {
                0, 1, 1, 1, 0,
                0, 1, 0, 1, 0,
                0, 1, 1, 1, 0,
                0, 1, 0, 1, 0,
                0, 1, 1, 1, 0
            };
            for (int i = 0; i < NUM_PIXELS; i++) {
                led_buffer[i] = matriz_8[i];
            }
            break;

        case '9':
            printf("\n Exibindo 9\n");
            bool matriz_9[NUM_PIXELS] = {
                0, 1, 1, 1, 0,
                0, 0, 0, 1, 0,
                0, 1, 1, 1, 0,
                0, 1, 0, 1, 0,
                0, 1, 1, 1, 0
            };
            for (int i = 0; i < NUM_PIXELS; i++) {
                led_buffer[i] = matriz_9[i];
            }
            break;

        default:
        bool matriz_none[NUM_PIXELS] = {
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0
        };
        for (int i = 0; i < NUM_PIXELS; i++) {
            led_buffer[i] = matriz_none[i];
        }
            break;
    }
}


// Função para transmitir o valor de cada pixel
static inline void put_pixel(uint32_t pixel_grb)
{
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

// Função para converter a cor em valor que pode ser enviado
static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b)
{
    return ((uint32_t)(r) << 8) | ((uint32_t)(g) << 16) | (uint32_t)(b);
}

// Função para setar os LEDs com a cor desejada
void set_one_led(uint8_t r, uint8_t g, uint8_t b)
{
    // Define a cor com base nos parâmetros fornecidos
    uint32_t color = urgb_u32(r, g, b);
    
    // Define todos os LEDs com a cor especificada
    for (int i = 0; i < NUM_PIXELS; i++)
    {
        if (led_buffer[i])
        {
            put_pixel(color); // Liga o LED com um no buffer
        }
        else
        {
            put_pixel(0);  // Desliga os LEDs com zero no buffer
        }
    }
}

// Função de interrupção com debouncing
void gpio_irq_handler(uint gpio, uint32_t events)
{
    // Obtém o tempo atual em microssegundos
    uint32_t current_time = to_us_since_boot(get_absolute_time());
    
    
    // Verifica se passou tempo suficiente desde o último evento
    if (current_time - last_time > 200000) // 20 ms de debouncing
    {
        last_time = current_time; // Atualiza o tempo do último evento

        if (gpio == BUTTON_A) {
            estate_A = !estate_A;
            gpio_put(LED_GREEN, estate_A);
            //Exibir no monitor serial o estado do led GREEN
            printf("LED_GREEN: %s\n", estate_A ? "ON" : "OFF");
        
            
        } else if (gpio == BUTTON_B) {
            printf("Foi B\n");
            estate_B = !estate_B;
            gpio_put(LED_BLUE, estate_B);
            //Exibir no monitor serial o estado do led BLUE
            printf("LED_BLUE: %s\n", estate_B ? "ON" : "OFF");
            
        }

        led_update_flag = true; // Marca a flag para atualizar o led_buffer
    }
}



int main()
{
    stdio_init_all();
    setup();

    // Inicializar o pio para a comunicação com o WS2812
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, MATRIZ, 800000, IS_RGBW);

    
    
    
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled(BUTTON_B, GPIO_IRQ_EDGE_FALL, true);

    while (true) {
        if(stdio_usb_connected()){
            char n;
            scanf("%c", &n);
            show_number(led_buffer, n);
            set_one_led(LED_RED, 0, LED_BLUE); // Exibe a cor
        }
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
