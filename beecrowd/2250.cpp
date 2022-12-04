#include <bits/stdc++.h>
using namespace std; 
#define f first
#define s second
#define pi 3.14159
#define pb push_back
#define ll long long
#define ii pair<int,int>
#define p push
#define icN(a, b) for(int i=a; i<b; ++i)
#define idN(a, b) for(int i=a; i>=b; --i)
#define c(a) cin >> a; 
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL)

struct UF{ 
    vector<int>pai,r;
    UF(int n){
        pai.resize(n);
        r.resize(n);
        for(int i=1;i<n;i++){
            pai[i]=i;
            r[i]=1;            
        }
    }
    UF(){}
    int acha(int x){
        if(pai[x]==x) 
            return x;
        return pai[x]=acha(pai[x]);
    }
    void unir(int x, int y){
        x=acha(x);
        y=acha(y);
        if(r[x]>r[y]){
            pai[y]=x;
            r[x]+=r[y];
        }
        else{
            pai[x]=y;
            r[y]+=r[x];
        }
    }
    bool mesmoConjunto(int x,int y){
        return acha(x)==acha(y);
    }
};

void solve(int a, int b)
{
    vector<pair<int, ii>>vec; 
    int x, y, peso; 
    set<int>idk_father; 
    for(int i=0; i<b; ++i)
    {
        cin >> x >> y >> peso;
        vec.pb({peso, {x, y}});  
    }
    sort(vec.begin(), vec.end()); 
    UF campus(a+1);
    peso=0;  
    for(int i=0; i<b; ++i)
    {
        int pesoAtual = vec[i].f; 
        int ligOne = vec[i].s.f; 
        int ligTwo = vec[i].s.s; 
        if(!campus.mesmoConjunto(ligOne, ligTwo))
        {
            campus.unir(ligOne, ligTwo); 
            peso+=pesoAtual; 
        }
    }
    for(int i=0; i<a; ++i) idk_father.insert(campus.acha(i+1));
    if(idk_father.size()==1) cout << peso; 
    else cout << "impossivel";  
}

int main()
{
    _; 
    int a, b; 
    while(cin >> a >> b)
    {
        solve(a, b); 
        cout << endl; 
    }
}
