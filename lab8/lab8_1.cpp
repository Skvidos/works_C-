#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Структура для представления анкеты ребенка
struct Child
{
  string name;
  string gender;
  int height;
};

// Функция для ввода информации о детях из файла
void inputChildren(Child *children, int N, const string &filename);

// Функция для нахождения самой высокой девочки
Child findTallestGirl(Child *children, int N);

int main()
{
  setlocale(LC_ALL, "ru_RU.UTF-8");
  int N;
  cout << "Введите количество детей: ";
  cin >> N;

  Child *children = new Child[N];
  inputChildren(children, N, "children.txt");

  Child tallestGirl = findTallestGirl(children, N);
  if (tallestGirl.name.empty())
  {
    cout << "Среди введенных детей нет девочек.\n";
  }
  else
  {
    cout << "Имя самой высокой девочки: " << tallestGirl.name << '\n';
  }

  delete[] children;

  return 0;
}

// Функция для ввода информации о детях из файла
void inputChildren(Child *children, int N, const string &filename)
{
  ifstream file(filename);
  if (!file)
  {
    cerr << "Не удалось открыть файл\n";
    return;
  }

  for (int i = 0; i < N; i++)
  {
    file >> children[i].name >> children[i].gender >> children[i].height;
  }
}

// Функция для нахождения самой высокой девочки
Child findTallestGirl(Child *children, int N)
{
  Child tallestGirl = {"", "девочка", 0};
  for (int i = 0; i < N; i++)
  {
    if (children[i].gender == "девочка" && children[i].height > tallestGirl.height)
    {
      tallestGirl = children[i];
    }
  }
  return tallestGirl;
}