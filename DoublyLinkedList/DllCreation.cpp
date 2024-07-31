#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Node {

    public:
        int data;
        Node* next;
        Node* back;

    public:
        Node(int data1)
        {
            data = data1;
            next = NULL;
            back = NULL;

        }

        Node( int data1 , Node* next1 , Node* prev1)
        {
            data = data1;
            next = next1;
            back = prev1;
        }

};

Node* convertArrToDll(int arr[] , int n )
{
    Node* head = new Node(arr[0]);
    Node* previous = head;

    for(int i = 1 ; i < n ; i++)
    {
        Node* temp = new Node( arr[i] , NULL , previous);
        previous -> next = temp;
        previous = temp;
    }
return head;

}

Node* deleteHead(Node* head)
{
    if( head == NULL || head -> next == NULL)
    {
        return NULL;
    }

    Node* prev = head;
    head = head -> next;

    prev->next = NULL;
    head->back = NULL;

    return head;
}

Node* deleteTail(Node* head)
{
    if( head == NULL || head -> next == NULL)
    {
        return NULL;
    }

    Node* tail = head;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    Node* prev = tail->back;
    tail->back = NULL;
    prev->next = NULL;

    delete tail;

    return head;
    
}

void print(Node* head)
{
    Node* temp = head;
    while (temp!=NULL)
    {
        cout << temp -> data <<" ";
        temp = temp -> next;
    }
    
}

Node* deleteAtK(Node* head , int k)
{
    if( head == NULL || head->next == NULL )
    {
        return NULL;
    }

    Node* temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        if(cnt == k)
        {
            break;
        }

        temp = temp->next;
    }
    
    Node* prev = temp->back;
    Node* front = temp->next;

    if( prev == NULL && front == NULL)
    {
        delete temp;
        return NULL;
    }
    else if( prev == NULL )
    {
        return deleteHead(head);
    }
    else if( front == NULL )
    {
        return deleteTail(head);
    }
    else
    {
        prev->next = front;
        front->back = prev;

        temp->back = NULL;
        temp->next = NULL;

        delete temp;
    }

return head;
    

}

Node* insertAtHead(Node* head , int data)
{
    Node* newHead = new Node(data  , head , NULL );
    head->back = newHead;

    return newHead;
}

Node* insertAtTail(Node* head , int data)
{
    Node* tail = head;
    while (tail->next!=NULL)
    {
        tail = tail->next;
    }

    Node* newTail = new Node(data  , NULL , tail );\
    tail->next = newTail;

    return head;
    
}
Node* insertAtK(Node* head , int data , int k)
{
    if( k == 1)
    {
        return insertAtHead(head , data);
    }

    Node* temp = head;
    int cnt = 0;
    while (temp!=NULL)
    {
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    if(temp == NULL)
    {
        return insertAtTail(head , data);
    }

    Node*prev = temp->back;
    Node* newNode = new Node(data  , temp , prev );

    prev->next = newNode;
    temp->back = newNode;

    return head;
}

Node* reverseDLL(Node* head)
{
    Node* current = head;
    Node* last = NULL;

    while (current!=NULL)
    {
        last = current -> back;
        current -> back = current -> next;
        current -> next = last;
        current = current -> back;
    }

    head = last -> back;

    return head;
    
}
int main()
{
    int arr[]={13 , 46 , 54 , 18 , 9};
    Node* head = convertArrToDll(arr,5);
    print(head);
    cout<<endl;
    head = insertAtK(head , 300  , 6);
    print(head);
    cout<<endl;
    head = reverseDLL(head);
    print(head);
    
    return 0;
}