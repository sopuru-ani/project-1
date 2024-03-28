

#include <iostream>
#include <string>
#include "storeCourse.h"
using namespace std;


int main()
{
    StoreCourse s;
    string cc;
    int ch;
    double g;
    for (int i = 0; i < 2; i++) {
        cout << "Course #" << i + 1 << endl;
        cout << "Input course code: \n";
        getline(cin, cc);
        cout << "Input the credit hours: \n";
        cin >> ch;
        cout << "Input the grade: \n";
        cin >> g;
        cin.ignore();
        s.insert(cc, ch, g);
    }
    s.deleteNode();
    cout << "Last node was just deleted!\n";
    s.displayList();
    s.deleteNode();
    cout << "Last node was just deleted!\n";
    s.displayList();
}

