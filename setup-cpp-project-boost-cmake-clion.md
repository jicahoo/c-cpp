# Setup complete C++ project using CMake on Linux

# Version info
* Ubuntu: `Linux ubuntu 5.3.0-28-generic #30~18.04.1-Ubuntu SMP Fri Jan 17 06:14:09 UTC 2020 x86_64 x86_64 x86_64 GNU/Linux`

## Install boost
* `sudo apt install libboost-all-dev`  
* Consume about 450MB. It also install its depends: g++, libc++....

## use boost
* Code
```C++
#include <stdio.h>
#include <string>

#include <boost/optional.hpp>

boost::optional<int> func(const std::string &str)
{
        boost::optional<int> value;
        int tmp = 0;

        if (sscanf(str.c_str(), "%d", &tmp) == 1)
                value.reset(tmp);

        return value;
}

int main(int argc, char **argv)
{
        boost::optional<int> v1 = func("31245");
        boost::optional<int> v2 = func("hello");

        if (v1)
                printf("%d\n", v1.get());
        else
                printf("v1 not valid\n");

        if (v2)
                printf("%d\n", v2.get());
        else
                printf("v2 not valid\n");

        return 0;
}
```
* compile: `g++ main.cpp -o main`
* Problem: how g++  and main exe find the boost?
    * g++ -v option will output the LIBRARY_PATH, Include path:
    * header files from /usr/include/boost/.
    * Lib path: /usr/lib/x86_64-linux-gnu/libboost_* (on ubuntu 64 bit)

## Install CMake on ubuntu
* Follow the steps (using comand) at https://vitux.com/how-to-install-cmake-on-ubuntu-18-04/
### CMake Hello World:
* http://derekmolloy.ie/hello-world-introductions-to-cmake/
* https://riptutorial.com/cmake/example/7501/simple--hello-world--project
* https://coderefinery.github.io/cmake/03-hello-world-cmake/
* https://arne-mertz.de/2018/05/hello-cmake/
* CMake script introduction: https://preshing.com/20170522/learn-cmakes-scripting-language-in-15-minutes/
