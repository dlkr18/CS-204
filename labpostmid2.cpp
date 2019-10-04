#include<bits/stdc++.h>
using namespace std;

struct point{
	int x,y;
};

point p0;

point btop(stack<point> &s){
	point p=s.top();
	s.pop();
	point x=s.top();
	s.push(p);
	return x;
}


void swap_p(point &m,point &n){
	point temp=m;
	m=n;
	n=temp;
	}
	
int dist(point p1,point p2){
	return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}	

int orient(point p,point q,point r){
	int val=(q.y -p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
	if(val==0) return 0;
	return (val > 0)?1:2;
}


int comp(const void *vp1,const void *vp2){
	point *p1=(point *)vp1;
	point *p2=(point *)vp2;
	int d=orient(p0,*p1,*p2);
	if(d==0)
		return (dist(p0,*p2)>=dist(p0,*p1))?-1:1;
		
	return (d==2)?-1:1;	
}	
	
	

void convexhull(point p[],int t){
	int ymin=p[0].y,min=0;
	
	
	for(int i=1;i<t;i++){
		int y=p[i].y;
		if((y<ymin) || (ymin==y&& p[i].x<p[min].x))
					{ymin=p[i].y;min=i;}			
		}
	swap_p(p[0],p[min]);
	p0=p[0];
	qsort(&p[1],t-1,sizeof(point),comp);
	
	int m=1;
	for(int j=1;j<t;j++){
		while(j<t-1 && orient(p0,p[j],p[j+1])==0)
			j++;
			p[m]=p[j];
			m++;
	} 
	
	if(m<3) return ;
	
	stack<point> s;
	s.push(p[0]);
	s.push(p[1]);
	s.push(p[2]);
	
	for(int k=3;k<m;k++){
		while(orient(btop(s),s.top(),p[k])!=2)
			s.pop();
		s.push(p[k]);	
	}
	
	
	cout << s.size() << '\n';
		
	while(!s.empty()){
		point p=s.top();
		cout << p.x << '\t' <<  p.y <<'\n' ;
		s.pop();
	}	
}

int main(){
	int t,a,b;
	cin >> t;
	point p[t];
	for(int i=0;i<t;i++){
		cin >> a;
		cin >>b;
		p[i].x=a;p[i].y=b;
	      }
	 convexhull(p,t);     
return 0;
}
	
