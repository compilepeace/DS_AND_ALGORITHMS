#include <iostream>
using namespace std;
#define N 4

template <typename T>
class vector
{  

private:
    T *arr;
    size_t maxSize;
    size_t cur;

public:

    // Default constructor
    vector(): maxSize(N)
    {
        arr = new T[maxSize];
        cur = 0;
    }

    // Parameterized constructor
    vector(size_t n, char v = '0')
    {
        maxSize = n;        // We would have done 'this->maxSize = maxSize' if 'n' was named 'maxSize'
        cur = 0;
        arr = new T[maxSize]{v};
    }

   
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    size_t getMaxSize() { return maxSize; }


    void extendVector(int limit)
    {
        maxSize = maxSize * 2;
        T *alloc = new T[maxSize]{0};

        // Copy arr to alloc
        for (int i = 0; i < limit; ++i)
            alloc[i] = arr[i];

        // free arr
        delete [] arr;
        arr = alloc;
    }


    void push_back(T val)
    {   
        if (cur >= maxSize)
            extendVector(cur);
               
        arr[cur++] = val;
    }

    bool empty()    { return (cur == 0); }
    size_t length() { return cur; }
    
    T pop_back()
    {
        if (!empty())
            return arr[cur--];
    }

    // Operators
    T &operator[](size_t i)
    {
        if (i < cur) return arr[i];
    }


    // Copy asignment operator
    void operator= (vector<T> &v)
    {
        delete [] arr;

        cur = v.length();
        maxSize = v.getMaxSize();
        
        // We use deep copy
        arr = new T[maxSize];

        for (int i = 0; i < maxSize; ++i){
            arr[i] = v.arr[i];
        }
     }


    // FUNCTOR/FUNCTIONAL OBJECT:  vector help
    void operator() ()
    {
        cout << "maxSize: " << getMaxSize() << endl;
        cout << "length:  " << length() << endl;
        cout << "operators overloaded: =, [], <<, () " << endl;
        cout << "vector content: ";
        print(); 
        cout << endl;
    }
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // print vector
    void print(){
        for (int i = 0; i < cur; ++i)
            printf("%d ", arr[i]);
            printf("\n");
    }

    // Destruction 
    ~vector()
    {
        printf("Calling destructor\n");
        delete [] arr;
    }
};



template <typename T>
ostream &operator<< (ostream &os, vector<T> &v)
{
    v.print();
    return os;
}


int main()
{
    vector<int> v, vs;

    for (int i = 0; i < 30; ++i)
    {
        //if ( !(i % 16) ) printf("haha %d \n", v.getMaxSize());
        v.push_back(i);
    }

    vs.push_back(22);
    vs.push_back(33);
    vs.push_back(44);

    cout << "v        : " << v << endl;
    cout << "vs before: " << vs << endl;
    vs = v;
    vs[29] += 100;
    cout << "vs Now   : " << vs << endl;;
    
    v();            // help with vector v
    cout << endl;
    vs();           // help with vector vs
}
