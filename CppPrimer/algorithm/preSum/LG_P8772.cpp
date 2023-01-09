#include <bits/stdc++.h>
using namespace std;

const int MAX=200010;
long long nums[MAX];
long long preSum[MAX];

long long sumRange(int left,int right){
    return preSum[right+1]-preSum[left];
}
int main()
{
    int n;
    long long sum=0;
    scanf("%d",&n);
    for(int i=0;i!=n;i++){
        scanf("%lld",&nums[i]);
    }

    for(int i=1;i!=n+1;i++){
        preSum[i]=preSum[i-1]+nums[i-1];
    }

    for(int i=0;i!=n-1;i++){
        sum+=nums[i]*(sumRange(i+1,n-1));
    }
    printf("%lld",sum);
}