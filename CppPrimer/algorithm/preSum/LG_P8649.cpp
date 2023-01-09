#include <bits/stdc++.h>
using namespace std;

const int MAX=100010;
long long nums[MAX];
long long ans[MAX];
long long preSum[MAX];

/* 如果sum[0,1,...,x1]%k=a,sum[0,1,2,3,...,x2]%k=a,且x2>x1,
   则(sum[0,...,x2]-sum[0,...,x1])%k=0,
   即nums数组区间[x1，x2]为一个k倍区间，sum[x1,x1+1,...,x2]可以被k整除
*/
int main()
{
    int n,k;
    long long cnt=0;
    scanf("%d %d",&n,&k);
    
    for(int i=0;i!=n;i++){
        scanf("%lld",&nums[i]);
    }

    for(int i=1;i!=n+1;i++){
        preSum[i]=preSum[i-1]+nums[i-1];
        ans[preSum[i]%k]++;   //前缀和%k所得余数相同的，计数加1    
    }

    for(int i=0;i!=k;i++){
        cnt+=ans[i]*(ans[i]-1)/2;  //排列组合，前缀和%k所得余数相同的，任意选两个值为：x*(x-1)/2个k倍区间
    }
    cnt+=ans[0];
    printf("%d",cnt);
    return 0;
}
