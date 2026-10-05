const int startButton = 2;

const int buttons[4] = {3, 4, 5, 6};
const int leds[4]    = {7, 8, 9, 10};

const int MAX_LEVEL = 50;
int sequence[MAX_LEVEL];

int level = 1;

void setup() {

  pinMode(startButton, INPUT_PULLUP);

  for (int i = 0; i < 4; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
    pinMode(leds[i], OUTPUT);
  }

  randomSeed(analogRead(A0));
}

void loop() {

  // انتظر كبسة START
  if (digitalRead(startButton) == LOW) {

    delay(200);

    level = 1;

    // أول رقم عشوائي
    sequence[0] = random(0, 4);

    while (true) {

      // عرض التسلسل
      for (int i = 0; i < level; i++) {

        digitalWrite(leds[sequence[i]], HIGH);
        delay(500);

        digitalWrite(leds[sequence[i]], LOW);
        delay(250);
      }

      // اللاعب يعيد التسلسل
      for (int i = 0; i < level; i++) {

        int pressed = waitForButton();

        // إذا ضغط الزر الغلط
        if (pressed != sequence[i]) {

          gameOver();
          return;
        }
      }

      // صح → زيد مرحلة
      if (level < MAX_LEVEL) {

        sequence[level] = random(0, 4);
        level++;

        delay(700);
      }
    }
  }
}


// انتظر اللاعب يضغط زر
int waitForButton() {

  while (true) {

    for (int i = 0; i < 4; i++) {

      if (digitalRead(buttons[i]) == LOW) {

        // ضوي LED تبع الزر
        digitalWrite(leds[i], HIGH);

        delay(200);

        // انتظر يرفع إصبعه
        while (digitalRead(buttons[i]) == LOW);

        digitalWrite(leds[i], LOW);

        delay(100);

        return i;
      }
    }
  }
}


// عند الخسارة
void gameOver() {

  // كل الأضواء تومض 3 مرات
  for (int x = 0; x < 3; x++) {

    for (int i = 0; i < 4; i++)
      digitalWrite(leds[i], HIGH);

    delay(300);

    for (int i = 0; i < 4; i++)
      digitalWrite(leds[i], LOW);

    delay(300);
  }

  // بعدها لازم تكبس START من جديد
}