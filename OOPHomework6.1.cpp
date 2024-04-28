#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkBrackets(const string& str)
{
    stack<char> s;

    for (char c : str) 
    {
        switch (c) 
        {
        case '(':
        case '{':
        case '[':
            s.push(c);
            break;
        case ')':
            if (s.empty() || s.top() != '(') 
            {
                return false;
            }
            s.pop();
            break;
        case '}':
            if (s.empty() || s.top() != '{')
            {
                return false;
            }
            s.pop();
            break;
        case ']':
            if (s.empty() || s.top() != '[') 
            {
                return false;
            }
            s.pop();
            break;
        default:
            break;
        }
    }

    return s.empty();
}

int main()
{
    string str;
    cout << "Enter String: ";
    getline(cin, str);

    if (checkBrackets(str)) 
    {
        cout << "String true" << endl;
    }
    else 
    {
        cout << "String false " << str << endl;
    }
}