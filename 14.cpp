/*

IKEYB - I-Keyboard
*/


#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define INF 100000000
 
int res[100][100],t,n,m;
char keys[100],alpha[100];
long int freq[100],dp[100][100];
 
int calc(int ini,int key)
{
    if(ini==m)  
        return(INF);
    
    if(dp[ini][key])
        return(dp[ini][key]);
    long int store=0,mini=INF;
    if(key==n-1)
    {
        for(int i=ini;i<m;i++)
            store=store+freq[i]*(i-ini+1);
        dp[ini][key]=store;
        res[ini][key]=m-ini;
        return(dp[ini][key]);
    }
    for(int i=ini;i<m;i++)
    {
        store=store+freq[i]*(i-ini+1);
        if(store+calc(i+1,key+1) < mini)
        {
            mini=store+dp[i+1][key+1];
            res[ini][key]=i-ini+1;
        }
    }
    dp[ini][key]=mini;
    return(dp[ini][key]);
}
 
int main()
{
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        memset(dp,INF,sizeof(dp));
        memset(res,0,sizeof(res));
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            cin>>keys[i];
        for(int i=0;i<m;i++)
            cin>>alpha[i];
        for(int i=0;i<m;i++)
            cin>>freq[i];
        calc(0,0);
        cout<<"Keypad #"<<cas<<":\n";
        int x=0;
        for(int i=0;i<n;i++)
        {
            cout<<keys[i]<<": ";
            for(int j=x;j<x+res[x][i];j++)
            {
                cout<<alpha[j];
            }
            cout<<"\n";
            x=x+res[x][i];
        }
        cout<<"\n";
    }
}