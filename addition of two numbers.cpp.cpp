#include <iostream>

using namespace std;

void reversestr(string& str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
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

int main()
{int t,i;
cin >> t;
    string a[t],b[t];
    for(i=0;i<t;i++){

    cin >> a[i] >> b[i];}
    for(i=0;i<t;i++){
	
    cout << add(a[i],b[i]) << "\n";}
    return 0;
}
