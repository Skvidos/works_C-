#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Генерация случайных координат шарика в заданном диапазоне
pair<double, double> generateCoordinates(double minX, double maxX, double minY, double maxY);
// Проверка, попал ли шарик в мишень
bool isInTarget(double x, double y);

int main()
{
  setlocale(LC_ALL, "ru_RU.UTF-8");
  srand(time(nullptr)); // инициализация генератора случайных чисел

  while (true)
  {
    cout << "Введите число 0 для завершения обстрела или любую другую для продолжения: ";
    int command;
    cin >> command;

    if (command == 0)
    {
      cout << "Обстрел завершен." << endl;
      break;
    }
    else
    {
      double x, y;
      pair<double, double> coordinates = generateCoordinates(-10, 10, -10, 10);
      x = coordinates.first;
      y = coordinates.second;

      if (isInTarget(x, y))
      {
        cout << "Шарик с координатами (" << x << ", " << y << ") попал в мишень." << endl;
      }
      else
      {
        cout << "Шарик с координатами (" << x << ", " << y << ") не попал в мишень." << endl;
      }
    }
  }

  return 0;
}

pair<double, double> generateCoordinates(double minX, double maxX, double minY, double maxY)
{
  double x = (maxX - minX) * (rand() / (double)RAND_MAX) + minX;
  double y = (maxY - minY) * (rand() / (double)RAND_MAX) + minY;
  return make_pair(x, y);
}

bool isInTarget(double x, double y)
{
  // Условие попадания в мишень
  if (((x - 0) * (x - 0) + (y - (-1)) * (y - (-1)) >= 3 * 3) && (y >= -4) && (y <= x + 3.2433) && (y <= -x + 3.2433))
    return false;
  else
    return true;
}
