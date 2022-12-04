#include <bits/stdc++.h>
using namespace std; 
int main()
{
	int casos; cin >> casos; 
	for(int h=0; h<casos; ++h)
	{
		int x, y; cin >> x >> y; 
		vector<vector<int>>g(102);
		for(int i=0; i<y; ++i)
		{
			int k; cin >> k; 
			int casa = k%x; 
			g[casa].push_back(k); 
		}
		for(int i=0; i<x; ++i)
		{
			cout << i <<" ->";
			for(int j=0; j<g[i].size(); ++j)
			{
				cout << ' ' << g[i][j] << " ->";

			} 
			cout << " \\"; 
			cout << endl; 
		}
		if(h!=(casos-1))cout << endl; 
	}
}
