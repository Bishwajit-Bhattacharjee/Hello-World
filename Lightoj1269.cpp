#include <bits/stdc++.h>
using namespace std;

int const CNT = 2;
int const MX = 5e4 + 100;

struct node{
	node* edge[CNT];

	node(){
		for(int i = 0 ; i < CNT; i++)
			edge[i] = 0;
	}
};
node* root ;

void insert(string &str)
{
	node* cur = root;
	
	for(int i = (int)str.size() - 1; i >= 0; i--)
	{
		int id = str[i] - '0';

		if(cur->edge[id] == 0){
			cur->edge[id] = new node();
		}
		cur = cur->edge[id] ;
	}
}

int mxQuery(string &str){
	node* cur = root;
	int ret = 0;

	for(int i = (int)str.size() - 1 ; i >= 0; i--){
		
		int id = str[i] - '0';
		if(id){
			if(cur->edge[0]){
				cur = cur->edge[0];
				ret |= (1 << i);
			}else{
				cur = cur->edge[1];
			}
		}
		else {
			if(cur->edge[1]){
				cur = cur->edge[1];
				ret |= (1 << i);
			}else{
				cur = cur->edge[0];
			}
			//cout << ret << " " << id << endl;
		}
		

	}
	return ret;

}
int mnQuery(string& str)
{
	node* cur = root;
	int ret = 0;

	for(int i = (int)str.size() - 1 ; i >= 0; i--){
		
		int id = str[i] - '0';
		if(!id){
			if(cur->edge[0]){
				cur = cur->edge[0];
			}else{
				cur = cur->edge[1];
				ret |= (1 << i);
			}
		}
		else{
			if(cur->edge[1]){
				cur = cur->edge[1];
			}else{
				cur = cur->edge[0];
				ret |= (1 << i);
			}
			//cout << ret << " " << id << endl;
		}
	}
	return ret;	
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

int ara[MX];

string toBin(int num)
{
	string tmp = "";
	while(num)
	{
		tmp += ((num % 2) + '0');
		num /= 2;
	}
	while(tmp.size() < 31){
		tmp += '0';
	}
	//reverse(tmp.begin(), tmp.end());
	return tmp;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	int t, c =0 ;
	cin >> t;
	string zero = toBin(0);
	//cout << zero << endl;

	while(t--)
	{
		root = new node();
		int n;
		scanf("%d",&n);
		for(int i =0 ;i < n; i++)
			scanf("%d",&ara[i]);
		int mx = -1;
		int mn = INT_MAX;

		insert(zero);
		int cumXor = 0;
		for(int i = 0; i < n; i++)
		{
			cumXor ^= ara[i];
			string con = toBin(cumXor);
			mx = max(mx, mxQuery(con));//	cout << mxQuery(con) << endl;
			mn = min(mn, mnQuery(con));
			insert(con);
			/*cout << con << endl;*/
		}
		printf("Case %d: %d %d\n",++c, mx, mn);
		
		del(root);

	}
	return 0;
}