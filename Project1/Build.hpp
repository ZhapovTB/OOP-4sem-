#pragma once 
#ifndef BUILD_HPP
#define BUILD_HPP
#include <iostream>
#include <stdlib.h>
#include <string>
class Test {
public:
    // Шаблонный метод Тестов числа 

    bool Proverka(std::string object)
    {
        obj = object;
        if (this->vvod()) {
            if (this->conditions()) {
                if (this->mainTest()) {
                    return 1;
                }
                else { return 0; }
            }
            else return 0;
        }
        else return 0;
    }

    void showError() {
        std::cout << error;
    }
    void test() {}
protected:
    std::string  obj;
    std::string error;
    virtual bool vvod() = 0; // Проверка на правильные входные данные
    virtual bool conditions() = 0; // Проверка произвольных условий
    virtual bool mainTest() = 0; // Необходимая нам проверка
 
    
};

class IsdigitSimple : public Test //Является ли число простое
{
    bool vvod() override {
        int size = obj.size();
        if (obj[0] == '-' || isdigit(obj[0])) {
            for (int i = 1; i < obj.size(); i++)

                if (!isdigit(obj[i]))
                {
                    error = "IsNotNumber";
                    return false;
                }

            digit = std::stoi(obj, nullptr, 10);
            return 1;
        }
        else {
            error = "IsNotNumber";
            return false;
        }
    }
    bool conditions() {
        if (digit > 0) return 1;
        else { error = "digit<=0"; return 0; }
    }
    bool mainTest(){
        int k=0;
        for (int i = 1; i <= digit;i++) {
            if (digit % i == 0) k++;
       }
        if (k == 2) {
            return 1;
        }
        else { error = "IsNotSimple"; return 0; }


    }
private:
    int digit;
};



class IsdigitEven : public Test //Является ли число четным
{
    bool vvod() override {
        int size = obj.size();
        if (obj[0] == '-' || isdigit(obj[0])) {
            for (int i = 1; i < obj.size(); i++)

                if (!isdigit(obj[i]))
                {
                    error = "IsNotNumber";
                    return false;
                }
           
            digit = std::stoi(obj, nullptr, 10); 
            return 1;
        }
        else{
            error = "IsNotNumber";
            return false;
        }
    }
   
    bool conditions() {
        if (digit > 0) return 1;
        else { error = "digit<=0"; return 0; }
    }

    bool mainTest() {
        if (digit % 2 == 0) return 1;
        else { error = "IsNotEven"; return 0; }
    }

private:
    int digit;

};



















#endif 