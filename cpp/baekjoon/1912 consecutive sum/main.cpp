#include <iostream>

using namespace std;

//연속합 아이디어
//1. 마지막까지 더한 합보다 현재 수와 더한게 작으면 거기서 멈춘다 dp[i] + dp[i-1] >0
//2. 이전수의 합이 음수면 버린다  dp[i-1] > 0 이어야함
int main() {
    int N;
    int a[100001];
    int dp[100001];
    int max=0;
    scanf("%d",&N);
    for(int i =1; i<=N; i++)
    {
        scanf("%d",&a[i]);
    }

    max = a[1];
    dp[1]=a[1];

    for(int i=2;i<=N;i++) {
        if (dp[i-1]+a[i] > a[i]) {
            dp[i] = dp[i-1] + a[i];
        }
        else{
            dp[i]= a[i];
        }
    }

    for(int i=1; i<=N; i++){
        if(max<dp[i]){
            max=dp[i];
        }
    }
    printf("%d",max);
    return 0;
}
