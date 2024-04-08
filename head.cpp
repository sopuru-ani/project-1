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
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    }
    else {
        nodePtr = head;
        prevNode = nullptr;
        while (nodePtr && extractCourseNum(nodePtr->courseCode) < extractCourseNum(cc)) {
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (!prevNode) {
            /*newNode->next = head;
            head = newNode;*/
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
//void StoreCourse::deleteNode(string cc) {
//    if (head == nullptr) {
//        cout << "List is empty. No node to delete.\n";
//        return;
//    }
//
//    /*if (head->next == nullptr) {
//        delete head;
//        head = nullptr;
//        cout << "smth";
//        return;
//    }*/
//
//    CourseNode* current = head;
//    CourseNode* prev = nullptr;
//
//    
//    /*while (current != nullptr) {
//        prev = current;
//        current = current->next;
//    }*/
//    while (current && current->courseCode != cc) {
//        prev = current;
//        current = current->next;
//    }
//    if (current != nullptr) {
//        prev->next = current->next;
//    }
//    /*head = nullptr;
//    head = current;*/
//
//    /*prev->next = nullptr;*/
//    delete current;
//}
void StoreCourse::deleteNode(string cc) {
    if (head == nullptr) {
        cout << "List is empty. No node to delete.\n";
        return;
    }

    CourseNode* current = head;
    CourseNode* prev = nullptr;

    if (head->courseCode == cc) {
        current = head->next;
        delete head;
        head = current;
    }
    else {
        while (current && current->courseCode != cc) {
            prev = current;
            current = current->next;
        }

        if (current) {
            prev->next = current->next;
        }

        delete current;
    }
    
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
    //cout << "That's all" << endl;
}

StoreCourse::~StoreCourse() {
    deleteAllNodes();
    cout << "That's all, have a nice day!\n";
}