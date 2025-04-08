#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
class myCompare
{
public:
    void operator()(int val)
    {
        std::cout << val << " ";
    }
};
class myFind{
    public:
        bool operator()(int val){
            return val > 5;
        }
        
};
class mySort{
    public:
    bool operator()(int a,int b){
        return a > b;
    }
};

void algorithmTest()
{
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // 遍历算法
    //for_each
    std::for_each(v.begin(), v.end(), myCompare());
    std::cout << std::endl;

    // 查找算法
    //find
    std::vector<int>::iterator it = std::find(v.begin(), v.end(), 5);
    if( it != v.end()){
        std::cout << "find it" << std::endl;
    }
    else{
        std::cout << "not find it" << std::endl;
    }
    //find_if
    std::vector<int>::iterator it1 = std::find_if(v.begin(), v.end(), myFind());
    if( it1 != v.end()){
        std::cout << "find it" << std::endl;
    }
    else{
        std::cout << "not find it" << std::endl;
    }
    //binary_search,二分法
    bool ret = std::binary_search(v.begin(), v.end(), 9);
    if(ret){
        std::cout << "find it" << std::endl;
    }
    else{
        std::cout << "not find it" << std::endl;
    }
    //count
    int ret1 = std::count(v.begin(), v.end(), 9);
    std::cout << ret1 << std::endl;

    //排序算法
    //sort
    std::sort(v.begin(), v.end(), mySort());
    std::for_each(v.begin(), v.end(), myCompare());
    std::cout << std::endl;
    //random_shuffle,洗牌
    std::random_shuffle(v.begin(), v.end());
    std::for_each(v.begin(), v.end(), myCompare());
    std::cout << std::endl;
    //reverse,反转
    std::reverse(v.begin(), v.end());
    std::for_each(v.begin(), v.end(), myCompare());
    std::cout << std::endl;

    //拷贝和替换算法
    //copy
    std::vector<int> v1;
    v1.resize(v.size());
    std::copy(v.begin(), v.end(),v1.begin());
    std::for_each(v1.begin(), v1.end(), myCompare());
    std::cout << std::endl;
    //replace,不止替换一个
    std::replace(v.begin(), v.end(),1,99);
    std::for_each(v.begin(), v.end(), myCompare());
    std::cout << std::endl;
    //replace—_if,不止替换一个
    std::replace_if(v.begin(), v.end(),myFind(),99);
    std::for_each(v.begin(), v.end(), myCompare());
    std::cout << std::endl;
    //swap
    std::swap(v,v1);
    std::for_each(v.begin(), v.end(), myCompare());
    std::cout << std::endl;

    //算数生成算法(要加头文件numeric)
    //accumulate，累加总和
    int total = accumulate(v.begin(), v.end(),0);
    std::cout << total << std::endl;
    //fill
    int arr[5];
    std::fill(std::begin(arr), std::end(arr), 10);
    std::for_each(std::begin(arr), std::end(arr), myCompare());
    std::cout << std::endl;

    //集合算法
    //set_intersection,交集
    std::vector<int> s1;
    std::vector<int> s2;
    for (int i = 0; i < 10; i++)
    {
        s1.push_back(i); //0~9
        s2.push_back(i + 2); //2~11
    }
    std::vector<int> s3;
    s3.resize(std::min(s1.size(),s2.size()));//当一个集合包含另一个集合时取最小
    std::vector<int>::iterator itEnd = std::set_intersection(s1.begin(), s1.end(),s2.begin(), s2.end(),s3.begin());
    std::for_each(s3.begin(), itEnd, myCompare());
    std::cout << std::endl;
    //set_union,并集
    s3.resize(s1.size()+s2.size());//当一个集合和另一个集合时没有交集时，两者相加
    std::vector<int>::iterator itEnd1 = std::set_union(s1.begin(), s1.end(),s2.begin(), s2.end(),s3.begin());
    std::for_each(s3.begin(), itEnd1, myCompare());
    std::cout << std::endl;
    //set_difference,差集
    s3.resize(std::max(s1.size(),s2.size()));//当一个集合和另一个集合时没有交集时，取最大
    //s1与s2的差集
    std::vector<int>::iterator itEnd2 = std::set_difference(s1.begin(), s1.end(),s2.begin(), s2.end(),s3.begin());
    std::for_each(s3.begin(), itEnd2, myCompare());
    std::cout << std::endl;
    //s2与s1的差集
    std::vector<int>::iterator itEnd3 = std::set_difference(s2.begin(), s2.end(),s1.begin(), s1.end(),s3.begin());
    std::for_each(s3.begin(), itEnd3, myCompare());
    std::cout << std::endl;
}
