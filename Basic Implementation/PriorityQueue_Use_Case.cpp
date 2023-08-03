#include"PriorityQueue_Class.cpp"

int main(){
    PriorityQueue PQ;
    PQ.insert(6);
    PQ.insert(9);
    PQ.insert(1);
    PQ.insert(0);
    cout<<PQ.removeMin()<<endl;
    cout<<PQ.removeMin()<<endl;
    cout<<PQ.removeMin()<<endl;
    cout<<PQ.removeMin()<<endl;
    cout<<PQ.removeMin()<<endl;
}