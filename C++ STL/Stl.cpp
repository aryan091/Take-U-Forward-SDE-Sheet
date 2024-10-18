// C++ STL

#include <bits/stdc++.h>
using namespace std;

// Algorithms
// Containers
// Functions
// Iterators

// Pair

void explainPairs()
{
    pair<int, int> p = {1, 2};

    cout << p.first << " ---> " << p.second << endl;

    pair<int, pair<int, int>> p1 = {1, {2, 3}};

    cout << p1.first << " ---> " << p1.second.first << " ---> " << p1.second.second << endl;

    pair<int , int> arr[3] = {{1, 2}, {3, 4}, {5, 6}};
    cout << arr[1].first << " ---> " << arr[1].second << endl;
}



// Vector

void explainVector()
{
    vector<int> v = {1, 2, 3, 4, 5};   // Singly Linked List

    vector<int> v1;
    v1.push_back(1);
    v1.emplace_back(2);

    vector<pair<int, int>> vec;
    vec.push_back({1, 2});
    vec.emplace_back(3, 4);

    // Iterator

    // begin -> first element of vector .begin gives us address of first element to access it use *(begin)
    // end -> next to last element of vector

    for(auto it : v)
    {
        cout << it << " ";
    }

    v.erase(v.begin()+1);
    cout << endl;

    for(auto it : v)
    {
        cout << it << " ";
    }

    vector<int> vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  

    cout << endl;

    for(auto it : vector)
    {
        cout << it << " ";
    }

    vector.erase(vector.begin()+1, vector.begin()+3); //[begin, end) // 1 4 5 6 7 8 9 10
    cout << endl;

   for(auto it : vector)
    {
        cout << it << " ";
    }

    // Insert

    std::vector<int> vec2(2 , 100);
    cout << endl;
    vec2.insert(vec2.begin() + 1, 2 , 10);

    std::vector<int> copy(2 , 50);
    vec2.insert(vec2.begin() , copy.begin(), copy.end());


    for(auto it : vec2)
    {
        cout << it << " ";
    }

    cout << endl << vec2.size() << endl << vec2.capacity() << endl << vec.empty() << endl;
    vec2.pop_back(); // Removes Last Element


     for(auto it : vec2)
    {
        cout << it << " ";
    }
    cout << endl;
}

void explainList()
{
    list<int> ls; // Doubly Linked List
    ls.push_back(2);
    ls.emplace_back(3);

    ls.push_front(1); // In vector it is costly 
    ls.emplace_front(0);

    for(auto it : ls)   
    {
        cout << it << " ";
    }

    cout << endl;
}

void explainStack()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.emplace(4);

 
    cout << s.size() << " " << s.empty() << " " <<s.top() << endl;
    // All operations are O(1)
}   

void explainQueue(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.emplace(4);

    cout << q.front() << " " << q.back() << endl;
    q.pop();
    cout << q.size() << " " << q.empty() << " " << q.front() << endl;
}

void explainPriorityQueue(){
    priority_queue<int> pq;
    pq.push(10);
    pq.push(2);
    pq.push(3);
    pq.emplace(4);

    cout << pq.top() << endl;
    pq.pop();
    cout << pq.size() << " " << pq.empty() << " " << pq.top() << endl;

    // Data is not stored in linear form
    // Minimum Heap

    cout << "-------MIN HEAP---------" << endl;

    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(10);
    pq1.push(2);
    pq1.push(3);
    pq1.emplace(4);

    cout << pq1.top() << endl;
    pq1.pop();
    cout << pq1.size() << " " << pq1.empty() << " " << pq1.top() << endl;


    cout << "Push ---> Log(N)" << endl;
    cout << "Pop ---> Log(N)" << endl;
    cout << "Top ---> O(1)" << endl;
}

void explainSet(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.emplace(4);   

    cout << s.size() << " " << s.empty() << " " << *s.begin() << endl;

    auto it = s.find(2);

    s.erase(1);
    int count = s.count(4);

    auto it1 = s.lower_bound(2);
    auto it2 = s.upper_bound(2);

    cout << *it1 << " " << *it2 << " " << count << endl;

    //  All operations are O(Log(N))
}

void explainMultiSet(){
    // Sorted but can allow duplicates
    multiset<int> s;
    s.insert(1);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.emplace(4);

    cout << s.size() << " " << s.empty() << " " << *s.begin() << endl;

    auto it = s.find(2);

    s.erase(1); // Erases all occurences of 1
    int count = s.count(4);

    auto it1 = s.lower_bound(2);
    auto it2 = s.upper_bound(2);

    cout << *it1 << " " << *it2 << " " << count << endl;    
}

void explainUnorderedSet(){
    // Hash Table
    // All operations are O(1)

    // When collosion occurs, it uses chaining complexity goes to O(N)

    unordered_set<int> s;
    s.insert(1);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.emplace(4);

    cout << s.size() << " " << s.empty() << " " << *s.begin() << endl;

    auto it = s.find(2);

    s.erase(1);
    int count = s.count(4);
    cout << *it << " " << count << endl;
}

void explainMap(){
    // Sorted
    // Unordered
    // Allows duplicates
    // All operations are O(Log(N))

    map<int, int> m;
    m[1] = 10;
    m[2] = 20;
    m[3] = 30;
    m[4] = 40;

    auto it = m.find(2);

    m.insert({5, 50});
    m.emplace(6, 60);

    cout << m.size() << " " << m.empty() << " " << it->first << endl;
}

void explainMultiMap()
{
    multimap<int, int> m;
    m.insert({1, 10});
    m.insert({2, 20});
    m.insert({4, 30});
    m.insert({4, 40});

    auto it = m.find(2);

    m.insert({5, 50});
    m.emplace(6, 60);

    cout << m.size() << " " << m.empty() << " " << it->first << endl;
}

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if( p1.second < p2.second ) return true;
    if( p1.second > p2.second ) return false;

    if( p1.first > p2.first ) return true;

    return false;
}

void explainSort()
{
    vector<int> v = {1, 2, 3, 4, 5};
    sort(v.begin(), v.end() , greater<int>());
    for (auto i : v)
        cout << i << " ";
    cout << endl;


    pair<int, int> p[] = {{1, 2}, {2, 1}, {4, 1}};
    sort(p, p + 3, comp  );

    for (auto i : p)
        cout << i.first << " " << i.second << endl;
}
void explainBinary()
{
    int num = 6;
    int cnt = __builtin_popcount(num);

    cout << cnt << endl;

    long long num1 = 1657765356364;
    int cnt_ll = __builtin_popcountll(num1);

    cout << cnt_ll << endl;
}

void explainPermutation()
{
    string s = "abc";
    do{
        cout << s << endl;
    }while (next_permutation(s.begin(), s.end()));
}

void explainMaxElement()
{
    int p[] = {1, 2, 3, 4, 5};
    int n = sizeof(p) / sizeof(p[0]);

    int maxi=  *max_element(p, p + n);

    cout << maxi << endl;

}
int main()
{
    cout << " --------- Pairs --------- " << endl;
    explainPairs();
    cout << " --------- Vector --------- " << endl;
    explainVector();
    cout << " --------- List --------- " << endl;
    explainList();
    cout << " --------- Stack ( LIFO ) --------- " << endl;
    explainStack();
    cout << " --------- Queue ( FIFO ) --------- " << endl;
    explainQueue();
    cout << " --------- Priority Queue --------- " << endl;
    explainPriorityQueue();
    cout << " --------- Set ( Sorted & Unique ) --------- " << endl;
    explainSet();
    cout << " --------- MultiSet ( Sorted ) --------- " << endl;
    explainMultiSet();
    cout << " --------- UnorderedSet ( Unique ) --------- " << endl;
    explainUnorderedSet();
    cout << " --------- Map ( Key - Value -> ( Unique Keys in Sorted Order ) ) --------- " << endl;
    explainMap();
    cout << " --------- MultiMap ( Key - Value -> ( Duplicates Keys in Sorted Order ) ) --------- " << endl;
    explainMultiMap();
    cout << " --------- MultiMap ( Key - Value -> ( Duplicates Keys in Sorted Order ) ) --------- " << endl;
    explainMultiMap();
    cout << " ---------Sort (Decreasing Order) --------- " << endl;
    explainSort();
    cout << " --------- Binary (No of Set Bits)--------- " << endl;
    explainBinary();
    cout << " --------- Permutation --------- " << endl;
    explainPermutation();
    cout << " --------- Max Element --------- " << endl;
    explainMaxElement();
    return 0;
}