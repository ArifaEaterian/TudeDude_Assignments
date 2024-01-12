/*
BRCKTS - Brackets
*/



#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

int const N = 3e4 + 10;
int n, m, k;
char s[N];
pair<int, int> seg[N * 4];

void merge(int at) {
	seg[at].F = max(0, seg[at << 1].F - seg[at << 1 | 1].S) + seg[at << 1 | 1].F;
	seg[at].S = max(0, seg[at << 1 | 1].S - seg[at << 1].F) + seg[at << 1].S;
}

void build(int at, int l, int r) {
	if(l == r) {
		seg[at].F = (s[l] == '(');
		seg[at].S = (s[l] == ')');
		return;
	}

	int m = (l + r) >> 1;
	build(at << 1, l, m);
	build(at << 1 | 1, m + 1, r);
	merge(at);
}

void update(int at, int l, int r) {
	if(r < k || l > k)
		return;

	if(l == r) {
		if(s[l] == '(')
			s[l] = ')';
		else
			s[l] = '(';

		seg[at].F = (s[l] == '(');
		seg[at].S = (s[l] == ')');
		return;
	}

	int m = (l + r) >> 1;
	update(at << 1, l, m);
	update(at << 1 | 1, m + 1, r);
	merge(at);
}

int main() {
  for(int i = 1; i <= 10; ++i) {
  	printf("Test %d:\n", i);

  	scanf("%d\n%s", &n, s + 1);

  	memset(seg, 0, sizeof seg);
  	build(1, 1, n);

  	scanf("%d", &m);
  	while(m-- != 0) {
  		scanf("%d", &k);

  		if(k == 0) {
  			if(seg[1].F == 0 && seg[1].S == 0)
  				puts("YES");
  			else
  				puts("NO");
  		} else
  			update(1, 1, n);
  	}
  }

  return 0;
}