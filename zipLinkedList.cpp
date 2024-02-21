/*
given a list like this 1->2->3->4->5  zip it so that it becomes 
1->5->2->4->3. Do it inplace..

Approach --> reverse the last half of the list and then merge alternatively from
there both the lists
*/
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
        Node* temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

    Node* reverseList(Node* head){
        Node* prev = nullptr;
        Node* curr = head;
        Node* nex = nullptr;
        while(curr!= nullptr){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }

    Node* zipList(Node* head, int k){
        // k == size
        int mid = k/2;
        Node* middle = head;
        while(mid--) middle = middle->next;
        // once reached the middle we will reverse the second half 
        Node* secondList = reverseList(middle->next);
        middle->next = nullptr;
        // now two lists are ready first and second...merge then alternatively
        // this will require some manipulation of pointers
        Node* firstList = head;
        Node* t1 = nullptr;
        Node* t2 = nullptr;
        while(secondList!=nullptr){ //because secondlist can be smaller than first list
            t1 = firstList->next;
            t2 = secondList->next;
            firstList->next = secondList;
            secondList->next = t1;
            firstList = t1;
            secondList = t2;
        }
        return head;
        
    }
};
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // head->displayList(head);
    Node* zippedListHead = head->zipList(head, 5);
    head->displayList(zippedListHead);
    return 0;
}
