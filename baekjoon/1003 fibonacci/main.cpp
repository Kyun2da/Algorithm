/*
   피보나치 수에서 0이 나타나는 개수와 1이 나타나는 개수 또한 피보나치 수임을 수학적 귀납법으로 증명할 수 있다.
   */
#include <iostream>
using namespace std;

int main() {
    int a[41],b[41];
    int N,num;

    a[0]=1, a[1]=0;
    b[0]=0, b[1]=1;

    for(int i=2; i<=40; i++)
    {
        a[i]=a[i-1]+a[i-2];
        b[i]=b[i-1]+b[i-2];
    }

    scanf("%d",&N);
    for(int i =0; i<N; i++)
    {
        scanf("%d",&num);
        printf("%d %d\n",a[num],b[num]);
    }
    return 0;
}
