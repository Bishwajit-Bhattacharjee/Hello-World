#include <bits/stdc++.h>
using namespace std;


void prefCalc(string s, vector < int > &v)
{
	int now = -1;
	v[0] = -1;

	for(int i = 1; i < s.size(); i++)
	{
		while(now != -1 and s[now + 1] != s[i])
			now = v[now] ;
		
		if(s[now + 1] == s[i])
			v[i] = ++now;
		else 
			v[i] = now = -1;
	}
}

int kmp(string &T, string &P,vector < int > &pref)
{
	int now = -1;

	for(int i = 0;i < T.size(); i++)
	{
		while(now != -1 and P[now+1] != T[i])
			now = pref[now];

		if(P[now + 1] == T[i]) ++now;
		else 
			now = -1;
	}
	return now + 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	int caseNo = 0;

	while(t--)
	{
		string T;
		cin >> T;
		vector < int > pref(T.size());
		string P = T;

		reverse(P.begin(),P.end());
		prefCalc(P,pref);

		int minus = kmp(T,P,pref);

		
		cout <<"Case "<< ++caseNo << ": " << 2*T.size() - minus << '\n';
	}
	return 0;	
}