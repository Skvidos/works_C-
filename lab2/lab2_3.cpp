#include <iostream>
using namespace std;
int main()
{
  unsigned int num, result;
  cout << "Vvedite chislo: ";
  cin >> num;
  result = ((num & 0x5555) << 1) | ((num & 0xAAAA) >> 1);
  cout << "Otvet: " << result << endl;

  return 0;
}
