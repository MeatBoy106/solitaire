#ifndef SOLITAIREBOARD_H
#define SOLITAIREBOARD_H

#include <array>

class SolitaireBoard
{
    enum PositionState: uint8_t{
        out,
        fre,
        peg
    };

    using board_t = std::array<std::array<PositionState, 7>, 7>;
    board_t mBoard;
    
public:
    struct Position{
        board_t::size_type i;
        board_t::size_type j;
    };
    
public:
    SolitaireBoard() = delete;
    SolitaireBoard(const board_t& board, const Position& p);
    
    PositionState look(Position p){return mBoard[p.i][p.j];}
    
    void move(const Position& from, const Position& to);
    
    void moveChecked(const Position& from, const Position& to);
        
public:
    static constexpr board_t europeanBoard = {
        out, out, peg, peg, peg, out, out,
        out, peg, peg, peg, peg, peg, out,
        peg, peg, peg, peg, peg, peg, peg,
        peg, peg, peg, fre, peg, peg, peg,
        peg, peg, peg, peg, peg, peg, peg,
        out, peg, peg, peg, peg, peg, out,
        out, out, peg, peg, peg, out, out,
    };
    
    static constexpr board_t englishBoard = {
        out, out, peg, peg, peg, out, out,
        out, out, peg, peg, peg, out, out,
        peg, peg, peg, peg, peg, peg, peg,
        peg, peg, peg, fre, peg, peg, peg,
        peg, peg, peg, peg, peg, peg, peg,
        out, out, peg, peg, peg, out, out,
        out, out, peg, peg, peg, out, out,
    };
};

#endif // SOLITAIREBOARD_H
