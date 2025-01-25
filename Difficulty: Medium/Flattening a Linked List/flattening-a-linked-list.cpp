//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->bottom;
    }
    printf("\n");
}

Node* createLinkedList(vector<Node*>& v) {
    Node* head = new Node(0);
    Node* temp = head;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        temp->next = v[i];
        temp = temp->next;
    }
    return head->next;
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    // Merges two linked lists in a particular
    // order based on the data value
    Node* merge(Node* list1, Node* list2){
        // Create a dummy node as a
        // placeholder for the result
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
    
        // Merge the lists based on data values
        while(list1 != NULL && list2 != NULL){
            if(list1->data < list2->data){
                res->bottom = list1;
                res = list1;
                list1 = list1->bottom;
            }
            else{
                res->bottom = list2;
                res = list2;
                list2 = list2->bottom;
            }
            res->next = NULL;
        }
    
        // Connect the remaining
        // elements if any
        if(list1){
            res->bottom = list1;
        } else {
            res->bottom = list2;
        }
    
        // Break the last node's
        // link to prevent cycles
        if(dummyNode->bottom){
            dummyNode->bottom->next = NULL;
        }
    
        return dummyNode->bottom;
    }
    
    // Flattens a linked list with child pointers
    Node* flatten(Node* head){
        // If head is null or there 
        // is no next node, return head
        if(head == NULL || head->next == NULL){
            return head;
        }
    
        // Recursively flatten the
        // rest of the linked list
        Node* mergedHead = flatten(head->next);
        head = merge(head, mergedHead);
        return head;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->bottom = newNode;
                temp = temp->bottom;
            }
            v[i] = head->bottom;
        }

        Solution ob;
        Node* list = createLinkedList(v);
        Node* head = ob.flatten(list);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends