#include <bits/stdc++.h>
using namespace std;
//左闭右开
int right_bound0(int nums[],int target,int size){
    int left=0;
    int right=size;
//right=left-1
    while(left<right){
        int mid=left+(right-left)/2;
        if(nums[mid]==target){
            left=mid+1;//[mid+1,right)   //mid=left-1
        }
        else if(nums[mid]<target){
            left=mid+1;//[mid+1,right)
        }
        else if(nums[mid]>target){
            right=mid;//[left,right)
        }                             
    }
    if(left-1<0){  //left min 0
        return -1;
    }
    return nums[left-1]==target ? left-1 : -1;
};

//左闭右闭
int right_bound1(int nums[],int target,int size){
    int left=0;
    int right=size-1;

    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==target){
            left=mid+1;//[mid+1,right]  //mid=left-1
        }
        else if(nums[mid]<target){
            left=mid+1;//[mid+1,right]
        }
        else if(nums[mid]>target){
            right=mid-1;//[left,mid-1]
        }       
    }    
    if(left-1<0){ 
        return -1;
    }
    return nums[left-1]==target ? left-1 : -1;
};
int main()
{
    int nums[6]={1,2,2,2,3,4};
    cout<<right_bound0(nums,2,6)<<endl;
    cout<<right_bound1(nums,2,6)<<endl;
    return 0;
}