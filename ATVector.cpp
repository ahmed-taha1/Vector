#include "ATVector.h"


// **********************  vector constructor   **********************
template <typename type>
ATVector<type>::ATVector(int siz){
    Size = siz;
    Capacity = siz;
    ptr = new type[siz];
    for(int i = 0; i < Size; i++)
        ptr[i] = type();
}


// **********************  vector constructor copy from array   **********************
template<typename type>
ATVector<type>::ATVector(type *arr, int n) {
    Size = n;
    Capacity = n;
    ptr = new type[Size];
    for(int i = 0; i < n; i++){
        ptr[i] = arr[i];
    }
}


// **********************  copy vector constructor  **********************
template <typename type>
ATVector<type>::ATVector(const ATVector <type>& h2){
    this->Size = h2.Size;
    this->ptr = new type[Size];
    for(int i = 0; i < h2.Size; i++)
        this->ptr[i] = h2.ptr[i];
}


// **********************  copy assignment  **********************
template <typename type>
ATVector<type>& ATVector<type>::operator=(const ATVector <type>& h2){
    delete [] this->ptr;
    Size = h2.Size;
    ptr = new type[Size];
    for(int i = 0; i < Size; i++)
        this->ptr[i] = h2.ptr[i];

    return *this;
}


// **********************  move assignment  **********************
template <typename type>
ATVector<type>& ATVector<type>::operator=(ATVector <type>&& h2) noexcept{
    delete [] this->ptr;
    Size = h2.Size;
    ptr = new type[Size];
    for(int i = 0; i < Size; i++)
        this->ptr[i] = h2.ptr[i];

    delete [] h2.ptr;
    h2.Size = 0;
    h2.ptr = new type(0);

    return *this;
}


// **********************  destructor   ********************
template <typename type>
ATVector<type>::~ATVector(){
    delete [] ptr;
}


// **********************  output overload function   **********************
template <typename type>
ostream& operator <<(ostream& os, const ATVector<type>& Arr){
    for(int i = 0; i < Arr.Size; i++)
        os << Arr.ptr[i] << " ";
    return os;
}


// ***********************access on elements with brackets [] function*********************
template <typename type>
type & ATVector<type>::operator[](const int& ind){
    if(ind < 0 || ind >= Size)  // check if the index in the size range
        throw out_of_range {"index out of range"};  // throw error
    return ptr[ind];
}


// ***************************** push back function *************************
template<typename type>
int ATVector<type>::push_back(const type &value) {
    // create temp array to copy from the main array
    // and delete the main array and reintialize it with bigger size
    // return copied elements and add the value at the end

    type* temp = new type [Size];
    for(int i = 0; i < Size; i++)
        temp[i] = ptr[i];
    delete [] ptr;
    Size++;
    ptr = new type [Size];
    for(int i = 0; i < Size - 1; i++)
        ptr[i] = temp[i];
    ptr[Size - 1] = value;

    delete [] temp;
    return Size;
}


// *************************** pop back funtion *************************
template<typename type>
type ATVector<type>::pop_back() {
    Size--;
    type* temp = new type [Size];
    for(int i = 0; i < Size; i++)
        temp[i] = ptr[i];

    delete [] ptr;
    ptr = new type [Size];
    for(int i = 0; i < Size; i++)
        ptr[i] = temp[i];

    delete [] temp;
    return ptr[Size - 1];
}


// **************************** clear function ********************
template<typename type>
void ATVector<type>::clear() {
    Size = 0;
}


// ***************************** empty function *********************
template<typename type>
bool ATVector<type>::empty() {
    return (Size == 0);
}


// ************************** size function *************************
template<typename type>
int ATVector<type>::size() const {
    return Size;
}


// ************************* capacity function **********************
template<typename type>
int ATVector<type>::capacity() const {
    return Size;
}


// *********************** resize function ********************
template<typename type>
void ATVector<type>::resize(const int size) {
    if(size <= Size){
        throw out_of_range {"you can't small the size"};
        return;
    }
    type* temp = new type [Size];
    for(int i = 0; i < Size; i++) {
        temp[i] = ptr[i];
    }

    int oldSize = Size;
    Size = size;
    delete [] ptr;
    ptr = new type [Size];

    for(int i = 0; i < Size; i++) {
        if(i >= oldSize)
            ptr[i] = type();
        else
            ptr[i] = temp[i];
    }
}


// *************************** begin function ****************
template<typename type>
typename ATVector<type>::iterator ATVector<type>::begin() {
    return ptr;
}


// ************************* end function **********************
template<typename type>
typename ATVector<type>::iterator ATVector<type>::end(){
    return (ptr + Size);
}


// *********************** erase function ********************
template<typename type>
void ATVector<type>::erase(iterator it){
    int dis = distance(this->begin(), it);
    if(dis >= Size) {
        throw out_of_range{"wrong iterator"};
        return;
    }

    ATVector<type> temp(Size - 1);
    int current = 0;
    for(int i = 0; i < Size; i++){
        if(dis == i)
            continue;
        else {
            temp[current] = ptr[i];
            current++;
        }
    }

    delete [] ptr;
    Size--;
    ptr = new type[Size];
    for(int i = 0; i < Size; i++)
        ptr[i] = temp[i];
}


// ************************ erase function with two iterators **********************
template<typename type>
void ATVector<type>::erase(iterator it1, iterator it2){
    if( it1 > it2)
            return;
    if(it1 < this-> begin() || it1 >= this->end() || it2 < this-> begin() || it2 >= this->end() ){
        throw out_of_range {"out of range"};
        return;
    }

    int deletes = distance(it1, it2) + 1;
    int start = distance (this -> begin(), it1);
    int current = 0;
    
    ATVector<type> temp(Size - deletes);
    
    
    for(int i = 0; i < Size; i++){
        if( i == start)
            i+= deletes - 1;
        else{
            temp[current] = ptr[i];
            current++;
        }
    }
     
    Size-= deletes;
    delete[] ptr;
    ptr = new type[Size];
    for(int i = 0; i < Size; i++)
        ptr[i] = temp[i];
}


// ***************************** insert function ************************
template<typename type>
void ATVector<type>::insert(iterator it, type value) {
    int dis = distance(this->begin(), it);
    if(dis >= Size) {
        throw out_of_range{"wrong iterator"};
        return;
    }

    ATVector<type> temp(Size + 1);
    int current = 0;

    for(int i = 0; i < Size; i++){
        if(dis == i){
            temp[current] = value;
            current++;
            temp[current] = ptr[i];
            current++;
        }
        else{
            temp[current] = ptr[i];
            current++;
        }
    }
    Size++;
    delete [] ptr;
    ptr = new type[Size];
    for(int i = 0; i < Size; i++)
        ptr[i] = temp[i];
}


// ******************************** check equal function ********************************
template<typename type>
bool ATVector<type>::operator==(const ATVector<type> &h2) {
    if(this-> Size != h2.Size)
        return false;
    bool equal = true;
    for(int i = 0; i < Size; i++){
        if(ptr[i] != h2.ptr[i]) {
            equal = false;
        }
    }
    return equal;
}


// ******************************** check smaller than funcion ************************
template<typename type>
bool ATVector<type>::operator<(const ATVector<type> &h2) {
    bool smaller = true;
    bool equal = true;
    for(int i = 0; i < min(Size, h2.Size); i++){
        if(ptr[i] < h2.ptr[i]){
            equal = false;
            break;
        }
        if(ptr[i] > h2.ptr[i]) {
            smaller = false;
            equal = false;
            break;
        }
        if(ptr[i] != h2.ptr[i])
            equal = false;
    }
    if(equal && Size > h2.Size)
        return false;
    else if(equal && Size < h2.Size)
        return true;
    else if(equal && Size == h2.Size)
        return false;
    else
        return smaller;
}