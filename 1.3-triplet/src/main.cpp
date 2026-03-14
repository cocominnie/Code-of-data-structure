#include "triplet.hpp"

int main()
{
    Triplet t;

    if (InitTriplet(t, 1, 2, 3) == OK) {
        cout << "Triplet values: " << t[0] << ", " << t[1] << ", " << t[2] << endl;
    }
   
    int e = 0;
    if (Get(t, 1, e) == OK) {
        cout << "Value at index 1: " << e << endl;
    } else {
        cout << "Failed to get value at index 1." << endl;
    }

    if (Put(t, 2, 42) == OK) {
        cout << "Value at index 2 updated successfully." << endl;
        cout << "Updated Triplet values: " << t[0] << ", " << t[1] << ", " << t[2] << endl;
    } else {
        cout << "Failed to update value at index 2." << endl;
    }

    if(IsAscending(t)) {
        cout << "The triplet is in ascending order." << endl;
    } else if(IsDescending(t)) {
        cout << "The triplet is in descending order." << endl;
    } else {
        cout << "The triplet is neither in ascending nor descending order." << endl;
    }

    int maxVal, minVal;
    if(Max(t, maxVal) == OK) {
        cout << "Maximum value in the triplet: " << maxVal << endl;
    } else {
        cout << "Failed to get maximum value." << endl;
    }

    if(Min(t, minVal) == OK) {
        cout << "Minimum value in the triplet: " << minVal << endl;
    } else {
        cout << "Failed to get minimum value." << endl;
    }

    if (DestroyTriplet(t) == OK) {
        cout << "Triplet destroyed successfully." << endl;
    } else {
        cout << "Failed to destroy the triplet." << endl;
    }

    return 0;
}
