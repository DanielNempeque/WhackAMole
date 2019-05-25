import processing.serial.*;
Serial port;
int score;
PImage fondo;
Topo topo1, topo2, topo3, topo4, topo5, topo6, topo7, topo8, topo9;
int x, y;
void setup() {
  port= new Serial(this, "COM12", 9600);
  size(640, 360, P3D);
  x=(width/2)-30;
  y=150;
  score=0;
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
  
  noStroke();
}

void draw() {
  background(fondo);
  displayInit();
  if (port.available()>0) {
    String input=port.readString();
    if (input.equals("mole1H")) {
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
  }
}
void displayInit() {
  topo1.displayMole();
  topo2.displayMole();
  topo3.displayMole();
  topo4.displayMole();
  topo5.displayMole();
  topo6.displayMole();
  topo7.displayMole();
  topo8.displayMole();
  topo9.displayMole();
  if (port.available()>0) {
    String input=port.readString();
    if (input.equals("mole1H")) {
      topo1.setState(true);
    } else if (input.equals("mole1L")) {
      topo1.setState(false);
    }
  }
}
