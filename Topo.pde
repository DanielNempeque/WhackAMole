public class Topo {
  int x;//Possition of the mole on X-axis 
  int y;//Possition of the mole on Y-axis 
  PImage mole, hole, hel;//Define the image variables
  boolean isOutside = false;//Define the state of the mole
//Constructor of the class mole
  Topo(int x, int y) {
    this.x = x;
    this.y = y;
    this.mole = loadImage("topo.png");
    this.hole = loadImage("agujero.png");
    this.hel = loadImage("casco.png");
    this.rez();
  }
  //Change the size of the mole, hole and helmet
  void rez() {
    this.mole.resize(50, 60);
    this.hole.resize(60, 20);
    this.hel.resize(28, 16);
  }
  //Change the state of the mole 
  void setState(boolean io){
    this.isOutside=io;
  }
  //Draw the mole in the screen
  void displayMole() {
    image(hole, x-5, y+40);
    if (isOutside) {
      image(mole, x, y);
    } else if (!isOutside) {
      image(hel, x+13, y+40);
    }
  }
}