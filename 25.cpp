/*

POUR1 - Pouring water
*/



#include <bits/stdc++.h>
#define GREEN "\033[32m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
using namespace std;
#ifdef BCDBG

#else
#define dbg(...)
#define dba(arr,...)
#endif
typedef long long ll;
typedef unsigned long long ull;
const char df = '\n';

int go(int A, int B, int c) {
  int ct = 1, a = A, b = 0;
  while (a != c && b != c) {
    if (a == 0) {
      a = A;
      ct++;
    } else if (b == B) {
      b = 0;
      ct++;
    } else {
      int m = min(B - b, a);
      a -= m;
      b += m;
      ct++;
    }
  }
  return ct;
}

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (c % __gcd(a, b) || (c > a && c > b)) {
    cout << -1 << df;
    return;
  }
  cout << min(go(a, b, c), go(b, a, c)) << df;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt = 1;
  cin >> tt;
  for (int i = 1; i <= tt; i++) {
    solve();
  }
  return 0;
}