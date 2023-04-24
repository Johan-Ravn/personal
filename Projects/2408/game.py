""" 2048 game"""

import random as rand

class game:
    def __init__(self, rows, columns) -> None:
        self.empty_space = '_'
        self.board = [[self.empty_space] * columns] * rows
        self.board_row = rows
        self.board_columns = columns
        self.total_elements = rows * columns
    
    def display_board(self):
        for i in self.size_board_row:
            for j in self.size_board_columns:
                print(f"| {self.board[i][j]}")

    def game_done(self) -> bool:
        game_done = True
        for i in self.board_columns:
            for j in self.board_row:
                if (self.board[i][j] == self.empty_space):
                    game_done = False
        return game_done
    
    def add_2(self):
        empty_spaces_index = []
        index_to_add = 0
        for i in self.board_columns:
            for j in self.board_row:
                if (self.board[i][j] == self.empty_space):
                    empty_spaces_index.insert([i, j])
        index_to_add = rand(empty_spaces_index)
        self.board[][]

def main():
    start_game = game(4, 4)

if __name__ == '__main__':
    main()

