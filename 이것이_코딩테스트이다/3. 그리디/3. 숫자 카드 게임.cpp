#include <iostream>
#include <algorithm>

using namespace std;

/*

    [ 문제 정리 ]
    가장 높은 숫자가 쓰인 카드 한 장을 뽑는다. 규칙은 아래와 같다.
    1. 숫자가 쓰인 카드들이 N X M 의 형태로 놓여 있다. 이때 N은 행의 개수를 의미하며, M은 열의 개수를 의미한다
    2. 먼저 뽑고자 하는 카드가 포함되어 있는 행을 선택한다
    3. 그다음 선택된 행에 포함된 카드들 중 가장 숫자가 낮은 카드를 뽑아야 한다
    4. 따라서 처음에 카드를 골라낼 행을 선택할 때, 이후에 해당 행에서 가장 숫자가 낮은 카드를 뽑을 것을 고려하여
      최종적으로 가장 높은 숫자의 카드를 뽑을 수 있도록 전략을 세워야 한다

    [ 해결 방법 ]
    각 행에서 최소값 중 가장 큰 값을 찾는다


    [ 자료형 ]
    1 <= N, M <= 100
    1 <= 숫자 <= 10,000


    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초
    O(N X M) = O(100 * 100) => O(10000) => 0.0001 초


*/

int main()
{
    int N, M;
    cin >> N >> M;

    int arr[N][M];

    int localMin = 100000, answer = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; ++i)
    {
        localMin = 100000;
        for (int j = 0; j < N; ++j)
        {
            localMin = min(localMin, arr[i][j]);
        }
        answer = max(answer, localMin);
    }

    cout << answer;
}
