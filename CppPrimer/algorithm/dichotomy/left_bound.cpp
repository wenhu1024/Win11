#include <bits/stdc++.h>
using namespace std;
//左闭右开[left,right)
/*
while break条件：left=right
[left,right) [1,1) null

1 2 2 2 4 5 
*/
int left_bound0(int nums[],int target,int size){
    int left=0;
    int right=size;

    while(left<right){
        int mid=left+(right-left)/2;
        if(nums[mid]==target){
            right=mid; //[left,mid)
        }
        else if(nums[mid]>target){
            right=mid;//[left,mid)
        }
        else if(nums[mid]<target){
            left=mid+1;//[mid+1,right)
        }
    }

    if(left==size) {//left==right   right max=size
        return -1;//no
    }    
    return nums[left]==target ? left : -1; //left==mid
};
//左闭右闭
//[left,right]   [right+1,right]//null
int left_bound1(int nums[],int target,int size){
    int left=0;
    int right=size-1;

    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==target){
            right=mid-1;//[left,mid-1]  
        }
        else if(nums[mid]>target){
            right=mid-1;//[left,mid-1]
        }
        else if(nums[mid]<target){
            left=mid+1;//[mid+1,right]
        }
        
    }
    if(left==size){  //left=right+1   right  max size-1
        return -1;
    }
    return nums[left]==target ? left : -1;
};

int main()
{   int a[4]={1,2,3,4};
    int nums[6]={1,2,2,2,3,4};
    cout<<left_bound0(a,3,4)<<endl;
    cout<<left_bound1(nums,2,6)<<endl;  
    return 0;
}

