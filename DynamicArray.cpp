#include<iostream>
#include"MyArray.hpp"
//普通数据类型测试
void test(){
	MyArray <int> m1;
	//插入任意数量值
	m1.Push_back(1);
	m1.Push_back(2);
	m1.Push_back(3);
	for (int i = 0; i < m1.getSize(); i++)
	{
		std::cout << m1[i] << std::endl;
	}
	std::cout <<"容量："<< m1.getCapacity() << std::endl;
	std::cout <<"大小："<< m1.getSize() << std::endl;
	m1.Pop_back();
	std::cout <<"尾删后大小："<< m1.getSize() << std::endl;
	for (int i = 0; i < m1.getSize(); i++)
	{
		std::cout << m1[i] << std::endl;
	}
}
//自定义数据类型测试
class Person{
	public:
		Person(){}
		Person(int age,std::string name){
			m_age = age;
			m_name = name;
		}
		int m_age;
		std::string m_name;
	};
void test1(){
	MyArray <Person> m2;
	Person p1(12,"tom");
	Person p2(11,"dog");
	Person p3(10,"jerry");
	Person p4(15,"jack");
	Person p5(16,"cat");
	m2.Push_back(p1);
	m2.Push_back(p2);
	m2.Push_back(p3);
	m2.Push_back(p4);
	m2.Push_back(p5);
	for (int i = 0; i < m2.getSize(); i++)
	{
		std::cout << m2[i].m_age << m2[i].m_name << std::endl;
	}
	std::cout <<"容量："<< m2.getCapacity() << std::endl;
	std::cout <<"大小："<< m2.getSize() << std::endl;
	m2.Pop_back();
	std::cout <<"尾删后大小："<< m2.getSize() << std::endl;
	for (int i = 0; i < m2.getSize(); i++)
	{
		std::cout << m2[i].m_age << m2[i].m_name << std::endl;
	}
}
int main() {
	test();
	test1();
	return 0;
}