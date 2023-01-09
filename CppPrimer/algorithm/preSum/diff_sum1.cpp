#include <bits/stdc++.h>
using namespace std;

const int n = 5;
int nums[n];
int d[n+1];
int p[n+1];
void add(int left,int right,int v){
    d[left]+=v;
    d[right+1]-=v;
}

int main()
{
    int nums[n] = { 1,3,7,5,2 };

    add(2, 4, 5);

	add(1, 3, 2);
	add(0, 2, -3);
    for(int i=1;i!=n;i++){        
        p[i]=d[i-1]+p[i-1];
    }
    
    for(int i=0;i!=n;i++){
        nums[i]+=p[i+1];
    }

    for(int i=0;i!=n;i++){
        printf("%d\t",nums[i]);
    }
    return 0;
}
