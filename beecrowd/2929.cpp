#include <bits/stdc++.h>
using namespace std;
stack<int>minhaPilha;
int main(){
    int casos, x;
    string oqFazer;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> casos;
    for(int i = 0; i < casos; ++i)
	{
        cin >> oqFazer;
        if(oqFazer == "PUSH")
		{
            cin >> x;
            if(minhaPilha.empty()) minhaPilha.push(x);
			else 
			{
				if(minhaPilha.top()<x) minhaPilha.push(minhaPilha.top()); 
				else minhaPilha.push(x); 
			}
        }
		else if(oqFazer == "POP")
		{
            if(minhaPilha.empty()) cout << "EMPTY" << endl;
			else minhaPilha.pop();
        }
		else
		{
            if(minhaPilha.empty()) cout << "EMPTY" << endl;
			else cout << minhaPilha.top() << endl;
        }
    }
}