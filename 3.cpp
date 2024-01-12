/*

SBSTR1 - Substring Check (Bug Funny)
*/

#include <iostream>
using namespace std;
int main()
{
    int arr1[10] = {1, 1, 1, 0, 1, 1, 1, 0, 1, 1}; // string
    int arr2[5] = {1, 1, 1, 1, 1};                 // substring
    int i, j = 0, k;
    bool found = 0;
    for (i = 0; i <= 5; i = i + 1)
    {
        k = 0;
        found = 0;
        for (j = i; j < i + 5; j = j + 1)
        {
            if (arr1[i+k] == arr2[k])
            {
                k = k + 1;
                if (k == 5)
                {
                    cout << "1";
                    found = 1;
                    break;
                }
            }
            else
            {
                break;
            }
        }
        if(found)break;
    }

    if(!found)cout<<"0";

}