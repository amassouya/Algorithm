#include "LinkedList.h"
#include <vector>
using namespace std;

void ListE::print_reversed_helper(NodeE* node) const
{
    if (node != nullptr) {
        print_reversed_helper(node->next);
        std::cout << node->item << " ,  ";
    }
}





bool ListE::swap(const int& index) {
    if (index < 1 || index >= m_length) {
        std::cout << "Ungültiger Index!" << std::endl;
        return false;
    }

    if (index == 1) {
        NodeE* first = m_head;
        NodeE* second = m_head->next;

        first->next = second->next;
        second->next = first;
        m_head = second;

        //m_lenght == 1
        if (m_tail == second) {
            m_tail = first;
        }
    }
    else {
        NodeE* prev = m_head;
        for (int i = 1; i < (index - 1); ++i) {
            prev = prev->next;
        }

        NodeE* first = prev->next;
        NodeE* second = first->next;

        first->next = second->next;
        second->next = first;
        prev->next = second;

        if (m_tail == second) {
            m_tail = first;
        }
    }

    std::cout << "Elemente an Position " << index << " und " << index + 1 << " erfolgreich getauscht!" << std::endl;
    return true;
}

void ListE::print_reversed() const
{
    std::vector<int> elements;
    NodeE* temp = m_head;

    while (temp != nullptr) {
        elements.push_back(temp->item);
        temp = temp->next;
    }

    for (int i = elements.size() - 1; i >= 0; i--) {
        std::cout << elements[i] << " , ";
    }
    cout << endl;
    cout << endl;
    cout << "helper rekrusiv: " << endl;
    print_reversed_helper(m_head);
    std::cout << std::endl;
}











