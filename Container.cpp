#include <iostream>
#include "Person.h"
#include "stringTest.h"
#include "vectorTest.h"
#include "listTest.h"
#include "setTest.h"
#include "mapTest.h"
#include "AlgorithmTest.h"
void containerTest()
{
    // 基本数据类型
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    // 第一种遍历，iterator返回的是类似指针的东西
    std::vector<int>::iterator b = v.begin();
    std::vector<int>::iterator e = v.end();
    while (b != e)
    {
        std::cout << *b << std::endl;
        b++;
    }

    std::vector<int> v1 = {1, 2, 3, 4, 5};
    // 第二种遍历
    for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        std::cout << *it << "";
    }

    // 第三种遍历
    for (auto it = v1.begin(); it != v1.end(); it++)
    {
        std::cout << *it << "";
    }
    std::cout << std::endl;

    // 自定义数据类型
    std::vector<Person> v2 = {{"tom", 12}, {"jerry", 11}, {"mike", 10}};
    for (std::vector<Person>::iterator it = v2.begin(); it != v2.end(); it++)
    {
        std::cout << "姓名：" << it->m_name << " 年龄：" << it->m_age << std::endl;
    }

    // 指针类型
    Person p1("tom1", 121);
    Person p2("jerry1", 111);
    Person p3("mike1", 101);
    std::vector<Person *> v3 = {&p1, &p2, &p3};
    for (std::vector<Person *>::iterator it = v3.begin(); it != v3.end(); it++)
    {
        // 指针的指针
        Person *p = *it;
        std::cout << "姓名：" << p->m_name << " 年龄：" << (*it)->m_age << std::endl; // 要加括号，->优先级大于*
    }

    // vector嵌套
    std::vector<std::vector<int>> vc;

    std::vector<int> v11 = {1, 2, 3};
    std::vector<int> v21 = {4, 5, 6};
    std::vector<int> v31 = {7, 8, 9};
    vc.push_back(v11);
    vc.push_back(v21);
    vc.push_back(v31);

    for (std::vector<std::vector<int>>::iterator it = vc.begin(); it != vc.end(); it++)
    {
        std::vector<int> vv = *it;
        for (std::vector<int>::iterator vit = vv.begin(); vit != vv.end(); vit++)
        {
            std::cout << *vit << " ";
        }
        std::cout << std::endl;
    }

    for (auto it = vc.begin(); it != vc.end(); it++)
    {
        auto vv = *it;
        for (auto vit = vv.begin(); vit != vv.end(); vit++)
        {
            std::cout << *vit << " ";
        }
        std::cout << std::endl;
    }
}
int main()
{
    // containerTest();
    // stringTest();
    // vectorTest();
    // listTest();
    // setTest();
    // mapTest();
    algorithmTest();
}