#include <iostream>
#include "Rectangle.h"

int main()
{
  Rectangle r;
  Rectangle *s = new Rectangle();
  r.SetHeightWidth(2, 3);
  s->SetHeightWidth(5,1);

  if(r == *s)
  {
    cout << r;
    cout << endl;
    cout << *s;
  }
  cout << r;
  cout << endl;
  cout << *s;

}
