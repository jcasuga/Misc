#include <iostream>

void sort(int data[], int size);

int main(){

int A[11]= {4, -3, 9, 8, 7, -4, -2, -1, 0, 6, -5};

sort(A, 11);
for(int i = 0; i <= 11; i++){
    std::cout << A[i] << ", ";
}
}

void sort(int data[], int size){
        for(int i = 0; i < size-3; i++){

        for(int j =0; j < size-2; j++){
           
            if(data[j] > data[j+1]){
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
                
                
            }
        }
    }
}