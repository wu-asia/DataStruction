//#include<iostream>
//#include<string>
//using namespace std;
//string s, sub;
//const int N = 1000;
//int pi[N];
//
//int kmp(string sub, string s)
//{
//	string ns = sub + " " + s;
//	int n = ns.size();
//	int m = sub.size();
//	ns = " " + ns;
//	for (int i = 2; i <= n; i++)
//	{
//		int j = pi[i - 1];
//		while (j && ns[j + 1] != ns[i]) j = pi[j];
//		if (ns[j + 1] == ns[i]) j++;
//		pi[i] = j;
//	}
//	int cnt = 0;
//	for (int i = m + 2; i <= n; i++)
//	{
//		if (pi[i] == m)
//		{
//			cnt++;
//			i += m - 1;
//		}
//			
//	}
//	return cnt;
//}
//int main()
//{
//	while (cin >> s >> sub)
//	{
//		cout << kmp(sub, s) << endl;
//	}
//	return 0;
//}
//
//#include<iostream>
//#include<string>
//
//using namespace std;
//const int N = 2010;
//string s, t;
//int n, m, pi[N];
//int main()
//{
//	while (cin >> s >> t)
//	{
//		n = s.size(), m = t.size();
//		s = " " + t + " " + s;
//		for (int i = 2; i <= n + m + 1; i++)
//		{
//			int j = pi[i - 1];
//			while (j && s[i] != s[j + 1]) j = pi[j];
//			if (s[i] == s[j + 1]) j++;
//			pi[i] = j;
//		}
//		int ret = 0;
//		for (int i = m + 1; i <= n + m + 1; i++)
//		{
//			if (pi[i] == n)
//			{
//				ret++;
//				i += m - 1;
//			}
//		}
//		cout << ret << endl;
//	}
//	return 0;
//}