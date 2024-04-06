#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;
int evaluateExpression(string expression);
// 生成指定范围内的随机整数
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// 生成一年级的加法或减法运算式
string generateFirstGradeExpression() {
    int num1, num2, result;
    char op;
    do {
        num1 = generateRandomNumber(1, 20);
        num2 = generateRandomNumber(1, 20);
        op = (rand() % 2 == 0) ? '+' : '-';
        result = (op == '+') ? num1 + num2 : num1 - num2;
    } while (result < 0 || result > 20); // 结果不符合条件则重新生成
    return to_string(num1) + " " + op + " " + to_string(num2);
}

// 生成二年级的加法、减法混合运算式
string generateSecondGradeExpression() {
    int num1, num2, result;
    char op;
    do {
        num1 = generateRandomNumber(1, 50);
        num2 = generateRandomNumber(1, 50);
        op = (rand() % 2 == 0) ? '+' : '-';
        result = (op == '+') ? num1 + num2 : num1 - num2;
    } while (result < 0 || result > 50); // 结果不符合条件则重新生成
    return to_string(num1) + " " + op + " " + to_string(num2);
}

// 生成三年级的加法、减法、乘法混合运算式
string generateThirdGradeExpression() {
    int num1, num2, result;
    char op;
    do {
        num1 = generateRandomNumber(1, 1000);
        num2 = generateRandomNumber(1, 1000);
        int operation = generateRandomNumber(0, 2);
        if (operation == 0) {
            op = '+';
            result = num1 + num2;
        }
        else if (operation == 1) {
            op = '-';
            result = num1 - num2;
        }
        else {
            op = '*';
            result = num1 * num2;
        }
    } while (result < 0 || result > 1000000000); // 结果不符合条件则重新生成
    return to_string(num1) + " " + op + " " + to_string(num2);
}

// 生成四到六年级的混合运算式
string generateFourthToSixthGradeExpression() {
    int num1 = generateRandomNumber(1, 10000);
    int num2 = generateRandomNumber(1, 10000);
    int num3 = generateRandomNumber(1, 10000);
    char op1 = "+-*/"[rand() % 4];
    char op2 = "+-*/"[rand() % 4];
    int result;
    do {
        string expression = "(" + to_string(num1) + " " + op1 + " " + to_string(num2) + ") " + op2 + " " + to_string(num3);
        result = evaluateExpression(expression);
        if (result < 0) { // 如果结果为负数，重新生成表达式
            num1 = generateRandomNumber(1, 10000);
            num2 = generateRandomNumber(1, 10000);
            num3 = generateRandomNumber(1, 10000);
            op1 = "+-*/"[rand() % 4];
            op2 = "+-*/"[rand() % 4];
        }
    } while (result < 0); // 结果不符合条件则重新生成
    return "(" + to_string(num1) + " " + op1 + " " + to_string(num2) + ") " + op2 + " " + to_string(num3);
}

// 计算表达式的结果
int evaluateExpression(string expression) {
    int result=0;
    try {
        result = stoi(expression);
    }
    catch (...) { // 如果表达式无法转换为整数，说明是带有运算符的表达式
        char op;
        int num1, num2;
        stringstream ss(expression);
        ss >> num1 >> op >> num2;
        switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        }
    }
    return result;
}

// 根据年级生成指定数量的题目
string generateExercises(int grade, int count) {
    srand(time(0)); // 初始化随机种子
    string exercise;
    for (int i = 0; i < count; ++i) {
        
        switch (grade) {
        case 1:
            exercise = generateFirstGradeExpression();
            break;
        case 2:
            exercise = generateSecondGradeExpression();
            break;
        case 3:
            exercise = generateThirdGradeExpression();
            break;
        case 4:
        case 5:
        case 6:
            exercise = generateFourthToSixthGradeExpression();
            break;
        default:
            cout << "Invalid grade!" << endl;
            return exercise;
        }
        cout << exercise << " = ?" << endl;
    }
    return exercise;
}

int main() {
    int grade, count;
    cout << "请输入年级(1-6): ";
    cin >> grade;
    cout << "请输入题目数量: ";
    cin >> count;
    generateExercises(grade, count);
    return 0;
}
