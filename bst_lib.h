#include <iostream>
using namespace std;

class Node {
private:
    int data;
    int rip;
    Node* leftc;
    Node* rightc;
public:
    Node(int d) :
        rip{ 1 }, data{ d }, rightc{ nullptr }, leftc{ nullptr } {};

    Node* insertR(int k) {
        if (this == nullptr) {
            return new Node(k);
        }

        if (k == this->data) {
            this->rip++;
        }
        else if (k < this->data) {
            this->leftc = this->leftc->insertR(k);
        }
        else {
            this->rightc = this->rightc->insertR(k);
        }

        return this;
    }

    void inOrder() {
        if (this == nullptr) return;

        this->leftc->inOrder();
        cout << this->data << " ";
        this->rightc->inOrder();

    }
};
