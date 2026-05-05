//#include<iostream>
//#include<string>
//using namespace std;
//string s;
//int n;
//const int N = 1e6 + 10;
//int pi[N];
//
//
//int kmp(string s)
//{
//	int n = s.size();
//	s = " " + s;
//	for (int i = 2; i <= n; i++)
//	{
//		int j = pi[i - 1];
//		while (j && s[j + 1] != s[i]) j = pi[j];
//		if (s[j + 1] == s[i]) j++;
//		pi[i] = j;
//	}
//	return n - pi[n];
//}
//int main()
//{
//	cin >> n;
//	cin >> s;
//	cout << kmp(s) << endl;
//	return 0;
//}