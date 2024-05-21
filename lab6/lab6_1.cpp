#include <iostream>
#include <cmath>

using namespace std;

double series(double x, int N);

void findStableN(double x, int maxN);

int main()
{
  setlocale(LC_ALL, "ru-RU.UTF-8");
  double x;
  cout << "Введите фиксированное значение x: ";
  cin >> x;

  findStableN(x, 25);

  return 0;
}

double series(double x, int N)
{
  double k1, k2, result = 0;
  for (int i = 1; i <= N; ++i)
  {
    k1 = cos(i * pow(x, 2 * i));
    k2 = pow(3 * i, 3);
    result += -k1 / k2;
  }
  return result;
}

void findStableN(double x, int maxN)
{
  double prev_sum = series(x, 5);
  cout << "N=5 Sum=" << prev_sum << endl;
  for (int N = 10; N <= maxN; N += 5)
  {
    double current_sum = series(x, N);
    cout << "N=" << N << " Sum=" << current_sum << endl;
    if (abs(current_sum - prev_sum) / prev_sum <= 0.1)
    {
      cout << "Сумма перестает изменяться более чем на 10% при N=" << N - 5 << endl;
      return;
    }
    prev_sum = current_sum;
  }
  cout << "Сумма изменяется более чем на 10% для всех заданных N" << endl;
}