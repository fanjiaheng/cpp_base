#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector
#include <string.h>

using namespace std;

int main() {
    //find() 函数作用于普通数组
    char stl[] ="http://c.biancheng.net/stl/";
    char * p = find(stl, stl + strlen(stl), 'c');
    if (p != stl + strlen(stl)) {
        cout << p << endl; //c.biancheng.net/stl/
    }

    //find() 函数作用于容器
    std::vector<int> myvector{ 10,20,30,40,50 };
    std::vector<int>::iterator it;
    it = find(myvector.begin(), myvector.end(), 30);
    if (it != myvector.end())
        cout << "查找成功：" << *it; //查找成功：30
    else
        cout << "查找失败";
    
    return 0;
}