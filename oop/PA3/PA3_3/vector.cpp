#include"Vector.h"
#include"iostream"
using namespace std;
//TODO 完成实现

//TODO 争取使用左右值提高效率
//OK
Vector::~Vector(){
    delete []array;
}
//OK
Vector::Vector(int n){
    capacity = n;
    len = 0 ;
    array = new Node[n];
}


//TODO check diff between & and &&
Vector::Vector(const Vector & other){
    capacity = other.capacity;
    len = other.len;
    array = new Node[capacity];
    for (int i = 0; i < len; i++){
        array[i] = other.array[i];
    }
}

//ok

Vector::Vector(Vector && other){
    if(this==&other)
    return;
    capacity = other.capacity;
    len = other.len;
    array = other.array;
    other.array = nullptr;
    other.len = 0;
}

//ok
Vector& Vector::operator=(const Vector &other){
    //FIXME 位拷贝
   capacity = other.capacity;
    len = other.len;
    Node* oldArray = array;
    array = new Node[capacity];
    for (int i = 0; i < len; i++) {
        array[i] = other.array[i];
    }
    delete[] oldArray;
    return *this;
}

//ok
Vector& Vector::operator=(Vector && other){
    if(this!=&other){
        capacity = other.capacity;
        len = other.len;
        Node* oldArray = array;
        array = other.array;
        other.array = nullptr;
        delete[] oldArray;
        other.len = 0;
    }
    return *this;
}

//ok
Node& Vector::operator[](int pos){
    return array[pos];
}

//ok
void Vector::append(int value){
    array[len] = Node(value);
    len++;
}

//ok
void Vector::insert(int pos, int value){
    for(int i = len++; i > pos; i--){
        array[i] = move(array[i-1]); 
    }
    array[pos] = move(value);
}

// ok
void Vector::swap(int pos1, int pos2){
    Node temp(move(array[pos1]));
    array[pos1] = move(array[pos2]);
    array[pos2] = move(temp);
}

//ok
void Vector::dilatation()
{
    capacity = 2*capacity;
    Node* newArray = new Node[capacity];
    for (int i = 0; i < len; i++) {
        newArray[i] = move(array[i]);
    }
    Node* oldArray = array;
    array = newArray;
    delete[] oldArray;
}

//ok
int Vector::getlen(){
    return len;
}