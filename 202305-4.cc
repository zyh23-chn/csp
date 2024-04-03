#include<bits/stdc++.h>
using namespace std;

const int inf=1e18;
using ll=long long;

int n,m,k,co[10000][10];
vector<int>g[10000];
vector<array<int,2>>e;
vector<vector<int>>coco;

int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;++i){
        for(int j=0;j<k;++j){
            cin>>co[i][j];
        }
    }
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        e.push_back({u,v});
        coco.push_back(vector<int>(k*k));
        for(int&t:coco[i]){
            cin>>t;
        }
    }
    if(n<=6 and k<=10){
        vector<int>a(n);
        ll ans=inf;
        function<void(int)>f=[&](int i){
            if(i==n){
                ll tmp=0;
                for(int i=0;i<n;++i){
                    tmp+=co[i][a[i]];
                }
                for(int i=0;i<m;++i){
                    int u=e[i][0],v=e[i][1];
                    tmp+=coco[i][a[u]*k+a[v]];
                }
                ans=min(ans,tmp);
                return;
            }
            for(int j=0;j<k;++j){
                a[i]=j;
                f(i+1);
            }
        };
        f(0);
        cout<<ans;
    }else if(m==n-1){
        ;
    }else if(m==n){
        ;
    }
    return 0;
} 
