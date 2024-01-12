/*
TOUR - Fake tournament
*/


#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define memo(a,b) memset(a,b,sizeof(a))
#define INF 1e9
#define EPS 1e-8
#define PI 3.14159265358979323846

typedef long long ll ;
typedef unsigned long long ull ;


int N , dt[1000+10] , ft[1000+10] , ct[1000+10] , indegree[1000+10] , t , cycle ;
bool visit[1000+10] ;
vector <int> G[1000+10] , GT[1000+10] , Q ;

void dfs1(int u)
{
    visit[u] = true ;
    dt[u] = ++t ;
    for(int i=0;i<G[u].size();i++)
    {
        int v = G[u][i] ;
        if(!visit[v]) dfs1(v);
    }
    ft[u] = ++t ;
    Q.pb(u);
}

void dfs2(int u,int cmp)
{
    visit[u] = false ;
    ct[u] = cycle ;
    for(int i=0;i<GT[u].size();i++)
    {
        int v = GT[u][i] ;
        if(visit[v]&&cmp>ft[v]) dfs2(v,cmp);
    }
}

void Reset()
{
    t = 0 ;
    cycle = 1 ;
    Q.clear();
    for(int i=0;i<=1000;i++)
    {
        G[i].clear();
        GT[i].clear();
        visit[i] = false ;
        indegree[i] = 0 ;
    }
}

int main()
{
    int T ;
    cin >> T ;
    while( T-- )
    {
        Reset();
        cin >> N ;
        for(int u=1;u<=N;u++)
        {
            int m ;
            cin >> m ;
            while( m-- )
            {
                int v ;
                cin >> v ;
                G[v].pb(u);
                GT[u].pb(v);
            }
        }
        for(int i=1;i<=N;i++) if(!visit[i]) dfs1(i);
        for(int i=Q.size()-1;i>=0;i--) if(visit[Q[i]]) { dfs2(Q[i],ft[Q[i]]); cycle++; }
        for(int u=1;u<=N;u++)
        {
            for(int i=0;i<G[u].size();i++)
            {
                int v = G[u][i] ;
                if(ct[u]!=ct[v]) indegree[ct[v]]++;
            }
        }
        int count = 0 ;
        for(int i=1;i<cycle;i++) if(indegree[i]==0) count++;
        if(count>1) puts("0");
        else
        {
            int ans = 0 ;
            for(int i=1;i<=N;i++) if(indegree[ct[i]]==0) ans++;
            cout << ans << endl ;
        }
    }
    return 0;
}