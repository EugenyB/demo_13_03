#include <iostream>

using namespace std;

struct element {
    int x;
    element * next;
};

element * head;
element * tail;

void add(int value) {
    element * t = new element;
    t->x = value;
    t->next = head;
    head = t;
}

void addInTail(int value) {
    element * t = new element;
    t->x = value;
    t->next = NULL;
    if (head==NULL) {
        head = t;
    } else {
        tail->next = t;
    }
    tail = t;
}

void print(element * head) {
    element * t = head;
    while (t != NULL) {
        cout << t->x << " ";
        t = t->next;
    }
    cout << endl;
}

element * find(element *head, int value) {
    element *p;
    p = head;
    while(p) {
        if (p->x == value) {
            break;
        } else {
            p = p->next;
        }
    }
    return p;
}

void addAfter(element *f, int value) {
    element * t = new element;
    t->x = value;
    t->next = f->next;
    f->next = t;
}

void addBefore(element *f, int value) {
    element * t = new element;
    t->x = f->x;
    f->x = value;
    t->next = f->next;
    f->next = t;
}

void deleteAfter(element *f) {
    element * t = f->next;
    f->next = f->next->next;
    delete t;
}

void deleteElement(element *f) {
    element *t = f->next;
    f->x = t->x;
    f->next = f->next->next;
    delete t;
}
int main() {
    head = NULL;
    addInTail(1);
    addInTail(4);
    addInTail(5);
    addInTail(7);
    addInTail(11);
    print(head);
    cout << "-----------------" << endl;
    element *f = find(head, 5);
    if (f) {
        cout << "found: " << f->x << endl;
    } else {
        cout << "not found" << endl;
    }

//    addAfter(f, 6);
//    addBefore(f, 6);
//    deleteAfter(f);
    deleteElement(f);
    print(head);
    return 0;
}