const int bab = 9;
const int btime = 8;
const int bmole_1 = 22;
const int bmole_2 = 23;
const int bmole_3 = 24;
const int bmole_4 = 25;
const int bmole_5 = 26;
const int bmole_6 = 27;

const int onTime = 1000;

const int mole_1 = 2;
const int mole_2 = 3;
const int mole_3 = 4;
const int mole_4 = 5;
const int mole_5 = 6;
const int mole_6 = 7;


int dif = 10;
int mole_counter = 0;
int gameMode = 3;
int stateAbility = 0;
int stateTime = 0;
int score = 0;

int val;
int val2;
int val3;
int val4;
int val5;
int val6;

unsigned long dif_t0 = 0;
unsigned long dif_t0_last = 0;

boolean inGame = false;

boolean point_mole1 = false;
boolean point_mole2 = false;
boolean point_mole3 = false;
boolean point_mole4 = false;
boolean point_mole5 = false;
boolean point_mole6 = false;

unsigned long timeStart = 0;

unsigned long t0mole_1 = 0;
unsigned long t0mole1_last = 0;
unsigned long t0mole_2 = 0;
unsigned long t0mole2_last = 0;
unsigned long t0mole_3 = 0;
unsigned long t0mole3_last = 0;
unsigned long t0mole_4 = 0;
unsigned long t0mole4_last = 0;
unsigned long t0mole_5 = 0;
unsigned long t0mole5_last = 0;
unsigned long t0mole_6 = 0;
unsigned long t0mole6_last = 0;

void setup() {
  Serial.begin(9600);
  pinMode(A15, INPUT);
  randomSeed(analogRead(A15));
  pinMode(bab, INPUT);
  pinMode(btime, INPUT);
  pinMode(bmole_1, INPUT);
  pinMode(mole_1, OUTPUT);
  pinMode(bmole_2, INPUT);
  pinMode(mole_2, OUTPUT);
  pinMode(bmole_3, INPUT);
  pinMode(mole_3, OUTPUT);
  pinMode(bmole_4, INPUT);
  pinMode(mole_4, OUTPUT);
  pinMode(bmole_5, INPUT);
  pinMode(mole_5, OUTPUT);
  pinMode(bmole_6, INPUT);
  pinMode(mole_6, OUTPUT);
  val = 102 * random(10, dif * 10);
  val2 = 105 * random(10, dif * 10);
  val3 = 120 * random(10, dif * 10);
  val4 = 140 * random(10, dif * 10);
  val5 = 104 * random(10, dif * 10);
  val6 = 113 * random(10, dif * 10);
}

void loop() {
  checkBtn();
  if (gameMode == 0) {
    abilityMode();
  }
  if (gameMode == 1) {
    timeMode();
  }
}
void game() {
  mole1();
  mole2();
  mole3();
  mole4();
  mole5();
  mole6();

  if (dif_t0 - dif_t0_last >= 10000) {
    if (dif > 2) {
      dif = dif - 1;
    }
  }

}
void mole1() {
  t0mole_1 = millis();
  if (t0mole_1 - t0mole1_last >= val) {
    if (digitalRead(mole_1) == HIGH) {
      digitalWrite(mole_1 , LOW);
      Serial.println("1L");
      if (!point_mole1 && gameMode == 0) {
        stateTime = 2;
      }
      val = (100 * random(10, dif * 10));
      mole_counter = mole_counter - 1;
      point_mole1 = false;
    } else if (digitalRead(mole_1) == LOW) {
      digitalWrite(mole_1 , HIGH);
      Serial.println("1H");
      mole_counter = mole_counter + 1;
      val = onTime;
    }

    t0mole1_last = millis();
  }
  if (digitalRead(bmole_1) && digitalRead(mole_1) && !point_mole1) {
    point_mole1 = true;
    score = score + 1;
    Serial.print("Score: ");
    Serial.println(score);
  }
}
void mole2() {
  t0mole_2 = millis();
  if (t0mole_2 - t0mole2_last >= val2) {
    if (digitalRead(mole_2) == HIGH) {
      digitalWrite(mole_2 , LOW);
      Serial.println("2L");
      if (!point_mole2 && gameMode == 0) {
        stateTime = 2;
      }
      val2 = (100 * random(10, dif * 10));
      mole_counter = mole_counter - 1;
      point_mole2 = false;
    } else if (digitalRead(mole_2) == LOW) {
      digitalWrite(mole_2 , HIGH);
      Serial.println("2H");
      mole_counter = mole_counter + 1;
      val2 = onTime;
    }
    t0mole2_last = millis();
  }
  if (digitalRead(bmole_2) && digitalRead(mole_2) && !point_mole2) {
    point_mole2 = true;
    score = score + 1;
    Serial.print("Score: ");
    Serial.println(score);
  }
}
void mole3() {
  t0mole_3 = millis();
  if (t0mole_3 - t0mole3_last >= val3) {
    if (digitalRead(mole_3) == HIGH) {
      digitalWrite(mole_3 , LOW);
      Serial.println("3L");
      if (!point_mole2 && gameMode == 0) {
        stateTime = 2;
      }
      val3 = (100 * random(10, dif * 10));
      mole_counter = mole_counter - 1;
      point_mole3 = false;
    } else if (digitalRead(mole_3) == LOW) {
      digitalWrite(mole_3 , HIGH);
      Serial.println("3H");
      mole_counter = mole_counter + 1;
      val3 = onTime;
    }
    t0mole3_last = millis();
  }
  if (digitalRead(bmole_3) && digitalRead(mole_3) && !point_mole3) {
    point_mole3 = true;
    score = score + 1;
    Serial.print("Score: ");
    Serial.println(score);
  }
}
void mole4() {
  t0mole_4 = millis();
  if (t0mole_4 - t0mole4_last >= val4) {
    if (digitalRead(mole_4) == HIGH) {
      digitalWrite(mole_4 , LOW);
      Serial.println("4L");
      if (!point_mole2 && gameMode == 0) {
        stateTime = 2;
      }
      val4 = (100 * random(10, dif * 10));
      mole_counter = mole_counter - 1;
      point_mole4 = false;
    } else if (digitalRead(mole_4) == LOW) {
      digitalWrite(mole_4 , HIGH);
      Serial.println("4H");
      mole_counter = mole_counter + 1;
      val4 = onTime;
    }
    t0mole4_last = millis();
  }
  if (digitalRead(bmole_4) && digitalRead(mole_4) && !point_mole4) {
    point_mole4 = true;
    score = score + 1;
    Serial.print("Score: ");
    Serial.println(score);
  }
}
void mole5() {
  t0mole_5 = millis();
  if (t0mole_5 - t0mole5_last >= val5) {
    if (digitalRead(mole_5) == HIGH) {
      digitalWrite(mole_5 , LOW);
      Serial.println("5L");
      if (!point_mole5 && gameMode == 0) {
        stateTime = 2;
      }
      val5 = (100 * random(10, dif * 10));
      mole_counter = mole_counter - 1;
      point_mole5 = false;
    } else if (digitalRead(mole_5) == LOW) {
      digitalWrite(mole_5 , HIGH);
      Serial.println("5H");
      mole_counter = mole_counter + 1;
      val5 = onTime;
    }
    t0mole5_last = millis();
  }
  if (digitalRead(bmole_5) && digitalRead(mole_5) && !point_mole5) {
    point_mole5 = true;
    score = score + 1;
    Serial.print("Score: ");
    Serial.println(score);
  }

}
void mole6() {
  t0mole_6 = millis();
  if (t0mole_6 - t0mole6_last >= val6) {
    if (digitalRead(mole_6) == HIGH) {
      digitalWrite(mole_6 , LOW);
      Serial.println("6L");
      if (!point_mole6 && gameMode == 0) {
        stateTime = 2;
      }
      val6 = (100 * random(10, dif * 10));
      mole_counter = mole_counter - 1;
      point_mole6 = false;
    } else if (digitalRead(mole_6) == LOW) {
      digitalWrite(mole_6 , HIGH);
      Serial.println("6H");
      mole_counter = mole_counter + 1;
      val6 = onTime;
    }

    t0mole6_last = millis();
  }
  if (digitalRead(bmole_6) && digitalRead(mole_6) && !point_mole6) {
    point_mole6 = true;
    score = score + 1;
    Serial.print("Score: ");
    Serial.println(score);
  }
}
void abilityMode() {
  switch (stateTime) {
    case 0:
      delay(5000);
      stateTime = 1;
      inGame = true;
      timeStart = millis();
      randomi();
      break;
    case 1:
      game();
      break;
    case 2:
      gameMode = 3;
      stateTime = 0;
      off();
      inGame = false;
      dif = 10;
      score = 0;
      randomi();
      Serial.println("Game Over!");
      break;
  }
}
void timeMode() {
  if ((millis() - timeStart) < 60000) {
    switch (stateTime) {
      case 0:
        delay(5000);
        stateTime = 1;
        inGame = true;
        timeStart = millis();
        randomi();
        break;
      case 1:
        game();
        break;
    }
  } else {
    gameMode = 3;
    stateTime = 0;
    off();
    inGame = false;
    dif = 10;
    score = 0;
    randomi();
    Serial.println("Game Over!");
  }
}
void randomi() {
  val = 102 * random(10, dif * 10);
  val2 = 105 * random(10, dif * 10);
  val3 = 120 * random(10, dif * 10);
  val4 = 140 * random(10, dif * 10);
  val5 = 104 * random(10, dif * 10);
  val6 = 113 * random(10, dif * 10);
}
void off() {
  digitalWrite(mole_1, LOW);
  digitalWrite(mole_2, LOW);
  digitalWrite(mole_3, LOW);
  digitalWrite(mole_4, LOW);
  digitalWrite(mole_5, LOW);
  digitalWrite(mole_6, LOW);
  digitalWrite(mole_1, LOW);
  digitalWrite(mole_1, LOW);
  digitalWrite(mole_1, LOW);
  Serial.println("1L");
  Serial.println("2L");
  Serial.println("3L");
  Serial.println("4L");
  Serial.println("5L");
  Serial.println("6L");
}
void checkBtn() {
  if (digitalRead(bab) && !inGame) {
    gameMode = 0;
  }
  if (digitalRead(btime) &&  !inGame) {
    gameMode = 1;
  }
}
