#include <bits\stdc++.h>
using namespace std;

 // Forward declaration
template <typename type> class ATVector;

template <typename type>
ostream & operator<< (ostream & os, const ATVector<type> & Arr);

template <typename type>
class ATVector {
    private:
        type* ptr;  // the array
        int Size = 0;    // the size of the Array
        int Capacity = 0;
        
    public:
        // Constructors and Big 4
        typedef type * iterator;
        explicit ATVector(int siz = 0);   // constructor with size
        ATVector(type* arr, int n);
        ATVector(const ATVector <type>& h2); // copy Array with constructor
        ~ATVector();   //destructor
        ATVector<type>& operator=(const ATVector <type>& h2); // copy assignment
        ATVector<type>& operator=(ATVector <type>&& h2) noexcept ; // move assignment

        // Access operations
        type & operator[](const int& ind);  // access on elements with brackets []


        // Modifying operations
        int push_back(const type& value);
        type pop_back();
        void clear();
        void erase(iterator it);
        void erase(iterator it1, iterator it2);
        void insert(iterator it, type value);

        // capacity operations
        bool empty();
        int size() const;   // get Array's size
        int capacity() const;
        void resize(int size);

        // Comparison operations
        bool operator==(const ATVector<type>& h2);
        bool operator <(const ATVector<type>& h2);

        // iterators
        iterator begin();
        iterator end();

        friend  ostream& operator << <>(ostream& os, const ATVector<type>& Arr);   // output operator overload

};
