#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*

    https://www.acmicpc.net/problem/9184

    [ 문제 정리 ]
    if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
        1

    if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
        w(20, 20, 20)

    if a < b and b < c, then w(a, b, c) returns:
        w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

    otherwise it returns:
        w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)

    다음 재귀함수를 dp를 이용해 구한다.
    입력의 마지막은 -1 -1 -1 이다.


    [ 해결 방법 ]
    조건에 맞춰 w[a][b][c] 의 값을 채워나간다.

    (a <= 0 || b <= 0 || c <= 0)  =>  1 
    w[a][b][c] != 0 로 값이 구해진 적이 있다면 그 값을 반환
    아니면 dp를 통해 해당값을 찾는다.


    [ 자료형 ]
    -50 <= a, b, c <= 50  조건이 있으므로 int 자료형을 사용한다

*/

int w[51][51][51];

int dp(int a, int b, int c)
{
    int result;

    if (a <= 0 || b <= 0 || c <= 0)
        return 1;

    else if (w[a][b][c] != 0)
        return w[a][b][c];

    else if (a > 20 || b > 20 || c > 20)
        result = dp(20, 20, 20);

    else if (a < b && b < c)
        result = dp(a, b, c - 1) + dp(a, b - 1, c - 1) - dp(a, b - 1, c);

    else
        result = dp(a - 1, b, c) + dp(a - 1, b - 1, c) + dp(a - 1, b, c - 1) - dp(a - 1, b - 1, c - 1);
    w[a][b][c] = result;
    return result;
}

int main()
{
    std::cin.tie(0);
    std::cout.tie(0);
    ios::sync_with_stdio(0);

    int a, b, c;
    cin >> a >> b >> c;
    while (!(a == -1 && b == -1 && c == -1))
    {
        cout << "w(" << a << ", " << b << ", " << c << ") = " << dp(a, b, c) << '\n';
        cin >> a >> b >> c;
    }
}