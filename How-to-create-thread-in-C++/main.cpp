#include <iostream>
#include <thread>

//! Five different types for create thread
// 1. Function Pointer
// 2. Lambda function
// 3. Functor
// 4. Non-static member function
// 5. Static member function

void func_t(int i){
    while (i --> 0) {
        std::cout << i << std::endl;
    }
}

class Base
{
public:
    void operator()(int x){
        while (x --> 0){
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
};

class Test
{
public:
    void run(int x){
        while (x --> 0){
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
    static void run_2(int x){
         while (x --> 0){
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
};


int main()
{
    //! type 1: Function Pointer
    /*std::thread t1(func_t, 10);
    std::thread t2(func_t, 20);
    t1.join();
    t2.join();*/

    //! type 2: Lambda Function
    /*auto f = [](int x){
        while (x --> 0){
            std::cout << x << " ";
        }
        std::cout << std::endl;
    };
    std::thread t1(f, 30);
    t1.join();

    std::thread t2([](int x){
        while (x --> 0){
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }, 20);t2.join();*/

    //!. type 3: Functor (Function Object)
    /*std::thread t((Base()), 10);
    t.join();*/

    //!. type 4: Non-static member function
    /*Test test1;
    std::thread t(&Test::run, &test1, 20);
    t.join();*/

    //!. type 5: Static member function
    std::thread t(&Test::run_2, 30);
    t.join();

    return 0;
}