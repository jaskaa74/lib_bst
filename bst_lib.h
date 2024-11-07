#include <iostream>
using namespace std;

struct node {
    int data;
    int rip;
    node* leftc;
    node* rightc;

    node(int d) {
        rip = 1;
        data = d;
        rightc = nullptr;
        leftc = nullptr;
    }
};

node* insert(node* root, int key) {
    if (root == nullptr) {
        return new node(key);
    }

    if (key == root->data) {
        root->rip++;
    }
    else if (key < root->data) {
        root->leftc = insert(root->leftc, key);
    }
    else {
        root->rightc = insert(root->rightc, key);
    }

    return root;
}

node* insert2(node* r, int key) {
    if (r == nullptr) {
        return new node(key);
    }

    node* current = r;
    node* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (key == current->data) {
            current->rip++;
            return r;
        }
        else if (key < current->data) {
            current = current->leftc;
        }
        else {
            current = current->rightc;
        }
    }

    if (key < parent->data) {
        parent->leftc = new node(key);
    }
    else {
        parent->rightc = new node(key);
    }

    return r;
}

void a(int i) {
    cout << "a";
}

void pre_order(node* r) {
    if (r == nullptr) return;

    cout << r->data << " ";

    pre_order(r->leftc);
    pre_order(r->rightc);

}

void in_order(node* r) {
    if (r == nullptr) return;

    in_order(r->leftc);
    cout << r->data << " ";
    in_order(r->rightc);

}

void post_order(node* r) {
    if (r == nullptr) return;

    pre_order(r->leftc);
    pre_order(r->rightc);

    cout << r->data << " ";
}

node* DeleteL(node* r, int key) {            //per foglie
    if (r == nullptr) {
        return nullptr;
    }

    if (key == r->data) {
        delete r;
        return nullptr;
    }
    else if (key < r->data) {
        r->leftc = DeleteL(r->leftc, key);
    }
    else {
        r->rightc = DeleteL(r->rightc, key);
    }

    return r;
}

node* DeleteC(node* r, int key) {            //per nodi con 1 figlio
    if (r == nullptr) {
        return nullptr;
    }

    if (key < r->data) {
        r->leftc = DeleteC(r->leftc, key);
    }
    else if (key > r->data) {
        r->rightc = DeleteC(r->rightc, key);
    }
    else if (r->leftc == nullptr) {
        node* temp = r;
        r = r->rightc;
        delete temp;
    }
    else if (r->rightc == nullptr) {
        node* temp = r;
        r = r->leftc;
        delete temp;
    }

    return r;
}

node* DeleteN(node* r, int key) {            //per nodi con 2 figli
    if (r == nullptr) {
        return nullptr;
    }

    if (key < r->data) {
        r->leftc = DeleteN(r->leftc, key);
    }
    else if (key > r->data) {
        r->rightc = DeleteN(r->rightc, key);
    }
    else {
        if (r->rightc != nullptr && r->leftc != nullptr) {
            node* parent = r;
            node* temp = r->rightc;

            while (temp->leftc != nullptr) {
                parent = temp;
                temp = temp->leftc;
            }

            r->data = temp->data;

            if (parent->leftc == temp) {
                parent->leftc = temp->rightc;
            }
            else {
                parent->rightc = temp->rightc;
            }

            delete temp;
        }
    }

    return r;
}

int height(node* root) {
    if (root == NULL) return 0;

    int l = height(root->leftc);
    int r = height(root->rightc);

    return max(l, r) + 1;
}

node* find(node* root, int key) {
    if (root == nullptr) {
        cout << "il numero non c'è" << endl;
        return nullptr;
    }

    if (key == root->data) {
        cout << "il numero si trova: " << root << " ed è stato inserito " << root->rip << " volte" << endl;
        return root;
    }
    else if (key < root->data) {
        return find(root->leftc, key);
    }
    else {
        return find(root->rightc, key);
    }

    return root;
}

bool isBST(node* r, int min = INT_MIN, int max = INT_MAX) {
    if (r == nullptr) {
        return true;
    }

    if (r->data < min || r->data > max) {
        return false;
    }

    return isBST(r->leftc, min, r->data) && isBST(r->rightc, r->data, max);
}