#pragma once
#include <iostream>
#include <set>
// 函数对象（仿函数）
class Compare
{
public:
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};
class ComparePerson
{
public:
    bool operator()(const Person &p1, const Person &p2) const
    {
        return p1.m_age < p2.m_age;
    }
};
void setTest()
{
    // 二叉树,自动排序
    // set不允许重复元素，multiset允许重复元素
    std::set<int> s;

    // 插入
    s.insert(10);
    s.insert(30);
    s.insert(20);
    s.insert(20);
    s.insert(40);

    // 删除
    s.erase(30);

    for (std::set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 查找和统计
    std::set<int>::iterator pos = s.find(20);
    if (pos != s.end())
    {
        std::cout << *pos << std::endl;
    }
    else
    {
        std::cout << "未找到";
    }

    int num = s.count(20);
    std::cout << num << std::endl;

    // 对组
    std::pair<std::string, int> p = std::make_pair("tom", 12);
    std::cout << p.first << p.second << std::endl;

    std::pair<std::set<int>::iterator, bool> ret = s.insert(10);
    if (ret.second)
    {
        std::cout << "插入成功" << std::endl;
    }
    else
    {
        std::cout << "插入失败" << std::endl;
    }

    // 排序,普通数据类型
    // 要在插之前排序，利用仿函数指定规则
    std::set<int, Compare> s1;

    s1.insert(90);
    s1.insert(40);
    s1.insert(20);
    s1.insert(50);
    s1.insert(10);

    for (std::set<int, Compare>::iterator it = s1.begin(); it != s1.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    // 排序,自定义数据类型
    Person p1 = {"tom", 12};
    Person p2 = {"jerry", 13};
    Person p3 = {"mike", 11};
    Person p4 = {"mike", 11};

    std::set<Person, ComparePerson> s2;

    s2.insert(p1);
    s2.insert(p2);
    s2.insert(p3);
    s2.insert(p4);

    for (std::set<Person, ComparePerson>::iterator it = s2.begin(); it != s2.end(); it++)
    {
        std::cout << it->m_name << it->m_age << std::endl;
    }
}