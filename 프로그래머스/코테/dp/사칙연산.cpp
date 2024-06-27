
/*

    https://school.programmers.co.kr/learn/courses/30/lessons/1843

    [ 문제 정리 ]


    [ 해결 방법 ]


    [ 자료형 ]
    1 <= N <= 100,000

    [ 시간 복잡도 ]

*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dp_max[200][200];
int dp_min[200][200];

int solution(vector<string> arr)
{
    int answer = 1;
    int num = arr.size() / 2 + 1;
    fill(&dp_max[0][0], &dp_max[199][200], -101000);
    fill(&dp_min[0][0], &dp_min[199][200], 101000);

    for (int i = 0; i < num; ++i)
    {
        dp_max[i][i] = stoi(arr[i * 2]);
        dp_min[i][i] = stoi(arr[i * 2]);
    }

    for (int round = 1; round < num; ++round)
    {
        for (int start = 0; start < num - round; ++start)
        {
            int end = round + start;
            for (int mid = start; mid < end; ++mid)
            {
                if (arr[mid * 2 + 1] == "-")
                {
                    dp_max[start][end] = max(dp_max[start][end], dp_max[start][mid] - dp_min[mid + 1][end]);
                    dp_min[start][end] = min(dp_min[start][end], dp_min[start][mid] - dp_max[mid + 1][end]);
                }
                else if (arr[mid * 2 + 1] == "+")
                {
                    dp_max[start][end] = max(dp_max[start][end], dp_max[start][mid] + dp_max[mid + 1][end]);
                    dp_min[start][end] = min(dp_min[start][end], dp_min[start][mid] + dp_min[mid + 1][end]);
                }
            }
        }
    }
    answer = dp_max[0][num - 1];

    return answer;
}