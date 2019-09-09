#include <bits/stdc++.h>
using namespace std;

int comp(string a,string b){
    string ab=a.append(b);
    string ba=b.append(a);
return ab.compare(ba) > 0 ? 1 :0;
     }

int main(){
int t;
cin >> t;


while(t--){
	vector<string> str;

	int r;
	cin >> r;
	string s="";
	while(r--){ 
		cin >> s;
		str.push_back(s);
		}
	sort(str.begin(),str.end(),comp);
        for(int i=0;i < str.size();i++) 
		cout << str[i];
		cout << '\n';
	}
return 0;
}
	
