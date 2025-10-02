#include "deck.hpp"
#include <random>
#include <iostream>


Deck::Deck() {

}


int* Deck::Shuffle() {
    // Declaration
    int arrSize = 52;
    int* arr = new int[arrSize];
    
    for (int i = 0; i < arrSize; i++) {
        int temp = rand() % arrSize;
        bool exists = false;
        // Check if already in deck
        for (int j = 0; j < i; j++) {
            if (arr[j] == temp) {
                exists = true;
                break;
            }
        }
        // Retry || Set value
        if (exists == true) {
            i--; 
        } else {
            arr[i] = temp;
        }
    }
    // Debug
    // for (int i = 0; i < arrSize; i++) {
    //     std::cout << arr[i] << std::endl;
    // }

    return arr; // delete[] arr;
}