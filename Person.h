#pragma once
#include <iostream>
class Person
{
public:
    Person(std::string name, int age)
    {
        m_name = name;
        m_age = age;
    }
    std::string m_name;
    int m_age;
};