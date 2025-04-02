#pragma once
#include <iostream>
// 重新生成解决方案
template <class T>
class MyArray
{
public:
	// 有参构造，默认数组容量为0
	MyArray(int capacity = 0)
	{
		std::cout << "构造函数调用, 对象地址: " << this << std::endl;
		m_capacity = capacity;
		m_size = 0;
		pAddress = new T[m_capacity]; // 直接赋值
	}
	//尾插法
	void Push_back(const T& val){
		if(m_capacity == m_size){
			//按当前容量扩大两倍扩容
			int new_capacity = m_capacity == 0 ? 1 : m_capacity * 2;
			T * new_pAddress = new T[new_capacity];

			for (int i = 0; i < m_size; i++)
			{
				new_pAddress[i] = pAddress[i];
			}
			delete[] pAddress;

			pAddress = new_pAddress;
			m_capacity = new_capacity;
		}
		pAddress[m_size++] = val;
	}
	//尾删法
	void Pop_back(){
		if(m_size == 0){
			return;
		}
		m_size--;
	}
	//通过下标返回数组元素
	T& operator[](int index){
		if (index < 0 || index >= m_size) {
			throw std::out_of_range("无效范围");
		}
		return pAddress[index];
	}
	//获取容量
	int getCapacity(){
		return m_capacity;
	}
	//获取大小
	int getSize(){
		return m_size;
	}
	// 拷贝构造
	MyArray(const MyArray &array)
	{
		std::cout << "拷贝构造函数调用, 对象地址: " << this << std::endl;
		m_capacity = array.m_capacity;
		m_size = array.m_size;
		// 浅拷贝会导致两个对象共享同一块内存，可能导致重复释放或数据不一致的问题。
		// pAddress = array.pAddress;
		// 深拷贝
		pAddress = new T[m_capacity];
		for (int i = 0; i < m_size; i++)
		{
			pAddress[i] = array.pAddress[i];
		}
	}
	// 运算符重载
	MyArray &operator=(const MyArray &array)
	{
		std::cout << "运算符重载调用,对象地址: " << this << std::endl;
		delete[] pAddress; // delete nullptr是安全的
		m_capacity = array.m_capacity;
		m_size = array.m_size;
		pAddress = new T[m_capacity];
		for (int i = 0; i < m_size; i++)
		{
			pAddress[i] = array.pAddress[i];
		}
		return *this;
	}
	// 析构函数
	~MyArray()
	{
		std::cout << "析构函数调用, 对象地址: " << this << std::endl;
		delete[] pAddress;
	}

private:
	T *pAddress;	// 指向堆区数组
	int m_capacity; // 数组容量
	int m_size;		// 数组大小
};