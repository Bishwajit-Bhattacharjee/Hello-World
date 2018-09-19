#include <bits/stdc++.h>
using namespace std;
 
int const CNT = 4;
struct node{
    int len;
    int prefCnt;
    node* edge[CNT];
 
    node(){
        len = prefCnt = 0;
        for(int i = 0 ; i < CNT; i++)
            edge[i] = 0;
    }
};
node* root ;
int ans ;
 
void insert(string &str)
{
    node* cur = root;
   
    for(int i = 0; i < str.size(); i++)
    {
        if(cur->edge[str[i] -'A'] == 0){
            cur->edge[str[i]-'A'] = new node();
        }
        int tmpLen = cur->len;
 
        cur = cur->edge[str[i]-'A'] ;
        cur->prefCnt++;
        cur->len = tmpLen + 1;
        ans = max(ans, cur->prefCnt * cur->len);
    }
   
    //cur->hasEnd = 1;
}
void del(node* now)
{
    node* cur = now;
    for(int i =0; i < CNT ; i++){
        if(cur->edge[i]){
            del(cur->edge[i]);
        }
    }
    delete cur;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
 
    int t, c = 0;
    cin >> t;
    while(t--)
    {
        root = new node();
        ans = 0;
        int n;
        scanf("%d",&n);
       
        for(int i = 0;i < n; i++)
        {
            string s;
            cin >> s;
            for(int i =0 ; i < s.size(); i++){
                if(s[i] == 'C')
                    s[i] = 'B';
                else if(s[i] == 'G')
                    s[i] = 'C';
                else if(s[i] == 'T')
                    s[i] = 'D';
            }
            insert(s);
        }
        printf("Case %d: %d\n",++c,ans);
        del(root);
    }
    return 0;
}
