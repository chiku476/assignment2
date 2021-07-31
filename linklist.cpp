#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int data;
	Node *next;
};
Node* insert(Node* head,int value){
     Node* temp=head;
    
	Node* new_node = new Node();
	new_node->data=value;
	new_node->next=NULL;
	if(temp==NULL){
	    
     	head=new_node;
	}
	
	 else{
	      while(temp->next){
            temp=temp->next;
	          
	      }
	      temp->next=new_node;
	 }
	 return head;
}
void printList(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return;
}
Node * deletenode(Node *head ,Node * temp){
    
     Node * temp2=head;
     if(head==temp){
         head=temp->next;
          delete temp2;
     }
     else{
           while(temp2->next!=temp){
         temp2=temp2->next;
     }
     temp2->next=temp->next;
      delete temp;
     }
   return head;
}
	
	Node* deleteall(Node* head, int value){
	    Node* temp= head;
	   
	   while(head->data==value && head!=NULL){
	       temp=head;
	       head=head->next;
	       delete temp;
	   }
	    Node* temp2= head;
	     while(temp2 && temp2->next){
	         if(temp2->next->data==value){
	             temp=temp2->next;
	             temp2->next=temp->next;
	             temp2=temp2->next;
	             delete temp;
	         }
	         else{
	             temp2=temp2->next;
	         }
	     }
	    return head;
	}
	int displaySpace(Node** head_ref) {
    int count=0;
    Node* temp = *head_ref;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

Node * deleteconjecitive(Node* head, int value){
     Node* temp= head;
	   
	   while(head->data==value && head!=NULL){
	       temp=head;
	       head=head->next;
	       delete temp;
	       temp=head;
	       if(head){
	           head=head->next;
	           delete temp;
	       }
	   }
	    Node* temp2= head;
	     while(temp2 && temp2->next){
	         if(temp2->next->data==value){
	             temp=temp2->next;
	             temp2->next=temp->next;
	             delete temp;
	             temp=temp2;
	              temp2=temp2->next;
	             if(temp2){
	                 temp->next=temp2->next;
	                 delete temp2;
	                 temp2=temp->next;
	             }
	         }
	         else{
	             temp2=temp2->next;
	         }
	     }
	    return head;
    
}
	
int main()
{
	
	Node* head = NULL;

   int p[]={4,1,4,7,8,9,4};
   for(int i=0;i<7;i++){
      head= insert(head,p[i]);
   }
 
	cout<<"Created Linked list is: ";
	printList(head);
	cout<<"enter 1 for Adding a new node"<<endl;
    cout<<"enter 2 for Deleting a particular node (referenced by the location)"<<endl;
    cout<<"enter 3 for Delete all the nodes from the list which contain a particular data say a number 5"<<endl;

    cout<<"enter 4 for Display the total memory space occupied by the linked list"<<endl;
    cout<<"enter 5 for Delete all the nodes from the list which contain a particular data say a number 5 and the next subsequent node"<<endl;
     int i;
    cin>>i;
 
  switch(i){
      case 1: 
            int d;
            cin>>d;
            head= insert(head,d);
            cout<<"Linked list is after operation : ";
            printList(head);
            break;
     case 2:
           head= deletenode(head,head);
           cout<<"Linked list is after operation : ";
           printList(head);
          break;
     case 3: int da;
            cin>>da;
           head= deleteall(head,da);
           cout<<"Linked list is after operation : ";
           printList(head);
           break;
     case 4:    
            int space;
           space = displaySpace(&head) * (sizeof(Node));
           cout<<"The total memory space occupied is: "<<space<<endl;
           break;
     case 5:
             int x;
             cin>>x;
           head =deleteconjecitive(head,x);
           cout<<"Linked list is after operation : ";
          printList(head);
          break;
     default: 
           break;    
  }
	
	return 0;
}