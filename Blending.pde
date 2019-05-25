PImage img1, img2, img3,img4;
int disTopoX, disTopoY,disAgX,disAgY,disCascoX,disCascoY;

void setup() {
  size(640, 360, P3D);
  disTopoX=width/2-30;
  disTopoY=150;
  disAgX=disTopoX-5;
  disAgY=disTopoY+40;
  disCascoX=disTopoX+13;
  disCascoY=disTopoY+40;
  img1 = loadImage("topo.png");
  img2 = loadImage("fondo.jpg");
  img3 = loadImage("agujero.png");
  img4 = loadImage("casco.png");
  
  img1.resize(50, 60);
  img3.resize(60, 20);
  img4.resize(28,16);

  noStroke();
}

void draw() {
  background(img2);
  
 
  image(img3, disAgX, disAgY);
  image(img3, disAgX-100, disAgY+70);
  image(img3, disAgX, disAgY+70);
  image(img3, disAgX+100, disAgY+70);
  image(img3, disAgX-100,disAgY+140);
  image(img3, disAgX, disAgY+140);
  image(img3, disAgX+100, disAgY+140);  
  image(img3, disAgX-200, disAgY+140);
  image(img3, disAgX+200, disAgY+140);
  
  image(img1, disTopoX, disTopoY);
  image(img1, disTopoX-100, disTopoY+70);
  image(img1, disTopoX, disTopoY+70);
  image(img1, disTopoX+100, disTopoY+70);
  image(img1, disTopoX-100, disTopoY+140);
  image(img1, disTopoX, disTopoY+140);
  image(img1, disTopoX+100, disTopoY+140);
  image(img1, disTopoX-200, disTopoY+140);
  image(img1, disTopoX+200, disTopoY+140);
  
  //image(img4, disCascoX, disCascoY);
  //image(img4, disCascoX-100, disCascoY+70);
  //image(img4, disCascoX, disCascoY+70);
  //image(img4, disCascoX+100, disCascoY+70);
  //image(img4, disCascoX-100, disCascoY+140);
  //image(img4, disCascoX, disCascoY+140);
  //image(img4, disCascoX+100, disCascoY+140);
  //image(img4, disCascoX-200, disCascoY+140);
  //image(img4, disCascoX+200, disCascoY+140);
  
}