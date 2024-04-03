#include <iostream>
#include <cmath>
using namespace std;

double factorial(int n);

int main()
{
  // Пример последовательности
  int sequence[] = {1, 12, 6, 5, 2, 6, 18, 13, 7, 10, 9};
  int seq_size = sizeof(sequence) / sizeof(int);
  int product = 1;
  double result;
  for (int k = 0; k < seq_size; ++k)
  {
    if (k + 1 < sequence[k] && sequence[k] < factorial(k))
    {
      product *= sequence[k];
      printf("Product: %d\n", product);
    }
  }
  result = 1.0 / product;
  cout << "Result: " << result << std::endl;

  return 0;
}

double factorial(int n)
{
  if (n == 0)
    return 1;
  else
    return n * factorial(n - 1);
}
