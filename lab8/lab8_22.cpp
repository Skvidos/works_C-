#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Структура для представления книги
struct Book
{
  string author;
  string title;
  string publisher;
  int year;
  double cost;
};
// Функция для ввода информации о книгах из файла
Book *inputBooks(const string &filename, int &N);

// Функция для фильтрации книг по издательству и сортировки по названию
Book *filterAndSortBooks(Book *books, int N, int &M);

int main()
{
  setlocale(LC_ALL, "ru_RU.UTC-8");
  int N;
  Book *books = inputBooks("books.txt", N);

  if (books != nullptr)
  {
    int M;
    Book *filteredBooks = filterAndSortBooks(books, N, M);

    cout << "Отфильтрованные и отсортированные книги, где в названии издательства есть буква 'k':\n";
    for (int i = 0; i < M; i++)
    {
      cout << filteredBooks[i].author << " " << filteredBooks[i].title << " " << filteredBooks[i].publisher << " " << filteredBooks[i].year << " " << filteredBooks[i].cost << "\n";
    }

    delete[] books;
    delete[] filteredBooks;
  }

  return 0;
}

// Функция для ввода информации о книгах из файла
Book *inputBooks(const string &filename, int &N)
{
  ifstream file(filename);
  if (!file)
  {
    cerr << "Не удалось открыть файл\n";
    return nullptr;
  }

  N = 0;
  string line;
  while (getline(file, line))
  {
    N++;
  }

  Book *books = new Book[N];

  // Возвращаемся в начало файла
  file.clear();
  file.seekg(0, ios::beg);

  string field;
  for (int i = 0; i < N; i++)
  {
    getline(file, books[i].author, ',');
    getline(file, books[i].title, ',');
    getline(file, books[i].publisher, ',');
    getline(file, field, ',');
    books[i].year = stoi(field);
    getline(file, field);
    books[i].cost = stod(field);
  }

  return books;
}

// Функция для фильтрации книг по издательству и сортировки по названию
Book *filterAndSortBooks(Book *books, int N, int &M)
{
  // Фильтрация
  Book *filteredBooks = new Book[N];
  M = 0;
  for (int i = 0; i < N; i++)
  {
    int countK = 0; // переменная для подсчёта букв 'k'
    for (char ch : books[i].publisher)
    {
      if (ch == 'k')
      {
        countK++;
      }
    }

    if (countK == 1) // проверка, что k встречается один раз
    {
      filteredBooks[M++] = books[i];
    }
  }

  // Сортировка
  for (int i = 0; i < M - 1; i++)
  {
    for (int j = 0; j < M - i - 1; j++)
    {
      if (filteredBooks[j].title > filteredBooks[j + 1].title)
      {
        swap(filteredBooks[j], filteredBooks[j + 1]);
      }
    }
  }

  return filteredBooks;
}
