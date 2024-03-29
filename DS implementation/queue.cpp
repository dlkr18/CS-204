#include<iostream>
typedef int type;

using namespace std;

struct ll
{
  type value;
  ll *next;
};

class Queue
{
public:
  ll *head=NULL;
  ll *tail=NULL;

  int size();
  bool isempty();
  void push(type x);
  void pop();
  type front();
  type back();

};

int Queue::size()
{
  if(tail==NULL && head==NULL) return 0;
  return (tail-head)/2+1;
}

bool Queue::isempty()
{
  if(tail==NULL && head==NULL) return true;
  return false;
}

void Queue::push(type x)
{
  ll *temp;
  temp = new ll;
  temp->value=x;
  temp->next=NULL;
  if(tail!=NULL) tail->next=temp;
  tail=temp;
  if(head==NULL) head=tail;
}

void Queue::pop()
{
  if(head==NULL)
  {
    cout<<"Error: Cannot pop while Queue is empty."<<endl;
    return;
  }
  ll *temp;
  temp=head;
  if(head==tail)
  {
    head=NULL;
    tail=NULL;
    delete temp;
    return;
  }
  head=head->next;
  delete temp;
  return;
}

type Queue::front()
{
  if(tail==NULL && head==NULL)
  {
    cout<<"Queue Empty, returned 0 by default."<<endl;
    return 0;
  }
  return head->value;
}

type Queue::back()
{
  if(tail==NULL && head==NULL)
  {
    cout<<"Queue Empty, returned 0 by default."<<endl;
    return 0;
  }
  return tail->value;
}

int main()
{
  type a;
  Queue S;
  cin>>a;
  S.push(a);
  S.push(a+1);
  cout<<S.size()<<endl;
  cout<<S.front()<<endl;
  S.pop();
  cout<<S.size()<<endl;
  cout<<S.front()<<endl;
  S.pop();
  cout<<S.size()<<endl;
  cout<<S.front()<<endl;
  S.pop();
  
}
