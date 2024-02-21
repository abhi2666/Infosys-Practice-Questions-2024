#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }

    void displayList(Node* head){
        Node* cur = head;
        while(cur!=nullptr){
            cout<<cur->data<<" ";
            cur = cur->next;
        }
    }

    Node* reverseList(Node* head){
        Node* prev = nullptr;
        Node* curr = head;
        Node* nex = nullptr;
        while(curr!=nullptr){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }

    Node* addOneToList(Node* head){
        // first you will have to reverse the list
        Node* revList = reverseList(head);
        Node* temp = revList;
        // now add the value 1 to the list from the start 
        int carry = 1;
        while(temp!=nullptr){
            int sum = temp->data + carry;
            carry = sum/10;
            int dig = sum%10;
            temp->data = dig;
            temp = temp->next;
        }
        // now reverse the list and if there is any carry then add it to the the front of the list
        Node* res = reverseList(revList);
        if(carry!=0){
            Node* extraNode = new Node(carry);
            extraNode->next = res;
            return extraNode;
        }
        return res;
    }
};

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    Node* addedList = head->addOneToList(head);
    cout<<"transformed"<<endl;
    addedList->displayList(addedList);
    return 0;
}
