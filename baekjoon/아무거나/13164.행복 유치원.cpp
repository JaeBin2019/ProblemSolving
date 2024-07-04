#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

/*

    https://www.acmicpc.net/problem/13164

    [ 문제 정리 ]
    조에서 가장 키가 큰 원생과 가장 키가 작은 원생의 키 차이만큼 비용이 든다
    원생의 수와 조의 수를 주었을 때, 최소 비용을 구하여라


    [ 해결 방법 ]
    1 3 5 6 10  이라는 원생들이 있을 때,
    차이는
    2 2 1 4 와 같이 나고,
    여기서 (n - 조의 개수) 만큼 값을 더해주면 된다
    조가 1개라면, 5 - 1 이므로 4개의 값을 더하고
    조가 3개라면, 5 - 3 이므로 2개를 더해주면 된다
    이미 정렬된 값으로 입력되므로, 처음부터 차이값을 priority_queue에 저장해주면 된다

    [ 자료형 ]
    N : 원생의 수
    1 <= N <= 300,000

    K : 조의 수
    1 <= K <= N

    원생의 키 <= 10억 이하 자연수

    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초
    O(2 * (log1 + log2 ... + logn)) => 2log2(n!) => 2log2(300,000!)

*/

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    priority_queue<int, vector<int>, greater<int>> minQueue;

    int n, k;

    cin >> n >> k;

    int height;
    cin >> height;

    for (int i = 1; i < n; ++i)
    {
        int input;
        cin >> input;
        minQueue.push(input - height);
        height = input;
    }

    int result = 0;
    for (int i = 0; i < n - k; ++i)
    {
        result += minQueue.top();
        minQueue.pop();
    }

    cout << result;
}