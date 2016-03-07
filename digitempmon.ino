#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 8

OneWire ourWire(ONE_WIRE_BUS);
DallasTemperature sensors(&ourWire);

int led = 13;

void blink()
{
    digitalWrite(led, HIGH);
    delay(111);

    digitalWrite(led, LOW);
    delay(222);
}

void pulse(int n)
{
    int i;
    for(i = 0; i < n; i = i+1) {
        blink();
    }

    delay(500);
}

void sequence(int n)
{
    int lg = 25;
    int sm = 5;

    pulse(n/lg);
    pulse((n%lg)/sm);
    pulse((n%lg)%sm);
}

void setup()
{
    pinMode(led, OUTPUT);
    sensors.begin();
}

void loop()
{
    sensors.requestTemperatures();

    int t = sensors.getTempFByIndex(0); // sensors.getTempCByIndex(0);

    sequence(t);
    delay(6000);
}
