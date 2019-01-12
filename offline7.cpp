#include <bits/stdc++.h>
using namespace std;

class generator
{
    set < string > S;
    int cnt;
public:
    generator() { cnt = 0;}
    int get_val()
    {
        return cnt;
    }
    string next_string()
    {
        string str;
        do{
            str = "";
            for(int i = 0; i < 7; i++)
                str += (char)('a' + (rand() % 26));
        }while(S.find(str) != S.end());
        S.insert(str);
        cnt++;
        return str;
    }

};

int const INF = 1e9;

struct node
{
    string key;
    int val;
    node* next;
    node()
    {
        val = -INF;
    }
    node(string key,int val)
    {
        this->key = key;
        this->val = val;
        this->next = 0;
    }
};

class linked_list
{
    node* root ;
    int size;
    int search_hit;
public:
    linked_list()
    {
        root = 0;
        size = 0;
        search_hit = 0;
    }
    int get_size()
    {
        return size;
    }
    int get_search_hit()
    {
        return search_hit;
    }
    void insert(string key, int val)
    {
        node* here = new node(key,val);
        if(root)
        {
            here->next = root;
            root = here;
        }
        else {
            root = here;
        }
        size++;
    }

    void erase(string key)
    {
        node *prev,*now ;
        if(!root)
        {
            return;
        }
        if(root->key == key)
        {
            delete root;
            size--;
            root = 0;
            return ;
        }

        prev = root;
        while(prev->next and prev->next->key != key)
        {
            prev = prev->next;
        }
        if(prev->next){
            now = prev->next;
            prev->next = now->next;
            delete now;
            size--;
        }

    }

    int search(string key)
    {
        node* now = root;
        search_hit = 1;
        if(!now)
        {
            return -INF;
        }
        while(now->next and now->key != key)
            now = now->next, search_hit++;

        if(now and now->key == key)
            return now->val;
        else {
            return -INF;
        }
    }
    void des(node* now)
    {
        if(!now)
            return;
        if(now and now->next == 0 )
        {
            delete now;
            return ;
        }
        if(now and now->next)
        {
            des(now->next);
            delete now;
        }
        return ;
    }
    ~linked_list()
    {
        des(root);
    }
};

int hash1(string s,int n)
{
    int base = 37;
    int pos_val = 1;
    int val = 0;
    for(int i = 0; i < s.size(); i++)
    {
        val = (val * base + (s[i] - 'a' + 1)) % n;
    }
    return val;
}

int hash2(string s, int n)
{
    int base = 31;
    int pos_val = 1;
    int val = 0;
    for(int i = 0; i < s.size(); i++)
    {
        val = (val * base + (s[i] - 'a' + 1)) % n;
    }
    return val;
}

int aux_hash(string s,int n)
{
    int val = 0;

    for(int i =0 ; i < s.size(); i++)
        val = (val + (s[i] - 'a' + 1)) % n;
    return val;
}

class hash_table1
{
    linked_list *ara, *ara1;
    int n;
    int aux = 0;

public:
    hash_table1(int N)
    {
        n = N ;
        ara = new linked_list[N] ;
        ara1 = new linked_list[N] ;
    }
    int get_aux()
    {
        return aux;
    }
    void insert1(string key, int val)
    {
        int id = hash1(key,n);
        aux = ara[id].get_size();
        ara[id].insert(key,val);

    }

    void insert2(string key, int val)
    {
        int id = hash2(key,n);
        aux = ara1[id].get_size();
        ara1[id].insert(key,val);
    }

    int search1(string key)
    {
        int id = hash1(key,n);
        int val = ara[id].search(key);
        aux = ara[id].get_search_hit();
        return val;
    }

    int search2(string key)
    {
        int id = hash2(key,n);
        int val = ara1[id].search(key);
        aux = ara1[id].get_search_hit();
        return val;
    }

    void Delete1(string key)
    {
        int id = hash1(key,n);
        ara[id].erase(key);
        return;
    }
    void Delete2(string key)
    {
        int id = hash2(key,n);
        ara1[id].erase(key);
        return;
    }
};

class double_hash_table
{
    node *ara, *ara1;
    int n;
    int aux;
public:
    double_hash_table(int N)
    {
        this->n = N ;
        aux = 0;
        ara = new node[N] ;
        ara1 = new node[N] ;
    }

    int get_aux()
    {
        return aux;
    }
    void insert1(string key, int val)
    {
        //int id = hash1(key,n);
        long long int i = 0;
        while(i < n )
        {
            int idx = ( hash1(key,n) + i * aux_hash(key,n) ) % n;
            if(ara[idx].val < 0 )
            {
                ara[idx].key = key;
                ara[idx].val = val;
                break;
            }
            i++;
        }
        aux = i + 1;
    }

    void insert2(string key, int val)
    {
        //int id = hash1(key,n);
        long long int i = 0;
        while(i < n )
        {
            int idx = ( hash2(key,n) + i * aux_hash(key,n) ) % n;
            if(ara1[idx].val < 0 )
            {
                ara1[idx].key = key;
                ara1[idx].val = val;
                break;
            }
            i++;
        }
        aux = i + 1;
    }

    int search1(string key)
    {
        long long int i = 0;

        while(i < n)
        {
            int idx = ( hash1(key,n) + i * aux_hash(key,n) ) % n;
            if(ara[idx].val == -INF)
                return -INF;
            if(ara[idx].key == key)
                return ara[idx].val;
            i++;
            aux = i;
        }

        return -INF;
    }

    int search2(string key)
    {
        long long int i = 0;

        while(i < n)
        {
            int idx = ( hash2(key,n) + i * aux_hash(key,n) ) % n;
            if(ara1[idx].val == -INF)
                return -INF;
            if(ara1[idx].key == key)
                return ara1[idx].val;
            i++;
            aux = i;
        }

        return -INF;
    }

    void Delete1(string key)
    {
        int sval = search1(key);
        if(sval == -INF) return;

        long long int it = 0;
        while(it < n )
        {
            int idx = ( hash1(key,n) + it * aux_hash(key,n) ) % n;
            if(ara[idx].key == key)
            {

                ara[idx].val = -1;
                return;
            }
            it++;
            aux = it;
            
        }
    }

    void Delete2(string key)
    {
        int sval = search2(key);
        if(sval == -INF) return;

        long long int it = 0;
        while(it < n )
        {
            int idx = ( hash2(key,n) + it * aux_hash(key,n) ) % n;
            if(ara1[idx].key == key)
            {

                ara1[idx].val = -1;
                return;
            }
            it++;
            aux = it;
        }

    }
};



//class

class custom_hash_table
{
    node *ara, *ara1;
    int n;
    int aux ;
public:
    custom_hash_table(int N)
    {
        this->n = N ;
        aux = 0;
        ara = new node[N] ;
        ara1 = new node[N] ;
    }

    int get_aux()
    {
        return aux;
    }
    void insert1(string key, int val)
    {
        //int id = hash1(key,n);
        long long int i = 0;
        while(i < n )
        {
            int idx = ( hash1(key,n) + 31 * i * aux_hash(key,n) + 37 * i * i ) % n;
            if(ara[idx].val < 0 )
            {
                ara[idx].key = key;
                ara[idx].val = val;
                break;
            }
            i++;
        }
        aux = i + 1;
    }

    void insert2(string key, int val)
    {
        //int id = hash1(key,n);
        long long int i = 0;
        while(i < n )
        {
            int idx = ( hash2(key,n) + 31 * i * aux_hash(key,n) + 37 * i * i ) % n;
            if(ara1[idx].val < 0 )
            {
                ara1[idx].key = key;
                ara1[idx].val = val;
                break;
            }
            i++;
        }
        aux = i + 1;
    }

    int search1(string key)
    {
        long long int i = 0;

        while(i < n)
        {
            int idx = ( hash1(key,n) + 31 * i * aux_hash(key,n) + 37 * i * i ) % n;
            if(ara[idx].val == -INF)
                return -INF;
            if(ara[idx].key == key)
                return ara[idx].val;
            i++;
            aux = i + 1;
        }

        return -INF;
    }

    int search2(string key)
    {
        long long int i = 0;

        while(i < n)
        {
            int idx = ( hash2(key,n) + 31 * i * aux_hash(key,n) + 37 * i * i ) % n;
            if(ara1[idx].val == -INF)
                return -INF;
            if(ara1[idx].key == key)
                return ara1[idx].val;
            i++;
            aux = i + 1;
        }

        return -INF;
    }

    void Delete1(string key)
    {
        int sval = search1(key);
        if(sval == -INF) return;

        long long int it = 0;
        while(it < n )
        {
            int idx = ( hash1(key,n) + 31 * it * aux_hash(key,n) + 37 * it * it ) % n;
            if(ara[idx].key == key)
            {

                ara[idx].val = -1;
                return;
            }
            it++;
        }
    }

    void Delete2(string key)
    {
        int sval = search2(key);
        if(sval == -INF) return;

        long long int it = 0;
        while(it < n )
        {
            int idx = ( hash2(key,n) + 31 * it * aux_hash(key,n) + 37 * it* it ) % n;
            if(ara1[idx].key == key)
            {

                ara1[idx].val = -1;
                return;
            }
            it++;
        }

    }
};
typedef long long int ll;

int main()
{
    srand(time(0));
    int sz = 10000;
    hash_table1 hs(4*sz);
    double_hash_table hs1(10*sz);
    custom_hash_table hs2(10*sz);
    generator g1;

    vector < string > randString(sz);
    vector < int > value(sz);

    int col1 , col2 , col3;
    col1 = col2 = col3 = 0;
    long long int result[2][3][2];
    
    for(int i = 0; i < randString.size(); i++)
    {
        randString[i] = g1.next_string();
        value[i] = g1.get_val();
        hs.insert1(randString[i],value[i]);
        result[0][0][0] += hs.get_aux();
        hs1.insert1(randString[i],value[i]);
        result[0][1][0] += hs1.get_aux();

        hs2.insert1(randString[i],value[i]);
        result[0][2][0] += hs2.get_aux();
    }

    //cout << col1 << " " << col2 << " " << col3 << endl;
    
    for(int i = 0; i < randString.size(); i++)
    {
        //randString[i] = g1.next_string();
        //value[i] = g1.get_val();
        hs.insert2(randString[i],value[i]);
        result[1][0][0] += hs.get_aux();
        hs1.insert2(randString[i],value[i]);
        result[1][1][0] += hs1.get_aux();

        hs2.insert2(randString[i],value[i]);
        result[1][2][0] += hs2.get_aux();
    }
    //cout << col11 << " " << col21 << " " << col31 << endl;
    
    
    for(int i = 0; i < 1000; i++)
    {
        int id = rand() % sz;
        hs.search1(randString[id]);
        result[0][0][1] += hs.get_aux();
        hs1.search1(randString[id]);
        result[0][1][1] += hs1.get_aux();
        hs2.search1(randString[id]);
        result[0][2][1] += hs2.get_aux();
       ///* /*
        hs.search2(randString[id]);
        result[1][0][1] += hs.get_aux();
        
        hs1.search2(randString[id]);
        result[1][1][1] += hs1.get_aux();
        
        hs2.search2(randString[id]);
        result[1][2][1] += hs2.get_aux();
        //*/
        //*/
    }
    
    cout << "                                       Hash1               " << endl;
    
    cout << "Chaining Method : " << result[0][0][0] << " " << 1.0 * result[0][0][1] / 1000 << endl;
    cout << "Double Hashing Method : " << result[0][1][0] << " " << 1.0 * result[0][1][1] / 1000 << endl;
    cout << "custom hashing Method : " << result[0][2][0] << " " << 1.0 * result[0][2][1] / 1000 << endl;
    
    cout << "                                       Hash2               " << endl;
    
    cout << "Chaining Method : " << result[1][0][0] << " " << 1.0 * result[1][0][1] / 1000 << endl;
    cout << "Double Hashing Method : " << result[1][1][0] << " " << 1.0 * result[1][1][1] / 1000 << endl;
    cout << "custom hashing Method : " << result[1][2][0] << " " << 1.0 * result[1][2][1] / 1000 << endl;
    
    return 0;
}
