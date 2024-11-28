#include <iostream>
using namespace std;

class Node {
private:
    int data;
    int weight;
    Node* lchild;
    Node* rchild;
public:
    Node(int d) :
        weight{ 1 }, data{ d }, rchild{ nullptr }, lchild{ nullptr } {};

    Node* insertR(int k) {
        if (this == nullptr) {
            return new Node(k);
        }

        if (k == this->data) {
            this->weight++;
        }
        else if (k < this->data) {
            this->lchild = this->lchild->insertR(k);
        }
        else {
            this->rchild = this->rchild->insertR(k);
        }

        return this;
    }

    Node* insertI(int k) {
        if (this == nullptr) {
            return new Node(k);
        }

        Node* current = this;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (k == current->data) {
                current->weight++;
                return this;
            }
            else if (k < current->data) {
                current = current->lchild;
            }
            else {
                current = current->rchild;
            }
        }

        if (k < parent->data) {
            parent->lchild = new Node(k);
        }
        else {
            parent->rchild = new Node(k);
        }

        return this;
    }

    void inOrder() {
        if (this == nullptr) return;

        this->lchild->inOrder();
        cout << this->data << " ";
        this->rchild->inOrder();

    }

    void preOrder() {
        if (this == nullptr) return;

        cout << this->data << " ";
        this->lchild->inOrder();
        this->rchild->inOrder();

    }

    void postOrder() {
        if (this == nullptr) return;

        this->lchild->inOrder();
        this->rchild->inOrder();
        cout << this->data << " ";

    }

    Node* searchR(int k) {
        if (root == nullptr) {
            cout << "il numero non c'è" << endl;
            return nullptr;
        }

        if (k == this->data) {
            cout << "il numero si trova: " << this << " ed è stato inserito " << this->weight << " volte" << endl;
            return this;
        }
        else if (k < this->data) {
            return this->lchild->search(k);
        }
        else {
            return this->rchild->search(k);
        }

        return this;
    }

    int height() {
        if (this == NULL) return 0;

        int l = this->lchild->height();
        int r = this->rchild->height();

        return max(l, r) + 1;
    }

    bool isBst(int min = INT_MIN, int max = INT_MAX) {
        if (this == nullptr) {
            return true;
        }

        if (this->data < min || this->data > max) {
            return false;
        }

        return this->lchild->isBST(min, this->data) && this->rchild->isBST(this->data, max);
    }

};
