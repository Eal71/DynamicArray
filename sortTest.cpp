#include <iostream>
#include <list>
#include <algorithm>
class Person
{
public:
    Person(std::string name, int age, int height)
    {
        m_name = name;
        m_age = age;
        m_height = height;
    }
    std::string m_name;
    int m_age;
    int m_height;
};
void listPrint(std::list<Person> &l)
{
    for (std::list<Person>::iterator it = l.begin(); it != l.end(); it++)
    {
        std::cout << "姓名：" << it->m_name << "年龄：" << it->m_age << "身高：" << it->m_height << std::endl;
    }
}
bool compare(Person &p1,Person &p2){
    if(p1.m_age == p2.m_age){
        return p1.m_height > p2.m_height;
    }
    else{
        return p1.m_age < p2.m_age;
    }
}
int main()
{
    std::list<Person> l;
    Person p1 = {"tom", 12, 168};
    Person p2 = {"jerry", 13, 161};
    Person p3 = {"mike", 11, 178};
    Person p4 = {"mike", 11, 179};
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    listPrint(l);
    std::cout << "-----------------------------------------------" << std::endl;;
    l.sort(compare);
    listPrint(l);
}