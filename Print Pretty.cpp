#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int number_test_cases;
    cin >> number_test_cases;

    for (int i = 0; i < number_test_cases; i++)
    {
        long double A, B, C;
        cin >> A >> B >> C;

        cout << std::showbase << std::hex << static_cast<long long int>(A) << endl;

        cout << std::noshowbase << std::dec << std::setw(15) << std::setfill('_') << std::fixed << std::setprecision(2) << std::right << showpos << B << endl;
    cout << std::noshowbase << std::dec << std::uppercase << std::scientific << std::setprecision(9) << noshowpos << C << endl;
}
}
