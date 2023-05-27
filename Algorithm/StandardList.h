#pragma once
#include <list>
#include <string>
#include <iostream>
using namespace std;



void printList(list<int> pList) {
    // Convert the list to a string
    string str = "[";
    for (auto it = pList.begin(); it != pList.end(); ++it) {
        str += to_string(*it);
        if (next(it) != pList.end()) {
            str += ", ";
        }
    }
    str += "]";

    // Print the string
    cout << str << endl;
}

std::list<int> union_of_lists(const std::list<int>& l1,
    const std::list<int>& l2)
{
    // Ihre Loesung hier:  

    list<int> united;
    int i = 1;
    auto a = l1.begin();
    auto b = l2.begin();

    while (a != l1.end() && b != l2.end()) {

        if (*a < *b) {
            united.push_back(*a);
            a++;
        }
        else if (*b < *a) {
            united.push_back(*b);
            b++;
        }
        else {
            united.push_back(*a);
            united.push_back(*b);
            a++;
            b++;
        }

    }while (a != l1.end()) {
        united.push_back(*a);
        a++;
    }
    while (b != l2.end()) {
        united.push_back(*b);
        b++;
    }

    return united;
}