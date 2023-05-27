#include "LinkedListDouble.h"
using namespace std;
bool ListD::swap(const int& index) {
    NodeD* current = m_head;

    NodeD* target_prev = nullptr;
    NodeD* target = nullptr;
    NodeD* sec_target = nullptr;
    NodeD* target_next = nullptr;

    //Empty List
    if (current == nullptr) {
        std::cout << "Empty List\n";
        return false;
    }//One Node
    else if (m_head == m_tail) {
        std::cout << "You cant swap a list with one node  \n";
        return false;
    }//Search pos
    else {
        for (size_t i = 0; i < index; i++) {
            current = current->next;
            if (current == m_tail) {
                std::cout << "Index out of bound\n";
                return false;
            }
        }
    }
    {
        //Swaping
        //Two nodes
        if (current == m_head && current->next == m_tail) {
            //Set
            target = current;
            sec_target = target->next;

            //Swap
            sec_target->next = target;
            sec_target->prev = nullptr;
            target->prev = sec_target;
            target->next = nullptr;

            m_head = sec_target;
            m_tail = target;

        }//Beginning
        else if (index == 0) {
            //Set
            target = current;
            sec_target = target->next;
            target_next = sec_target->next;

            //Swap
            sec_target->next = target;
            sec_target->prev = nullptr;
            target->prev = sec_target;
            target->next = target_next;

            target_next->prev = target;
            m_head = sec_target;
        }//End
        else if (current->next == m_tail) {
            //Set
            target_prev = current->prev;
            target = current;
            sec_target = target->next;

            //Swap
            target_prev->next = sec_target;
            sec_target->next = target;
            target->next = nullptr;

            sec_target->prev = target_prev;
            target->prev = sec_target;

            m_tail = target;
            return true;
        }//Mid
        else {
            //Set
            target_prev = current->prev;
            target = current;
            sec_target = target->next;
            target_next = sec_target->next;

            //Swap
            target_prev->next = sec_target;
            target->next = target_next;
            sec_target->next = target;

            target->prev = sec_target;
            sec_target->prev = target_prev;
            target_next->prev = target;
        }
    }

}


/*if (index < 0 || index > m_length - 1) {
    std::cout << "Ungültiger Index!" << std::endl;
    return false;
}*/
//List with two nodes
//if (m_head->next->next == nullptr) {

//    
//    NodeD* temp = m_head;
//    NodeD* seconde = m_head->next;
//    

//    temp->next = nullptr;
//    temp->prev = seconde;
//    
//    seconde->prev = nullptr;
//    seconde->next = temp;

//    m_tail = temp;
//    m_head = seconde;

//}
//else {
//    NodeD* temp = m_head;

//    for (int i = 0; i < index-1; i++)
//    {
//        if (temp->next != nullptr) {
//            temp = temp->next;
//        }
//        else {
//            cout << "Out of bound" << endl;
//        }
//	}
// if (index == 1) {

//	NodeD* second = temp->next;
//	NodeD* third = second->next;
//	NodeD* fourth = third->next;

//	temp->next = third;
//	second->next = fourth;
//	third->next = second;

//	second->prev = third;
//	third->prev = temp;
//	fourth->prev = second;

//	m_head = temp;
//}
//    Swap on Beginning 
//     if(temp == m_head){
//        NodeD* first = m_head;
//        NodeD* second = m_head->next;
//        NodeD* third = m_head->next->next;

//        first->next = third;
//        first->prev = second;

//        second->prev = nullptr;
//        second->next = first;

//        third->prev = first;

//        m_head = second;

//    }// Swap on End
//    else if (temp->next == m_tail) {
//        NodeD* first = m_tail;
//        NodeD* second = m_tail->prev;
//        NodeD* third = m_tail->prev->prev;

//        first->next = second;
//        first->prev = third;

//        second->prev = first;
//        second->next = nullptr;
//        third->next = first;

//        m_tail = second;

//    }//Swap in the middle
//    else{
//        NodeD* second = temp->next;
//        NodeD* third = temp->next->next;
//	    NodeD* fourth = temp->next->next->next;

//        second->next = third->next;
//        second->prev = third;

//        third->next = second;
//        third->prev = temp;

//        temp->next = third;
//    
//        fourth->prev = second;
//        return true;
//    }
//}










/* if (index < 1 || index >= m_length) {
       std::cout << "Ungültiger Index!" << std::endl;
       return false;
   }

   NodeD* current = m_head;
   int i = 1;

   while (i < index && current != nullptr) {
       current = current->next;
       i++;
   }

   if (current == nullptr) {
       std::cout << "Ungültiger Index!" << std::endl;
       return false;
   }

   NodeD* first = current;
   NodeD* second = current->next;
   NodeD* third = second->next;

   if (third == nullptr) {
       std::cout << "Knoten an der Stelle " << index << " ist der letzte Knoten in der Liste!" << std::endl;
       return false;
   }

   first->next = third;
   second->prev = nullptr;
   second->next = third->next;
   third->prev = first;
   third->next = first;
   first->prev = third;

   if (first == m_head) {
       m_head = second;
   }

   if (third == m_tail) {
       m_tail = first;
   }

   std::cout << "Elemente an Position " << index << " und " << index + 1 << " erfolgreich getauscht!" << std::endl;
   return true;*/