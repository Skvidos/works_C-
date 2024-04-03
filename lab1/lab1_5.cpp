#include <iostream>
using namespace std;

int main()
{
  bool l = 1;
  int a[12];
  int m, d, r;
  int sum = 0;
  cout << "Vas god visokosnii? (1-No, 0-Yes): ";
  cin >> l;
  if (l == 0)
  {
    int a[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cout << "Vas god visokosnii \n";
  }
  else
  {
    int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cout << "Vas god nevisokosnii \n";
  }
  cout << "Vvedite mesyatc: ";
  cin >> m;
  cout << "Vvedite den: ";
  cin >> d;
  for (int i = 0; i < m - 1; i++)
    sum += a[i];
  sum += d;
  r = (sum - 1) % 7 + 1;
  switch (r)
  {
  case 1:
    cout << "Ponedelnik";
    break;
  case 2:
    cout << "Vtornik";
    break;
  case 3:
    cout << "Sreda";
    break;
  case 4:
    cout << "Chetverg";
    break;
  case 5:
    cout << "Pyatnica";
    break;
  case 6:
    cout << "Subbota";
    break;
  case 7:
    cout << "Voskresenie";
  default:
    cout << "Error";
  }

  return 0;
}
