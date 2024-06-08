#include <iostream>
#include <stdexcept>
#include <string>
#include <windows.h>

#include <config.hpp>

#define ROOT_DIR std::string(CPM::getCWD() + "\\")

namespace CPM {
    std::string getCWD();
    bool createDir(const std::string dirName);
    bool createFile(const std::string fileName);
    void initProject();
};

const std::string DIRECTORIES[5] = {
    "app",
    "config",
    "external",
    "include",
    "src"
};

int main(int argc, char** argv){
    std::cout<<project_name<<std::endl;
    std::cout<<project_version<<std::endl;

    CPM::initProject();

    return 0;
}

namespace CPM {
    std::string getCWD(){
        TCHAR cwd[MAX_PATH];
        if(!GetCurrentDirectory(MAX_PATH, cwd)){
            std::cerr<<"-- Error Getting Current Directory"<<std::endl;
            return "\0";
        }
        return std::string(cwd);
    }

    bool createDir(const std::string dirName){
        const std::string path = ROOT_DIR + dirName;

        if(!CreateDirectory(path.c_str(), NULL)){
            std::cerr<<"-- Error Creating Directory: "<<path<<std::endl;
            return false;
        }

        return true;
    }

    bool createFile(const std::string fileName){
        HANDLE file = CreateFile(
            std::string(ROOT_DIR + fileName).c_str(),
            GENERIC_WRITE,
            0,
            NULL,
            CREATE_NEW,
            FILE_ATTRIBUTE_NORMAL,
            NULL
        );

        if(file == INVALID_HANDLE_VALUE){
            std::cerr<<"-- Error Creating File: "<<fileName<<"\n"<<GetLastError()<<std::endl;
            return false;
        }

        CloseHandle(file);
        return true;
    }

    void initProject(){
        try{
            // Create folder structure
            for(const std::string dir : DIRECTORIES){
                if(!createDir(dir)) throw std::runtime_error("-- Error Creating directory: " + ROOT_DIR + dir);
                if(!createFile(dir + "\\CMakeLists.txt")) throw std::runtime_error("-- Error Creating File: " + ROOT_DIR + dir + "\\CMakeLists.txt");
            }
        }catch(const std::runtime_error& error){
            std::cerr<<"-- Error Initializing Project"<<std::endl;
            std::cerr<<error.what()<<std::endl;
            return;
        }catch(...){
            std::cerr<<"-- Unknown Error Initializig Project"<<std::endl;
            return;
        }
    }
};