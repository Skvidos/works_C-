#include <iostream>

using namespace std;

void calculateLiquidLevel(int N, double &sum);

int main()
{
  int N;
  cout << "Input N: ";
  cin >> N;

  double sum = 0;
  calculateLiquidLevel(N, sum);

  cout << sum << endl;
  return 0;
}

void calculateLiquidLevel(int N, double &sum)
{
  const int s = 100;
  double liqL[N] = {0};
  double d = s / N;

  for (int i = 0; i < d; i++)
  {
    for (int sec = 0; sec < N; sec++)
    {
      int inflow_rate = 10;
      double outflow_rate = 0;
      liqL[sec] += inflow_rate;
      outflow_rate = liqL[sec] * 0.1;
      liqL[sec] -= outflow_rate;
    }

    cout << i << endl;

    for (int i = 0; i < N; ++i)
    {
      cout << liqL[i];
      if (i < N - 1)
      {
        cout << ", ";
      }
    }

    cout << endl;
    cout << "---------------------------" << endl;
  }

  for (int i = 0; i < N; i++)
  {
    sum = sum + liqL[i];
  }
}
