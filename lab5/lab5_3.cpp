#include <iostream>

using namespace std;

// Функция для заполнения массива
void fillArray(int *a, int size);

// Функция для подсчета количества установленных бит в числе
int countSetBits(int num);

// Функция для поиска и вывода пар элементов с одинаковым количеством установленных бит
void findAndPrintPairs(int *a, int *count, int size);

int main()
{
  setlocale(LC_ALL, "ru_RU.UTF-8");
  const int size = 25;
  int a[size];
  int count[size] = {0};

  fillArray(a, size);

  for (int i = 0; i < size; i++)
  {
    count[i] = countSetBits(a[i]);
  }

  findAndPrintPairs(a, count, size);

  return 0;
}

void fillArray(int *a, int size)
{
  for (int i = 0; i < size; i++)
  {
    a[i] = 4 * i + 23;
  }
}

int countSetBits(int num)
{
  int count = 0;
  while (num != 0)
  {
    count += num & 1;
    num >>= 1;
  }
  return count;
}

void findAndPrintPairs(int *a, int *count, int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (count[i] == count[j])
      {
        cout << "Пары: " << a[i] << ", " << a[j] << endl;
      }
    }
  }
}