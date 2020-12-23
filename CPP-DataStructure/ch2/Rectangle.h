#include <iostream>
#ifndef RECTANGLE_H
#define RECTANGLE_H

using namespace std;
class Rectangle {
  friend ostream& operator<< (ostream& os, Rectangle& r);
  public:
    Rectangle(int x = 0, int y = 0, int h = 0, int w = 0)
    : xLow(x), yLow(y), height(h), width(w)
    { }
    // ~Rectangle();
    int GetHeight();
    int GetWidth();
    bool SetHeightWidth(int, int);
    bool operator==(const Rectangle& s);

  private:
    int xLow, yLow, height, width;
};
#endif
