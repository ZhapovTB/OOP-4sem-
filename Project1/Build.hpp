#pragma once 
#ifndef BUILD_HPP
#define BUILD_HPP
#include <iostream>

class Builder
{
public:
    // Шаблонный метод (Халтура) Дописать

    void build()
    {
        this->test();
        this->lint();
        this->assemble();
        this->deploy();
    }
protected:
    virtual void test() = 0;
    virtual void lint() = 0;
    virtual void assemble() = 0;
    virtual void deploy() = 0;

};

class AndroidBuilder : public Builder
{
    void test() override
    {
        std::cout << "Running android tests" << std::endl;
    }

    void lint() override
    {
        std::cout << "Linting the android code" << std::endl;
    }

    void assemble() override
    {
        std::cout << "Assembling the android build" << std::endl;
    }

    void deploy() override
    {
        std::cout << "Deploying android build to server" << std::endl;
    }
};

class IosBuilder : public Builder
{
    void test() override
    {
        std::cout << "Running ios tests"<< std::endl;
    }

    void lint() override
    {
        std::cout << "Linting the ios code" << std::endl;
    }

    void assemble() override
    {
        std::cout << "Assembling the ios build" << std::endl;
    }

    void deploy() override
    {
        std::cout << "Deploying ios build to server" << std::endl;
    }
};



















#endif 