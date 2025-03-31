#include <SoftwareSerial.h>

#define APC_RX 10
#define APC_TX 11
#define APC_SET 12

#define FREQ "434000"

SoftwareSerial APC220(APC_RX,APC_TX);

void setup_APC()
{
    char cmd[20];
    sprintf(cmd,"WR %s 3 9 0 0", FREQ);
    Serial.println(cmd);

    digitalWrite(APC_SET, LOW);
    delay(10);
    APC220.println(cmd);
    delay(10);

    while(APC220.available())
    {
        Serial.write(APC220.read());
    }

    digitalWrite(APC_SET, HIGH);
    delay(200);
}

void setup()
{
    pinMode(APC_SET, OUTPUT);

    Serial.begin(9600);
    APC220.begin(9600);

    setup_APC();
}

void loop()
{

}
