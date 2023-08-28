// Online C++ compiler to run C++ program online
#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int data;
    Node* next;
  
    Node()
    {
        data = 0;
        next = NULL;
    }
  
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Time and Space O(n)
Node* reverse(Node* head, int begin, int end)
{
    if(head == nullptr || begin == end) return head;
    
    unordered_map<int, Node*> list;
    int key = 1;
    
    Node* temp = head;
    
    while(temp != nullptr) 
    {
        list[key] = temp;
        temp = temp->next;
        key++;
    }
    
    if(begin == 1) head = list[end];
    else list[begin - 1]->next = list[end];
    
    if(end == key) list[begin]->next = nullptr;
    else list[begin]->next = list[end+1];
    
    int i = end;
    while(i != begin)
    {
        list[i]->next = list[i-1];
        i--;
    }
    
    return head;
}

int main() {
    Node* head;
    Node* temp;
    Node* one = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);
    Node* four = new Node(4);
    Node* five = new Node(5);
    Node* six = new Node(6);

    
    // Connect nodes
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = nullptr;
    head = one;
    temp = head;
    
    while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
    }
    
    cout << endl;
    head = reverse(head, 2, 4);
    
    temp = head;
    while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
    }

    return 0;
}
