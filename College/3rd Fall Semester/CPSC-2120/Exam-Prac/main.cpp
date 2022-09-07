#include <iostream>


struct Node{
    int val;
    Node * next;

    Node(int val){
        this->val = val;
        next = nullptr;
    }
};

Node * head = nullptr;

void insert(Node* node){
    node->next = head;
    head = node;
}


int main() {
    head = new Node(30);
    insert(new Node(45));
    insert(new Node(45));
    insert(new Node(45));


    for(Node* node = head; node != nullptr; node = node->next){
        std::cout<<node->val<<std::endl;
    }

}
