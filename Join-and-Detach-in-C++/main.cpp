// JOIN NOTES
// 0. Once a thread is started we wait for this thread to finish by calling join() function on thread object.
// 1. Double join will result in program termination.
// 2. If needed we should check thread is joinable before joining. ( using joinable() function)
// 
// DETACH NOTES
// 0. This is used to detach a newly created thread from the parent thread.
// 1. Always check before detaching a thread that it is joinable otherwise we may end up double detaching and 
//    double detach() will result in program termination.
// 2. If we have detached thread and main function is returning then the detached thread execution is suspended.
// 
// NOTES:
// Either join() or detach() should be called on thread object, otherwise during thread object�s destructor it will 
// terminate the program. Because inside destructor it checks if thread is still joinable? if yes then it terminates the program.

#include <iostream>
#include <chrono>
#include <thread>

void run(int count){
    while (count --> 0)
    {
        std::cout << "nlp" << std::endl;
    }
    //std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "thread finished" <<std::endl;
}

int main()
{
    std::thread t1(run, 10);
    std::cout << "main()" << std::endl;
    // if(t1.joinable()){
    //     t1.join();
    // }
    t1.detach();
    std::cout << "main() after" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));

    return 0;
}