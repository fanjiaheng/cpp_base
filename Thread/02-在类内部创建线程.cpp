#include <iostream> // std::cout
#include <thread>
#include <string>
#include <unistd.h>
#include <functional>

using namespace std;

// 在Singleton模式内部创建线程
class CTread
{
public:
    static void start()
    {
        thread t(bind(&CTread::hello, CTread::instance()));

        t.join();
    }

    void hello(void)
    {
        while (1)
        {
            sleep(1);
            cout << "hello world" << endl;
        }
    }

    static CTread *instance(void)
    {
        static CTread inst;
        return &inst;
    }

private:
    CTread(){}
    ~CTread(){}
};

int main()
{
    cout << "Main线程" << endl;
    CTread::start();

    return 0;
}