#include <iostream>

using namespace std;

class Person
{
  const string name;
  unsigned age;

public:
  void print()
  {
    cout << "Name: " << name << " Age: " << age << endl;
  }
  Person(string p_name, unsigned p_age) : name{p_name}, age{p_age} {}
};

int main()
{
  Person tom{"Tom", 38};
  tom.print();
}