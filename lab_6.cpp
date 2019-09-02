#include <bits/stdc++.h>
using namespace std;

struct node{
	long long int id;
	int am;
	};

int main(){
	int q;
	cin >>q;
	vector<node> r;
	vector<int> p;
	int y;
	long long int x;
	int t;
	cin >> t;
	if(t==2){cout << "no data available" << '\n';}
	if(t==1){
		cin>>x;
		struct node *temp=new(node);
				temp->id=x;
				cin >>y;
				temp->am=y;
				r.push_back(*temp);
				p.push_back(x);}
	int s=q-1;
	while(s--){
		
		cin >> t;
		
		if(t==1){
			cin >>x;
			if(find(p.begin(),p.end(),x)!=p.end()){ 
					cin >> y;
					for(auto i=r.begin();i!=r.end();i++){
						if(i->id==x) i->am+=y;
							}
					}
			else{
				struct node *temp=new(node);
				temp->id=x;
				cin >>y;
				temp->am=y;
				r.push_back(*temp);
				p.push_back(x);
			    }
			}
		 if(t==2){
			long long int a;
			int b;
			a=r.begin()->id;b=r.begin()->am;
			for(auto i=r.begin();i!=r.end();i++){
					if(i->am>b)
						{ a=i->id;
						b=i->am;}	
					}
			
			cout <<a << "\n";
			}
		
		}
return 0;
}





















 
