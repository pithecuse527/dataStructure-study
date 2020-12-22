#include <iostream>

int DivZero(int, int, int);

using namespace std;
int main()
{
     try
	  {
          cout << DivZero(2, 0, 4) << endl;
     }
     catch(const char* e)
     {
          cout << "The parameters to DivZero were 2, 0, 4" << endl;
          cout <<  "An exception has been thrown" << endl;
          cout << e << endl;
          return 1;
     }
     return 0;
}
int DivZero(int a, int b, int c)
{
     if(a <=0 || b <=0 || c <=0)
          throw "All parameters should be >0";
	  return a+b*c+b/c;
}
