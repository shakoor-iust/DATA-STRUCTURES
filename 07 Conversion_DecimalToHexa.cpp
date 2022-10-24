#include <iostream>
using namespace std;

int Decimal_to_Hexa(int n)
{
    if(n == 0) return 0;

    Decimal_to_Hexa(n / 16);
    if(n % 16 > 9)
        cout << char(n % 16 + 55);
    else
        cout << n % 16;

    return 0; 
}
int main()
{
    int num;

    cout << "Enter the Decimal Number : ";
    cin >> num;

    cout << "After Converting " << num << " into Hexa = ";
    Decimal_to_Hexa(num);

    return 0;
}