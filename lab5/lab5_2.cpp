#include <iostream>

using namespace std;

// Функция для подсчета количества произведенных веников
int calculateProducedBrooms(int totalHvorostrin, int hvorostrinPerBroom);

// Функция для подсчета количества оставшихся недефектных хворостин
int calculateRemainingHvorostrin(int totalHvorostrin, int hvorostrinPerBroom, int k);

int main()
{
  setlocale(LC_ALL, "ru_RU.UTF-8");
  int N; // Общее количество хворостин
  int m; // Хворостин на венике
  int k; // Количество k-й хворостин, которые могут быть недефектными.

  cout << "Введите общее количество хворостин (N): ";
  cin >> N;

  cout << "Введите количество хворостин на веник (м): ";
  cin >> m;

  cout << "Введите значение k (дефектный хворостин): ";
  cin >> k;

  // Подсчет результатов
  int producedBrooms = calculateProducedBrooms(N, m);
  int remainingHvorostrin = calculateRemainingHvorostrin(N, m, k);

  // Отображение результатов
  cout << "Количество произведенных веников: " << producedBrooms << endl;
  cout << "Оставшийся недефектный хворостин: " << remainingHvorostrin << endl;

  return 0;
}

int calculateProducedBrooms(int totalHvorostrin, int hvorostrinPerBroom)
{
  return totalHvorostrin / hvorostrinPerBroom;
}

int calculateRemainingHvorostrin(int totalHvorostrin, int hvorostrinPerBroom, int k)
{
  int defectiveHvorostrin = totalHvorostrin / k;
  return totalHvorostrin - defectiveHvorostrin;
}
