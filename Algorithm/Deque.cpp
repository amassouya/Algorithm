#include "Deque.h"
#include <iostream>
using namespace std;
void Deque::push_front(const int& item)
{
	NodeD* neu = new NodeD;
	NodeD* temp = m_head;
	if (m_head != nullptr) {
		neu->next = temp;
		neu->prev = nullptr;
		neu->item = item;

		temp->prev = neu;

		if (temp == m_head) {
			m_head = neu;
		}
		if (temp->next == nullptr) {
			m_tail = temp;

		}
		while (temp->next != nullptr)
		{
			temp = temp->next;
			if (temp->next == nullptr) {
				m_tail = temp;
			}
		}

	}
	else {

		neu->item = item;
		neu->prev = nullptr;
		neu->next = nullptr;
		m_head = neu;

	}

}

int Deque::pop_front()
{
	NodeD* temp = m_head;

	if (m_head->next != nullptr) {
		NodeD* second = temp->next;

		temp->next = nullptr;

		second->prev = nullptr;

		if (temp = m_head) {
			m_head = second;
		}
		delete temp;

		return 1;

	}
	else {
		delete temp;

	}


}

void Deque::push_back(const int& item)
{
	NodeD* temp = new NodeD;
	NodeD* beforeTail = m_tail;



	temp->item = item;
	temp->next = nullptr;
	temp->prev = beforeTail;
	cout << beforeTail->item << endl;
	beforeTail->next = temp;

	if (beforeTail == m_tail) {
		m_tail = temp;
	}

}

int Deque::pop_back()
{
	if (m_head != nullptr) {

		if (m_tail->prev == nullptr) {
			m_tail == m_head;
		}
		NodeD* temp = m_tail;
		NodeD* second = temp->prev;


		temp->prev = nullptr;

		second->next = nullptr;

		if (temp == m_tail) {
			m_tail = second;

		}

	}
	else
	{
		cout << "Deque ist Leer" << endl;
	}

	return 0;
}

void Deque::print_all() const
{
	NodeD* temp = m_head;


	while (temp != nullptr) {

		cout << temp->item << " , ";
		temp = temp->next;

	}

}
