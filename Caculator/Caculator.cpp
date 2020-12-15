/*实现计算器*/
#include <iostream>
#include <cmath>
#include <stack>
#include <algorithm>
#include <stdexcept>
#include <string>

using namespace std;

/*返回运算符的优先级,值越大,优先级越高*/
inline size_t precedence(const char r) {
    if (r == '+' || r == '-')
        return 1;
    if (r == '*' || r == '/')
        return 2;
    if (r == '^')
        return 3;
    throw runtime_error{ string{"表达式中存在无效的运算符"} + r };
}

/*实现计算*/
double execute(stack<char>& str, stack<double>& operands) {
    /*存储结果*/
    double ans{};
    double right = operands.top();/*右操作数*/
    operands.pop();
    double left{ operands.top() };/*左操作数*/
    operands.pop();
    switch (str.top()) {
    case '+':
        ans = left + right;
        break;
    case '-':
        ans = left - right;
        break;
    case '*':
        ans = left * right;
        break;
    case '/':
        ans = left / right;
        break;
    case '^':
        ans = pow(left, right);
        break;
    default:
        throw runtime_error{ string{"无效的操作数"} + str.top() };
    }
    str.pop();
    operands.push(ans);/*结果入栈*/
    return ans;
}

int main(int argc, char* argv[]) {
    stack<double> operands;/*表达式的数值*/
    stack<char> operators;/*表达式的运算符*/
    string str;
    try {
        while (true) {
            cout << "请输入表达式(按Enter键结束)" << endl;
            getline(cin, str, '\n');
            if (str.empty())
                break;
            /*剔除无效的空格*/
            str.erase(remove(begin(str), end(str), ' '), end(str));/*remove并不是删除,而是将所有的删除元素放到后面,返回的迭代器指向第一个删除的元素*/

            size_t index{};/*初始化,index保存str中第一个非数值字符的下标,这样保证入栈的正是运算符类型的*/
            operands.push(stod(str, &index));
            cout << index << endl;
            while (true) {
                operators.push(str[index++]);
                size_t i{};
                operands.push(stod(str.substr(index), &i));/*substr取后部分*/
                index += i;
                if (index == str.length()) {
                    while (!operators.empty())
                        execute(operators, operands);
                    break;
                }
                /*判断优先级*/
                while (!operators.empty() && precedence(str[index]) <= precedence(operators.top()))
                    execute(operators, operands);
            }
            cout << "Result=" << operands.top() << endl;
        }

    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    cout << "计算结束" << endl;
    return 0;
}