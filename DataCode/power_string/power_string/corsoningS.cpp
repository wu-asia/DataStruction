#include<iostream>

using namespace std;
const int N = 1e6 + 10;
string s, t;
int st[N], top;
int pi[N];
int main()
{
	cin >> s >> t;
	int n = s.size();
	int m = t.size();
	s = " " + t + " " + s;
	st[++top] = 1;
	for (int i = 2; i <= n + m + 1; i++)
	{
		int j = pi[st[i - 1]];
		while (j && s[j + 1] != s[i]) j = pi[j];
		if (s[i] == s[j + 1]) pi[i] = j;
		st[++top] = i;
		if (pi[i] == m)
			for (int k = 0; k < m; k++)
				top--;
	}
	for (int i = m + 2; i <= top; i++) cout << s[st[i]];
	return 0;
}