#include <iostream>
#include <cmath>
#include <iomanip> // используется для установки точности вывода дробных чисел

using namespace std;

// Функция для вычисления значения сигнала
double signalValue(double k, double omega, double phi, double t);

// Функция для измерения сигнала
void measureSignal(double k, double omega, double phi, double error_rate, double threshold, double initial_time, double time_step);

int main()
{
  setlocale(LC_ALL, "ru-RU.UTF-8");
  const double k = 1.2e-2;
  const double omega = 2.6e-3;
  const double phi = 1.7e2;
  const double error_rate = 0.05;  // 5% погрешность
  const double threshold = 0.4;    // Пороговое значение
  const double initial_time = 1.0; // Начальное время
  const double time_step = 0.5;    // Шаг времени

  measureSignal(k, omega, phi, error_rate, threshold, initial_time, time_step);

  return 0;
}

double signalValue(double k, double omega, double phi, double t)
{
  return exp(k * t) * sin(omega * t + phi);
}

void measureSignal(double k, double omega, double phi, double error_rate, double threshold, double initial_time, double time_step)
{
  double U, U_initial, U_previous;
  bool half_value_reached = false;

  // Вычисляем начальное значение сигнала
  U_initial = signalValue(k, omega, phi, initial_time);
  U_previous = U_initial;

  cout << "t(s)\tU(t)\tError(+/-)\n";
  cout << fixed << setprecision(4);

  for (double t = initial_time;; t += time_step)
  {
    U = signalValue(k, omega, phi, t);
    double error = U * error_rate;

    cout << t << "\t" << U << "\t" << error << "\n";

    // Проверяем, не упало ли значение ниже порога
    if (U < threshold)
    {
      break;
    }

    // Проверяем, понизился ли сигнал более чем на 50%
    if (!half_value_reached && U <= U_initial / 2)
    {
      cout << "Сигнал понизился более чем на 50% при t=" << t << " секунд\n";
      half_value_reached = true;
    }

    U_previous = U;
  }
}
