#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция ввода
void input(int &count, int &min, int &max, int &M);

// Функция генерации цен
void generatePrices(int *prices, int count, int min, int max);

// Функция вычисления
void calculate(int *prices, int count, int M, int &countT, int &sum, int &min_price, int &max_price);

// Функция вывода
// void output(int countT, int M, int sum, int min_price, int max_price);

int main()
{
  srand(time(0));

  int count;    // количество товаров
  int min, max; // диапазон стоимости товаров
  int M;        // выделенная сумма

  input(count, min, max, M);

  int *prices = new int[count];
  generatePrices(prices, count, min, max);

  int countT = 0;
  int sum = 0;
  int min_price = max;
  int max_price = min;
  calculate(prices, count, M, countT, sum, min_price, max_price);

  // output(countT, M, sum, min_price, max_price);

  delete[] prices;

  cout << "Можно купить " << countT << " товаров\n";
  cout << "Неизрасходованная сумма: " << M - sum << "\n";
  if (countT > 0)
  {
    cout << "Стоимость самого дешёвого товара: " << min_price << "\n";
    cout << "Стоимость самого дорогого товара: " << max_price << "\n";
  }

  return 0;
}

void input(int &count, int &min, int &max, int &M)
{
  cout << "Введите количество товаров: ";
  cin >> count;

  cout << "Введите минимальную стоимость товара: ";
  cin >> min;

  cout << "Введите максимальную стоимость товара: ";
  cin >> max;

  cout << "Введите выделенную сумму: ";
  cin >> M;
}

void generatePrices(int *prices, int count, int min, int max)
{
  for (int i = 0; i < count; i++)
  {
    prices[i] = min + rand() % (max - min + 1);
    cout << prices[i] << " ";
  }
}

void calculate(int *prices, int count, int M, int &countT, int &sum, int &min_price, int &max_price)
{
  for (int i = 0; i < count + 1; i++)
  {
    if (sum + prices[i] > M)
    {
      continue;
    }
    sum += prices[i];
    countT++;
    if (prices[i] < min_price)
    {
      min_price = prices[i];
    }
    if (prices[i] > max_price)
    {
      max_price = prices[i];
    }
  }
}

// void output(int countT, int M, int sum, int min_price, int max_price)
// {
// }
