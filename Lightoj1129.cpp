#include <bits/stdc++.h>
using namespace std;

int const CNT = 52;
struct node{
	int hasEnd;
	node* edge[CNT];

	node(){
		hasEnd = 0;
		for(int i = 0 ; i < CNT; i++)
			edge[i] = 0;
	}
};

int Map(char ch)
{
	if(ch >= 'a' and ch <= 'z')
		return 26 + (ch - 'a');
	return ch - 'A';
}

void modify(string& str)
{
	if(str.size() == 1) return;
	priority_queue < char > pq;
	for(int i = 1; i + 1 < str.size(); i++){
		pq.push(str[i]);
	}
	for(int i = 1; i + 1 < str.size(); i++){
		str[i] = pq.top();
		pq.pop();
	}

}
node* root ;

void insert(string &str)
{
	node* cur = root;
	
	for(int i = 0; i < str.size(); i++)
	{
		int id = Map(str[i]);
		if(cur->edge[id] == 0){
			cur->edge[id] = new node();
		}
		cur = cur->edge[id] ;
		
	}
	cur->hasEnd++;

}

int query(string &str){
	node* cur = root;

	for(int i = 0 ; i < str.size(); i++){
		int id = Map(str[i]);
		if(cur->edge[id] == 0) return 0;
		cur = cur->edge[id];
	}
	return cur->hasEnd;
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
//char dick[110], buf[4], input[(int)1e5 + 100];

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
		root = new node();
		int n;
		scanf("%d",&n);
		//cin >> n;

		for(int i = 0; i < n;i++){
			string s;
				
			modify(s);
			//cout << s << endl;
			insert(s);
			
		}
		printf("Case %d:\n",++c);

		//cout << "Case " << ++c << ":" << '\n';
	 	int m;
	 	cin >> m;
	 	//cout << m << endl;
	 	cin.ignore();

	 	while(m--){
	 		int ans = 1;
	 		string input;
	 		getline(cin,input);
	 		//cout << input << endl;
	 		stringstream srm(input);
	 		string tmp;
	 		while(srm >> tmp){
	 			//cout << tmp << endl;
	 			modify(tmp);
	 			//cout << query(tmp) << endl;

	 			ans *= query(tmp);
	 		}
	 		printf("%d\n",ans); //;
	 	}
		//printf("Case %d: %d\n",++c,ans);
		del(root);
	}
	return 0;
}