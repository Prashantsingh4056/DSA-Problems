#include <bits/stdc++.h>
using namespace std;

int main() {
    
    priority_queue<int> pq;  //*    Max heap

    pq.push(10);
    pq.push(20);
    pq.push(70);
    pq.push(110);
    pq.push(90);
    pq.push(13);
    pq.push(120);

    cout << pq.top() << endl;

    //  Delete
    pq.pop();

    cout << pq.top() << endl;

    cout << pq.size() << endl;

    while(!pq.empty()){

        cout << pq.top() << " ";
        pq.pop();
    }


    //* Min Heap :
    priority_queue<int , vector<int> , greater<int>> PQ;

    PQ.push(12);
    PQ.push(45);
    PQ.push(36);
    PQ.push(67);
    PQ.push(98);

    cout << PQ.top() << endl;

    while(!PQ.empty()){

        cout << PQ.top() << " ";
        PQ.pop();
        
    }

    return 0;
}