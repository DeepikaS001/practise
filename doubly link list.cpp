#include <iostream>

using namespace std;

struct node
{
   int data;
   node *prev;
   node *next;
};

class DLL
{
   private:
   node *head, *tail;
   public:
   DLL()
    {
       head=NULL;
       tail=NULL;
    }

   void createnode(int value)
   {
       node *temp=new node;
       temp->data=value;
       temp->next=NULL;
       if(head==NULL)
       {
           temp->prev=NULL;
           head=temp;
       }
       else
        {
           temp->prev=tail;
           tail->next=temp;
        }
        tail=temp;
   }

   void ins_beg(int value)
   {
       node *temp=new node;
       temp->data=value;
       temp->next=head;
       temp->prev=NULL;
       if(head==NULL)
       {
           tail=temp;
       }
       else
        {
           head->prev=temp;
           head=temp;
        }
   }

    void ins_end(int value)
   {
       node *temp=new node;
       temp->data=value;
       temp->prev=tail;
       temp->next=NULL;
       if(tail==NULL)
       {
           head=temp;
       }
       else
        {
           tail->next=temp;
           tail=temp;
        }
   }

   void ins_pos(int pos, int value)
   {
       node *temp=new node;
       node *p=new node;
       node *q=new node;
       temp->data=value;
       q=head;
       for(int i=0;i<pos;i++)
       {
           p=q;
           q=q->next;
       }
       p->next=temp;
       temp->prev=p;
       temp->next=q;
       q->prev=temp;
   }

   void del_beg()
   {
       node *temp;
       temp=head;
       head->next->prev=NULL;
       head=head->next;
       delete temp;
   }


  void del_pos(int pos)
  {
      node *p=new node;
      node *q=new node;
      q=head;
      for(int i=1;i<pos;i++)
      {
          p=q;
          q=q->next;
      }
      p->next=q->next;
      q->next->prev=p;
      delete q;
  }

  void del_end()
  {
      node *p, *q;
      q=head;
      while(q->next!=NULL)
      {
          p=q;
          q=q->next;
      }
      tail=p;
      p->next=NULL;
      delete q;
  }

  //display
  void for_trav()
  {
      cout<<endl;
      node *temp;
      temp=head;
      cout<<"Doubly link list on forward traversal: "<<endl;
      while(temp!=NULL)
      {
          cout<<temp->data<<endl;
          temp=temp->next;
      }
  }

  void back_trav()
  {
      cout<<endl;
      node *temp;
      temp=tail;
      cout<<"Doubly link list on traversing backward: "<<endl;
      while(temp!=NULL)
      {
          cout<<temp->data<<endl;
          temp=temp->prev;
      }
  }
};

  int main()
  {
      DLL l;
      l.createnode(2);
      l.createnode(5);
      l.createnode(4);
      cout<<"Created doubly link list is: "<<endl;
      l.for_trav();
      l.back_trav();
      l.ins_beg(1);
      l.ins_end(5);
      l.ins_pos(2,4);
      cout<<endl;
      cout<<"Doubly link list after insertion: "<<endl;
      l.for_trav();
      l.del_beg();
      l.del_end();
      l.del_pos(5);
      cout<<endl;
      cout<<"Doubly link list after deletion: "<<endl;
      l.for_trav();
      return 0;
  }
