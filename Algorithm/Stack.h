class DoubleStack
{
public:
    // Ihr(e) Konstruktor(en) hier:  
  /*  DoubleStack() {
        this->m_array = new int[0];
        this->m_allocation_size = 0;
        this->m_size = 0;
        this->m_i_stack0 = -1;
        this->m_i_stack1 = 0;

    }*/
    DoubleStack(int allocation, int m_size) {
        this->m_array = new int[m_size];
        this->m_allocation_size = allocation;
        this->m_size = m_size;
        this->m_i_stack0 = -1;
        this->m_i_stack1 = m_size;
    }
    // Ihr(e) Dekonstruktor(en) hier:
    // Destruktor
    ~DoubleStack()
    {
        delete[] m_array;
    }

    // Fuegt ein Element zu Stack 0 hinzu
    void push0(const int& item);
    // Fuegt ein Element zu Stack 1 hinzu
    void push1(const int& item);

    // Entfernt ein Element von Stack 0
    int pop0();
    // Entfernt ein Element von Stack 1
    int pop1();

    void print(int was);
    // Hier gehoert eigentlich ein Assignment (copy) Operator hin
    // (der wird aber fuer uebersichtlicheren Code weggelassen)
private:
    // Ihre Variablen hier:
    int* m_array;
    int m_allocation_size;  // Wie viel Speicher allokiert werden soll, 
    // bei einer vergroeﬂerung des Arrays
    int m_size; // Groeﬂe des Arrays
    int m_i_stack0;  // Index von Stack 0
    int m_i_stack1;  // Index von Stack 1

    // Interne Resize Methode um bei vollem Array mehr 
    // Speicher zu allokieren:
    void resize();
};