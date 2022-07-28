#include <cstdlib>

void die() {
    printf("Memory Error.");
    exit(1);
}

class stackNode {
public:
    int value;
    stackNode *next;

    explicit stackNode(int x) {
        value = x;
        next = nullptr;
    }
};

class stack {
    int _size;
    stackNode *top;

public:
    int size() {
        return _size;
    }

    stack() {
        _size = 0;
        top = nullptr;
    }

    int peek() {
        if (_size <= 0) die();
        return top->value;
    }

    void push(int value) {
        auto* newTop = new stackNode(value);
        newTop->next = top;
        top = newTop;
        _size++;
    }

    void pop() {
        if (_size <= 0) die();
        stackNode *oldTop = top;
        top = top->next;
        delete oldTop;
        _size--;
    }

    void display() {
        // prints out the stack
        stackNode* node = top;
        while (node) {
            printf("%d ", node->value);
            node = node->next;
        }
    }

    bool isFull() {
        // stack can never be full since max size in unspecified
        return false;
    }

    bool isEmpty() {
        return _size == 0;
    }
};