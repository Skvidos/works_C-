#include <iostream>

using namespace std;

bool isPalindrome(int n);

int main()
{
  unsigned int n;
  cout << "Vvedite chislo: ";
  cin >> n;

  if (isPalindrome(n))
    cout << "Chislo polindrom: " << n << endl;
  else
    cout << "Chislo ne polindrom :" << n << endl;
}

bool isPalindrome(int n)
{
  int reversed = 0;
  int origininal = n;

  while (n > 0)
  {
    reversed = reversed * 10 + n % 10;
    n /= 10;
  }

  return origininal == reversed;
}