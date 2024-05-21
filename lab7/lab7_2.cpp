#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Функция для нахождения наиболее часто встречающегося символа в строке
void findMostFrequentChar(const string &str);

int main()
{
  setlocale(LC_ALL, "ru-RU.UTF8");
  ifstream file("input.txt");
  if (!file)
  {
    cerr << "Не удалось открыть файл\n";
    return 1;
  }

  string line;
  getline(file, line);
  cout << "Строка из файла: " << line << '\n';

  findMostFrequentChar(line);

  return 0;
}

// Функция для нахождения наиболее часто встречающегося символа в строке
void findMostFrequentChar(const string &str)
{
  int count[256] = {0};
  int len = str.length();
  int max = 0;
  char result;

  // Вычисляем частоту каждого символа
  for (int i = 0; i < len; i++)
  {
    count[str[i]]++;
    if (max < count[str[i]])
    {
      max = count[str[i]];
      result = str[i];
    }
  }

  cout << "Наиболее часто встречающийся символ: '" << result << "' с количеством повторений: " << max << '\n';
}
