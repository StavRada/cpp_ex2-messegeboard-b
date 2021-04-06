#include <iostream>
#include "Board.hpp"
#include <ctype.h>
using namespace std;
using namespace ariel;

namespace ariel{

    //"hello"
    void Board::post(uint row, uint col, Direction direction, string const & message) {
        //****************{min_row,max_row,min_col,max_col}
        min_max[0]=min(min_max[0],row);
        min_max[1]=max(min_max[1],row);
        min_max[2]=min(min_max[2],col);
        min_max[3]=max(min_max[3],col);

        for(char c: message){
        this->board[row][col] = c;
        //Horizontal ->  col ++
        // Vertical -> row ++
        (direction==Direction::Horizontal) ? col++ : row ++;
        // cout << row <<" "<< col << '\n';
        }
    }

    string Board::read(uint row, uint col, Direction direction, uint length)
    {
        string ans;
        for(int i=0;i<length;i++){
          (this->board[row][col] == '\0') ? ans+='_' : ans+=this->board[row][col];
          (direction==Direction::Horizontal) ? col++ : row ++;
        }
        return ans;
    }

    void Board::show()
    {
      string ans;
      //****************{min_row,max_row,min_col,max_col}

      std::cout << min_max[0] <<" "<< min_max[1]<<" "<< min_max[2]<<" "<< min_max[3] << '\n';
      for(uint row =min_max[0]-1; row< min_max[1]+3; row++ ){
        for(uint col =min_max[2]-1; col< min_max[3]+4; col++ ){
          (this->board[row][col] == '\0') ? ans+='_' : ans+=this->board[row][col];
        }
        ans+="\n";
      }
      std::cout << ans << '\n';
    }
}
