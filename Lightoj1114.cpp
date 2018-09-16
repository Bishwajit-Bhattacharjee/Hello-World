#include <bits/stdc++.h>
using namespace std;

int const CNT = 52;

void modify(string& str)
{
    if(str.size() <= 2 ) return;
    sort(str.begin() + 1, str.end() - 1);

}
char input[(int)1e5 + 10];
string work;
map < string , int > mp;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif


    int t, c = 0;
    scanf("%d",&t);

    while(t--)
    {
        mp.clear();
        //root = new node();
        int n;
        scanf("%d",&n);
        gets(input);
        //cin >> n;
        for(int i = 0; i < n;i++){
            gets(input);
            work = input;
            modify(work);
            //cout << s << endl;
            //insert(work);
            mp[work]++;

        }
        printf("Case %d:\n",++c);

        //cout << "Case " << ++c << ":" << '\n';
        int m;
        scanf("%d",&m);
        gets(input);
        while(m--){
            int ans = 1;
            gets(input);
            work = input;
            stringstream srm(work);
            while(srm >> work){

                modify(work);

                if(mp.count(work)){
                    ans *= mp[work];
                }
                else
                    ans = 0;

            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
