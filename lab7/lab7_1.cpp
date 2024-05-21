#include <iostream>
#include <string>

using namespace std;

// Функция для подсчета количества букв 'е' в слове
int countLetterE(const string &word);

// Функция для обработки каждого слова в строке
void processWords(const string &line);

int main()
{
  setlocale(LC_ALL, "ru-RU.UTF-8");
  string line;
  cout << "Введите строку: ";
  getline(cin, line);

  processWords(line);

  return 0;
}

// Функция для подсчета количества букв 'е' в слове
int countLetterE(const string &word)
{
  int count = 0;
  for (char c : word)
  {
    if (c == 'e')
    {
      count++;
    }
  }
  return count;
}

// Функция для обработки каждого слова в строке
void processWords(const string &line)
{
  string word;
  for (char c : line)
  {
    if (c == ' ')
    {
      if (!word.empty())
      {
        int count = countLetterE(word);
        cout << "Слово '" << word << "' содержит " << count << " букв(ы) 'е'\n";
        word.clear();
      }
    }
    else
    {
      word += c;
    }
  }
  if (!word.empty())
  {
    int count = countLetterE(word);
    cout << "Слово '" << word << "' содержит " << count << " букв(ы) 'е'\n";
  }
}