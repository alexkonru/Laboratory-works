#include <iostream>
#include "z1.h"
#include "z2.h"
#include "z3.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Какую задачу нужно решить? (1-3)\n";
    cin >> n;
    switch (n)
    {
    case 1: z1 Z1 = z1();
        Z1.main();
        break;
    case 2: z2 Z2 = z2();
        Z2.main();
        break;
    case 3: z3 Z3 = z3();
        Z3.main();
        break;
    default:
        break;
    }
    return 0;
}