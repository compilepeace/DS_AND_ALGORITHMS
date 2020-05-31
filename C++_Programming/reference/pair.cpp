#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


// make_pair() - To make 2 elements as single entity (a pair) 
int main()
{
    pair<int, char> p;
    p.first  = 10;
    p.second = 'a';

    pair<int, char> p1(p);
    cout << p1.first << " : " << p1.second << endl;


    pair<int, string> p2 = make_pair(007, "James bond");
    cout << p2.first << " : " << p2.second << endl;


    pair<pair<int,int>, string> person;
    person.first.first = 0;
    person.first.second = 1;
    person.second = "Abhinav";

    cout << person.second << " is @ (" << person.first.first << ", " << person.first.second << ")\n";
}
