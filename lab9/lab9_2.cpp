#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

// Функция инициализации целочисленного массива
int *initializeIntArray(size_t k1, size_t k2);

// Функция инициализации вещественного массива
double *initializeDoubleArray(size_t size);

// Шаблон метода для вывода массива
template <typename T>
void printArray(T *array, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    cout << array[i] << " ";
  }
  cout << endl;
}

// Шаблон метода для преобразования массива
template <typename T>
void rearrangeArray(T *array, size_t size, T p)
{
  stable_partition(array, array + size, [p](T value)
                   { return abs(value) <= p; });
}

int main()
{
  setlocale(LC_ALL, "ru_RU.UTF-8");
  srand(static_cast<unsigned int>(time(0))); // инициализация генератора случайных чисел

  size_t k1 = rand() % 15 + 1;    // от 1 до 15 включительно
  size_t k2 = rand() % (16 - k1); // так, чтобы k1 + k2 <= 15

  int *A = initializeIntArray(k1, k2);
  double *B = initializeDoubleArray(k1); // размер такой же, как и у A

  cout << "Целочисленный массив A: ";
  printArray(A, k1);

  cout << "Вещественный массив B: ";
  printArray(B, k1);

  // Преобразование массивов
  int p = 1; // заданное число для сравнения с модулем элементов массива
  rearrangeArray(A, k1, p);
  rearrangeArray(B, k1, static_cast<double>(p));

  cout << "Преобразованный массив A: ";
  printArray(A, k1);

  cout << "Преобразованный массив B: ";
  printArray(B, k1);

  delete[] A; // освобождение памяти
  delete[] B;

  return 0;
}

// Функция инициализации целочисленного массива
int *initializeIntArray(size_t k1, size_t k2)
{
  int *array = new int[k1];
  unsigned int x = rand(); // случайное число

  for (size_t i = 0; i < k1; ++i)
  {
    array[i] = (x >> (k2 + i)) & 1; // получаем биты числа x, начиная с позиции k2
  }

  return array;
}

// Функция инициализации вещественного массива
double *initializeDoubleArray(size_t size)
{
  double *array = new double[size];
  for (size_t i = 0; i < size; ++i)
  {
    double C = rand();
    double D = rand();
    while (D == 0)
    { // проверка деления на ноль
      D = rand();
    }
    array[i] = fmod(C / D, 1.0); // дробная часть отношения C/D
  }

  return array;
}