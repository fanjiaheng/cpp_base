#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

//以普通函数的方式实现自定义排序规则
bool mycomp(int i, int j) {
    return (i < j);
}

//以函数对象的方式实现自定义排序规则
class mycomp2 {
public:
    bool operator() (int i, int j) {
        return (i < j);
    }
};

void print(std::vector<int> v)
{
    //输出 v 容器中的元素
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << ' ';
    }

    std::cout << std::endl;
}

int main() {
    std::vector<int> myvector{ 32, 71, 12, 45, 26, 80, 53, 33 };

    //调用第一种语法格式，对 32、71、12、45 进行排序
    std::sort(myvector.begin(), myvector.begin() + 4); //(12 32 45 71) 26 80 53 33
    std::cout << "***********区间排序***********" << std::endl;
    print(myvector);

    //调用第二种语法格式，利用STL标准库提供的其它比较规则（比如 greater<T>）进行排序
    std::sort(myvector.begin(), myvector.begin() + 4, std::greater<int>()); //(71 45 32 12) 26 80 53 33
    std::cout << "***********利用STL标准库提供的比较规则排序***********" << std::endl;
    print(myvector);


    //调用第二种语法格式，通过自定义比较规则进行排序
    std::sort(myvector.begin(), myvector.end(), mycomp2());//12 26 32 33 45 53 71 80
    std::cout << "***********自定义比较规则排序***********" << std::endl;
    print(myvector);

    return 0;
}
