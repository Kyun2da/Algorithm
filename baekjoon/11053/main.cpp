#include <iostream>

int main() {
    int N;
    int a[1001];
    int dp[1001];
    int dp_max=0;
    int answer=0;
    scanf("%d",&N);
    for(int i=1; i<=N; i++){
        scanf("%d",&a[i]);
    }

    dp[1]=1;
    for(int i=2; i<=N; i++){
        dp_max=0;
        for(int j=1; j<i; j++){
            if(a[j]<a[i] && dp_max < dp[j]){
                dp_max=dp[j];
            }
        }
        dp[i]=dp_max+1;
    }

    for(int i=1; i<=N; i++){
        if(answer<dp[i])
            answer=dp[i];
        //printf("%d",dp[i]);
    }
    printf("%d",answer);
    return 0;
}
