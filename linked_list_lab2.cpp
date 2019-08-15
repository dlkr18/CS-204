#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct point{
 int a;int b;
};
struct node{
 point p;
 node *next;
}*head;

class linkedlist{

 public:
	linkedlist(){
		head = NULL;
		}

 void AddFirst(int x,int y){
     node *temp=new node();

     (temp->p).a=x;
     (temp->p).b=y;

 if(head==NULL)
  {
  head=temp;temp->next=NULL;}
 else{
   temp->next=head;
   head=temp;
   }
}



void DelFirst(){
      if(head==NULL) cout << -1;
 	else{
           node *temp=new node();
           temp=head;
           head=temp->next;
           free (temp);}
}

 void search(int x,int y){
	int c=0;
	node *temp=new node();
        temp=head;
	if(head==NULL) cout << "False";
	else{
	    while(temp!=NULL){
             if((temp->p).a==x && (temp->p).b==y) c++;
		temp=temp->next;}
		if(c>0) cout << "True";
		   else cout << "False";
            }


}


 void Del(int x,int y){

if(sr(x,y)>=1){

           if(head==NULL) cout << -1;
       else{
	       node *temp=new node();
	       node *prev=new node();
     	  	temp=head;prev=NULL;
		while((temp->p).a!=x || (temp->p).b!=y){prev=temp;temp=temp->next;}
 		if(prev!=NULL){prev->next=temp->next;free(temp); }
              else{
			   DelFirst();}
              if(temp==NULL){cout << -1;
			  }

        }

  }
else cout << -1;
 }


 void Search(float d){
     int c=0;
   if(head==NULL) cout << -1;
   else{
      node *temp=new node();
      temp=head;
          while(temp!=NULL){
		  float m=(temp->p).a,n=(temp->p).b;
		  if(m*m+n*n<=d*d){c++;}
   								temp=temp->next;}

   					if(c>0)		cout << c;
   					   else cout << -1;
   							}
							  }


 void length (){
 	int c=0;
 	node *temp=new node();
 	temp=head ;
 	if(head==NULL){cout << 0;
	 }
 	while(temp!=NULL){
 		c++;
 		temp=temp->next;
 	 }
 cout << c;
 }

 int sr (int x,int y){
   int c=0;
	node *temp=new node();
        temp=head;
	if(head==NULL) return 0;
	else{
	    while(temp!=NULL){
             if((temp->p).a==x && (temp->p).b==y) c++;
		temp=temp->next;}
		return c;
            }



 }







};

int main(){

	linkedlist ll;
	head=NULL;

   int t,i;
	int x,y,r;
	float d;
  cin >> t;

		cin >> r;
		for(;;){
			switch(r){
				case 1:
				cin >> x >> y;
				ll.AddFirst (x,y);
				break;
				case 2:ll.DelFirst ();break;
				case 3:cin >> x >> y;ll.Del (x,y);break;
				case 4:cin >> d; ll.Search (d);break;
				case 5:cin >> x >> y;ll.search (x,y);break;
				case 6:ll.length ();break;
			}
			cin >> r;}





return 0;
}
