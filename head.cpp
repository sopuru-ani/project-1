#include <string>
#include <iostream>
#include "storeCourse.h"
using namespace std;

StoreCourse::StoreCourse() {
	head = nullptr;
	//head->next = nullptr;
}

void StoreCourse::insert(string cc, int ch, double g) {
    CourseNode* prevNode;
    CourseNode* nodePtr;
    CourseNode* newNode = nullptr;
    newNode = new CourseNode;
    newNode->courseCode = cc;
    newNode->creditHours = ch;
    newNode->grade = g;

    if (!head) {
        head = newNode;
    }
    else {
        nodePtr = head;
        prevNode = nullptr;
        while (nodePtr != nullptr && extractCourseNum(nodePtr->courseCode) < extractCourseNum(cc)) {
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (!prevNode) {
            newNode->next = head;
            head = newNode;
        }
        else {
            prevNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

int StoreCourse::extractCourseNum(string courseCode){
    string n = "";
    for (char c : courseCode) {
        if (isdigit(c)) {
            n += c;
        }
    }
    if (n.empty()) {
        return 0;
    }
    else {
        return stoi(n);
    }
}
void StoreCourse::deleteNode() {
    if (head == nullptr) {
        cout << "List is empty. No node to delete.\n";
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    CourseNode* current = head;
    CourseNode* prev = nullptr;

    while (current->next != nullptr) {
        prev = current;
        current = current->next;
    }

    prev->next = nullptr;
    delete current;
}

void StoreCourse::deleteAllNodes() {
    CourseNode* current = head;
    CourseNode* next;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
}

void StoreCourse::displayList() {
    CourseNode* temp = head;
    while (temp != nullptr) {
        cout << temp->courseCode << ", " << temp->creditHours << ", " << temp->grade << endl;
        temp = temp->next;
    }
    cout << endl;
}

StoreCourse::~StoreCourse() {
    deleteAllNodes();
}