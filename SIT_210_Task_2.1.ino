const int buttonPin = 2;
const int ledPin = 13;

int buttonState = 0;
int lastButtonState = 0;
bool blinking = false;
const char* name = "KHUSHI"; // Change this to your first name
int nameLength = strlen(name);

// Define Morse code for each letter (A-Z)
const char* morseCode[] = {
 ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."  
};

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      blinking = !blinking; // Toggle blinking state
      if (blinking) {
        blinkName();
      } else {
        digitalWrite(ledPin, LOW); // Turn off LED if blinking is stopped
      }
    }
    lastButtonState = buttonState;
  }
}

void blinkName() {
  for (int i = 0; i < nameLength; i++) {
    char letter = toupper(name[i]);
    if (letter >= 'A' && letter <= 'Z') {
      int index = letter - 'A';
      if (index >= 0 && index < 26) {
        const char* morse = morseCode[index];
        for (int j = 0; morse[j] != '\0'; j++) {
          if (morse[j] == '.') {
            digitalWrite(ledPin, HIGH);
            delay(200); // Dot duration
          } else if (morse[j] == '-') {
            digitalWrite(ledPin, HIGH);
            delay(600); // Dash duration
          }
          digitalWrite(ledPin, LOW);
          delay(200); // Gap between dots and dashes
        }
      }
      delay(600); // Gap between letters
    }
  }
}
