#include <iostream>
#include <cstring>
#include <windows.h>

#include <config.hpp>

void createDir(const char* dirName);

int main(int argc, char** argv){
    std::cout<<project_name<<std::endl;
    std::cout<<project_version<<std::endl;

    return 0;
}

void createDir(const char* dirName){
    TCHAR pwd[MAX_PATH];
    if(!GetCurrentDirectory(MAX_PATH, pwd)){
        std::cerr<<"Error Getting Current Directory: "<<pwd<<'\\'<<std::endl;

        return;
    }

    size_t dirLen = sizeof(pwd) + sizeof(dirName) + 2;

    char* path = new char[dirLen];
    path[0] = '\0';

    strcat(path, pwd);
    strcat(path, "\\");
    strcat(path, dirName);

    if(!CreateDirectory(path, NULL)){
        std::cerr<<"Error Creating Directory: "<<path<<std::endl;

        return;
    }

    delete path;
}