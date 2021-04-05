#pragma once

#include "Direction.hpp"
#include <string>
#include <map>
#include <stdint.h>

using namespace std;

namespace ariel {

    class Board {

        private:
        //****************{min_row,max_row,min_col,max_col}
        uint min_max[4] = {UINT16_MAX,0,UINT16_MAX,0};

        map<uint,map<uint,char>> board;
        // void resizeBoard(uint row, uint col);

        public:
            Board(){};
            void post(uint row, uint col, Direction d, string message);
            string read(uint row, uint col,Direction d, uint num);
            void show();
    };
}
