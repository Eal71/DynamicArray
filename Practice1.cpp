#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
/*
有5名选手，选手ABCDE，10个评委分别对每一位选手打分，去掉最高和最低分，去平均分
*/
class Person{
    public:
    Person(std::string name,int score){
        m_name = name;
        m_score = score;
    }
    std::string m_name;
    int m_score;
};
//创建5个选手
void createPerson(std::vector<Person>& v){
    std::string nameSeed = "ABCDE";
    int score = 0;
    for (int i = 0; i < 5; i++)
    {
        
        std::string name = "选手";
        name += nameSeed[i];

        Person p(name,score);
        v.push_back(p);
    }
}
//为每个选手分配10个分数
void createScore(std::vector<Person>& v){
  
    std::deque<int> d;
    srand(time(0));//随机种子
    //遍历每个选手
    for (std::vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        //10个评委为选手打分
        for (int i = 0; i < 10; i++)
        {
            int score = rand() % 101;//0~100随机数
            //放入deque
            d.push_back(score);
        }
        //排序
        sort(d.begin(),d.end());

        //去掉最大最小值
        d.pop_front();
        d.pop_back();

        int sum = 0;
        //10个数累加
        for (std::deque<int>::iterator it = d.begin(); it != d.end(); it++)
        {
           sum += *it;
        }
        //平均分
        int avg = sum/d.size();
        it->m_score = avg;
    }
}
int main(){
    std::vector<Person> v;
    createPerson(v);
    createScore(v);
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << "姓名：" << v[i].m_name << " 分数：" << v[i].m_score << std::endl;
    }
}