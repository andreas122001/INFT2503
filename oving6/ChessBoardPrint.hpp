#pragma once
#include "ChessBoard.hpp"
#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>

using namespace std;

class ChessBoardPrint {

public:
  ChessBoardPrint(ChessBoard *board_) : board(board_) {

    board->after_move_piece = [this]() { printBoard(); };
    board->on_lost_game = [](ChessBoard::Color color) {
      cout << "\n***Game over!***\n==="
           << (color == ChessBoard::Color::BLACK ? "BLACK" : "WHITE")
           << " wins!==="
           << endl;
    };
    board->on_piece_move = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
      cout << "\n-> Piece " << piece.to_string() << " moved from " << from << " to " << to << endl;
    };
    board->on_piece_move_invalid = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
      cout << "!! Invalid move !!: Can not move " << piece.to_string() << " from " << from << " to " << to << endl;
    };
    board->on_piece_move_missing = [](const string &square) {
      cout << "!! Invalid move !!: slot " << square << " does not contain a piece" << endl;
    };
    board->on_piece_removed = [](const ChessBoard::Piece &piece, const string &square) {
      cout << "Piece " << piece.to_string() << " lost at " << square << endl;
    };
  }

  ChessBoard *board;

  void printBoard() {
    cout << "  _______________" << endl;
    cout << "  a b c d e f g h" << endl;
    for (size_t i = board->squares.size(); i-- > 0;) {
      cout << i + 1 << " ";
      for (size_t j = 0; j < board->squares[0].size(); j++) {
        auto &piece = board->squares[j][i];
        cout << (piece ? piece->to_string() : "- ");
      }
      cout << endl;
    }
    cout << endl;
  }
};
