#pragma once
#include <iostream>
#include <vector>

void printVector(std::vector<int> &v)
{
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void vectorTest()
{
    std::vector<int> v;
    // empty()为真为空
    if (v.empty())
    {
        std::cout << "为空" << std::endl;
    }

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.pop_back();

    // 容量
    std::cout << v.capacity() << std::endl;
    // 元素个数
    std::cout << v.size() << std::endl;
    printVector(v);
    std::cout << std::endl;
    // 改变存放的元素个数（大小）
    v.resize(2);
    // 容量
    std::cout << v.capacity() << std::endl;
    // 元素个数
    std::cout << v.size() << std::endl;
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    // 插入2个100
    v.insert(v.begin(), 2, 100);
    // 删除
    v.erase(v.begin());
    printVector(v);
    // 清空
    //  v.clear();

    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    // swap收缩空间，利用匿名对象立即被销毁的特性和vector拷贝构造的特性
    std::vector<int> vec1;

    for (int i = 0; i < 100; i++)
    {
        vec1.push_back(i);
    }

    vec1.resize(3);
    std::cout << "初始容量：" << vec1.capacity() << std::endl;
    std::cout << "初始大小：" << vec1.size() << std::endl;
    std::vector<int>(vec1).swap(vec1);
    std::cout << "收缩后容量：" << vec1.capacity() << std::endl;
    std::cout << "收缩后大小：" << vec1.size() << std::endl;
}