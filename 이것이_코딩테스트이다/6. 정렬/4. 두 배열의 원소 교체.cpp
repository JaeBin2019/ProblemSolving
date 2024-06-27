#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*

    6-4. 두 배열의 원소 교체

    [ 문제 정리 ]
    A 와 B 배열에 값이 주어지고, 두 배열에 있는 값을 최대 K회 변경할 수 있다.
    A 배열 전체 합이 최대가 되도록 하여라.

    N K
    A 배열
    B 배열

    5 3
    1 2 5 4 3
    5 5 6 6 5

    => 26

    [ 해결 방법 ]
    A 를 오름차순으로, B를 내림차순으로 정렬해서
    A < B 인 경우에만 교체를 한다.

    [ 자료형 ]
    1 <= N <= 100,000
    0 <= K <= N

    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초

*/

vector<int> A;
vector<int> B;

bool compare(int x, int y)
{
    return x > y;
}

int main()
{
    int N, K;
    int sumVal = 0;

    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    for (int i = 0; i < N; ++i)
    {
        int tmp;
        cin >> tmp;
        B.push_back(tmp);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), compare);

    for (int i = 0; i < K; ++i)
    {
        if (A[i] < B[i])
            A[i] = B[i];
        else
            break;
    }

    for (int val : A)
    {
        sumVal += val;
    }

    cout << sumVal;
}
