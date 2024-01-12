
/*CMPLS - Complete the Sequence! */
#include <iostream>
using namespace std;

int c[101];
double a[101];
int T,S,C;


double divByFactorial(double denom, int n)
{
  for(int i=1;i<=n;i++)
	{
		denom/=double(i);
	}
	return denom;
}

double cool(int n,int t)
{
	double temp=1;
	for(int i=0;i<t;i++)
	{
		temp=temp*(n-i);
	}
	return temp;
}

void process(int n)
{
	 double temp=c[n];
	 for(int i=0;i<n-1;i++)
	 {
		temp=temp-a[i+1]*cool(n-1,i);
	 }
	 a[n]=divByFactorial(temp,n-1);
}

void come(int n)
{
	double temp=0;
	for(int i=1;i<=S;i++)
	{
		temp+=a[i]*cool(n-1,i-1);
	}
	cout<<int(temp)<<' ';
}

int main()
{
	cin>>T;
	for(int test=1;test<=T;test++)
	{
		cin>>S>>C;
		cin>>c[1];
		a[1]=c[1];
		
		for(int i=2;i<=S;i++)
		{
			cin>>c[i];
			process(i);
		}
			
	    for(int next=1;next<=C;next++)
		{
			come(S+next);
		}	
		cout<<'\n';
	}
}