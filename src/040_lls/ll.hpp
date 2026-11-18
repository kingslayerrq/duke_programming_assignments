#pragma once

#include <assert.h>
#include <cstdlib>
#include <exception>
#include <utility>

//YOUR CODE GOES HERE
class CustomException : public std::exception{
private:
    std::string msg;
public:
    CustomException():msg("") {};
    explicit CustomException(const std::string& msg) : msg(msg){};
    virtual ~CustomException() throw() {}
    virtual const char* what() const throw() {
        return msg.c_str();
    }
};


template <typename T>
class LinkedList
{
private:
    class Node
    {
    public:
        T data;
        Node* next;
        Node* prev;

        Node():data(T()), next(nullptr), prev(nullptr) {};
        explicit Node(const T& data):data(data), next(nullptr), prev(nullptr) {};

        T& getData() {
            return data;
        }
        const T& getData() const {
            return data;
        }
    };
    
    Node* head;
    Node* tail;
    
public:
    LinkedList<T>():head(nullptr), tail(nullptr) {};
    LinkedList<T>(const LinkedList<T>& rhs) : head(nullptr),tail(nullptr) {
        Node* cur = rhs.head;
        while (cur != nullptr) {
            Node* next = new Node(cur->data);
            
            if (head == nullptr){
                head = next;
                tail = next;
            }
            else {
                tail->next = next;
                next->prev = tail;
                tail = next;
            }
            cur = cur->next;
        }
    }
    ~LinkedList() {
        while (head != nullptr) {
            Node* next = head->next;
            delete head;
            head = next;
        }
        tail = nullptr;
    }

    void addFront(const T& item) {
        Node* newNode = new Node(item);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void addBack(const T& item) {
        Node* newNode = new Node(item);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    bool remove(const T& item) {
        const Node* cur = head;
        while (cur != nullptr) {
            if (cur->getData() == item) {
                Node* prev = cur->prev;
                Node* next = cur->next;
                if (prev == nullptr) {
                    head = prev;
                }
                else {
                    prev->next = next;
                }
                if (next == nullptr) {
                    tail = next;
                }
                else {
                    next->prev = prev;
                }
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
    T& operator[](int index) {
        if (index >= getSize() || index < 0){
            throw CustomException("Custom error msg");
        }
        else{
            Node* cur = head;
            for (int i = 0; i < index; ++i) {
                cur = cur->next;
            }
            return cur->getData();
        }
    }
    const T& operator[](int index) const {
        if (index >= getSize() || index < 0){
            throw CustomException("Custom error msg");
        }
        else{
            const Node* cur = head;
            for (int i = 0; i < index; ++i) {
                cur = cur->next;
            }
            return cur->getData();
        }
    }
    int find(const T& item) const {
        const Node* cur = head;
        int index = 0;
        while (cur != nullptr) {
            if (cur->getData() == item) {
                return index;
            }
            index++;
            cur = cur->next;
        }
        return -1;
    }
    void swap(LinkedList<T>& other) {
        using std::swap;
        swap(head, other.head);
        swap(tail, other.tail);
    }
    LinkedList<T>& operator=(const LinkedList<T>& rhs) {
        *this->swap(rhs);
        return *this;
    }
    int getSize() const {
        const Node* cur = head;
        int count = 0;
        while (cur != nullptr) {
            count++;
            cur = cur->next;
        }
        return count;
    }
};



