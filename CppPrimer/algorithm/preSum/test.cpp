#include <bits/stdc++.h>
using namespace std;

const int MAX=5010;
int nums[MAX][MAX];


int main()
{
    int n,r;
    
    
    scanf("%d %d",&n,&r);
    r=min(r,50001);
    int cow=r,row=r;
    while(n--)
    {
        int x,y,w;
        x++;
        y++;
        scanf("%d %d %d",&x,&y,&w);
        nums[x][y]=+w;
        cow=max(x,cow);
        row=max(y,row);
    }
    int ans=0;
    for(int i=1;i!=row+1;i++){
        for(int j=1;j!=cow+1;j++){
            nums[i][j]+=nums[i-1][j]+nums[i][j-1]-nums[i-1][j-1];
        }
    }
    
    
    for(int i=r;i!=row+1;i++){
        for(int j=r;j!=cow+1;j++){
            ans=max(ans,nums[i][j]-nums[i-r][j]-nums[i][j-r]+nums[i-r][j-r]);
        }
    }
       
    printf("%d",ans);
    return 0;
}
//   r=2    1  2  3    3-2    res, s[i][j] - s[i - R][j] - s[i][j - R] + s[i - R][j - R]
//0 0 0 0     
//0 1 2 3    1 3 6`
//0 1 2 3    2 6 12