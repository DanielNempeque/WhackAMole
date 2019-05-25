import processing.serial.*;
Serial port;
String score="Score: 0";
PImage fondo;

Topo topo1, topo2, topo3, topo4, topo5, topo6, topo7, topo8, topo9;
int linefeed = 10;
int x, y;
void setup() {
  port= new Serial(this, "COM12", 9600);
  port.bufferUntil(linefeed);
  size(640, 360, P3D);
  x=(width/2)-30;
  y=150;
  fondo = loadImage("fondo.jpg");
  topo1= new Topo(x, y);
  topo2= new Topo(x-100, y+70);
  topo3= new Topo(x, y+70);
  topo4= new Topo(x+100, y+70);
  topo5= new Topo(x-100, y+140);
  topo6= new Topo(x, y+140);
  topo7= new Topo(x+100, y+140);
  topo8= new Topo(x-200, y+140);
  topo9= new Topo(x+200, y+140);
  textSize(32);
  noStroke();
}

void draw() {
  background(fondo);
  displayInit();
  if (port.available()>0) {
  }
}
void serialEvent(Serial port) {
  String input = port.readString();
  
  input = trim(input);
  //switch(input) {
  //case "1L":
  //  print("Topo 1 abajo");
  //  break;
  //case "1H":
  //  print("Topo 1 arriba");
  //  break;
  //case "2L":
  //  print("Topo 2 abajo");
  //  break;
  //case "2H":
  //  print("Topo 2 arriba");
  //  break;
  //}
  
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
  
  if(input.contains("Score:")){
    score = input;
  }
  if(input.contains("Game")){
    score = "Score: 0";
  }
}
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
