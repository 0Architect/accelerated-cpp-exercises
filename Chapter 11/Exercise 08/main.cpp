#include <cstddef> // for size_t

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
    };

public:
    class Iterator {
    public:
        Iterator(Node* node) : currentNode(node) {}

        T& operator*() const {
            return currentNode->data;
        }

        Iterator& operator++() {
            currentNode = currentNode->next;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const Iterator& other) const {
            return currentNode == other.currentNode;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }

    private:
        Node* currentNode;
    };

public:
    List() : head(nullptr), tail(nullptr), listSize(0) {}
    ~List() {
        clear();
    }

    void push_back(const T& value) {
        Node* newNode = new Node{value, nullptr, nullptr};

        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        ++listSize;
    }

    void pop_back() {
        if (isEmpty())
            return;

        if (tail == head) {
            delete tail;
            head = tail = nullptr;
        } else {
            Node* previous = tail->prev;
            delete tail;
            tail = previous;
            tail->next = nullptr;
        }

        --listSize;
    }

    size_t size() const {
        return listSize;
    }

    bool isEmpty() const {
        return listSize == 0;
    }

    Iterator begin() const {
        return Iterator(head);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }

    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        listSize = 0;
    }

private:
    Node* head;
    Node* tail;
    size_t listSize;
};