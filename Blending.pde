import processing.serial.*;//Import Serial Library
Serial port;//Asing a name to the port7
String score="Score: 0";//Start the score of the game
PImage fondo;//Variable refered to the background

Topo topo1, topo2, topo3, topo4, topo5, topo6, topo7, topo8, topo9;//Define all of the moles in the game
int linefeed = 10;//Detect the line change
int x, y;//Put the variables of distribution of the moles
void setup() {
  port= new Serial(this, "COM12", 9600);//Initialize the port
  port.bufferUntil(linefeed);//Read the entry of the console untill it encounters a line break
  size(640, 360, P3D);//Define the size of the screen
  x=(width/2)-30;//Asing a value to the variable x
  y=150;//Asing a value to the variable y
  fondo = loadImage("fondo.jpg");//Asing the image to the background
  //Create all moles
  topo1= new Topo(x, y);
  topo2= new Topo(x-100, y+70);
  topo3= new Topo(x, y+70);
  topo4= new Topo(x+100, y+70);
  topo5= new Topo(x-100, y+140);
  topo6= new Topo(x, y+140);
  topo7= new Topo(x+100, y+140);
  topo8= new Topo(x-200, y+140);
  topo9= new Topo(x+200, y+140);
  //Define the text size
  textSize(32);
  //Disables drawing the stroke
  noStroke();
}

void draw() {
  //Draw the background
  background(fondo);
  displayInit();
}
void serialEvent(Serial port) {
  //Read the input
  String input = port.readString();
  //Clean the input
  input = trim(input);

//Compare the string to sohw the state of the mole
  if (input.equals("1H")) {
    topo1.setState(true);
  } else if (input.equals("1L")) {
    topo1.setState(false);
  } else if (input.equals("2H")) {
    topo2.setState(true);
  } else if (input.equals("2L")) {
    topo2.setState(false);
  } else if (input.equals("3H")) {
    topo3.setState(true);
  } else if (input.equals("3L")) {
    topo3.setState(false);
  } else if (input.equals("4H")) {
    topo4.setState(true);
  } else if (input.equals("4L")) {
    topo4.setState(false);
  } else if (input.equals("5H")) {
    topo5.setState(true);
  } else if (input.equals("5L")) {
    topo5.setState(false);
  } else if (input.equals("6H")) {
    topo6.setState(true);
  } else if (input.equals("6L")) {
    topo6.setState(false);
  } else if (input.equals("7H")) {
    topo7.setState(true);
  } else if (input.equals("7L")) {
    topo7.setState(false);
  } else if (input.equals("8H")) {
    topo8.setState(true);
  } else if (input.equals("8L")) {
    topo8.setState(false);
  } else if (input.equals("9H")) {
    topo9.setState(true);
  } else if (input.equals("9L")) {
    topo9.setState(false);
  }
  //Put the string score in the screen
  if(input.contains("Score:")){
    score = input;
  }
  //Restore the default value of the score
  if(input.contains("Game")){
    score = "Score: 0";
  }
}

//Draw the moles 
void displayInit() {
  text(score, width/2-60, 30);
  topo1.displayMole();
  topo2.displayMole();
  topo3.displayMole();
  topo4.displayMole();
  topo5.displayMole();
  topo6.displayMole();
  topo7.displayMole();
  topo8.displayMole();
  topo9.displayMole();
}