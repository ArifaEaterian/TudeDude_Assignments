/*
JULKA - Julka
*/

#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
int t=10,carry,a[105],b[105],temp[105];
char sum[105],diff[105];

while(t--)
{
    cin>>sum;          // sum and diff accepted as strings
    cin>>diff;
    int i,j,k=0,r;
    for(i=strlen(sum)-1,j=strlen(diff)-1;i>=0,j>=0;i--,j--)  
    {
        if( sum[i] >= diff[j] )  //loop to find sum -diff.Result in temp
            temp[k++]=sum[i]-diff[j];
        else
        {   temp[k++]=10+sum[i]-diff[j];
            r=i-1;
            while(1)
            {

                if(sum[r]=='0')
                {
                    sum[r]='9';
                    r--;
                    continue;
                }
                sum[r]=(char)(sum[r]-1);
                break;
            }
        }
    }
    if(i>=0)        // for digits after diff's msb,we simply pass it to temp 
    {   for(j=i;j>0;j--)
        {
            temp[k++]=sum[j]-'0';
        }
        if(sum[0]!='0')             //if last digit is 0,we don't want it
            temp[k++]=sum[0]-'0';
    }

    //finding the smaller
    j=0;                     // a=(sum-diff)/2
    carry=0;
    for(i=k-1;i>=0;i--)
    {   a[j++]=(temp[i]+10*carry)/2;
        carry=(temp[i]+10*carry)%2; //a msb at 0
    }
    int cnt_a=k;


    //finding bigger

    k=0,i=j-1,r=strlen(diff)-1;  // b=a+diff
    carry=0;
    while(i>=0&&r>=0)           
    {
        b[k++]= (a[i]+(diff[r]-'0')+carry)%10;  //a lsb at j-1,b lsb at 0
        carry=(a[i--]+(diff[r--]-'0')+carry)/10;
    }

    while(i>=0) // if a>diff for digits after diff's msb,we pass it to b
    {   b[k++]= (a[i]+carry)%10;
        carry=  (a[i--]+carry)/10;
    }

    while(r>=0) // if diff>a for digits after a's msb,we pass it to b
    {   b[k++]= ( (diff[r]-'0')+carry)%10;
        carry=  ( (diff[r--]-'0')+carry)/10;
    }
    int cnt_b=k;

    //printing a and b

    if(cnt_b>1)      //printing b

    {   if(b[cnt_b-1]!=0)          //if msb was 0 we don't print it
            printf("%d",b[cnt_b-1]);


        for(i=cnt_b-2;i>=0;i--)
            printf("%d",b[i]);

        printf("\n");
    }
    else if(cnt_b==1) //if only 1 digit we print msb even if it's 0
        printf("%d\n",b[0]);


    if(cnt_a>1)          //printing b

    {   if(a[0]!=0)
            printf("%d",a[0]);   //if msb was 0 we don't print it

        for(i=1;i<cnt_a;i++)
            printf("%d",a[i]);
        printf("\n");
    }
    else if(cnt_a==1)       //if only 1 digit we print msb even if it's 0
        printf("%d\n",a[0]);


}
return 0;
}