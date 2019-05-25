public class Topo {
  int x;
  int y;
  PImage mole, hole, hel;
  boolean isOutside=false;
  Topo(int x, int y) {
    this.x = x;
    this.y = y;
    this.mole = loadImage("topo.png");
    this.hole = loadImage("agujero.png");
    this.hel = loadImage("casco.png");
    this.rez();
  }
  void rez() {
    this.mole.resize(50, 60);
    this.hole.resize(60, 20);
    this.hel.resize(28, 16);
  }
  void setState(boolean io){
    this.isOutside=io;
  }
  void displayMole() {
    image(hole, x-5, y+40);
    if (isOutside) {
      image(mole, x, y);
    } else if (!isOutside) {
      image(hel, x+13, y+40);
    }
  }
}