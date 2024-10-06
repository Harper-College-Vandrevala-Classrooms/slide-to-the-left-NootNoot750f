#include <iostream>
#include <string>
#include <cassert>
#include <vector>
using namespace std;

void array_shift_left(int array[], int size, int numberOfShifts) {
    numberOfShifts = numberOfShifts % size;
    if(numberOfShifts == 0) {
        return;
    }
    for(int i = 0; i < numberOfShifts; i++) {
        int first = array[0];
        for(int j = 0; j < size-1; j++) {
            array[j] = array[j + 1];
        }
        array[size-1] = first;
    }
}
void array_shift_right(int array[], int size, int numberOfShifts) {
    numberOfShifts = numberOfShifts % size;
    if (numberOfShifts == 0) {
        return;
    }
    for (int i = 0; i < numberOfShifts; i++) {
        int last = array[size - 1];
        for (int j = size - 1; j > 0; j--) {
            array[j] = array[j - 1];
        }
        array[0] = last; 
    }
}
void vector_shift(vector<int> &theVector, int numberOfShifts) {
    //Passing by reference instead of passing by value so that we can change the values
    int size = theVector.size();
    numberOfShifts = numberOfShifts % size;
    if(numberOfShifts == 0) {
        return;
    }
    for(int i = 0; i < numberOfShifts; i++) {
        int last = theVector[size - 1];
        for(int j = size - 1; j > 0; j--) {
            theVector[j] = theVector[j - 1];
        }
        theVector[0] = last;
    }
}
    int main(){
    int numberArrayLeft[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int numberArrayRight[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> theVector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //Shift Array to the Left
    array_shift_left(numberArrayLeft, 10, 1);//This should shift the array over by 1 so then it would be {2,3,4,5,6,7,8,9,10,1}
    assert(numberArrayLeft[0] == 2);

    //Shift Array to the Right
    array_shift_right(numberArrayRight, 10, 1);//This should shift the array over by 1 so then it would be {10,1,2,3,4,5,6,7,8,9}
    assert(numberArrayRight[0] == 10);

    //Shift Vector
    vector_shift(theVector,1); //Should be the same as the shift to the right one
    assert(theVector[0] == 10);
//
    cout << "All Tests Passed!" << endl;
}