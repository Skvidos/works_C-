#include <iostream>
#include <cmath>
using namespace std;

double P(double k, double p);

int main()
{
  double r;
  int p, k;
  cout << "Vvedite p: ";
  cin >> p;
  cout << "Vvedite k: ";
  cin >> k;
  if (p < 0)
  {
    r = P(0, p) + P(1, p * p);
    cout << "Otvet: " << r;
  }
  else if (k > 1 && k < 4 && p >= 0 && p <= 10)
  {
    r = P(k, p);
    cout << "Otvet: " << r;
  }
  else
  {
    r = 1;
    cout << "Otvet: " << r;
  }
}

double P(double k, double p)
{
  if (k == 0)
  {
    return tan(sin(abs(p * p * p))) * tan(sin(abs(p * p * p)));
  }
  else if (k == 1)
  {
    return cos(p) * cos(p) - sin(p) * sin(p);
  }
  else
  {
    return P(k - 1, p) * sin(p) * sin(p) - P(k - 2, p) * cos(p) * cos(p);
  }
}
