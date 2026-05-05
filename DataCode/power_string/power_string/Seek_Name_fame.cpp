//#include<iostream>
//#include<string>
//
//using namespace std;
//string s;
//const int N = 4e5 + 10;
//int pi[N], ret[N];
//int main()
//{
//	while (cin >> s)
//	{
//		int n = s.size();
//		s = " " + s;
//		for (int i = 2; i <= n; i++)
//		{
//			int j = pi[i - 1];
//			while (j && s[j + 1] != s[i]) 
//				j = pi[j];
//			if (s[i] == s[j + 1])
//				j++;
//			pi[i] = j;
//		}
//		int top = 0;
//		for (int i = n; i; i = pi[i])
//		{
//			ret[top++] = i;
//		}
//		for (int i = top - 1; i >= 0; i--)
//			cout << ret[i] << " ";
//		cout << endl;
//	}
//}