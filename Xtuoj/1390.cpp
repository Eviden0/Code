#include <iostream>
#include <stack>
#include <map>
#include <string>
std::string parseExpression(const std::string& expr) {
    std::stack<char> stack;
    std::string result;
    for (char c : expr) {
        if (c == ')') {
            std::string temp;
            while (!stack.empty() && stack.top() != '(') {
                temp = stack.top() + temp;
                stack.pop();
            }
            stack.pop(); // 移除左括号
            stack.push(temp[0]); // 将第一个字符推入栈中
            result += temp.substr(1); // 将剩余字符添加到结果字符串中
        } else if (c != '(') {
            stack.push(c);
        }
    }
    while (!stack.empty()) {
        result += stack.top();
        stack.pop();
    }
    return result;
}
std::map<char, int> countCharacters(const std::string& str) {
    std::map<char, int> counts;
    for (char c : str) {
        counts[c]++;
    }
    return counts;
}
int main() {
    std::string expr;
    std::cout << "请输入表达式：";
    std::getline(std::cin, expr);
    std::string str = parseExpression(expr);
    std::map<char, int> counts = countCharacters(str);
    std::cout << "字符统计结果：\n";
    for (const auto& pair : counts) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }
    return 0;
}