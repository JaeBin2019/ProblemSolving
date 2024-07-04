#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

/*

    https://www.acmicpc.net/problem/2212

    [ 문제 정리 ]



    [ 해결 방법 ]



    [ 자료형 ]
    N : 센서 개수
    1 <= N <= 10,000

    K : 집중국 개수
    1 <= K <= 1000


    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초

*/

int sensor[10001];

priority_queue<int, vector<int>, greater<int>> minQueue;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> sensor[i];
    }

    sort(sensor, sensor + n);

    int tmp = sensor[0];

    for (int i = 1; i < n; ++i)
    {
        minQueue.push(sensor[i] - tmp);
        tmp = sensor[i];
    }

    int answer = 0;

    for (int i = 0; i < n - k; ++i)
    {
        answer += minQueue.top();
        minQueue.pop();
    }

    cout << answer;
}