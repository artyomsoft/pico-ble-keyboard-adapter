#include "pico/stdlib.h"       // Базовые функции Pico (stdio, GPIO, sleep)
#include "pico/cyw43_arch.h"   // Работа с чипом связи (Wi-Fi/BT) и poll()
#include "tusb.h"              // Основные функции TinyUSB (tuh_init, tuh_task)
#include "bsp/board_api.h"     // Инициализация платы (board_init)
#include "hog_keyboard.h"      // Ваш заголовочный файл (btstack_start и GATT-база)

int main() {
    stdio_init_all();
    board_init();

    tuh_init(BOARD_TUH_RHPORT);

    if (board_init_after_tusb) {
        board_init_after_tusb();
    }

    btstack_start();

    while (true) {
        cyw43_arch_poll();
        tuh_task();
    }
}
