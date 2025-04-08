#pragma once
#include <iostream>
#include <map>
class mapCompare{
    public:
    bool operator()(int v1,int v2) const {
        return v1 > v2;
    }
};
void mapTest()
{
    // 二叉树
    // map不允许有重复key值，multimap允许
    std::map<int, int> m;

    m.insert({1, 10});
    m.insert(std::make_pair(2, 20));
    m.insert(std::pair<int, int>(3, 30));

    for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        std::cout << "key:" << it->first << " value:" << it->second << std::endl;
    }

    //排序
    std::map<int, Person,mapCompare> m1;
    Person p1 = {"tom", 12};
    Person p2 = {"jerry", 13};
    Person p3 = {"mike", 11};
    Person p4 = {"mike", 11};
    m1.insert({1, p1});
    m1.insert({3, p3});
    m1.insert({4, p4});
    m1.insert({2, p2});
    for (std::map<int, Person,mapCompare>::iterator it = m1.begin(); it != m1.end(); it++)
    {
        std::cout << "key:" << it->first << " value:" << " age:"<<it->second.m_age <<" name:"<< it->second.m_name << std::endl;
    }
}