#include <bits/stdc++.h>
using namespace std; 
int main()
{
	int x, y, casas, j=0; 
	while(cin >> casas, casas!=0)
	{
		cout << "Cidade# "<< j++ <<":"<< endl; 
		map<int, int>consumo;
		double sum1=0, sum2=0; 
		for(int i=0; i<casas; ++i) 
		{ 
			cin >> x >> y;
			sum1+=x; 
			sum2+=y; 
			map<int, int>::iterator it; 
			it = consumo.find(floor(y/x)); 
			if(it==consumo.end()) consumo.insert(pair<int, int> (floor(y/x), x)); 
			else it->second+=x; 
		}
		map<int, int>::iterator it=consumo.begin();
		cout << it->second << '-' << it->first; 
		it++; 
		for(; it!=consumo.end(); ++it)
		{
			cout << ' ' << it->second << '-' << it->first; 
		} 
		cout << endl; 
		double media; 
        int fp = (int) (modf ((double)sum2/sum1, &media) * 100);

        if(fp < 10) printf("Consumo medio: %d.0%d m3.", (int)media, (int)fp);
        else printf("Consumo medio: %d.%d m3.", (int)media, (int)fp);
        cout << endl; 
	    cout << endl; 
	}
}
