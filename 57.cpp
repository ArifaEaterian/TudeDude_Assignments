/*
SUPPER - Supernumbers in a permutation
*/


#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#define MAXN 100005

int tree[MAXN << 2]; 
int  arr[MAXN]; 
int  LIS[MAXN]; 
int  LDS[MAXN];

inline void update(int node, int lo, int hi, int idx, int value) {
    if (lo > hi || lo > idx || hi < idx)
        return;
    else if(lo == hi)
        tree[node] = value;
    else
    {
        int mid = (lo + hi) / 2;
        
        if (idx <= mid)
            update(node*2,      lo, mid, idx, value);
        else
            update(node*2+1, mid+1,  hi, idx, value);
        
        tree[node] = std::max(tree[node*2], tree[node*2+1]);
    }
}

inline int query(int node, int lo, int hi, int i, int j)
{
    if (lo > hi || lo > j || hi < i)
        return 0;
    else if (lo >= i && hi <= j)
        return tree[node];
    else
    {
        int mid = (lo + hi) / 2;
        int q1 = query(node*2,      lo, mid, i, j);
        int q2 = query(node*2+1, mid+1,  hi, i, j);
        
        return std::max(q1, q2);
    }
}

int main() 
{
    for (int t = 1; t <= 10; ++t)
    {
        int n;
        std::cin >> n;

        std::memset(tree, 0, sizeof(tree));

        int maxi = 1;
        for(int i = 1 ; i <= n ; ++ i) 
        {
            std::cin >> arr[i];
            LIS[i] = 1 + query(1, 1, n, 1, arr[i]);
            update(1, 1, n, arr[i], LIS[i]);
            maxi = std::max(maxi, LIS[i]);
        }
        
        std::memset(tree, 0, sizeof(tree));

        for(int i = n ; i ; -- i) 
        {
            LDS[i] = 1 + query(1, 1, n, arr[i], n);
            update(1, 1, n, arr[i], LDS[i]);
        }
        
        std::vector <int> ans;

        for(int i = 1 ; i <= n ; ++ i)
            if(LIS[i] + LDS[i] - 1 == maxi)
                ans.push_back(arr[i]);
            
        std::sort(ans.begin(), ans.end());

        std::cout << ans.size() << "\n";

        for(int i = 0 ; i < ans.size() ; ++ i)
            if(i != ans.size() - 1)
                std::cout << ans[i] << ' ';
            else
                std::cout << ans[i];

        std::cout << '\n';
    }
}