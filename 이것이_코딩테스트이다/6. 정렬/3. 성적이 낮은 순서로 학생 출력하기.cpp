#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*

    6-3. 성적이 낮은 순서로 학생 출력하기

    [ 문제 정리 ]
    성적 순으로 이름을 정렬

    2
    홍길동 95
    이순신 77

    이순신 홍길동


    [ 해결 방법 ]
    sort 함수 사용

    [ 자료형 ]
    1 <= N <= 100,000

    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초

    operator를 정의할 때, const를 설정해주지 않으면 오류가 발생한다!!
    이는 C++ 버전마다 차이가 있는 듯 하다. 반드시 const를 작성하는 습관을 들이자!!


*/

class Student
{
public:
    string name;
    int score;
    Student(string name, int score) : name(name), score(score) {}
    bool operator<(const Student &other) const
    {
        return this->score < other.score;
    }
};

int main()
{
    int N;
    vector<Student> v;

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        string name;
        int score;
        cin >> name >> score;
        v.push_back(Student(name, score));
    }

    sort(v.begin(), v.end());

    for (Student s : v)
    {
        cout << s.name << " ";
    }
}
