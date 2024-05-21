#include <iostream>

using namespace std;

int AddRightDigit(int D, int K);

int main()
{
  setlocale(LC_ALL, "ru_RU.UTF-8");
  int D1;
  int D2;
  int K;
  cout << "Ввести цифру D1 и цифру D2: ";
  cin >> D1 >> D2;
  cout << "Введите число K: ";
  cin >> K;

  K = AddRightDigit(D1, K);
  K = AddRightDigit(D2, K);

  cout << "Результат: " << K << endl;

  return 0;
}

int AddRightDigit(int D, int K)
{
  if (D < 0 || D > 9)
  {
    cout << "Ошибка: Число D должно быть в диапазоне [0;9]" << endl;
    return K;
  }

  return K * 10 + D;
}
