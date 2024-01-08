#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void addToFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void addToEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void addAfterValue(int target, int value) {
        Node* current = head;
        while (current) {
            if (current->data == target) {
                Node* newNode = new Node(value);
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        std::cout << "Element with value " << target << " not found." << std::endl;
    }

    void remove(int value) {
        if (!head) {
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
        std::cout << "Element with value " << value << " not found." << std::endl;
    }

    Node* find(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void print() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    LinkedList list1, list2, result1, result2;
    int n, value;

  std::cout << "Кількість елементів 1 списку: ";
    std::cin >> n;
    std::cout << "Напишіть елементи списку чередуючи Enter: ";
    for (int i = 0; i < n; i++) {
        std::cin >> value;
        list1.addToEnd(value);
    }

   std::cout << "Кількість елементів 2 списку: ";
    std::cin >> n;
    std::cout << "Напишіть елементи списку чередуючи Enter: ";
    for (int i = 0; i < n; i++) {
        std::cin >> value;
        list2.addToEnd(value);
    }

int filterValue;
    std::cout << "введіть число для 5 завдання: ";
    std::cin >> filterValue;

    Node* current1 = list1.head;
    Node* current2 = list2.head;
    while (current1) {
        if (current1->data >-1 ) {
            if(current1->data >filterValue){
            result1.addToEnd(current2->data);
            }

            if (current1->data > 0 ) {
            result2.addToEnd(current1->data);
        }
        }
        current1 = current1->next;
    }
    while(current2){
        if(current2->data >-1 ){
            if(current2->data >filterValue){
            result1.addToEnd(current2->data);
            }
            if(current2->data > 0 ){
            result2.addToEnd(current2->data);
        }
        }
current2 = current2->next;
}
    std::cout << "5 завдання : ";
    result1.print();

    std::cout << "9 завдання : ";
    result2.print();

    return 0;}
