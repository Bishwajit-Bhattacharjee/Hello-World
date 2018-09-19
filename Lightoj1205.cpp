#include <bits/stdc++.h>
using namespace std;
string num1, num2 ;
typedef long long int ll;
 
ll t1[20], palin[20];
 
void precalc()
{
    t1[1] = 10 , t1[2] = 10;
    palin[1] = palin[2] = 9;
 
    for(int i = 3; i < 18; i++)
    {
        palin[i] = 9 * t1[i-2] ;
        t1[i] = 10 * t1[i-2] ;
    }
 
}
ll dp[20][3][3];
// rt means the making number is bigger at any right character
 
 
string toString(ll num)
{
    string tmp = "";
    while(num)
    {
        tmp +=  (num % 10 + '0');
        num /= 10;
 
    }
    reverse(tmp.begin(), tmp.end() ) ;
    return tmp;
}
 
ll DP(int pos, bool lf, bool rt, string &s)
{
    if(s.size() == 1 and s[0] == '0')
        return 0;
    if(pos == ( (int) s.size() + 1) / 2 ) return lf | (!rt) ;
    ll &ret = dp[pos][lf][rt] ;
    if(ret != -1 ) return ret;
 
    ret = 0;
    if(lf)
    {
        for(int i = (pos == 0) ; i <= 9 ;i++)
        {
            ll tmp = 0;
            if(s[(int)s.size()-1-pos] > '0'+ i){
                tmp = DP(pos+1,lf, 0, s) ;
            }
            else if(s[(int)s.size()-1-pos] == ('0'+ i) )
                tmp = DP(pos +1, lf, rt, s) ;
            else
                tmp = DP(pos + 1, lf, 1, s);
            ret += tmp ;
        }
    }
    else
    {
        for(int i = (pos == 0); i <= s[pos] - '0'; i++)
        {
            ll tmp = 0;
            if(i == (s[pos] - '0'))
                lf = 0;
            else
                lf = 1;
 
            if(s[(int)s.size()-1-pos] > '0'+ i){
                tmp = DP(pos+1,lf, 0, s) ;
            }
            else if(s[(int)s.size()-1-pos] == ('0'+ i) )
                tmp = DP(pos +1, lf, rt, s) ;
            else
                tmp = DP(pos + 1, lf, 1, s);
 
            ret += tmp;
        }
    }
    return ret;
 
}
 
int main()
{
    int t, c =0 ;
    cin >> t;
    precalc();
//    string s = "9";
//    memset(dp,-1,sizeof dp);
//    cout << DP(0,0,0,s) << endl;
 
    while(t--)
    {
        ll a ,b ;
        cin >> a >> b;
        if(a > b) swap(a,b);
        a--;
        ll c1 = 0;
        num1 = toString(a);
        num2 = toString(b);
        memset(dp,-1,sizeof dp);
 
        for(int i = 1; i < num1.size(); i++)
            c1 += palin[i] ;
        c1 += DP(0,0,0,num1) ;
 
        ll c2 =0 ;
 
        for(int i = 1 ; i< num2.size() ; i++)
            c2 += palin[i];
 
     //   cout << "palin[5] " << palin[5] << endl;
 
       // cout << "here" << DP(0,0,0,num2) << endl;
    //    c2 += DP()
        memset(dp,-1,sizeof dp);
        c2 += DP(0,0,0,num2);
        ll ans = c2 - c1;
 
        if(a == -1 or a == 0 )
        {
            ans++;
        }
 
        printf("Case %d: %lld\n",++c,ans) ;
 
    }
    return 0;
}
