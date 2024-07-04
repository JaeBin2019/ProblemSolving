#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

/*

    https://www.acmicpc.net/problem/19598

    [ 문제 정리 ]



    [ 해결 방법 ]


    [ 자료형 ]
    1 <= N <= 100,000
    0 <= 시간 <= 2^31 - 1


    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초

*/

pair<int, int> lecture[100001];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    priority_queue<int, vector<int>, greater<int>> minQueue;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> lecture[i].first >> lecture[i].second;
    }

    sort(lecture, lecture + n);

    for (int i = 0; i < n; ++i)
    {
        minQueue.push(lecture[i].second);
        if (lecture[i].first >= minQueue.top())
        {
            minQueue.pop();
        }
    }

    cout << minQueue.size();
}