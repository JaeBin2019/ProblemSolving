#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

/*

    https://www.acmicpc.net/problem/21314

    [ 문제 정리 ]

    [ 해결 방법 ]
    MMMK

    => 최대값 K가 나오기 전 M의 개수에 따라 5000

    => 최솟값은 K가 나오기 전 M의 개수에 따라 1005

    [ 자료형 ]
    1 <= length < 3000

    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초


*/

char minVal[3005], maxVal[3005];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    memset(maxVal, (int)'0', sizeof(maxVal));
    memset(minVal, (int)'0', sizeof(minVal));

    string input;
    cin >> input;
    int n = input.size();
    int length = 0;

    maxVal[n] = '\0';
    minVal[n] = '\0';

    for (int i = 0; i < n; ++i)
    {
        if (input[i] == 'M')
            ++length;

        if (input[i] == 'K')
        {
            maxVal[i - length] = '5';
            minVal[i - length] = '1';
            minVal[i] = '5';
            length = 0;
        }
    }

    if (length != 0)
    {
        for (int i = n - length; i < n; ++i)
        {
            maxVal[i] = '1';
        }
        minVal[n - length] = '1';
    }

    cout << maxVal << '\n'
         << minVal;
}

// #include <iostream>
// #include <cstring>
// using namespace std;
// const int SIZ = 3005;
// string MK;
// char MIN_VAL[SIZ], MAX_VAL[SIZ];
// int N, st;
// int main()
// {
//     cin.tie(NULL);
//     ios_base::sync_with_stdio(false);
//     cin >> MK;
//     N = MK.size();
//     st = 0;
//     memset(MIN_VAL, (int)'0', sizeof(MIN_VAL));
//     memset(MAX_VAL, (int)'0', sizeof(MAX_VAL));
//     MIN_VAL[N] = '\0';
//     MAX_VAL[N] = '\0';
//     for (int i = 0; i < N; i++)
//     {
//         if (MK[i] == 'M')
//             st++;
//         else
//         {
//             MAX_VAL[i - st] = '5';
//             MIN_VAL[i - st] = '1';
//             MIN_VAL[i] = '5';
//             st = 0;
//         }
//     }
//     if (st)
//     {
//         for (int j = N - 1 - st + 1; j < N; j++)
//             MAX_VAL[j] = '1';
//         MIN_VAL[N - 1 - st + 1] = '1';
//     }
//     cout << MAX_VAL << '\n'
//          << MIN_VAL << '\n';
//     return 0;
// }