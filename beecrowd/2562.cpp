#include <bits/stdc++.h>
using namespace std;
int cont;  
void dfs(vector<vector<int>>&g,  int v, int *vis)
{
	vis[v]=1; 
	for(auto x : g[v])
	{
		if(!vis[x] and x!=0)
		{
			cont++; 
			dfs(g, x, vis); 
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int numEspecies, numInfos, x, y, euSou; 
	while(cin >> numEspecies >> numInfos)
	{
		int vis[numEspecies+1]={0}; 
		vector<vector<int>>g(numEspecies+1);
		cont = 1;  
		for(int i=0; i<numInfos; ++i)
		{
			cin >> x >> y; 
			g[x].push_back(y); 
			g[y].push_back(x); 
		}
		cin >> euSou; 
		dfs(g, euSou, vis); 
		cout << cont << endl; 
	}
}
