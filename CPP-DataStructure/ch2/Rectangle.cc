#include "Rectangle.h"
#include <iostream>

using namespace std;

int Rectangle::GetHeight() {return height;}
int Rectangle::GetWidth() {return width;}
bool Rectangle::SetHeightWidth(int h, int w) {
  height = h;
  width = w;
  return true;
};

bool Rectangle::operator==(const Rectangle &s)
{
     if (this == &s) return true;
     if ( (xLow == s.xLow) && (yLow == s.yLow) && (height == s.height) && (width == s.width) ) return true;
     return false;
}

ostream& operator << (ostream& os, Rectangle &r)
{
     os << "Position is: " << r.xLow << " ";
     os << r.yLow << endl;
     os << "Height is: " << r.height << endl;
     os << "Width is: " << r.width << endl;
     return os;
}
