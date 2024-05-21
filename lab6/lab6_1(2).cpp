#include <iostream>
#include <cmath>

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

int findMaxSumN(double x, int maxN)
{
  double max_sum = series(x, 5);
  int max_sum_N = 5;
  std::cout << "N=5 Sum=" << max_sum << std::endl;

  for (int N = 10; N <= maxN; N += 5)
  {
    double current_sum = series(x, N);
    std::cout << "N=" << N << " Sum=" << current_sum << std::endl;

    if (current_sum > max_sum)
    {
      max_sum = current_sum;
      max_sum_N = N;
    }
  }

  return max_sum_N;
}

int main()
{
  double x;
  std::cout << "Введите фиксированное значение x: ";
  std::cin >> x;

  int N_for_max_sum = findMaxSumN(x, 25);
  std::cout << "Максимальное значение суммы достигается при N=" << N_for_max_sum << std::endl;

  return 0;
}
