#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_DEPOSITORS = 100; // Максимальное количество вкладчиков

struct Depositor
{
  string surname;
  string district;
  string socialStatus;
  double deposit;
};

struct PensionerInfo
{
  string surname;
  double deposit;
  double difference;
};

// Функция для чтения информации о вкладчиках из файла
int readDepositors(const string &filename, Depositor depositors[]);

// Функция для расчета средней величины вклада
double averageDeposit(Depositor depositors[], int count);

// Функция для создания списка пенсионеров с вкладом ниже среднего
int findPensionersBelowAverage(Depositor depositors[], int count, PensionerInfo pensioners[], double average);

// Функция для записи информации о пенсионерах в новый файл
void writePensionersToFile(const string &filename, PensionerInfo pensioners[], int count);

int main()
{
  string inputFilename = "input.txt";
  string outputFilename = "output.txt";

  Depositor depositors[MAX_DEPOSITORS];
  PensionerInfo pensioners[MAX_DEPOSITORS];

  int count = readDepositors(inputFilename, depositors);
  double avgDeposit = averageDeposit(depositors, count);
  int pensionerCount = findPensionersBelowAverage(depositors, count, pensioners, avgDeposit);
  writePensionersToFile(outputFilename, pensioners, pensionerCount);

  return 0;
}

// Функция для чтения информации о вкладчиках из файла
int readDepositors(const string &filename, Depositor depositors[])
{
  ifstream file(filename);
  int count = 0;
  while (file >> depositors[count].surname >> depositors[count].district >> depositors[count].socialStatus >> depositors[count].deposit)
  {
    if (++count >= MAX_DEPOSITORS)
      break;
  }
  return count;
}

// Функция для расчета средней величины вклада
double averageDeposit(Depositor depositors[], int count)
{
  double sum = 0;
  for (int i = 0; i < count; ++i)
  {
    sum += depositors[i].deposit;
  }
  return count > 0 ? sum / count : 0;
}

// Функция для создания списка пенсионеров с вкладом ниже среднего
int findPensionersBelowAverage(Depositor depositors[], int count, PensionerInfo pensioners[], double average)
{
  int pensionerCount = 0;
  for (int i = 0; i < count; ++i)
  {
    if (depositors[i].socialStatus == "пенсионер" && depositors[i].deposit < average)
    {
      pensioners[pensionerCount].surname = depositors[i].surname;
      pensioners[pensionerCount].deposit = depositors[i].deposit;
      pensioners[pensionerCount].difference = average - depositors[i].deposit;
      pensionerCount++;
    }
  }
  return pensionerCount;
}

// Функция для записи информации о пенсионерах в новый файл
void writePensionersToFile(const string &filename, PensionerInfo pensioners[], int count)
{
  ofstream file(filename);
  for (int i = 0; i < count; ++i)
  {
    file << pensioners[i].surname << " " << pensioners[i].deposit << " " << pensioners[i].difference << endl;
  }
}
