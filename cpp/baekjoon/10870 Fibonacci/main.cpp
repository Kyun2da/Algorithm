#include <iostream>
using namespace std;

int solution(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else{
        return solution(n-1)+solution(n-2);
    }
}

int main() {
    int N, answer;
    cin >> N;
    answer = solution(N);
    cout << answer;
    return 0;
}
