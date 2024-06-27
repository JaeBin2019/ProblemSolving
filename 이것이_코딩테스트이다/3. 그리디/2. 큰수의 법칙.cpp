#include <iostream>
#include <algorithm>

using namespace std;

int firstMax = 0, secondMax = 0;
int N, M, K;

int main()
{
    cin >> N >> M >> K;
    int input, output = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> input;
        // 입력값이 가장 큰 값 보다 작거나 같을 때,
        // input이 secondMax 보다 크면 갱신
        if (firstMax >= input)
            secondMax = max(secondMax, input);
        // firstMax 보다 큰 값이 들어왔다면,
        // 현재 secondMax 값을 firstMax 값으로 갱신
        else
            secondMax = firstMax;
        firstMax = max(firstMax, input);
    }

    int cnt = (M / (K + 1)) * K + M % (K + 1);
    output += firstMax * cnt;
    output += secondMax * (M - cnt);

    cout << output << '\n';
    cout << firstMax << " " << secondMax;
}