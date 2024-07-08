#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

/*

    https://www.acmicpc.net/problem/1092

    [ 문제 정리 ]
    모든 화물은 박스에 안에 넣어져 있다. 항구에는 크레인이 N대 있고, 1분에 박스를 하나씩 배에 실을 수 있다. 모든 크레인은 동시에 움직인다.
    각 크레인은 무게 제한이 있다. 이 무게 제한보다 무거운 박스는 크레인으로 움직일 수 없다. 모든 박스를 배로 옮기는데 드는 시간의 최솟값을 구하라


    [ 해결 방법 ]
    크레인을 오름차순, 박스를 내림차순 하여, 최대한 성능 좋은 크레인이 가장 무거운 박스를 들도록 한다


    [ 자료형 ]
    N : 크레인 개수
    1 <= N <= 50

    크레인 무게 제한 <= 1,000,000

    M : 박스 개수
    1 <= M <= 10,000

    박스 무게 제한 <= 1,000,000


    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초
    O(M * N) => O(50 * 10,000) => O(500,000) => 0.02
*/

int crane[51];

vector<int> boxes;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int craneCount;
    cin >> craneCount;

    for (int i = 0; i < craneCount; ++i)
    {
        cin >> crane[i];
    }

    sort(crane, crane + craneCount, greater<>());

    int boxCount;
    cin >> boxCount;

    for (int i = 0; i < boxCount; ++i)
    {
        int tmp;
        cin >> tmp;
        boxes.push_back(tmp);
    }

    sort(boxes.begin(), boxes.end(), greater<>());

    int answer = 0;

    if (crane[0] < boxes[0])
    {
        answer = -1;
    }
    else
    {
        while (!boxes.empty())
        {
            for (int i = 0; i < craneCount; ++i)
            {
                for (int j = 0; j < boxes.size(); ++j)
                {
                    if (crane[i] >= boxes[j])
                    {
                        boxes.erase(boxes.begin() + j);
                        break;
                    }
                }
            }
            ++answer;
        }
    }

    cout << answer;
}