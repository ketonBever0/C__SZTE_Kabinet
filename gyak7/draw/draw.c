#include "paint.h"

void cloud(float size) {
  if(size < 50) {
    return;
  }
  draw_cloud(size - 20);

  cloud(size - 20);
}

void side(float length, int n) {
  // forward(length);
  if (n == 0) {
    forward(length);
  } else {
    length /= 3;

    side(length, n - 1);
    left(60);
    side(length, n - 1);
    right(120);
    side(length, n - 1);
    left(60);
    side(length, n - 1);
  }
}

void shape(float length) {
  for (int i = 0; i <= 3; i++)
  {
    side(length, 3);
    right(120); 
  }
  
}

int main() {
    create_window(600, 500);
    set_speed(0.1);
    // cloud(250);
    shape(120);
    close_window();
    return 0;
}
