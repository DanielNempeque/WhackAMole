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
  if (port.available()>0) {
    String input=port.readString();
    if (input.equals("mole1H")) {
      topo1.setState(true);
    } else if (input.equals("mole1L")) {
      topo1.setState(false);
    }
  }

  topo2.displayMole();
  topo3.displayMole();
  topo4.displayMole();
  topo5.displayMole();
  topo6.displayMole();
  topo7.displayMole();
  topo8.displayMole();
  topo9.displayMole();
}