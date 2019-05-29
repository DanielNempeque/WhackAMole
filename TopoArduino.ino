//Define the buttons for the gamemodes
const int bab = 51; //Button ability
const int btime = 50; //Button time

//Setup of the buttons of every single button
const int bmole_1 = 22;
const int bmole_2 = 23;
const int bmole_3 = 24;
const int bmole_4 = 25;
const int bmole_5 = 26;
const int bmole_6 = 27;
const int bmole_7 = 28;
const int bmole_8 = 29;
const int bmole_9 = 30;

//Time moles will be on
const int onTime = 1000;

//Setup of the led pins of every mole
const int mole_1 = 2;
const int mole_2 = 3;
const int mole_3 = 4;
const int mole_4 = 5;
const int mole_5 = 6;
const int mole_6 = 7;
const int mole_7 = 8;
const int mole_8 = 9;
const int mole_9 = 10;

int dif; //Difficulty counter
int mole_counter = 0; //Amount of moles up
int gameMode = 3; //Initialize the gamemode
int stateTime = 0; //Seetup the state machine defaul state
int score = 0; //Score counter

//Value of random operation Determines the amount of time a led will be off
int val;
int val2;
int val3;
int val4;
int val5;
int val6;
int val7;
int val8;
int val9;

//setup the values of first time executed and the last time executed of the time gamemode
unsigned long dif_t0 = 0;
unsigned long dif_t0_last = 0;

//Checks if there is a game active
boolean inGame = false;

//Blocks the buttons to only read one press per activation of a mole
boolean point_mole1 = false;
boolean point_mole2 = false;
boolean point_mole3 = false;
boolean point_mole4 = false;
boolean point_mole5 = false;
boolean point_mole6 = false;
boolean point_mole7 = false;
boolean point_mole8 = false;
boolean point_mole9 = false;

//Setup the time of start in the loop
unsigned long timeStart = 0;

//Stores the tinme of execution of a mole, and the last execution of it
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
unsigned long t0mole_7 = 0;
unsigned long t0mole7_last = 0;
unsigned long t0mole_8 = 0;
unsigned long t0mole8_last = 0;
unsigned long t0mole_9 = 0;
unsigned long t0mole9_last = 0;

void setup() {
  //Begin serial comunication
  Serial.begin(9600);
  //Sets the seed of the random function reading a unused pin to generate a different set of numbers every time
  pinMode(A15, INPUT);
  randomSeed(analogRead(A15));

  //Setup the buttons of gamemode as inputs
  pinMode(bab, INPUT);
  pinMode(btime, INPUT);
  dif = 10;

  //Set the button and the led of every single mole in input and output respectively
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
  pinMode(bmole_7, INPUT);
  pinMode(mole_7, OUTPUT);
  pinMode(bmole_8, INPUT);
  pinMode(mole_8, OUTPUT);
  pinMode(bmole_9, INPUT);
  pinMode(mole_9, OUTPUT);

  //Generates a first set of numbers for the moles
  val = 102 * random(10, dif * 10);
  val2 = 105 * random(10, dif * 10);
  val3 = 120 * random(10, dif * 10);
  val4 = 140 * random(10, dif * 10);
  val5 = 104 * random(10, dif * 10);
  val6 = 113 * random(10, dif * 10);
  val7 = 140 * random(10, dif * 10);
  val8 = 104 * random(10, dif * 10);
  val9 = 113 * random(10, dif * 10);
}

void loop() {
  checkBtn(); //Locks the gamemode buttons if there is a game being played
  //Initializate the game in a specific mode
  if (gameMode == 0) {
    abilityMode();
  }
  if (gameMode == 1) {
    timeMode();
  }
}
/*
 * Game method, executes in both gamemodes, but looks for the actual gamemode
 * Increases the difficulty of the game every 10 seconds
 */
void game() {
  mole1();
  mole2();
  mole3();
  mole4();
  mole5();
  mole6();
  mole7();
  mole8();
  mole9();
  if (dif_t0 - dif_t0_last >= 10000) {
    if (dif > 2) {
      dif = dif - 1;
    }
  }

}
/*
 * This method is the same for the 9 moles
 * Checks the last state of the led and then changes it
 * LOW -> HIGH | HIGH -> LOW
 */
void mole1() {
  t0mole_1 = millis();
  //Checks the last time of activation and then if is higher than the value of @val, changes the state of the led
  if (t0mole_1 - t0mole1_last >= val) {
    
    if (digitalRead(mole_1) == HIGH) { // if the last state is HIGH, then turn off the led
      digitalWrite(mole_1 , LOW);
      Serial.println("1L"); //Communicates with the UI and tells it that one mole is now off
      if (!point_mole1 && gameMode == 0) { //If the game mode is ability and there was no button pressed in the time the led was on, declares a lose state and continue
        stateTime = 2;
      }
      val = (100 * random(10, dif * 10));
      mole_counter = mole_counter - 1;
      point_mole1 = false; // activates the button again
    } else if (digitalRead(mole_1) == LOW) {// if the last state is LOW, then turn on the led
      digitalWrite(mole_1 , HIGH);
      Serial.println("1H");//Communicates with the UI and tells it that one mole is now on
      mole_counter = mole_counter + 1;
      val = onTime; //Puts the amount of time on to i sec
    }

    t0mole1_last = millis(); // Sets the las time executed as the runtime
  }
  //If the button is pressed, and the mole is on score one point
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
void mole7() {
  t0mole_7 = millis();
  if (t0mole_7 - t0mole7_last >= val7) {
    if (digitalRead(mole_7) == HIGH) {
      digitalWrite(mole_7 , LOW);
      Serial.println("7L");
      if (!point_mole7 && gameMode == 0) {
        stateTime = 2;
      }
      val7 = (100 * random(10, dif * 10));
      mole_counter = mole_counter - 1;
      point_mole7 = false;
    } else if (digitalRead(mole_7) == LOW) {
      digitalWrite(mole_7 , HIGH);
      Serial.println("7H");
      mole_counter = mole_counter + 1;
      val7 = onTime;
    }

    t0mole7_last = millis();
  }
  if (digitalRead(bmole_7) && digitalRead(mole_7) && !point_mole7) {
    point_mole7 = true;
    score = score + 1;
    Serial.print("Score: ");
    Serial.println(score);
  }
}
void mole8() {
  t0mole_8 = millis();
  if (t0mole_8 - t0mole8_last >= val8) {
    if (digitalRead(mole_8) == HIGH) {
      digitalWrite(mole_8 , LOW);
      Serial.println("8L");
      if (!point_mole8 && gameMode == 0) {
        stateTime = 2;
      }
      val8 = (100 * random(10, dif * 10));
      mole_counter = mole_counter - 1;
      point_mole8 = false;
    } else if (digitalRead(mole_8) == LOW) {
      digitalWrite(mole_8 , HIGH);
      Serial.println("8H");
      mole_counter = mole_counter + 1;
      val8 = onTime;
    }

    t0mole8_last = millis();
  }
  if (digitalRead(bmole_8) && digitalRead(mole_8) && !point_mole8) {
    point_mole8 = true;
    score = score + 1;
    Serial.print("Score: ");
    Serial.println(score);
  }
}
void mole9() {
  t0mole_9 = millis();
  if (t0mole_9 - t0mole9_last >= val9) {
    if (digitalRead(mole_9) == HIGH) {
      digitalWrite(mole_9 , LOW);
      Serial.println("9L");
      if (!point_mole9 && gameMode == 0) {
        stateTime = 2;
      }
      val9 = (100 * random(10, dif * 10));
      mole_counter = mole_counter - 1;
      point_mole9 = false;
    } else if (digitalRead(mole_9) == LOW) {
      digitalWrite(mole_9 , HIGH);
      Serial.println("9H");
      mole_counter = mole_counter + 1;
      val9 = onTime;
    }

    t0mole9_last = millis();
  }
  if (digitalRead(bmole_9) && digitalRead(mole_9) && !point_mole9) {
    point_mole9 = true;
    score = score + 1;
    Serial.print("Score: ");
    Serial.println(score);
  }
}
//Manages the abilty mode, is an structure of a state machine
void abilityMode() {
  switch (stateTime) {
    case 0: 
      //First state, gives the player a time to get ready
      delay(5000);
      stateTime = 1;
      inGame = true;
      timeStart = millis();
      randomi();
      break;
    case 1:
      //Loops in the game() method until a loose state comes true
      game();
      break;
    case 2:
      //is activated when the game is over and resets all the variables
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
//Manages the time mode, is an structure of a state machine
void timeMode() {
  if ((millis() - timeStart) < 60000) { //gives the player 60 seconds to play
    switch (stateTime) {
      case 0:
        delay(5000);
        //First state, gives the player a time to get ready
        stateTime = 1;
        inGame = true;
        timeStart = millis();
        randomi();
        break;
      case 1:
        //Loops in the game() method until the time is over
        game();
        break;
    }
  } else {
    //Reset the variables
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
//generate a random value for the off time of the moles
void randomi() {
  val = 102 * random(10, dif * 10);
  val2 = 105 * random(10, dif * 10);
  val3 = 120 * random(10, dif * 10);
  val4 = 140 * random(10, dif * 10);
  val5 = 104 * random(10, dif * 10);
  val6 = 113 * random(10, dif * 10);
}
//Sets off all the moles
void off() {
  digitalWrite(mole_1, LOW);
  digitalWrite(mole_2, LOW);
  digitalWrite(mole_3, LOW);
  digitalWrite(mole_4, LOW);
  digitalWrite(mole_5, LOW);
  digitalWrite(mole_6, LOW);
  digitalWrite(mole_7, LOW);
  digitalWrite(mole_8, LOW);
  digitalWrite(mole_9, LOW);
  Serial.println("1L");
  Serial.println("2L");
  Serial.println("3L");
  Serial.println("4L");
  Serial.println("5L");
  Serial.println("6L");
  Serial.println("7L");
  Serial.println("8L");
  Serial.println("9L");
}
//Checks the activation of the gamemode buttons and starts the respective game
void checkBtn() {
  if (digitalRead(bab) && !inGame) {
    gameMode = 0;
  }
  if (digitalRead(btime) &&  !inGame) {
    gameMode = 1;
  }
}
