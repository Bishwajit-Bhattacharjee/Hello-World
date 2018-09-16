#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, c = 0;
	vector < int > divi;
	cin >> t;
	while(t--)
	{
		int p, l;
		scanf("%d %d",&p,&l) ;
		int newP = p - l;
		divi.clear();

		for(int i = 1; 1LL*i* i <= newP; i++)
		{
			if(newP % i == 0){
				if(i > l )
					divi.push_back(i);

				if(i*1LL*i != newP){
					if(newP / i > l )
						divi.push_back(newP/i);
				}
			}
			
		}
		sort(divi.begin(), divi.end());

		if(divi.size() == 0){
			printf("Case %d: impossible\n",++c );
		}
		else {
			printf("Case %d:",++c );
			for(int i = 0; i < divi.size(); i++){
				printf(" %d",divi[i]);
			}
			printf("\n");
		}
	}
	return 0;

}