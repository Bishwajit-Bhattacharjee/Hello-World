#include <bits/stdc++.h>
using namespace std ;
int const MX = 55;
typedef unsigned int ll;
ll mod ;
ll p , q ;
struct  matrix
{
 
    ll ara[MX][MX] ;
    ll size;
    matrix(ll sz){
    	this->size = sz;

    	for(int i = 0 ; i < size ; i++){
    	    for(int j = 0 ; j < size ; j++)
    	        ara[i][j] = (i == j ) ;
    	
    	}
    }
    void setter() {
       // cout << -q << endl ;
        ara[0][0] = p ,  ara[0][1] = -q ;
        ara[1][0] = 1 ;
        ara[1][1] = 0;
 
    }
 
   /* void init(int number) {
        for(int i = 0 ; i< MX ; i++)
            for(int j = 0; j < MX ; j++)
                ara[i][j] = number ;
    }*/
    void print()
    {
        for(int i = 0 ; i < size; i++) {
            for(int j = 0; j < size ; j++) {
               cout << ara[i][j] << ' ' ; // printf("%llu ", ara[i][j] ) ;
            }
            cout << endl ;
        }
    }
    void identity()
    {
        for(int i = 0 ; i < MX ; i++){
            for(int j = 0 ; j < MX ; j++)
                ara[i][j] = (i == j ) ;
 
        }
    }
 
 
};
 
matrix mul(matrix a, matrix b )
{
 
        assert(a.size == b.size) ;
        matrix tmp(a.size) ;
        for(int i = 0 ; i < a.size ; i++){
            for(int j = 0 ; j < b.size; j++){
                tmp.ara[i][j] = 0 ;
                for(int k = 0 ; k < a.size; k++){
                    tmp.ara[i][j] += a.ara[i][k]  * b.ara[k][j];
                }
            }
        }
        return tmp ;
 
 
}
 
 
 
matrix bigmod(matrix mat , long long pow )
{
    matrix ans(mat.size) ;
    //ans.identity() ;
    matrix tmp(mat.size) ;
    //tmp.identity() ;
    if(pow == 0 )
        return ans ;
 
    for(ll i = 0 ; (1LL << i ) <= pow ; i++ ) {
 
        if(i == 0)
            tmp = mat ;// cout << ans.ara[0][0] << endl ;
        else
            tmp = mul(tmp , tmp ) ;
 
        if((1LL << i ) & pow )
            ans = mul( ans , tmp )  ;
    }
 
    return ans ;
}

ll nCr[54][54];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	for(int i =0 ; i < 54; i++)
	{
		if(!i)
			nCr[0][i] = 1;
		else 
			nCr[0][i] = 0;
	}

	for(int i = 1; i < 54; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			if(!j or j == i)
			{
				nCr[i][j] = 1;
				continue;
			}
			nCr[i][j] = nCr[i-1][j] + nCr[i-1][j-1];
		}
	}
	/*for(int i = 0; i < 54; i++)
	{
		for(int j = 0; j <= i;j++)
			cout << nCr[i][j] << endl;
	}*/

    int t , c = 0;
    cin >> t ;
    while(t--){
		long long n;
		int k;
		scanf("%lld %d",&n,&k) ;
        matrix exp(k+2);
        exp.ara[0][0] = 1;

        for(int i = 0; i < k + 1; i++)
        {
            exp.ara[0][i+1] = nCr[k][k-i];
        }
        
        for(int i = 1; i < k + 2;i++){
            for(int j = 0; j < k + 2; j++){
                if(j < i){
                    exp.ara[i][j] = 0;
                }else{
                    int up = k - i + 1;
                    int off = j - i;
                    int lo = up - off;
                    exp.ara[i][j] = nCr[up][lo];
                }
            }   
        }
        exp = bigmod(exp,n-1);
        ll ans = 0;
        for(int i = 0; i < k + 2; i++)
            ans += exp.ara[0][i] ;
        printf("Case %d: %u\n",++c,ans );
   	}
   	return 0 ;
}