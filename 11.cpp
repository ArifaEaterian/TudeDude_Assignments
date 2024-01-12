#include<bits/stdc++.h>

using namespace std;


int countOccurences(int a,int  b) {

    //variable to store result
    int res = 0;

    //variable to store original value of b
    int orig = b;

    //loop while b is less than a
    while(a/b > 0) {

        //divide a by b and add integer part to result
        res += (a/b);

        //double the b
        b *= orig;
    }

    //return the result
    return res;
}
int main() {

    //variable to store number of test cases
    int t;
    cin>>t;

    //loop over all test cases
    while(t--) {

        
        int n;
        cin>>n;

        
        int minimum = min(countOccurences(n,5),countOccurences(n,2));
        cout<<minimum<<endl;
    }
}