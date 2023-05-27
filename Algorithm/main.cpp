#include "LinkedList.h"
#include "LinkedListDouble.h"
#include "StandardList.h"
#include "infix.h"
#include "Deque.h"
#include <iostream>
#include "Stack.h"

using namespace std;



int main() {

	////ListE m;
	////m.add(1);
	////m.add(2);
	////m.add(3);
	////m.add(4);
	////m.add(5);
	//////m.add(4);
	//////m.add(5);
	//////m.add(6);
	//////m.add(7);
	//////m.swap(1);
	////m.print_reversed();



	///*ListD m;
	//m.add(1);
	//m.add(2);
	//m.add(3);
	//m.add(4);

	//m.swap(1);
	//m.print();*/
	////std::cout << "Testing Beginning\n";
	///*m.add(1);
	//m.add(2);

	//m.swap(1);
	//m.print();*/
	///*m.add(1);
	//m.add(2);
	//m.add(3);
	//m.add(4);
	//m.add(5);
	//std::cout << "[1, 2, 3, 4, 5] : "; m.print();

	//m.swap(0);
	//std::cout << "[2, 1, 3, 4, 5] : "; m.print();
	//m.swap(0);

	//std::cout << "Testing Middle\n";
	//m.swap(3);
	//std::cout << "[1, 3, 2, 4, 5] : "; m.print();
	//m.swap(3);


	//std::cout << "Testing End\n";
	//m.swap(4);
	//std::cout << "[1, 2, 3, 5, 4] : "; m.print();

	//std::cout << "Test ended";
	//*/




	///*std::list<int> l1 = { 10, 11, 13, 15, 18, 20, 21 };
	//std::list<int> l2 = { 4, 8, 10, 12, 14, 15, 18, 23 };

	//printList(union_of_lists(l1, l2));*/

	//cout << endl << "Deque " << endl << endl;

	///*Deque w;
	//w.push_front(1);
	//w.push_front(2);
	//w.push_front(3);
	//w.push_back(4);
	//w.push_back(5);
	//w.pop_back();
	//w.pop_back();
	//w.pop_back();
	//w.pop_back();
	//w.pop_back();
	//w.print_all();*/


	//DoubleStack h(1, 5);
	//h.push0(4);
	//h.push0(6);
	//h.push0(3);
	//h.push0(6);
	//h.push0(3);
	//h.push0(6);
	//h.push0(3);
	//h.push1(4);
	//h.push1(5);
	//h.push1(5);
	//h.push1(5);
	//h.push1(5);
	//h.print(1);



	cout << "T A S C H E N R E C H N E R" << endl << endl;


	//Aufgabe 6

	std::string input = "(4+3662.1*3)+(4-1)";
	int i = 6;

	std::cout << "Testing extract_num with input: " << input << " on Position: " << i << std::endl;
	std::cout << extract_num(input, i) << std::endl << std::endl;

	std::cout << "Testing test_infix_brackets with input: " << input << std::endl;
	std::cout << test_infix_brackets(input) << std::endl << std::endl;

	input = "(4+3) * (2-2)";
	std::cout << "Testing infix_to_postfix\n";
	std::cout << infix_to_postfix(input) << std::endl << std::endl;

	std::cout << "Testing calculate_postfix\n";
	std::string input_postfix = infix_to_postfix(input);
	double result = calculate_postfix(input_postfix);

	std::cout << "Infix: " << input << std::endl;
	std::cout << "Postfix: " << input_postfix << std::endl;
	std::cout << "_______________________________\n\n";
	std::cout << "Ergebnis: " << result << std::endl;


	system("PAUSE");

}