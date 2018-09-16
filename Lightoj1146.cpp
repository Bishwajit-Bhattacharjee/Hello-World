#include <bits/stdc++.h>
using namespace std;
const int DIM = 3;
struct point
{
    double co[DIM] ;

    point operator+(const point &rhs )const
    {
        point tmp ;
        for(int i = 0; i < DIM; i++)
            tmp.co[i] = this->co[i] + rhs.co[i];
        return tmp ;
    }
    double dist(const point &rhs)const
    {
        double dis = 0 ;
        for(int i = 0; i < DIM ; i++)
            dis += (co[i] - rhs.co[i])*(co[i] - rhs.co[i] );

        return dis ;
    }
    point operator*(double n)
    {
        point tmp ;
        for(int i = 0 ; i < DIM ; i++){
            tmp.co[i] = co[i] * n ;
        }
        return tmp ;
    }
    point new_point(point p1, double t)
    {
        point tmp ;
        tmp = (*this) * (1-t) + p1 * t ;
        return tmp;
    }

};
point ara[3] ;

double min_parameter()
{
    double lo = 0 , hi = 1;
    int step = 100 ;
    while(step--)
    {
        double mid1 , mid2;
        mid1 = lo + (hi - lo ) / 3 ;
        mid2 = lo + 2 * (hi-lo)/ 3 ;
        point p1, p2 ;
        p1 = ara[0].new_point(ara[1], mid1);
        p2 = ara[0].new_point(ara[1], mid2);
        double  dist1 = ara[2].dist(p1);

//        p1 = ara[0].new_point(ara[1], mid2);
//        p2 = ara[2].new_point(ara[3], mid2);
        double dist2 = ara[2].dist(p2);
        if(dist1 > dist2){
            lo = mid1 ;
        }
        else{
            hi = mid2 ;
        }
    }
    return lo ;
}

int main()
{
    int t , c= 0;
    cin >> t;
    while(t--)
    {

        for(int i =0 ; i < 3; i++){
            for(int j =0 ; j < 3; j++){
                scanf("%lf",&ara[i].co[j]);
            }
        }
        double pr = min_parameter() ;
        point p1, p2 ;
        p1 = ara[0].new_point(ara[1], pr);
       // p2 = ara[2].new_point(ara[3], pr);
        double dist1 = ara[2].dist(p1);
        printf("Case %d: %.10f\n",++c ,sqrt(dist1));
    }
    return 0;
}
