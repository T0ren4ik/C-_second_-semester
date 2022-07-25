#include "PPN.h"

bool balanced(const string& s) {
    Stack<char> stack;
    for (char c : s) {
        switch (c) {

        case '(': stack.push(')'); break;
        case '[': stack.push(']'); break;
        case '{': stack.push('}'); break;
        case '<': stack.push('>'); break;

        case ')':
        case ']':
        case '}':
        case '>':
            if (stack.isEmpty() || stack.Peek(1) != c) {
                return false;
            }
            stack.pop();
            break;
        default:
            break;
        }
    }
    return stack.isEmpty();
}

void test_balanced(const string& s) {
    std::cout << '"' << s << "\" " << (balanced(s) ? "yes" : "no") << '\n';
}


char C2PPN::nextChar()
{
    if (iin < (size(str_in)+1)) {
        return curc = str_in[iin++];
    }
    else return curc='\n';
}

bool C2PPN::isDigit(char c)
{
    return (c >= '0' && c<= '9')||(c>='a' && c<= 'z') || c=='.';
}

int C2PPN::prior(char c)
{
    switch (c) {
        case('*'): case('/'): return 3;
        case('+'): case('-'): return 2;
        case('('): return 1;
        default: return 0;
    }
}

void C2PPN::convert()
{
    Stack<char> stack;
    str_out = "";

    while (nextChar() != '\0') {
        //cout << curc << "|" << iin << "|" << str_out << endl;
        if (isDigit(curc)) {
            str_out += curc;
            continue;
        }
        else  str_out += ' ';

        switch (curc)
        {
        case('('):
            stack.push(curc);
            break;
        case '*': case '/': case '+': case '-':
            if (iin == size(str_in))
                throw (str_in+" Syntax error");
            else {
                while (prior(curc) <= prior(stack.top())) {
                    str_out += stack.pop();
                }
                if (prior(curc) > prior(stack.top())) {
                    stack.push(curc);
                }
                break;
            }
        case ')':
            while ((curc = stack.pop()) != '(') {
                str_out += curc;
            }
            break;

        default:
            throw (str_in +" Error: invalid symbol in the string");
        }
    }
    while (stack.getTop()) {
        str_out += ' ';
        str_out += stack.pop();
        str_out += ' ';
    }
}


int calculate(string& s)
{
    Stack<int> stack; //стек
    int n1, n2, res = 0, i;
    for (i = 0; i < s.length(); ++i) {
        //Добавлю settop, флаг и если встречаю цефру после цифры буду менять значение топ символа
        if (s[i] >= '0' && s[i] <= '9') {
            stack.push(static_cast<int>(s[i]) - 48);
        }
        else if (s[i] == ' ') continue;
        else {
            n2 = stack.pop();
            n1 = stack.pop();
            //cout << n1 << s[i] << n2 << endl;
            switch (s[i]) {
            case '+': res = n1 + n2; break;
            case '-': res = n1 - n2; break;
            case '*': res = n1 * n2; break;
            case '/': res = n1 / n2; break;
            default: cout << "Ошибка !\n";
            }
            stack.push(res);
        }
    }
    return stack.pop();
}

