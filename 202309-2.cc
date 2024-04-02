#include<bits/stdc++.h>
using namespace std;
int n,m;
double aa[100001],ab[100001];
int main()
{
    aa[0]=1;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        aa[i]=aa[i-1],ab[i]=ab[i-1];
        int t;
        double tt;
        cin>>t>>tt;
        if(t==1){
            aa[i]*=tt;
        }else{
            ab[i]+=tt;
        }
    }
    while(m--){
        int i,j,x,y;
        cin>>i>>j>>x>>y;
        double k=aa[j]/aa[i-1],theta=ab[j]-ab[i-1];
        printf("%f %f\n", k*(x*cos(theta)-y*sin(theta)),k*(x*sin(theta)+y*cos(theta)));
    }
    return 0;
} 
