#include <iostream>

using namespace std;

void reversestr(string& str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

bool large(string a,string b){
  int n1=a.length(),n2=b.length();
  if(n1>n2)return true;
  if(n1<n2)return false;
  for(int i=0;i<n1;i++){
    if (a[i]>b[i])return true;
    if (a[i]<b[i])return false;
  }
  return false;
}

string subtract(string a,string b){
    int n1=a.length(),n2=b.length();

    int c=0,i,sub;
    string r="";

        reversestr(a);
        reversestr(b);
        for(i=0;i<n2;i++){
          sub=((a[i]-'0')-(b[i]-'0')-c);
          if(sub<0){
            sub=sub+10;
            c=1;
          }
            else c=0;
            r.push_back(sub+'0');
        }
        for(i=n2;i<n1;i++){
            sub=((a[i]-'0')-c);
            if(sub<0){
               sub=sub+10;
            c=1;
            }
            else c=0;
            r.push_back(sub+'0');
        }
    reversestr(r);

  return r;
}

string add(string a,string b){
 if(a.length()>b.length())
    swap(a,b);
 string r="";
 int n1=a.length(),n2=b.length();
 int d=n2-n1;
 int c=0,i,sum;
 for(int i=n1-1;i>=0;i--){
     sum=((a[i]-'0')+(b[i+d]-'0')+c);
    r.push_back(sum%10+'0');
    c=sum/10;
 }
 for( i=n2-n1-1;i>=0;i--){
    sum=((b[i]-'0')+c);
    r.push_back(sum%10+'0');
    c=sum/10;
 }
 if(c)
    r.push_back(c+'0');

 reversestr(r);
 return r;
}



string quo(string a,string b){
    string var="";
    while(large(a,b)){
        a=subtract(a,b);var=add(var,"1");
    }

return var;
}

string rem(string a,string b){

    while(large(a,b)){
        a=subtract(a,b);
    }

return a;
}

int main()
{
int t,i;
cin >> t;
string a[t],b[t];
for(i=0;i<t;i++){
    cin >> a[i] >> b[i];
}
for(i=0;i<t;i++){
    cout << quo(a[i],b[i]);cout << "\n";cout << rem(a[i],b[i]);cout << "\n";
}
    return 0;
}
