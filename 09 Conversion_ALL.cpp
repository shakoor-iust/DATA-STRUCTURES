#include<iostream>
using namespace std;

int Convert(int n, int base)
{
    if(n == 0) return 0;

    Convert(n/base, base);
    if(base == 16 && n % base > 9)
        cout << char(n % base + 55);
    else
        cout << n % base;

    return 0;
}

int main()
{
    int num, base;

    cout << "Enter the Number : ";
    cin >> num;

    cout << "Enter the Base : ";
    cin >> base;

    cout << "Converting " << num << " With Base " << base << " = ";
    Convert(num,base);

    return 0;
}