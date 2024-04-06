#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;
int evaluateExpression(string expression);
// ����ָ����Χ�ڵ��������
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// ����һ�꼶�ļӷ����������ʽ
string generateFirstGradeExpression() {
    int num1, num2, result;
    char op;
    do {
        num1 = generateRandomNumber(1, 20);
        num2 = generateRandomNumber(1, 20);
        op = (rand() % 2 == 0) ? '+' : '-';
        result = (op == '+') ? num1 + num2 : num1 - num2;
    } while (result < 0 || result > 20); // �����������������������
    return to_string(num1) + " " + op + " " + to_string(num2);
}

// ���ɶ��꼶�ļӷ��������������ʽ
string generateSecondGradeExpression() {
    int num1, num2, result;
    char op;
    do {
        num1 = generateRandomNumber(1, 50);
        num2 = generateRandomNumber(1, 50);
        op = (rand() % 2 == 0) ? '+' : '-';
        result = (op == '+') ? num1 + num2 : num1 - num2;
    } while (result < 0 || result > 50); // �����������������������
    return to_string(num1) + " " + op + " " + to_string(num2);
}

// �������꼶�ļӷ����������˷��������ʽ
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
    } while (result < 0 || result > 1000000000); // �����������������������
    return to_string(num1) + " " + op + " " + to_string(num2);
}

// �����ĵ����꼶�Ļ������ʽ
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
        if (result < 0) { // ������Ϊ�������������ɱ��ʽ
            num1 = generateRandomNumber(1, 10000);
            num2 = generateRandomNumber(1, 10000);
            num3 = generateRandomNumber(1, 10000);
            op1 = "+-*/"[rand() % 4];
            op2 = "+-*/"[rand() % 4];
        }
    } while (result < 0); // �����������������������
    return "(" + to_string(num1) + " " + op1 + " " + to_string(num2) + ") " + op2 + " " + to_string(num3);
}

// ������ʽ�Ľ��
int evaluateExpression(string expression) {
    int result=0;
    try {
        result = stoi(expression);
    }
    catch (...) { // ������ʽ�޷�ת��Ϊ������˵���Ǵ���������ı��ʽ
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

// �����꼶����ָ����������Ŀ
string generateExercises(int grade, int count) {
    srand(time(0)); // ��ʼ���������
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
    cout << "�������꼶(1-6): ";
    cin >> grade;
    cout << "��������Ŀ����: ";
    cin >> count;
    generateExercises(grade, count);
    return 0;
}
