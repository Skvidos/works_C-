#include <iostream>
#include <string>
#include <map>

using namespace std;

// Функция для конвертации римского числа в десятичное
int romanToInt(const string &s);

// Перегруженная функция для вычисления количества лет между двумя датами (десятичные цифры)
int yearsBetweenD(int year1, int year2);

// Перегруженная функция для вычисления количества лет между двумя датами (римские цифры)
int yearsBetweenR(const string &year1Roman, const string &year2Roman);

int main()
{
  setlocale(LC_ALL, "ru_RU.UTF-8");
  int year1, year2;
  string year1Roman, year2Roman;
  cout << "Каким способом вы хотите ввести дату?" << endl;
  cout << "1. Десятичные цифры" << endl;
  cout << "2. Римские цифры" << endl;
  int choice;
  cin >> choice;
  if (choice == 1)
  {
    cout << "Напиши первую дату: ";
    cin >> year1;
    cout << "Напиши вторую дату: ";
    cin >> year2;
    cout << "Количество лет между датами: " << yearsBetweenD(year1, year2) << endl;
  }
  else if (choice == 2)
  {
    cout << "Напиши первую дату: ";
    cin >> year1Roman;
    cout << "Напиши вторую дату: ";
    cin >> year2Roman;
    cout << "Количество лет между датами: " << yearsBetweenR(year1Roman, year2Roman) << endl;
  }
  else
  {
    cout << "Неверный выбор" << endl;
  }
  return 0;
}

// Функция для конвертации римского числа в десятичное
int romanToInt(const string &s)
{
  map<char, int> roman{
      {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

  int sum = roman[s.back()];
  for (int i = s.length() - 2; i >= 0; --i)
  {
    if (roman[s[i]] < roman[s[i + 1]])
    {
      sum -= roman[s[i]];
    }
    else
    {
      sum += roman[s[i]];
    }
  }
  return sum;
}

// Перегруженная функция для вычисления количества лет между двумя датами (десятичные цифры)
int yearsBetweenD(int year1, int year2)
{
  return abs(year1 - year2);
}

// Перегруженная функция для вычисления количества лет между двумя датами (римские цифры)
int yearsBetweenR(const string &year1Roman, const string &year2Roman)
{
  int year1 = romanToInt(year1Roman);
  int year2 = romanToInt(year2Roman);
  return abs(year1 - year2);
}
