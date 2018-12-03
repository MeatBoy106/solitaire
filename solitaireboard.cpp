#include <cstdlib>
#include "solitaireboard.hpp"

using namespace std;

constexpr SolitaireBoard::board_t SolitaireBoard::europeanBoard;
constexpr SolitaireBoard::board_t SolitaireBoard::englishBoard;

SolitaireBoard::SolitaireBoard(const SolitaireBoard::board_t& board, const Position& p):
    mBoard(board)
{
    mBoard[p.i][p.j] = fre;
}

void SolitaireBoard::move(const Position& from, const Position& to){
    auto fi = from.i;
    auto fj = from.j;
    auto ti = to.i;
    auto tj = to.j;
    auto ii = (ti + fi) / 2;
    auto ij = (tj + fj) / 2;
    
    mBoard[fi][fj] = fre;
    mBoard[ii][ij] = fre;
    mBoard[ti][tj] = peg;
}
    
void SolitaireBoard::moveChecked(const Position& from, const Position& to){
    auto fi = from.i;
    auto fj = from.j;
    auto ti = to.i;
    auto tj = to.j;

    if(mBoard[fi][fj] != peg) throw runtime_error("Moving from a non-peg position.");
    if(mBoard[ti][tj] != fre) throw runtime_error("Moving to a non empty position.");
    if(fi != ti){
        if(fj != tj) throw runtime_error("Moving diagonaly.");
        if(abs(static_cast<int64_t>(ti - fi)) != 2) throw runtime_error("Moving neither 0 nor 2 lines from initial position.");
        
    }
    else if(fj == tj) throw runtime_error("Moving nowhere.");
    else if(abs(static_cast<int64_t>(tj - fj)) != 2) throw runtime_error("Moving neither 0 nor 2 columns from initial position.");
    
    auto ii = (ti + fi) / 2;
    auto ij = (tj + fj) / 2;
    if(mBoard[ii][ij] != fre) throw runtime_error("Trying to move accross a non-peg position.");
    
    mBoard[fi][fj] = fre;
    mBoard[ii][ij] = fre;
    mBoard[ti][tj] = peg;
}
