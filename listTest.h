#pragma once
#include <iostream>
#include <list>
void listPrint(std::list<int> &l, std::string notice)
{
    std::cout << notice << ": ";
    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
void listPrint(std::list<int> &l)
{
    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
bool compare(int &a, int &b)
{
    return a > b;
}
void listTest()
{
    // 双向循环链表
    std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    listPrint(l);

    // 后置运算符，还是原来的值
    l.insert(l.begin()++, 1000);
    listPrint(l);

    l.push_back(1000);
    l.push_back(1000);
    l.push_back(1000);
    listPrint(l);
    // 移除括号里所有的值
    l.remove(1000);
    listPrint(l);

    // 反转
    l.reverse();
    listPrint(l, "反转");

    // 排序，升序
    l.sort();
    listPrint(l, "升序");
    // 降序，放入一个布尔类型的自定义函数
    l.sort(compare);
    listPrint(l, "降序");
}