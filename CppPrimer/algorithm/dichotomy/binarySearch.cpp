#include <bits/stdc++.h>
using namespace std;
//左闭右闭
/*
    nums[0,1,,...size-1]
    <=   while break条件：left=right+1
    [right+1,right] null [3,2]
*/
int binarySearch(int nums[],int target,int size){
    int left=0;
    int right=size-1;

    while(left<=right){
    //(left+right)/2   int 10的9次方

        int mid=left+(right-left)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            right=mid-1;   //[left,mid-1]
        }else if(nums[mid]<target){
            left=mid+1; //[mid+1,right]
        }       
    }
    //left==right+1   size
    return -1; //no 
};

int main()
{
    int nums[5]={1,2,2,3,4};
    cout<<binarySearch(nums,2,5)<<endl;
    return 0;
}
/*
    for() O(n) q=1 

    nums[6]    1  3  4   5 6   7
    target=3  1
    [0,5]   mid=(right+left)/2  =2
            nums[2]==target   false
            right=mid-1 = 1
    [0,1]   mid= (right+left)/2=0  
            nums[0]=1 
            left=mid+1
    [1,1]   mid=1
            nums[mid]==target true               

*/