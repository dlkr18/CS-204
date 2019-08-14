#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int n,j;
	cin >> n;
        stack <char> st;
   for(j=n;j>0;j--)
	{
         int i;
	 string s;
         cin >> s;
         int l=s.length();
        if(l%2==1) 
		cout << "NO\n"; 
        else 
            {st.push(s[0]);
             for(i=1;i<l;i++)
			{if(st.empty()) st.push(s[i]); 
			else  if(s[i]==')' && st.top()=='(') {st.pop();}
			else  if(s[i]=='}' && st.top()=='{') {st.pop();}        
	  		else  if(s[i]==']' && st.top()=='[') {st.pop();}
			else  if(s[i]=='>' && st.top()=='<') {st.pop();}
			else  if(s[i]=='|' && st.top()=='|') {st.pop();}
			else st.push(s[i]);
			}
		if(st.empty()) cout << "YES" << "\n";
		else cout << "NO" << "\n" ;
	     }
	
        }
return 0;
}
