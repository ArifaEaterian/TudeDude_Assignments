#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
 
#define EPS 1e-11
#define inf ( 1LL << 31 ) - 1
#define LL long long
 
#define abs(x) (((x)< 0) ? (-(x)) : (x))
#define all(x) (x).begin(), (x).end()
#define ms(x, a) memset((x), (a), sizeof(x))
 
#define mp make_pair
#define pb push_back
#define sz(k) (int)(k).size()
 
using namespace std;
 
typedef vector <int> vi;
 
bool isPalindrome (string str)
{
	int start = 0, end = str.length() - 1;
	while (start < end)
	{
		if (str[start++] != str[end--])
		{
			return false;
		}
	}
	return true;
}
 
int get_bigger (string str1, string str2)
{
	int len = str1.length();
	for (int i = 0; i < len; i++)
	{
		if (str1[i] < str2[i])
		{
			return -1;
		}
		else if (str1[i] > str2[i])
		{
			return 1;
		}
	}
	return 0;
}
 
string rev (string str)
{
	string revstr = str;
	int start = 0, end = str.size() - 1;
	while (start <= end)
	{
		revstr[end]   = str[start];
		revstr[start++] = str[end--];
	}
	return revstr;
}
 
string inc_str (string str)
{
	int len = str.size() - 1;
	string res = str;
	int carry = 1;
	while (len >= 0 && carry)
	{
		if (str[len] == '9')
		{
			res[len--] = '0';
		}
		else
		{
			res[len--]++;
			carry = 0;
		}
	}
	if (carry)
	{
		res = "1" + res;
	}
	return res;
}
 
void process (string str)
{
	string str1, str2, str3;
	int len = str.size();
	str1 = str.substr (0, len/2);
	if (len % 2 == 0)
	{
		str2 = "";
		str3 = str.substr (len/2, len/2);
	}
	else
	{
		str2 = str.substr (len/2, 1);
		str3 = str.substr (len/2 + 1, len/2);
	}
	string rev_str1 = rev (str1);
	int rc = 0;
	if (rev_str1 > str3)
	{
		cout << str1 + str2 + rev_str1 << endl;
		return;
	}
	if (str2 == "")
	{
		int ix = str1.size();
		rev_str1 = "";
		rev_str1.append (ix, '0');
		str1 = inc_str (str1);
	}
	else
	{
		str2 = inc_str (str2);
		if (str2.size() > 1)
		{
			int ix = str1.size();
			rev_str1 = "";
			rev_str1.append (ix, '0');
			str1 = inc_str (str1);
			str2 = "0";
		}
	}
	string str4 = str1 + str2 + rev_str1;
	if (isPalindrome(str4)) 
	{
		cout << str4 << endl;
		return;
	}
	process (str4);
}
 
int main ()
{
	int total ;
	cin >> total;
	string str;
	while (total-- > 0)
	{
		cin >> str;
		process (str);
	}
	return 0;
}