#include <bits/stdc++.h>
using namespace std;
const int MAX=100010;

int n,k;
int h[MAX],w[MAX];

bool f(int x){
    int y=0;
    for(int i=0;i!=n;i++){
        y+=(h[i]/x)*(w[i]/x);
        if(y>=k){
            return true;
        }
    }
    return false;
};

int main()
{
    cin>>n>>k;
    for(int i=0;i!=n;i++){
        scanf("%d %d",&h[i],&w[i]);
    }
    
    int left=1;
    int right=1e5+1; 
        while(left<right){
            int mid=left+(right-left)/2;
            if(f(mid)){
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        cout<<left-1;
    return 0;
}