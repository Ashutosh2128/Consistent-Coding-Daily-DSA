#include<iostream>
using namespace std;

class Heap {
    public:
        int* arr;
        int capacity;
        int size;

        Heap(int capacity) {
            this -> arr = new int[capacity];
            this -> capacity = capacity;
            this -> size = 0;
        }

        void insertion(int val) {
            if(size == capacity - 1) {
                cout << "Overflow" << endl;
                return;
            }

            size++;
            arr[size] = val;

            int i = size;
            while(i > 1) {
                int pIndex = i/2;

                if(arr[pIndex] < arr[i]) {
                    swap(arr[pIndex], arr[i]);
                    i = pIndex;
                }
                else break;
            }
        }

        //always deletion occur in first node
        void deletion() {
            if(size == 0) {
                cout << "Underflow" << endl;
                return;
            }

            swap(arr[1], arr[size]);
            size--;

            heapify(1);
        }

        void heapify(int index) {
            if(size == 0) {
                cout << "All entry deleted from heap" << endl;
                return;
            }
            
            int bigIndex = index;
            int leftIndex = bigIndex * 2;
            int rightIndex = bigIndex * 2 + 1;

            if(leftIndex <= size && arr[bigIndex] < arr[leftIndex]) bigIndex = leftIndex;
            if(rightIndex <= size && arr[bigIndex] < arr[rightIndex]) bigIndex = rightIndex;

            if(bigIndex != index) {
                swap(arr[index], arr[bigIndex]);
                heapify(bigIndex);
            }
        }

        void print() {
            for(int i = 1; i <= size; i++) cout << arr[i] << " ";
            cout << endl;
        }
};

int main() {
    Heap pq(7);

    pq.insertion(10);
    pq.print();

    pq.insertion(20);
    pq.print();

    pq.insertion(30);
    pq.print();

    pq.insertion(40);
    pq.print();

    pq.insertion(50);
    pq.print();

    pq.insertion(60);
    pq.print();

    pq.insertion(70);
    pq.print();

    pq.deletion();
    pq.print();

    pq.deletion();
    pq.print();

    pq.deletion();
    pq.print();

    pq.deletion();
    pq.print();

    pq.deletion();
    pq.print();

    pq.deletion();
    pq.print();

    return 0;
}