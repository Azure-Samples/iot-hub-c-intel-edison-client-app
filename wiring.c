/*
 * IoT Hub sample for Intel Edison board - Microsoft Sample Code - Copyright (c) 2017 - Licensed MIT
 */
#include "./wiring.h"

static mraa_gpio_context m_gio;
static mraa_aio_context m_aio;

#if SIMULATED_DATA
float randomIn(int min, int max)
{
    int range = (int)(rand()) % (100 * (max - min));
    return min + (float)range / 100;
}

float readTemperature()
{
    return randomIn(20, 30);
}
#else
float readTemperature()
{
    int readValue = mraa_aio_read(m_aio);

    // how to calculate temperature: http://wiki.seeed.cc/Grove-Temperature_Sensor_V1.2/
    float R = 1023.0 / (float)readValue - 1.0;
    return 1.0 / (log((double)R) / 4275 + 1 / 298.15) - 273.15;
}
#endif

int readMessage(int messageId, char *payload)
{
    float temperature = readTemperature();
    snprintf(payload, BUFFER_SIZE, "{ messageId: %d, temperature: %f }",
             messageId,
             temperature);
    return (temperature > TEMPERATURE_ALERT) ? 1 : 0;
}

void blinkLED()
{
    mraa_gpio_write(m_gio, 1);
    sleep(1);
    mraa_gpio_write(m_gio, 0);
}

void setupWiring()
{
    m_aio = mraa_aio_init(SENSOR_PIN);
    if (m_aio == NULL)
    {
        (void)printf("Initialize pin %d failed", SENSOR_PIN);
    }
    m_gio = mraa_gpio_init(LED_PIN);
    if (m_gio == NULL)
    {
        (void)printf("Initialize pin %d failed", LED_PIN);
    }
    mraa_gpio_dir(m_gio, MRAA_GPIO_OUT);
}
