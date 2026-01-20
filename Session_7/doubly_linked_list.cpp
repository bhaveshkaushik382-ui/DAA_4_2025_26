#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node(){
        if(this->next!=NULL){
            delete next;
            next = NULL;
        }
    }
};
void athead(Node* &head,Node* &tail,int d){
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void attail(Node* &head,Node* &tail,int d){
    if(tail == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp->prev = tail;
        tail->next  = temp;
        tail = temp;
    }
}
void atinsert(Node* &head, Node* &tail,int d ,int pos){
    if(pos == 1){
        athead(head,tail,d);
        return;
    }
    else{
        Node* temp = head;
        int cnt = 1 ;
        while(cnt<pos - 1){
            temp = temp->next;
            cnt++;
        }
        if(temp->next ==NULL){
            attail(head,tail,d);
            return;
        }
        Node* insertat = new Node(d);
        temp->next->prev = insertat;
        insertat->next  = temp->next;
        temp->next  = insertat;
        insertat->prev = temp;
    }
}
void delate(Node* &head, Node* &tail,int pos){
    if(pos  == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next  = NULL;
        delete temp;
    }
    else{
        Node* temp= NULL;
        Node* curr= head;
        int cnt = 1;
        while(cnt<pos){
            temp = curr;
            curr = curr->next;
            cnt++;
        }
        temp->next  = curr->next;
        curr->prev = NULL;
        curr->next = NULL;
        delete curr;
    }
}

void print(Node* &head){
    if(head == NULL){
        cout<<"L.L IS EMPTY"<<endl;
    }
    else{
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}
int main(){
    
    Node* head  = NULL;
    Node* tail = NULL;
    
    athead(head,tail,25);
    attail(head,tail,35);
    attail(head,tail,45);
    attail(head,tail,55);
    attail(head,tail,65);
    print(head);
    atinsert(head,tail,40,3);
    print(head);
    delate(head,tail,1);
    print(head);
    delate(head,tail,3);
    print(head);
    
    
    
}