#include <iostream> // std::cout
#include <thread>
#include <string>
#include <unistd.h>

using namespace std;

// 普通函数的多线程调用

// 1. 无参数函数
void func1(void)
{
    while(1)
    {
        sleep(1);
        cout << "func1 thread running." << endl;
    }
}

// 2. 有参数函数
void func2(string msg)
{
    while(1)
    {
        sleep(1);
        cout << msg << endl;
    }
}

int main()
{
    cout << "Main线程" << endl;

    thread t1(func1);
    thread t2(func2, "fanjiaheng");

    // 主线程等待子线程结束之后退出
    t1.join();
    t2.join();

    return 0;
}