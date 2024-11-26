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

    void preOrder() {
        if (this == nullptr) return;

        cout << this->data << " ";
        this->leftc->inOrder();
        this->rightc->inOrder();

    }

    void postOrder() {
        if (this == nullptr) return;

        this->leftc->inOrder();
        this->rightc->inOrder();
        cout << this->data << " ";

    }

    Node* search(int k) {
        if (root == nullptr) {
            cout << "il numero non c'è" << endl;
            return nullptr;
        }

        if (k == this->data) {
            cout << "il numero si trova: " << this << " ed è stato inserito " << this->rip << " volte" << endl;
            return this;
        }
        else if (k < this->data) {
            return this->leftc->search(k);
        }
        else {
            return this->rightc->search(k);
        }

        return this;
    }

    int height() {
        if (this == NULL) return 0;

        int l = this->leftc->height();
        int r = this->rightc->height();

        return max(l, r) + 1;
    }

    bool isBST(int min = INT_MIN, int max = INT_MAX) {
        if (this == nullptr) {
            return true;
        }

        if (this->data < min || this->data > max) {
            return false;
        }

        return this->leftc->isBST(min, this->data) && this->rightc->isBST(this->data, max);
    }

};
