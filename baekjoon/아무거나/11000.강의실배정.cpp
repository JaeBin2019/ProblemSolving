#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

/*

    https://www.acmicpc.net/problem/11000

    [ 문제 정리 ]
    시간대가 중복되는 강의가 있다면, 최소한의 강의실 개수를 사용하여
    모든 강의가 가능하도록 해야한다

    [ 해결 방법 ]
    최대로 중복되는 강의가 있는 시간대를 찾아, 그 때의 개수를 반환한다
    i번째 강의가 끝나는 시점보다 먼저 시작하는 강의의 개수를 찾는다

    강의실이 필요하면, 하나를 추가로 빌려 쓴다
    만약, 현재 다 사용한 강의실이 있다면, 그 강의실에서 강의를 한다

    => 우선순위 큐를 최소값으로 정렬을 한다
    현재 큐의 top == 강의 중 가장 먼저 종료되는 강의

    현재 시작 시간이 강의 중 가장 먼저 종료되는 강의보다 더 앞이라면
    => 새 강의실을 사용하여 강의를 한다
    => endTimeQueue.push(lectureRoom[i].second);

    현재 시작 시간이 강의가 종료된 강의실에서 할 수 있다면
    => 기존 강의실을 사용하여 강의를 한다
    => endTimeQueue.push(lectureRoom[i].second);
    => endTimeQueue.pop();



    [ 자료형 ]
    N : 수업 개수
    1 <= N <= 200,000

    S : 수업 시작 시간, T : 수업 종료 시간
    0 <= S < T < 1,000,000,000

    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초

*/

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<pair<int, int>> lectureRoom;
    priority_queue<int, vector<int>, greater<int>> endTimeQueue;

    for (int i = 0; i < n; ++i)
    {
        int start, end;
        cin >> start >> end;
        lectureRoom.push_back({start, end});
    }

    sort(lectureRoom.begin(), lectureRoom.end());

    for (int i = 0; i < n; ++i)
    {
        endTimeQueue.push(lectureRoom[i].second);
        if (lectureRoom[i].first >= endTimeQueue.top())
        {
            endTimeQueue.pop();
        }
    }

    cout << endTimeQueue.size();
}