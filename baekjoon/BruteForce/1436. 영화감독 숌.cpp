#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*

    https://www.acmicpc.net/problem/1436

    [ 문제 정리 ]
    '666' 이 들어가는 N 번째 수를 구한다.
    N 이 1이면 666, N 이 2이면 1666 과 같이 가장 작은 666 부터 시작하여 값이 증가하는 형태이다

    [ 해결 방법 ]
    Brute Force 로 answer 의 값을 1씩 증가시키며, 666이 존재하면 count 를 증가시켰다.


    [ 자료형 ]
    1 <= N <= 10,000

    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초


*/

int main()
{
    int answer = 0;
    int N;
    cin >> N;
    int count = 0;
    while (count < N)
    {
        ++answer;
        int tmp = answer;
        while (tmp != 0)
        {
            if (tmp % 1000 == 666)
            {
                ++count;
                break;
            }
            tmp /= 10;
        }
    }
    cout << answer;
}