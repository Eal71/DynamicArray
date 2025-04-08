#pragma once
#include <iostream>
void stringTest()
{
    // 都是从索引前开始操作
    std::string str = "I Love You";
    std::string str2 = "I Love You";
    std::string str3 = "I Love You";
    std::string str1;
    // 追加 第二个参数：从str1的第几个开始（不包括你想要的那个），第三个参数：截的个数
    str1.append(str, 7, 3);
    std::cout << str1 << std::endl;

    // 查找
    // 从左往右找
    int pos = str.find("You");
    // 从右往左找，找不到返回-1
    int pos1 = str.rfind("You");
    std::cout << pos << std::endl;

    // 替换,从索引1开始的3个字符替换为qqqq
    str.replace(1, 3, "qqqq");
    std::cout << str << std::endl;

    // 比较
    if (str3.compare(str2) == 0)
    {
        std::cout << "相等" << std::endl;
    }

    // 遍历
    std::string str4 = "hello";
    for (int i = 0; i < str4.size(); i++)
    {
        std::cout << str4[i] << std::endl;
    }

    // 插入
    str.insert(1, "qqq");
    std::cout << str << std::endl;

    // 删除
    str.erase(1, 2);
    std::cout << str << std::endl;

    // 截取
    std::string str5 = "zhangsan@qq.com";
    int pos2 = str5.find("@");
    std::string str6 = str5.substr(0, pos2);
    std::cout << str6 << std::endl;
}