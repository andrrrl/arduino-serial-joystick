// Sends Joystick values through COM port (USB)
// Joystick used: generic "DIYables Joystick for Arduino"
// RGB LED is just for joystic feedback

#define LED_ON HIGH
#define LED_OFF LOW

// Arduino digital pins for RGB LED:
const int LED_R = 2;
const int LED_G = 3;
const int LED_B = 4;

// Arduino Analog pins for Joystic:
#define VRX_PIN A0 // Joystick X => Arduino Analog pin 0
#define VRY_PIN A1 // Joystick Y => Arduino Analog pin 1

int xValue = 0;
int yValue = 0;

void setup()
{
  Serial.begin(9600);
  // All LEDs in output mode
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

void loop()
{

  // Read analog X and Y analog values
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);

  // Warning:
  // X axis moves UP/DOWN
  // Y axis moves LEFT/RIGHT
  // This is just for comfort when using the joystick

  // Move DOWN
  if (xValue > 950)
  {
    digitalWrite(LED_R, LED_OFF);
    digitalWrite(LED_G, LED_ON);
    digitalWrite(LED_B, LED_OFF);
    Serial.println("ArrowDown");
  }

  // Move UP
  if (xValue < 100)
  {
    digitalWrite(LED_G, LED_OFF);
    digitalWrite(LED_R, LED_OFF);
    digitalWrite(LED_B, LED_OFF);
    Serial.println("ArrowUp");
  }

  // Move LEFT
  if (yValue > 950)
  {
    digitalWrite(LED_R, LED_OFF);
    digitalWrite(LED_G, LED_OFF);
    digitalWrite(LED_B, LED_ON);
    Serial.println("ArrowLeft");
  }

  // Move RIGHT
  if (yValue < 100)
  {
    digitalWrite(LED_R, LED_ON);
    digitalWrite(LED_G, LED_OFF);
    digitalWrite(LED_B, LED_OFF);
    Serial.println("ArrowRight");
  }

  // Wait 200 ms between readings
  delay(200);
}