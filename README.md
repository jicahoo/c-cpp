# c-cpp
# Boost
* 智能指针：
  * intrusive_ptr与share_ptr的区别与相同点：两者都有引用计数。设想下面这个例子。它是有漏洞的。 当sPtrA和sPtrB离开作用域时，都会释放rawPtrA指向的堆空间, 后释放的那个操作就会出问题。每次从裸指针构建一个shared_ptr，在堆空间中，会开辟一点空间，用于记录引用计数。拷贝构造或者赋值构造的shared_ptr会共享这个引用计数。在下面的例子中，sPtrA和strB会有两份引用计数。而intrusive_ptr的引用计数是和对象（new ClassA())对应的，所以说，iPtrA和iPtrB是共享引用计数的。所以，iPtrA和iPtrB是没有什么问题的。
  ```c++
  ClassA rawPtrA = new ClassA();
  shared_ptr<ClassA>  sPtrA = shared_ptr<ClassA>(rawPtrA);
  shared_ptr<ClassA>  sPtrB = shared_ptr<<ClassA>(rawPtrA);
  intrusive_ptr<ClassA> iPtrA = intrusive_ptr<ClassA>(rawPtrA)
  intrusive_ptr<ClassA> iPtrB = intrusive_ptr<ClassA>(rawPtrA)
  ```


# C++
* What's the mechanism of call by reference? https://stackoverflow.com/questions/3954764/how-is-reference-implemented-internally/38329120#38329120 
* 析构函数？和Java不同，在不需要该对象的时候（譬如说，对象出了作用域），会被调用。Java没有这种机制。这种机制有种奇怪的官方名字：RAII https://stackoverflow.com/questions/2321511/what-is-meant-by-resource-acquisition-is-initialization-raii . Java try(new) 和 python的 with open() as: 类似。
* 栈上的对象？Java也可做，只是常规情况下，没有栈上对象：https://stackoverflow.com/questions/25903320/creating-objects-on-the-stack-memory-in-java. C++: https://stackoverflow.com/a/26776709/4153267
* struct vs class: https://stackoverflow.com/questions/3574040/c-can-a-struct-inherit-from-a-class

# C/C++ program memory layout:
* https://unix.stackexchange.com/questions/200348/memory-layout-of-dynamic-loaded-linked-library
* https://manybutfinite.com/post/anatomy-of-a-program-in-memory/
