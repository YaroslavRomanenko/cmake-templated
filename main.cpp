#include <iostream>
#include "CmakeHandler.hpp"

void PrintInfo(int argc, char const *argv[]);

int main(int argc, char const *argv[])
{
    CmakeHandler cmakeHandler;
    cmakeHandler.AskProjectSetup();
    
    // PrintInfo(argc, argv);
    return 0;
}

void PrintInfo(int argc, char const *argv[])
{
    std::cout << "argc: " << argc << std::endl;

    for (int i = 0; i < argc; i++)
    {
        std::cout << "argv: " << argv[i] << std::endl;
    }
}
