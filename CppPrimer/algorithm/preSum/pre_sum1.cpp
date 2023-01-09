#include <bits/stdc++.h>
using namespace std;

const int n=6;
int nums[n]={3,5,2,-2,4,1};
int preSum[n+1];

int sumRange(int left,int right){
    return preSum[right+1]-preSum[left];//[0,right]-[0,left-1]
}

int main(){   
    for(int i=1;i!=n+1;i++){     //[1,n]
        preSum[i]=preSum[i-1]+nums[i-1];
    }
    printf("%d\n",sumRange(2,3));
    printf("%d\n",sumRange(0,5));
    return 0;
}
/*
    nums[0]   nums[1]    nums[2]   nums[3]
    1          3            5       2
问一个子区间的和？
[1,3]  for(int i=1;i<=3;i++){
    sum+=... O(n)
}
问多个子区间的和q
[1,3]  ,[0,3] ,[] 
O(qn)
            nums[0]     nums[1]     nums[2]     nums[3]     
                1       3            5              2
有一个数组nums[n]    n=4               
开数组：preSum[n+1]  5  令preSum[0]=0; n+1>i>=1时,preSum[i]=preSum[i-1]+nums[i-1],表示
preSum[0]  preSum[1]    preSum[2]    preSum[3]    preSum[4]    
  0          1             4            9           11      

[1,3]=[0,3]-[0,0]
sum[1,3]=preSum[4]-preSum[1];
[0,3]   preSum[4]-preSum[1];
不需要遍历了  O(n)->O(1)
*/


/*  i>0时，preSum[i] 记录 nums[0]+nums[1]+nums[2]+......nums[i-1] 
    的累加和，注意是一直到nums[i-1];
    
    好处是不用考虑数组越界的判断检查
*/