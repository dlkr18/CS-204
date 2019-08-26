#include <bits/stdc++.h>

using namespace std;

int stoi(string s)
{
	int l=s.length();
	int b=0;
	for(int p=0;p<l;p++)
	{
		int w=s[p]-48;
		b=10*b+w;
	}
		return b;
}

int prec(char m){
    if(m=='^')return 3;
    else if(m=='*'||m=='/')return 2;
    else if(m=='+'||m=='-')return 1;
    else return -1;
}


vector <string> in_to_pos(vector<string> exm){
    stack<string> g;
    g.push("empty");
    vector <string> opd;
    for(int i=0;i<exm.size();i++){
        if(exm[i]!="(" && exm[i]!=")" && exm[i]!='+' && exm[i]!='-' && exm[i]!='*' && exm[i]!='/' && exm!='^'){
            opd.push_back(exm[i]);
        }
        else if(exm[i]=='(') g.push("(");
        else if(exm[i]==')'){
            while(g.top()!="empty"&& g.top()!="("){
              string s=g.pop();
              opd.push_back(s);
            }
            if(g.top()=="("){
                g.pop();
            }
        }
        else{
            while(g.top()!="empty" && prec(exm[i])<=prec(g.top()) ){
                if(prec(exm[i])==3&&prec(g.top())==3)break;
                string s=g.pop();
                opd.push_back(s);
            }
            g.push(exp[i]);
        }
    }
    while(g.top()!="empty"){
        string s=g.pop();
        opd.push_back(s);
    }
    return opd;
}

struct tree{
  string value;
  tree *left,*right;
};

bool opt(char c){
 if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')return 1;
 return 0;
}


tree* newnode(string value){
    tree* temp= new tree;
    temp->left=temp->right=NULL;
    temp->value=val;
    return temp;
};



tree* newtree(vector<string> v){
    stack<tree*> st;
    tree *t,*t1,*t2;
    for(int i=0;i<v.size();i++){
        if(opt(v[i])==0){
          t=newnode(v[i]);
          st.push(t);
        }
        else{
            t=newnode(v[i]);
            t1=st.pop();

            t2=st.pop();
            t->right=t1;
            t->left=t2;
            st.push();
        }
    }
t=st.pop();
return t;
}


int eval(tree* t){
   if(!t)return 0;

   if(!t->left && !t->right)return stoi(t->value);
   int lval=eval(t->left);
    int rval=eval(t->right);
    if(t->value=='+')return lval+rval;
    if(t->value=='-')return lval-rval;
    if(t->value=='*')return lval*rval;
    if(t->value=='/')return lval/rval;
    else return pow(lval,rval);

}


int main(){
    unsigned int t;
    cin >>t;
    while(t--){
        int flag=1;
        string s;
        char prev='0';
        vector <string> n,p;
        cin >>s;
        string grp;
        for(int i=0;i<s.length();i++){
           if(s[i]=='(' || s[i]==')' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]== '^'){
                grp+=s[i];
                if(s[i]=='-' && prev=='('){
                    n.push_back("0");
                   }
                prev=s[i];
                n.push_back(grp);
           }
           else{
             while(s[i]!='(' && s[i]!=')' && s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/' && s[i]!='^' && i<s.length() ){
                if(s[i]>='0' && s[i]<='9'){
                    grp+=s[i];i++;
                }
                else{
                    flag=0;break;
                }
             }
              i--;
              n.push_back(grp);
           }
           if(flag==0)break;



    }
    if(flag){
       p=in_to_pos(v);
       tree *t=newtree(p);
       cout << eval(t);
    }
    else{
        cout << "cant be evaluated";
    }

  }
  return 0;
}
