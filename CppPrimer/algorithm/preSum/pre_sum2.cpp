#include <bits/stdc++.h>
using namespace std;

const int m=5;
const int n=5;
int matrix [m][n]={
    {3,0,1,4,2},
    {5,6,3,2,1},
    {1,2,0,1,5},
    {4,1,0,1,7},
    {1,0,3,0,5}
};
int preSum[m+1][n+1];
// 定义：i>0且j>0,preSum[i][j] 记录 matrix 中子矩阵 [0, 0, i-1, j-1] 的元素和
int sumRegion(int x1,int y1, int x2,int y2){
    return preSum[x2+1][y2+1]-preSum[x2+1][y1]-preSum[x1][y2+1]+preSum[x1][y1];
}
int main()
{   
    for(int i=1;i!=m+1;i++){
        for(int j=1;j!=n+1;j++){
            preSum[i][j]=matrix[i-1][j-1]+preSum[i][j-1]+preSum[i-1][j]-preSum[i-1][j-1];
        }
        printf("\n");
    }

    printf("%d\n",sumRegion(2,1,4,3));
    return 0;
}

