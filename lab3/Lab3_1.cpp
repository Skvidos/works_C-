#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N, k2;
    double x, k1;
    double result = 0;
    cout << "Input N: ";
    cin >> N;
    cout << "Input x: ";
    cin >> x;
    for (int i = 1; i <= N; ++i)
    {
        k1 = cos(i * pow(x, 2 * i));
        k2 = pow(3 * i, 3);
        result += -k1 / k2;
    }
    cout << "Result: " << result << std::endl;
    return 0;
}
