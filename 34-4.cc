///该解答未被验证！！！请谨慎使用
///时间复杂度 O(40000m)

#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=1000;
int n,m,v,b[N],c[N];
vector<int>qq[N];
int dp[40001];
int main(){
    cin>>n>>m>>v;
    for(int i=0;i<n;++i){
        cin>>b[i]>>c[i];
    }
    for(int i=0;i<m;++i){
        int a,t;
        cin>>a>>t;
        qq[t].push_back(a);
    }
    for(int i=0;i<n;++i){
        sort(qq[i].begin(),qq[i].end(),greater<>());
    }
    memset(dp,-1,sizeof dp);
    dp[0]=0;
    for(int i=0;i<n;++i){
        int cost=b[i],val=0;
        for(int a:qq[i]){
            if(a<=c[i])break;
            cost+=c[i],val+=a-c[i];
            for(int j=0;j+cost<=40000;++j){
                if(~dp[j])dp[j+cost]=max(dp[j+cost],dp[j]+val);
            }
        }
    }
    int ans=0;
    for(;ans<=40000;++ans){
        if(dp[ans]>=v)break;
    }
    cout<<ans;
    return 0;
}
