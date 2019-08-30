#define PIN_BUILTIN_LED LED_BUILTIN

// https://gist.github.com/MightyPork/6da26e382a7ad91b5496ee55fdc73db2
#define KEYCODE_SPACE 0x2c
#define KEYCODE_F1 0x3a

// http://mitchtech.net/arduino-usb-hid-keyboard/
// Keyboard report buffer
uint8_t buf[8] = {
	0
};

void setup() {
	Serial.begin(9600);
	pinMode(PIN_BUILTIN_LED, OUTPUT);
}

void loop() {
	delay(random(60,240) * 1000);

	// Simulate keypress (and turn LED on)
	digitalWrite(PIN_BUILTIN_LED, HIGH);
	buf[2] = KEYCODE_SPACE;
	Serial.write(buf, 8);
	delay(200);

	// Simulate key release (and turn LED off)
	digitalWrite(PIN_BUILTIN_LED, LOW);
	buf[2] = 0;
	Serial.write(buf, 8);
	delay(200);
}
