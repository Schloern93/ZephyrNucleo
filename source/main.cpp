#include <zephyr.h>
#include <device.h>
#include <drivers/gpio.h>

#define LED_PORT DT_GPIO_LABEL(DT_ALIAS(led0), gpios)
#define LED_PIN DT_GPIO_PIN(DT_ALIAS(led0), gpios)

void main(void) {
    const struct device *led_device;
    int ret;

    // Gerät für die LED abrufen
    led_device = device_get_binding(LED_PORT);
    if (led_device == NULL) {
        printk("Fehler: LED Gerät nicht gefunden!\n");
        return;
    }

    // LED Pin konfigurieren
    ret = gpio_pin_configure(led_device, LED_PIN, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        printk("Fehler: GPIO Pin konfigurieren fehlgeschlagen: %d\n", ret);
        return;
    }

    while (1) {
        // LED einschalten
        gpio_pin_set(led_device, LED_PIN, 1);
        k_msleep(500); // 500 ms warten

        // LED ausschalten
        gpio_pin_set(led_device, LED_PIN, 0);
        k_msleep(500); // 500 ms warten
    }
}