#include <iostream>

using namespace std;

void reversestr(string& a)
{
    int n = a.length();
    for (int i = 0; i < n / 2; i++)
        swap(a[i], a[n - i - 1]);
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



int main()
{int t,i;
cin >> t;
    string a[t],b[t];
    for(i=0;i<t;i++){
        cin >> a[i] >> b[i];
    }
    for(i=0;i<t;i++){
        if(large(a[i],b[i]))
        cout << subtract(a[i],b[i]) << "\n";
      else{
        swap(a[i],b[i]);
        cout << "-" << subtract(a[i],b[i]) << "\n";
      }
    }
    return 0;
}
