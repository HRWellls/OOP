#include <iostream>
#include <stdexcept>
using namespace std;
//----------------------------------------------------------------------------------------------------------------
template <class T>
class Vector {
public:
  Vector();                      // creates an empty vector
  Vector(int size);              // creates a vector for holding 'size' elements
  Vector(const Vector& r);       // the copy ctor
  ~Vector();                     // destructs the vector 
  T& operator[](int index);      // accesses the specified element without bounds checking
  T& at(int index);              // accesses the specified element, throws an exception of
                                 // type 'std::out_of_range' when index <0 or >=m_nSize
  int size() const;              // return the size of the container
  void push_back(const T& x);    // adds an element to the end 
  void clear();                  // clears the contents
  bool empty() const;            // checks whether the container is empty 
private:
  void inflate();                // expand the storage of the container to a new capacity,
                                 // e.g. 2*m_nCapacity
  T *m_pElements;                // pointer to the dynamically allocated storage
  int m_nSize;                   // the number of elements in the container
  int m_nCapacity;               // the total number of elements that can be held in the
                                 // allocated storage
};

template <class T>
Vector<T>::Vector() : m_nSize(0), m_nCapacity(0), m_pElements(nullptr) {}

template <class T>
Vector<T>::Vector(int size){ // 构造函数，接受初始大小参数
    this->m_nCapacity=size; // 设置容量为给定大小
    this->m_nSize=0; // 初始化大小为0
    this->m_pElements=new T [size]; // 分配内存以容纳元素
}

template <class T>
Vector<T>::Vector(const Vector& r) { // 复制构造函数
    this->m_nSize=r.m_nSize; // 复制大小
    this->m_nCapacity=r.m_nCapacity; // 复制容量
    this->m_pElements=new T [r.m_nCapacity]; // 分配内存以容纳元素
    for(int i=0;i<r.m_nCapacity;i++){ // 复制元素
        this->m_pElements[i]=r.m_pElements[i];
    }
}

template <class T>
Vector<T>::~Vector() { // 析构函数
    delete [] this->m_pElements; // 释放内存
}

template <class T>
T& Vector<T>::operator[](int index) { // 重载 [] 运算符
    return this->m_pElements[index]; // 返回给定索引处的元素的引用
}

template <class T>
T& Vector<T>::at(int index) { // 返回指定索引处的元素的引用，并进行边界检查
    if(index<0 || index>=this->m_nSize){ // 如果索引超出范围
        throw std::out_of_range("Index out of range"); // 抛出 out_of_range 异常
    }
    return this->m_pElements[index]; // 返回指定索引处的元素的引用
}

template <class T>
int Vector<T>::size() const { // 返回向量的大小
    return this->m_nCapacity;
}

template <class T>
void Vector<T>::push_back(const T& x) { // 将元素添加到向量末尾
    if(this->m_nSize==this->m_nCapacity){ // 如果当前大小等于容量
        this->inflate(); // 扩容
    }
    this->m_pElements[this->m_nSize]=x; // 在末尾添加元素
    this->m_nSize++; // 增加大小
}

template <class T>
void Vector<T>::clear() { // 清空向量
    this->m_nSize=0; // 将大小重置为0
}

template <class T>
bool Vector<T>::empty() const { // 检查向量是否为空
    return this->m_nSize==0; // 如果大小为0，返回true，否则返回false
}

template <class T>
void Vector<T>::inflate() { // 扩容函数
    if(this->m_nCapacity==0){ // 如果容量为0
        this->m_nCapacity=1; // 将容量设置为1
        this->m_pElements=new T [1]; // 分配内存以容纳一个元素
        this->m_pElements[0]=0; // 初始化第一个元素
    }
    else{
        this->m_nCapacity=this->m_nCapacity*2; // 将容量加倍
        T *temp=new T [this->m_nCapacity]; // 创建一个新的更大的数组
        for(int i=0;i<this->m_nSize;i++){ // 复制元素到新数组
            temp[i]=this->m_pElements[i];
        }
        for(int i=this->m_nSize;i<this->m_nCapacity;i++){ // 初始化新数组剩余的元素
            temp[i]=0;
        }
        delete [] this->m_pElements; // 释放原有的内存
        this->m_pElements=temp; // 更新指针指向新的数组
    }
}
//--------------------------------------------------------------------------------------------------------------------------------

int main() {
    // Test default constructor
    Vector<int> v1;
    cout<<"v1 size: "<<v1.size()<<endl;
    
    // Test constructor with size
    Vector<int> v2(5);
    cout<<"v2 size: "<<v2.size()<<endl;
    
    // Test push_back
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    
    // Test operator[] and size
    cout << "After push_back , v1 size: " << v1.size() << endl;
    cout << "v1 contains: ";
    for (int i = 0; i < v1.size(); ++i) {
        cout << v1[i] << " ";
    }
    cout << endl;

    // Test copy constructor
    Vector<int> v3(v1);
    cout<<"v3 size: "<<v3.size()<<endl;
    cout << "v3 contains: ";
    for (int i = 0; i < v3.size(); ++i) {
        cout << v3[i] << " ";
    }
    cout << endl;
    
    // Test at
    try {
        cout << "Element at index 3 in v1: " << v1.at(3) << endl;
        cout << "Element at index 10 in v1: " << v1.at(10) << endl; // Should throw an exception
    } catch (const out_of_range& e) {
        cerr << "Exception caught: " << e.what() << endl;
    }
    
    // Test clear and empty
    cout << "Is v1 empty ? " << (v1.empty() ? "Yes" : "No") << endl;
    v1.clear();
    cout << "Is v1 empty after clearing? " << (v1.empty() ? "Yes" : "No") << endl;
    
    //The inflate function is assured to be tested in the push_back function.
    return 0;
}
