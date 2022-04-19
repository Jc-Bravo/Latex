#include <iostream>

using namespace std;

class Test {
    int *buf;
public:
    Test() {
        buf = new int(0);
        cout << "Test(): this->buf @ " << hex << buf << endl;
    }
    Test(int val) {
        buf = new int(val);
        cout << "Test(int): this->buf @ " << hex << buf << endl;
    }
    ~Test() {
        cout << "~Test(): this->buf @ " << hex << buf << endl;
        if (buf) delete buf;
    }
    Test(const Test& t) : buf(new int(*t.buf)) {
        cout << "Test(const Test&) called. this->buf @ "
            << hex << buf << endl;
    }
    Test(Test&& t) : buf(t.buf) {
        cout << "Test(Test&&) called. this->buf @ "
            << hex << buf << endl;
        t.buf = nullptr;
    }
    Test& operator= (const Test& right) {
        cout<<"assignmen"<<endl;
        if (this != &right){
            if(buf) delete buf;
            buf = new int(*right.buf);
        }
        return *this;
    }
    Test& operator= (Test&& right) {
        if (this != &right){
            if(buf) delete buf;
            this->buf = right.buf;
            right.buf = nullptr;
        }
        cout<<"move assignmengt"<<endl;
        return *this;
    }
    void print(const char *name) {
        cout << name << ".buf @ " << hex << buf << endl;
    }
};

// A
//  Test F(Test a){
//      cout<<1<<endl;
//      Test b = std::move(a);
//     cout<<2<<endl;
//      return b;
//      cout<<3<<endl;
//  } 
//  int main(){
//     cout<<5<<endl;
//      Test a;
//     cout<<6<<endl;
//      a = 1;
//           cout<<7<<endl;
//      Test A = F(a);
//           cout<<8<<endl;
//      return 0;
//           cout<<9<<endl;
//  }

// B
//  Test F(const Test &a){
//      cout<<1<<endl;
//      Test b = std::move(a);
//     printf("a之前的地址是%p", &a);
//     printf("a之前的地址是%p", &b);
//     cout<<2<<endl;
//      return b;
//      cout<<3<<endl;
//  } 
//  int main(){
//     cout<<5<<endl;
//      Test A = F(1);
//     cout<<6<<endl;
//      return 0;
//  }
 /*
 Q1: when to use copy //理解为const 无法改变
 Q2: =?调用的是构造函数而不是运算符
 */

//  C
//  Test F(Test &&a){
//      cout<<1<<endl;
//      Test b = std::move(a);
//     cout<<2<<endl;
//      return b;
//  } 
//  int main(){
//     cout<<5<<endl;
//     Test A =F(1);
//      return 0;
//  }
//D
//  Test &&F(Test &a){
//      cout<<1<<endl;
//      Test b = a;
//     cout<<2<<endl;
//      return std::move(b);
//  } 
//  int main(){
//     cout<<5<<endl;
//     Test A =F(Test(1));
//      return 0;
//  }
// E
 const Test &F(const Test &a){
     cout<<1<<endl;
     Test b = a;
    cout<<2<<endl;
     return Test(1);
 } 
 int main(){
    cout<<5<<endl;
    Test a;
    cout<<6<<endl;
    const Test &A = F(std::move(a));
     return 0;
 }