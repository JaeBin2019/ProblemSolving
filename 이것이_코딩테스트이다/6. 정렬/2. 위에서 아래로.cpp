#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

/*

    https://www.acmicpc.net/problem/2751

    6-2. 위에서 아래로

    [ 문제 정리 ]
    1 ~ N 까지 정렬

    [ 해결 방법 ]
    병합정렬

    [ 자료형 ]
    1 <= N <= 500

    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초
    O(NlogN)

*/

int arr[1000001];
int tmp[1000001];

void merge(int left, int right, int mid)
{
    int l = left;
    int r = mid + 1;
    int tmpIdx = left;

    while (true)
    {
        // 왼쪽이 먼저 끝났다는 의미는, r ~ right 까지는 이미 정렬이 되어 있다는 의미이다.
        // 따라서 tmp 에서 l ~ mid 까지를 바로 arr 로 복사하면 된다
        if (l == mid + 1)
        {
            copy(tmp + left, tmp + tmpIdx, arr + left);
            // copy(arr + r, arr + mid + 1, tmp + tmpIdx);
            return;
        }

        // 오른쪽이 먼저 끝났다는 의미는, 왼쪽의 남은 부분을 arr의 오른쪽으로 옮기고
        // tmp 에 복사된 부분을 arr 로 가져오면 된다는 의미이다.
        // 1 3 7 9     2 4 5 6
        // tmp가 1 2 3 4 5 6   으로 정렬된 상태로 끝났다면, 남은 7 9 를 arr 의 오른쪽 끝으로 옮기고
        // tmp 에서 1 ~ 6 까지를 arr 의 왼쪽으로 복사해오면 된다
        else if (r == right + 1)
        {

            int remain = mid - l;
            copy(arr + l, arr + mid + 1, arr + right - remain);
            copy(tmp + left, tmp + tmpIdx, arr + left);
            // copy(arr + l, arr + mid + 1, tmp + tmpIdx);
            return;
        }

        if (arr[l] < arr[r])
        {
            tmp[tmpIdx] = arr[l];
            ++tmpIdx;
            ++l;
        }
        else
        {
            tmp[tmpIdx] = arr[r];
            ++tmpIdx;
            ++r;
        }
    }
    // copy(tmp + left, tmp + right + 1, arr + left);
}

void mergeSort(int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, right, mid);
}

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", arr + i);
    }

    mergeSort(0, N - 1);

    for (int i = 0; i < N; ++i)
    {
        printf("%d\n", arr[i]);
    }
}
