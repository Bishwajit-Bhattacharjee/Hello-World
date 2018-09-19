#include <bits/stdc++.h>
using namespace std;
 
struct node{
    bool hasEnd;
    int prefCnt;
    node* edge[10];
 
    node(){
        hasEnd = prefCnt = 0;
        for(int i = 0 ; i < 10 ; i++)
            edge[i] = 0;
    }
};
node* root ;
 
bool insert(string &str)
{
    node* cur = root;
   
    for(int i = 0; i < str.size(); i++)
    {
        if(cur->edge[str[i] -'0'] == 0){
            cur->edge[str[i]-'0'] = new node();
        }
        if(cur->hasEnd){
            return 0;
        }
        cur->prefCnt++;
        cur = cur->edge[str[i]-'0'] ;
    }
    if(cur->prefCnt){
        return 0;
    }
    cur->hasEnd = 1;
   
 
    return 1;
}
void del(node* now)
{
    node* cur = now;
    for(int i =0; i < 10; i++){
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
        int n;
        scanf("%d",&n);
        bool f = 1;
        for(int i = 0;i < n; i++)
        {
            string s;
            cin >> s;
            f &= insert(s);
        }
        printf("Case %d: %s\n",++c,f?"YES":"NO");
        del(root);
    }
    return 0;
}
