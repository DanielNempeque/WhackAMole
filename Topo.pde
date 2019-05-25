public class Topo {
  int x;
  int y;
  PImage mole, hole, hel;
  Topo(int x, int y) {
    this.x = x;
    this.y = y;
    this.mole = loadImage("topo.png");
    this.hole = loadImage("agujero.png");
    this.hel = loadImage("casco.png");
  }
  void rez() {
  }
  void displayMole(boolean isOutside) {
    image(hole, x-5, y+40);
    if (isOutside) {
      image(mole, x, y);
    } else if (!isOutside) {
      image(hel,x+13,y+40);
    }
  }
}