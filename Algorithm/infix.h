#pragma once
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>


// Algorithmus zum extrahieren einer Zahl aus einem String
std::string extract_num(const std::string& input, const int& start_index) {
    {
        std::string number = "";
        std::string number2 = "";
        bool has_decimal_point = false;

        for (int i = start_index; i < input.size(); i++) {
            const char& c = input[i];
            //Checks wether c is a decimal digit character
            //If c is a number, add it to the string: number
            if (isdigit(c))number += c;
            //Float 
            //Selbst geaddet
            else if (c == '.') {
                number = "";
                if (has_decimal_point) break;
                else {
                    has_decimal_point = true;
                    int j = 1;
                    while (j != start_index) {
                        if (isdigit(input[i - j])) {
                            number2 += input[i - j];
                            j++;
                        }
                        else if (!isdigit(input[i - j])) {
                            break;
                        }
                    }
                    //String nee to get reversed, because it saves the numbers from rigtht to left (using reverse from <algorithm>
                    std::reverse(number2.begin(), number2.end());
                    number += number2;
                    number += c;
                }
            }
            else break;
        }
        return number;
    }
}

//Algorithmus zum testen einer korrekten Infixnotations Klammerung
bool test_infix_brackets(std::string input) {
    // Ihre Loesung hier:
    int open_brackets = 0;
    //Run througth the string
    for (char& c : input) {
        if (c == '(') open_brackets++;
        else if (c == ')') open_brackets--;
    }
    return open_brackets == 0;
}

// Algorithmus zur Umwandlung einer Infix-Notation in eine Postfix-Notation
std::string infix_to_postfix(const std::string& input) {
    // Ihre Loesung hier:
    std::stack<char> operators;
    std::stringstream term;

    // Iteriere durch die Infix-Notation
    for (int i = 0; i < input.size(); i++) {
        const char& c = input[i];

        // Verarbeiten des chars
        if (c == ' ' or c == '(') continue;
        else if (c == ')') {
            // Eine Klammer zu schließt fuegt alle Operatoren an
            while (!operators.empty()) {
                term << operators.top() << " ";
                operators.pop();
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') operators.push(c);
        else if (isdigit(c)) {
            std::string number = extract_num(input, i);
            term << number << " ";  // Zahl direkt ausgeben
            i += number.size() - 1;  // index entsprechend der Groeße von der Zahl verschieben 
        }
        else {
            throw std::invalid_argument("Die Infixnotation '" + input + "', hat am Index "
                + std::to_string(i) + " ein ungueltiges Zeichen.");
        }
    }

    // restliche Operatoren anfuegen
    while (!operators.empty()) {
        term << operators.top() << " ";
        operators.pop();
    }

    // Rueckgabe der fertigen Postfix Notation als String
    return term.str();
}


double calculate_postfix(const std::string& input) {
    // Ihre Loesung hier
    std::stack<double> numbers;

    for (int i = 0; i < input.size(); i++) {
        const char& c = input[i];

        if (c == ' ') continue;
        else if (isdigit(c))  // 1. Fall
        {
            std::string number = extract_num(input, i);
            numbers.push(std::stod(number));
            i += number.size() - 1;
        }
        else  // 2. Fall
        {
            double num1 = numbers.top();
            numbers.pop();
            double num0 = numbers.top();
            numbers.pop();
            if (c == '+') numbers.push(num0 + num1);
            if (c == '-') numbers.push(num0 - num1);
            if (c == '*') numbers.push(num0 * num1);
            if (c == '/') numbers.push(num0 / num1);
        }
    }
    return numbers.top();
}