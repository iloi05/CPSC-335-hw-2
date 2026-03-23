#include <iostream>

// so can be used in reverse algo
struct Node {
    int data; // stuff in node
    Node* prev; //ptr
    Node* next; //ptr
};

void reverse (Node*& head) {
   Node* curr = head; //currently pointing at head
   Node* temp = nullptr; //temporarilly pointing at null

   while(curr) { 
    // moving the pointers and nodes around
    temp = curr->prev;
    curr->prev = curr->next;
    curr->next = temp;

    curr = curr->prev;
   }
   if (temp) {
    head = temp->prev;
   }

}
// for displaying the lists
void display (Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
  Node* first = new Node{11, nullptr, nullptr};
  Node* second = new Node{7, first, nullptr};
  Node* third = new Node{9, second, nullptr};
  Node* fourth = new Node{6, third, nullptr};

  //establishing what is pointing to what
  first->next = second;
  second->next = third;
  third->next = fourth;
  Node* head = first;

  std::cout << "Original: ";
  display(head);

  reverse(head);

  std::cout << "Reversed: ";
  display(head);


    
return 0;
}