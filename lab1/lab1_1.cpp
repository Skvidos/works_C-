#include <iostream>
using namespace std;
int main()
{
  double T1 = 300., P1 = 75000., T2;
  cout << "Vvedite T2: ";
  cin >> T2;
  cout << "Otvet: " << P1 * T2 / T1 << "Pa" << endl;
  system("pause");
  return 0;
}
