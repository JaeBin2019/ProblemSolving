#include <iostream>

using namespace std;

int n = 1260;
int cnt = 0;
int coinType[] = {500, 100, 50, 10};

int main()
{
    for (int i = 0; i < 4; ++i)
    {
        cnt += +n / coinType[i];
        n %= coinType[i];
        if (n == 0)
            break;
    }
    cout << cnt;
}