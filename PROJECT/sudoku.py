import tkinter as tk
from tkinter import messagebox
import random
import copy


def is_valid(board, row, col, num):
    for i in range(9):
        if board[row][i] == num or board[i][col] == num:
            return False

    start_row, start_col = 3 * (row // 3), 3 * (col // 3)
    for i in range(3):
        for j in range(3):
            if board[start_row + i][start_col + j] == num:
                return False

    return True


def solve_sudoku(board):
    for row in range(9):
        for col in range(9):
            if board[row][col] == 0:
                nums = list(range(1, 10))
                random.shuffle(nums)
                for num in nums:
                    if is_valid(board, row, col, num):
                        board[row][col] = num
                        if solve_sudoku(board):
                            return True
                        board[row][col] = 0
                return False
    return True

def generate_puzzle():
    board = [[0 for _ in range(9)] for _ in range(9)]
    solve_sudoku(board)

    solution = copy.deepcopy(board)

    attempts = 40
    while attempts > 0:
        r, c = random.randint(0, 8), random.randint(0, 8)
        if board[r][c] != 0:
            board[r][c] = 0
            attempts -= 1

    return board, solution



class SudokuGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Sudoku Solver")

        self.entries = [[None for _ in range(9)] for _ in range(9)]
        self.fixed = [[False for _ in range(9)] for _ in range(9)]
        self.solution = None

        vcmd = (self.root.register(self.validate_input), '%P')

        self.create_grid(vcmd)
        self.create_buttons()
        self.generate() 

    def validate_input(self, value):
        if value == "": return True
        if len(value) > 1: return False
        return value.isdigit() and 1 <= int(value) <= 9

    def create_grid(self, vcmd):
        for i in range(9):
            for j in range(9):
                e = tk.Entry(self.root, width=2, font=("Arial", 18), justify='center',
                             validate='key', validatecommand=vcmd)
                e.grid(row=i, column=j, padx=2, pady=2)
                self.entries[i][j] = e

    def load_board(self, board):
        for i in range(9):
            for j in range(9):
                self.entries[i][j].delete(0, tk.END)
                if board[i][j] != 0:
                    self.entries[i][j].insert(0, str(board[i][j]))
                    self.entries[i][j].config(state='disabled')
                    self.fixed[i][j] = True
                else:
                    self.entries[i][j].config(state='normal')
                    self.fixed[i][j] = False

    def get_board(self):
        board = []
        for i in range(9):
            row = []
            for j in range(9):
                val = self.entries[i][j].get()
                row.append(int(val) if val.isdigit() else 0)
            board.append(row)
        return board

    def generate(self):
        puzzle, self.solution = generate_puzzle()
        self.load_board(puzzle)

    def fill_solution(self):
        if self.solution:
            self.load_board(self.solution)

    def check_solution(self):
        user_board = self.get_board()
        if user_board == self.solution:
            messagebox.showinfo("Result", "Correct Solution!")
        else:
            messagebox.showerror("Result", "Incorrect Solution")

    def clear_user(self):
        for i in range(9):
            for j in range(9):
                if not self.fixed[i][j]:
                    self.entries[i][j].delete(0, tk.END)

    def create_buttons(self):
        tk.Button(self.root, text="Generate", command=self.generate).grid(row=10, column=0, columnspan=2)
        tk.Button(self.root, text="Fill Solution", command=self.fill_solution).grid(row=10, column=2, columnspan=2)
        tk.Button(self.root, text="Check", command=self.check_solution).grid(row=10, column=4, columnspan=2)
        tk.Button(self.root, text="Clear", command=self.clear_user).grid(row=10, column=6, columnspan=2)

  

if __name__ == "__main__":
    root = tk.Tk()
    app = SudokuGUI(root)
    root.mainloop()