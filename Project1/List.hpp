#pragma once 
#ifndef  LIST_HPP
#define  LIST_HPP
#include <iostream>
#include <cstddef>

template <typename T>
struct Node {
    T data;
    Node* next = NULL;
};
template <typename T>
class NodeList {
public: 
    struct Iterator //Под форвард
    {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        Iterator(Node<T>* node) : curr(node) {}

        reference operator*() const { return curr->data; }
        pointer   operator->()      { return &curr->data; }
        Iterator& operator++()      { curr = curr->next; return *this; }
        Iterator  operator++(int)   { Iterator tmp = *this; ++(*this); return tmp; }

        bool operator>(const Iterator& other) const {
            Iterator temp = *this;
            while (temp != other) {
                ++temp;
                if (temp.curr == nullptr) return false;
            }
            return true;
        }
        bool operator == (const Iterator& other) const { return curr == other.curr; };
        bool operator != (const Iterator& other) const { return curr != other.curr; };
        bool operator<(const Iterator& other) const { return !(*this >= other); }
        bool operator<=(const Iterator& other) const { return !(*this > other); }   
        bool operator>=(const Iterator& other) const { return (*this == other) || (*this > other); }
        
     

    private:
        Node<T>* curr;
    };

    class const_iterator {
    private:
        Node<T>* curr;

    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = const T;
        using pointer = const T*;
        using reference = const T&;
        using const_reference = value_type&;

        const_iterator(Node<T>* node) : curr(node) {}
        const_iterator(const const_iterator& other) : curr(other.curr) {}

        const_reference operator*() const {return curr->data;}
        const_iterator& operator++()      {curr = curr->next; return *this; }
        const T* operator->() const       {return &curr->data;}
        bool operator==(const const_iterator& other) const { return curr == other.curr;}
        bool operator!=(const const_iterator& other) const { return !(*this == other); }
    };
    

    Node<T>* head;

    NodeList() {
        head = NULL;
    };
    NodeList(Node<T> a) {
        head = new Node<T>;
        *head = a;
        Size++;
    };
    NodeList(T a) {
        head = new Node<T>;
        head->data = a;
        Size++;
    };
    NodeList(NodeList& copy) {
        Node<T>* current = copy.head;
        while (current) {
            PushBack(current->data);
            current = current->next;
        }
    };
    
    
    NodeList(NodeList&& other) : head(other.head), Size(other.Size){
        other.head = NULL;
        other.Size = 0;
     };
     
    /*
    NodeList(NodeList&& other){
        Node<T>* temp = other.head;
        while (temp) {
            PushBack(std::move(temp->data));
            temp = temp->next;
        }
    };
    */
    
    ~NodeList() {
        if (head != NULL) {
            Node<T>* current = this->head->next;
            while (current->next != NULL) {
                Node<T>* tmp = current;
                current = current->next;
                delete tmp;
            }
            delete this->head;
            this->head = NULL;
        }
        Size = 0;
    };

    void PushBack(T data) {

        Node<T>* tmp = new Node<T>;
        tmp->data = data;

        if (head == NULL) {
            head = tmp;
            head->next = NULL;
        }

        else {
            Node<T>* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = tmp;
            tmp->next = NULL;
        }
        Size++;
    };
    void print() {
        Node<T>* current = head;
        if (head == NULL) std::cout << "Список пуст";
        else {
            std::cout << head->ch << " ";
            while (current->next != NULL) {
                current = current->next;
                std::cout << current->ch << " ";
            }
            std::cout << std::endl;
        };
    }

    size_t size() { return Size; };
    size_t maxSize() { return 204903409; };
    void swap(NodeList* list2);


    NodeList& operator=(const NodeList& other) {
        if (this == &other) {
            return *this;
        }

        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }

        Node<T>* temp = other.head;
        while (temp) {
            push_back(temp->data);
            temp = temp->next;
        }

        return *this;
    }

    NodeList& operator=(NodeList&& other) {
        if (this != &other) {
            while (head) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
            
            head = other.head;
            Size = other.Size;

            other.head = NULL;
            other.Size = 0;


        }

        return *this;
    }
    bool operator ==  (const NodeList& nodelist) const {
        Node<T>* current = head;
        Node<T>* current2 = nodelist.head;
        if (head == NULL && nodelist.head == NULL) {
            return true;
        }
        else if (size == nodelist.size)
        {
            while (current->next != NULL) {
                if (current->ch != current2->ch) {
                    return false;
                }
                current = current->next;
                current2 = current2->next;
            }
            return true;
        }
        else return false;
    };
    bool operator !=  (const NodeList& nodelist) const {
        Node<T>* current = head;
        Node<T>* current2 = nodelist.head;
        if (head == NULL && nodelist.head == NULL) {
            return false;
        }
        else if (size == nodelist.size)
        {
            while (current->next != NULL) {
                if (current->ch != current2->ch) {
                    return true;
                }
                current = current->next;
                current2 = current2->next;
            }
            return false;
        }
        else return true;
    };



    NodeList::Iterator begin()        { return Iterator(head); };
    NodeList::Iterator end()          { return Iterator(NULL); };
    NodeList::const_iterator cbegin() { return const_iterator(head); };
    NodeList::const_iterator cend()             { return const_iterator(NULL); };
    
    
private:
    size_t Size = 0;
  
};

template <typename T>
void swap(NodeList<T>& list1, NodeList<T>& list2) {
    NodeList<T>& tmp = list2;
    list2 = list1;
    list2 = tmp;
};






#endif //  LIST_HPP
