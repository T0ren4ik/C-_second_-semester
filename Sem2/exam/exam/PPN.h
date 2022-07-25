#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


template <typename T>
class Stack
{
private:
    T* stackPtr; // ��������� �� ����
    int size; // ������ �����
    int Top; // ������� �����
public:
    // �� ��������� ������ ����� ����� 10 ���������
    Stack(int maxSize = 10) :
        size(maxSize) // ������������� ���������
    {
        stackPtr = new T[size]; // �������� ������ ��� ����
        Top = 0; // �������������� ������� ������� �����;
    };

    // ����������� �����������
    Stack(const Stack<T>& other) : size(other.size) {
        stackPtr = new T[other.size];

        Top = other.getPtr();
        for (int i = 0; i < Top; i++)
        {
            stackPtr[i] = other.getPtr()[i];
        }
    }; 

    // ����������
    ~Stack() {
        delete[] stackPtr;
    }

    // ��������� ������� � ������� �����
    inline void push(const T& value)
    {
        if (isFull()) throw - 1;

        stackPtr[Top++] = value;
    }    

    // ������� ������� �� ������� ����� � ������� ���
    inline T pop()
    {
        if (isEmpty()) throw - 1;
        T x = stackPtr[--Top];
        return x;
    }               

    // ����� ����� �� �����
    inline void printStack()
    {
        for (int ix = Top - 1; ix >= 0; ix--)
            cout << "|" << setw(4) << stackPtr[ix] << setw(4) << "|" << endl;
    }        

    // n-� ������� �� ������� �����
    inline const T& Peek(int nom) const
    {
        if (nom > size || nom > Top) throw - 1;

        return stackPtr[Top - nom]; // ������� n-� ������� �����
    } 

    // 0 ������� �� ������� �����
    inline const T& top() const
    {
        return stackPtr[Top-1]; 
    }

    // �������� ������ �����
    inline int getStackSize() const
    {
        return size;
    } 

    // �������� ��������� �� ����
    inline T* getPtr() const
    {
        return stackPtr;
    }         

    // �������� ����� �������� �������� � �����
    inline int getTop() const
    {
        return Top;
    }        

    //true, ���� ���� ������
    inline bool isEmpty() const
    { 
        return (Top == 0);
    }

    //true, ���� ���� �����
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



// ��������� ���������� ������
bool balanced(const string& s);
void test_balanced(const string& s);

// ��������� �����
int calculate(string&);