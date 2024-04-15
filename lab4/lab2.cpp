#include <iostream>
#include <cmath>

using namespace std;

// Вычисление arcctg(x)
double calculate(double x, int n);

int main()
{
  double x;
  int n;

  cout << "Введите значение x<1 : ";
  cin >> x;

  cout << "Введите количество членов ряда: ";
  cin >> n;

  double result = calculate(x, n);
  if (result)
  {
    cout << "Приближенное значение Arctan(" << x << ") = " << result << endl;
  }

  return 0;
}

double calculate(double x, int terms)
{
  if (abs(x) <= 1)
  {
    cout << "Значение x должно быть меньше 1." << endl;
    return false;
  }

  double sum = 0.0;
  for (int n = 0; n < terms; ++n)
  {
    sum += (n % 2 == 0 ? 1 : -1) / ((2 * n + 1) * pow(x, 2 * n + 1));
  }
  return sum / 2;
}