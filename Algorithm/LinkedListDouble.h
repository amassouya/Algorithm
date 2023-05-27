#pragma once
#include "NodeDouble.h"
#include <iostream>
#include <list>
#include <stdexcept>
#include <stack>
#include <string>
#include <ctype.h>
#include <sstream>

class ListD
{
private:
    NodeD* search_node(const int& item) const
    {
        NodeD* tmp = m_head;
        while (tmp != nullptr && tmp->item != item) tmp = tmp->next;
        return tmp;
    }

    NodeD* m_head;
    NodeD* m_tail;
    int m_length;

public:
    // Konstruktor
    ListD() : m_length(0), m_head(nullptr), m_tail(nullptr) { };
    ListD(std::initializer_list<int> init) : m_length(0), m_head(nullptr), m_tail(nullptr)
    {
        for (const int& item : init) this->add(item);
    }
    // Copy Konstruktor
    ListD(const ListD& other) { *this = other; }

    // Dekonstruktor
    ~ListD()
    {
        if (m_head == nullptr) return;
        while (m_head->next != nullptr)
        {
            m_head = m_head->next;
            delete m_head->prev;
        }
        delete m_head;
    }

    // Add Methode welche am Ende der Liste einen Knoten mit der 
    // Variable item anfuegt
    void add(const int& item)
    {
        m_length++;

        NodeD* new_node = new NodeD();
        new_node->item = item;
        new_node->prev = m_tail;

        if (m_tail == nullptr) m_head = new_node;
        else m_tail->next = new_node;

        m_tail = new_node;
    }

    // Search Methode sucht das Element item in der Liste
    bool search(const int& item) const
    {
        NodeD* search_node = this->search_node(item);
        if (search_node == nullptr) {
            std::cout << "Wert " << item << " ist nicht in der Liste vorhanden!" << std::endl;
            return false;
        }
        else {
            std::cout << "Wert " << item << " wurde in der Liste gefunden!" << std::endl;
            return true;
        }
    }

    // Print Methode um Liste auszugeben
    void print() const
    {
        NodeD* current = m_head;
        std::cout << "[";
        while (current != nullptr)
        {
            std::cout << current->item;
            if (current->next != nullptr)
            {
                std::cout << ", ";
                current = current->next;
            }
            else break;
        }
        std::cout << "]" << std::endl;
    }

    // Print Methode um Liste rueckwaerts auszugeben
    void print_reversed() const
    {
        NodeD* current = m_tail;
        std::cout << "[";
        while (current != nullptr)
        {
            std::cout << current->item;
            if (current->prev != nullptr)
            {
                std::cout << ", ";
                current = current->prev;
            }
            else break;
        }
        std::cout << "]" << std::endl;
    }

    // gibt die Laenge der Liste zurueck
    int length() const { return m_length; }

    // remove Methode löscht das Element item in der Liste
    bool remove(const int& item)
    {
        NodeD* del_node = search_node(item);
        if (del_node != nullptr) {
            if (del_node == m_head) m_head = del_node->next;
            if (del_node == m_tail) m_tail = del_node->prev;

            if (del_node->prev != nullptr) del_node->prev->next = del_node->next;
            if (del_node->next != nullptr) del_node->next->prev = del_node->prev;

            delete del_node;

            std::cout << "Element " << item << " erfolgreich aus der Liste entfernt!" << std::endl;
            return true;
        }
        else {
            std::cout << "Element " << item << " konnte nicht geloescht werden!" << std::endl;
            return false;
        }
    }

    // Swap Methode welche den Knoten an der stelle 
    // Index mit dem naechsten tauscht
    bool swap(const int& index);

    // Loescht alle Elemente aus der Liste
    void clear()
    {
        if (m_head == nullptr) return;
        // delete all nodes
        while (m_head->next != nullptr)
        {
            m_head = m_head->next;
            delete m_head->prev;
        }
        delete m_head;

        // cleanup
        this->m_head = nullptr;
        this->m_tail = nullptr;
        this->m_length = 0;
    }

    // Assignment (Copy) Operator
    ListD& operator=(const ListD& other)
    {
        this->clear();
        // copy nodes
        NodeD* current = other.m_head;
        while (current != nullptr)
        {
            this->add(current->item);
            current = current->next;
        }
        return *this;
    }

};