#pragma once
#include <vector>


class Deck {
    public:
        Deck();
        int* Shuffle();
    private:
        int cards[];
};

// spade : 0 - 12
// heart : 13 - 25
// diamond : 26 - 38
// club : 39 - 51