#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  const double a = 2.93e-06;
  const double b = -33.14e2;
  double x, r;
  cout << "Vvedite kol-vo radian: ";
  cin >> x;
  double q1 = cos(x);
  double q2 = a * (x * x * x) - pow(q1, 1. / 4);

  if (q1 >= 0 and q2 > 0 and (log(q2) / log(2. / 3)) > 0)
  {
    r = (log(q2) / log(2. / 3));
    cout << "Otvet: " << r << endl;
  }
  else
  {
    cout << "Ne ODZ";
  }
}
