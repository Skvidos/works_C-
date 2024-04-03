#include <iostream>
using namespace std;
int main()
{
  unsigned int lx, l41, l42, l43, l44;
  cout << "Vvedite chislo: ";
  cin >> lx;
  cout << "\n Vvedeno chislo lx = " << lx << endl;
  l41 = lx & 0xf;
  l42 = lx & 0xf0;
  l43 = lx & 0xf00;
  l44 = lx & 0xf000;
  lx = (lx >> 8) & 0xff0000;
  lx += (l42 << 8) + (l41 << 8) + (l44 >> 8) + (l43 >> 8);
  cout << "\n Otvet: lx = " << lx << endl;

  return 0;
}
