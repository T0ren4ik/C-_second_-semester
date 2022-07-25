#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


template <typename T>
class Stack
{
private:
    T* stackPtr; // указатель на стек
    int size; // размер стека
    int Top; // вершина стека
public:
    // по умолчанию размер стека равен 10 элементам
    Stack(int maxSize = 10) :
        size(maxSize) // инициализаци€ константы
    {
        stackPtr = new T[size]; // выделить пам€ть под стек
        Top = 0; // инициализируем текущий элемент нулем;
    };

    // конструктор копировани€
    Stack(const Stack<T>& other) : size(other.size) {
        stackPtr = new T[other.size];

        Top = other.getPtr();
        for (int i = 0; i < Top; i++)
        {
            stackPtr[i] = other.getPtr()[i];
        }
    }; 

    // деструктор
    ~Stack() {
        delete[] stackPtr;
    }

    // поместить элемент в вершину стека
    inline void push(const T& value)
    {
        if (isFull()) throw - 1;

        stackPtr[Top++] = value;
    }    

    // удалить элемент из вершины стека и вернуть его
    inline T pop()
    {
        if (isEmpty()) throw - 1;
        T x = stackPtr[--Top];
        return x;
    }               

    // вывод стека на экран
    inline void printStack()
    {
        for (int ix = Top - 1; ix >= 0; ix--)
            cout << "|" << setw(4) << stackPtr[ix] << setw(4) << "|" << endl;
    }        

    // n-й элемент от вершины стека
    inline const T& Peek(int nom) const
    {
        if (nom > size || nom > Top) throw - 1;

        return stackPtr[Top - nom]; // вернуть n-й элемент стека
    } 

    // 0 элемент от вершины стека
    inline const T& top() const
    {
        return stackPtr[Top-1]; 
    }

    // получить размер стека
    inline int getStackSize() const
    {
        return size;
    } 

    // получить указатель на стек
    inline T* getPtr() const
    {
        return stackPtr;
    }         

    // получить номер текущего элемента в стеке
    inline int getTop() const
    {
        return Top;
    }        

    //true, если стек пустой
    inline bool isEmpty() const
    { 
        return (Top == 0);
    }

    //true, если стек полон
    inline bool isFull() const
    { 
        return (Top == size);
    }
};



class C2PPN {
private:
    char curc;
    string& str_in, str_out;
    int iin;

    char nextChar();
    bool isDigit(char c);
    int prior(char c);

public:
    C2PPN() = default;
    inline C2PPN(string& s) : str_in(s), iin(0), curc(s[0]) {}
    inline C2PPN(C2PPN&) = delete;
    inline C2PPN& operator = (const C2PPN&) = delete;
    void convert(); 
    inline string& get_str_out(){
        return str_out;
    }
};



// ѕроверить растановку скобок
bool balanced(const string& s);
void test_balanced(const string& s);

// ѕосчитать полиз
int calculate(string&);