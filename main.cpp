/*
Name : Ahmed mohamed taha
ID   : 20210033
task : 1
last date modified : 12/6/2022
Description : vector impelmentation with oop
*/

#include "ATVector.cpp"

int main(){
    int arr[] = {1, 2, 3};
    ATVector<int> v1(arr, 3);
    cout <<"vector 1 : \n";
    cout << v1 << '\n';

    cout<<"vector 1 after pushing 0 :\n";
    v1.push_back(0);
    cout << v1 << '\n';

    cout << "vector 1 after clearing :\n";
    v1.clear();
    cout << v1 << '\n';

    v1.push_back(12);
    v1.push_back(4);
    cout << "vector 1 after pushing 12, 4 : \n";
    cout << v1 << '\n';


    ATVector<int> v2(v1);
    v1[0] = 3;
    v1[1] = 5;
    cout << "vector 1 and vector 2 after copying and changing vector 1 : \n";
    cout << v1 << '\n' << v2 << '\n';

    v2 = move(v1);
    cout << "vector 1 and vector 2 after moving v1 to v2 : \n";
    cout << v1 << '\n' << v2 << '\n';

    cout << "vector 2 size : ";
    cout << v2.size() << '\n';

    cout << "vector 2 after deleting first element : \n";
    v2.erase(v2.begin());
    cout << v2 << '\n';

    ATVector<string> v3(5);
    cout <<"capacity of vector 3 after creating it with size 5 and its size : \n";
    cout << v3.capacity() << '\n' << v3.size() << '\n';

    v3[0] = "ahmed";
    v3[1] = "mohamed";
    v3[2] = "abdelghany";
    v3[3] = "saad";
    v3[4] = "ali";
    cout <<"vector 3 after assigning values to it : \n";
    cout << v3 << '\n';

    cout << "vector 3 after pop back : \n";
    v3.pop_back();
    cout << v3 << '\n';

    cout << "vector 3 after deleting from index 1 to index 2 : \n";
    v3.erase(v3.begin()+1, v3.begin()+2);
    cout << v3 << '\n';

    cout <<"vector 3 after inserting \"taha\" to index 1 : \n";
    v3.insert(v3.begin()+1, "taha");
    cout << v3 << '\n';

    cout << "is vector 3 empty ? : ";
    cout << v3.empty() << '\n';

    cout <<"creating vector 4 copying vector 3 on it and check if they are equal : ";
    ATVector<string> v4(v3);
    cout << (v3 == v4) << '\n';

    v3[0] ="aaaa";
    cout << "is vector 3 less than vector 4 after changing its first index to \"aaaa\" : ";
    cout << (v3 < v4) << '\n';

    ATVector<int> v5(2);
    v5[0] = 1;  v5[1] = 4;
    ATVector<int> v6(2);
    v6[0] = 2;  v6[1] = 5;
    cout <<"is vector 5(1, 4) is less than vector 6(2, 5) : ";
    cout << (v5 < v6) << '\n';
}