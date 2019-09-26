#include<bits/stdc++.h>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int part(int A[], int l, int r, int x)
{
        int i;
    for (i=l; i<r; i++)
        if (A[i] == x)
           break;
    swap(&A[i], &A[r]);
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (A[j] <= x)
        {
            swap(&A[i], &A[j]);
            i++;
        }
    }
    swap(&A[i], &A[r]);
    return i;
}

int med(int A[], int n)
{
    sort(A, A+n);
    return A[n/2];
}

int select(int A[], int l, int r, int k)
{
    if (k > 0 && k<= r - l + 1)
    {
        int n = r-l+1;
        int i, median[(n+4)/5];
        for (i=0; i<n/5; i++)
            median[i] = med(A+l+i*5, 5);
        if (i*5 < n)
        {
            median[i] = med(A+l+i*5, n%5);
            i++;
        }
        int y= (i == 1)? median[i-1]:
                                 select(median, 0, i-1, i/2);
        int pos = part(A, l, r, y);
        if (pos-l == k-1)
            return A[pos];
        if (pos-l > k-1)
            return select(A, l, pos-1, k);
        return select(A, pos+1, r, k-pos+l-1);
    }
    return INT_MAX;
}


int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i=0;i<n;i++){
            int x,y;
            cin >> x;
            cin >> y;
            A[i]=x*x+y*y;
        }
        int k=(n+1)/2;
       int h=select(A,0,n-1,k);
        cout << sqrt(h) <<'\n';
    }
    return 0;
}
