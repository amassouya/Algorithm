#pragma once
#include"Node.h"
#include <iostream>
#include <list>
#include <stdexcept>
#include <stack>
#include <string>
#include <ctype.h>
#include <sstream>

class ListE
{

private:
    // Hilf Methode fuer print reversed (wenn print reversed rekursiv 
    // implementiert wird)
    void print_reversed_helper(NodeE* node) const;


    NodeE* search_node(const int& item)
    {
        NodeE* tmp = m_head;
        while (tmp != nullptr && tmp->item != item) tmp = tmp->next;
        return tmp;
    }

    NodeE* m_head;
    NodeE* m_tail;
    int m_length;


public:
    // Konstruktor
    ListE() {
        m_length = 0;
        m_head = nullptr;
        m_tail = nullptr;
    }
    ListE(std::initializer_list<int> init) : m_length(0)
    {
        for (const int& item : init) this->add(item);
    }
    // Copy Konstruktor
    ListE(const ListE& other) { *this = other; }

    // Dekonstruktor
    ~ListE()
    {
        while (m_head != nullptr)
        {
            NodeE* tmp = m_head->next;
            delete m_head;
            m_head = tmp;
        }
    }

    // Add Methode welche am Ende der Liste einen 
    // Knoten mit der Variable item anfuegt
    void add(const int& item)
    {
        m_length++;
        NodeE* new_node = new NodeE();
        new_node->item = item;
        if (m_tail == nullptr) m_head = new_node;
        else m_tail->next = new_node;

        m_tail = new_node;
    }

    // Search Methode sucht das Element item in der Liste
    bool search(const int& item)
    {
        NodeE* search_node = this->search_node(item);
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
        NodeE* current = m_head;
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

    // Gibt die Laenge der Liste zurueck
    int length() const { return m_length; }

    // remove Methode l�scht das Element item in der Liste
    bool remove(const int& item)
    {
        // Suche den Knoten
        NodeE* parent = nullptr;
        NodeE* del_node = m_head;
        while (del_node != nullptr && del_node->item != item)
        {
            parent = del_node;
            del_node = del_node->next;
        }

        if (del_node != nullptr) {
            // Entferne den Knoten
            if (del_node == m_head) m_head = del_node->next;
            if (del_node == m_tail) m_tail = parent;

            if (parent != nullptr) parent->next = del_node->next;

            delete del_node;

            std::cout << "Element " << item << " erfolgreich aus der Liste entfernt!" << std::endl;
            return true;
        }
        else {
            // Knoten nicht gefunden
            std::cout << "Element " << item << " konnte nicht geloescht werden!" << std::endl;
            return false;
        }
    }

    // Swap Methode welche den Knoten an der stelle 
    // Index mit dem naechsten tauscht
    bool swap(const int& index);

    // Print Methode welche die Knoten rueckwaerts 
    // (in O(n)) ausgibt. Wird bei Aufgabe 4 implementiert.
    void print_reversed() const;


    // Loescht alle Elemente aus der Liste
    void clear()
    {
        if (m_head == nullptr) return;

        // delete all nodes
        while (m_head != nullptr)
        {
            NodeE* tmp = m_head->next;
            delete m_head;
            m_head = tmp;
        }

        // clean
        this->m_head = nullptr;
        this->m_tail = nullptr;
        this->m_length = 0;
    }

    // Assignment (Copy) Operator
    ListE& operator=(const ListE& other)
    {
        this->clear();

        // copy nodes
        NodeE* current = other.m_head;
        while (current != nullptr)
        {
            this->add(current->item);
            current = current->next;
        }
        return *this;
    }
};
