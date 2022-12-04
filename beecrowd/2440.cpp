#include <bits/stdc++.h>
using namespace std; 
vector<vector<int>>g(100000+1); 
bool vis[100000+1]={false}; 
void dfs(int v)
{
	vis[v]=true;
	for(auto x : g[v])
	{
		if(!vis[x])
		{
			dfs(x); 
		}
	}
}
int main()
{
	int x, y; cin >> x >> y; 
	for(int i=0; i<y; ++i)
	{
		int p, k; cin >> p >> k; 
		g[p].push_back(k);
		g[k].push_back(p);  
	}
	int cont=0; 
	for(int i=1; i<=x; ++i)
	{
		if(!vis[i])
		{
			dfs(i); 
			cont++; 
		}
	}
	cout << cont << endl; 
}
