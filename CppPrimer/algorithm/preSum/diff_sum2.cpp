#include <bits/stdc++.h>
using namespace std;

const int m = 3;
const int n = 4;
int nums[m][n]={
	{1,5,6,8},
	{9,6,7,3},
	{5,3,2,4},
};
int preSumD[m+1][n+1];
int d[m+1][n+1];

void add(int x1,int y1,int x2,int y2,int v){
	d[x1][y1]+=v;
    d[x1][y2+1]-=v;
    d[x2+1][y1]-=v;
    d[x2+1][y2+1]+=v;
}


int main() {
    add(0,0,2,1,3);
	for(int i=1;i!=m+1;i++){
        for(int j=1;j!=n+1;j++){
            preSumD[i][j]=d[i-1][j-1]+preSumD[i-1][j]+preSumD[i][j-1]-preSumD[i-1][j-1];
        }
    }
    
    for(int i=0;i!=m;i++){
        for(int j=0;j!=n;j++){
            nums[i][j]+=preSumD[i+1][j+1];
            printf("%d\t",nums[i][j]);
        }
        printf("\n");
    }
	return 0;
}
