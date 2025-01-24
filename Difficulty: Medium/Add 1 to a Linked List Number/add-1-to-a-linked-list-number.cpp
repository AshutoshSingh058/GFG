//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverseList(Node* head) {
        Node* curr=head ,* P=NULL, *N=NULL;
        while(curr ){
            N=curr->next;
            curr->next=P;
            P=curr;
            curr=N;
        }
        // if(curr!=NULL)curr->next=P;
        return P;
    }
    

    
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        head= reverseList(head);
        Node* l = head;
        Node * dnode= new Node(-1);
        Node* temp= dnode;
        int n=0, carry=1;
        
        while(l ){
            n= l->data + carry;
            carry=n/10;
            n=n%10;
            Node* newNode = new Node(n);
            temp->next=newNode;
            temp=temp->next;
            l=l->next;
        }
        if(carry){
            Node* newNode = new Node(carry);
            temp->next=newNode;
            temp=temp->next;
        }
        
        // if(l){
        //     temp->next= l;
        // }
        
        dnode= reverseList(dnode->next);
        
        return dnode;
        
    }
    
    
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
    //     int carry=0, n=0;
    //     ListNode* dnode = new ListNode(-1);
    //     ListNode* temp = dnode;
    //     while(l1 && l2){
    //         n=(l1->val)+ (l2->val)+ carry;
    //         carry= n/10;
    //         n=n%10;
    //         ListNode * newNode= new ListNode(n);
    //         temp->next=newNode;
    //         temp= temp->next;
    //         l1=l1->next; l2=l2->next;

    //     }
    //     while(l1){
    //         n=(l1->val)+ carry;
    //         carry= n/10;
    //         n=n%10;
    //         ListNode * newNode= new ListNode(n);
    //         temp->next=newNode;
    //         temp= temp->next;
    //         l1=l1->next;
    //     }
    //     while(l2){
    //         n=(l2->val)+ carry;
    //         carry= n/10;
    //         n=n%10;
    //         ListNode * newNode= new ListNode(n);
    //         temp->next=newNode;
    //         temp= temp->next;
    //         l2=l2->next;
    //     }

    //     if(carry!=0){
    //         ListNode * newNode= new ListNode(carry);
    //         temp->next=newNode;
    //     }     

    //     return (dnode->next);
        
        
    // }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends