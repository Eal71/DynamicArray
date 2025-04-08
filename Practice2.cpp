#include <iostream>
#include <vector>
#include <map>
#define CEHUA 0
#define MEISHU 1
#define YANFA 2
/*
公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作。
员工信息有：姓名、工资组成；部门分为：策划、美术、研发。
随机给10名员工分配部门和工资。
通过multimap进行信息的插入 key(部门编号) value(员工)
分部门显示员工信息
*/
class Person
{
public:
    Person(std::string name, int salary) : m_name(name), m_salary(salary) {}
    std::string m_name;
    int m_salary;
};
// 将员工放入vector
void createWorker(std::vector<Person> &v)
{
    std::string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < nameSeed.size(); i++)
    {
        std::string name = "员工";
        name += nameSeed[i];
        int salary = rand() % 10001 + 10000;
        Person p = {name, salary};
        v.push_back(p);
    }
}
// 设置部门
void setGroup(std::vector<Person> &v, std::multimap<int, Person> &m)
{
    for (std::vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        int dept = rand() % 3;
        m.insert({dept, *it});
    }
}
// 分组显示
void showGroup(std::multimap<int, Person> &m)
{
    std::cout << "--------------策划部---------------" << std::endl;
    for (std::multimap<int, Person>::iterator it = m.find(CEHUA); it != m.find(MEISHU); it++)
    {
        std::cout << "部门编号：" << it->first << " 姓名：" << it->second.m_name << " 薪水：" << it->second.m_salary << std::endl;
    }
    std::cout << "--------------美术部---------------" << std::endl;
    for (auto it = m.find(MEISHU); it != m.find(YANFA); it++)
    {
        std::cout << "部门编号：" << it->first << " 姓名：" << it->second.m_name << " 薪水：" << it->second.m_salary << std::endl;
    }
    std::cout << "--------------研发部---------------" << std::endl;
    // for (std::multimap<int, Person>::iterator it = m.find(YANFA); it != m.end(); it++)
    // {
    //     std::cout << "部门编号：" << it->first << " 姓名：" << it->second.m_name << " 薪水：" << it->second.m_salary << std::endl;    
    // }
    std::multimap<int, Person>::iterator it = m.find(YANFA);
    while(it != m.end()){
        std::cout << "部门编号：" << it->first << " 姓名：" << it->second.m_name << " 薪水：" << it->second.m_salary << std::endl;    
        it++;
    }
}
int main()
{
    srand(time(0));
    std::vector<Person> v;
    createWorker(v);
    std::multimap<int, Person> m;
    setGroup(v, m);
    showGroup(m);
}