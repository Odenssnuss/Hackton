#include <LiquidCrystal.h>
#include <stdlib.h>

String words[] = {
  "apple", "banana", "car", "dog", "elephant", "flower", "guitar", "house", "ice cream", "jungle",
  "kangaroo", "lion", "moon", "nest", "ocean", "piano", "queen", "rainbow", "sun", "tree",
  "umbrella", "violin", "watermelon", "xylophone", "yacht", "zebra", "airplane", "ball", "cat", "dolphin",
  "elephant", "fire", "guitar", "horse", "island", "jacket", "kite", "lemon", "mountain", "notebook",
};
int numWords = sizeof(words) / sizeof(words[0]);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

unsigned long roundStartTime;
unsigned long roundDuration = 15000;  // 15 seconds

int score = 0;

void setup() {
  pinMode(13, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.setCursor(5, 0);
  lcd.print("KASTrulya!");
  lcd.setCursor(0, 1);
  lcd.print("Press to start!");
}

void loop() {
  if (!digitalRead(13) == HIGH) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Word: ");

    int randomIndex = random(numWords);
    lcd.setCursor(0, 1);
    lcd.print(words[randomIndex]);

    roundStartTime = millis();  // Start the round timer
  }

  // Check if the round time has elapsed
  if (millis() - roundStartTime >= roundDuration) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Time's up!");
    lcd.setCursor(0, 1);
    lcd.print("Tap to play!");

    // Add your code to handle the end of the round here
    score++;
    lcd.setCursor(0, 1);
    lcd.print("Score: ");
    lcd.print(score);
    delay(2000);  // Delay to display the score for 2 seconds

  } else {
    // Calculate the remaining time
    unsigned long elapsedTime = millis() - roundStartTime;
    unsigned long remainingTime = roundDuration - elapsedTime;

    // Convert remaining time to seconds
    unsigned int seconds = remainingTime / 1000;

    // Display the countdown on the top right corner of the screen
    lcd.setCursor(12, 0);
    lcd.print(seconds);
    lcd.print("s");
  }
}