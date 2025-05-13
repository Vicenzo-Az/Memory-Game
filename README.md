# Memory Game (Jogo da Memória)

A simple command-line memory game developed in C for a Logic and Programming course during the first semester of Internet Systems. The game challenges players to match pairs of symbols on a 4x4 grid.  
**Note:** The code is written in Portuguese (pt-br) and was designed for educational purposes.

---

## 🎮 Features
- **4x4 grid** with 8 pairs of numbers.
- **Symbol shuffling** for a unique experience each game.
- **Simple text interface** with hidden/revealed cards.
- **Input validation** for row and column selections.

## 🚀 How to Run
### Prerequisites
- GCC compiler installed.
- **Windows** recommended (uses `system("cls")`; for Linux/macOS, replace with `system("clear")` in the code).

## 🕹️ How to Play
1. Enter **row** (1-4) and **column** (1-4) numbers to flip two cards.
2. If the symbols match, they stay visible, and your score increases by 10.
3. If not, the cards flip back, and you try again.
4. Win by matching all 8 pairs!

## 🧠 Code Structure (Key Functions)
| Function               | Description                                                                 |
|------------------------|-----------------------------------------------------------------------------|
| `inicializarTabuleiro` | Initializes and shuffles symbols on the board.                              |
| `imprimirTabuleiro`    | Displays the board, hiding unmatched cards with `*`.                       |
| `verificarPar`         | Checks if two selected cards match.                                        |
| `main`                 | Manages game loop, input, score, and win condition (all pairs revealed).    |

## 📝 Notes
- The game uses **ANSI escape codes** to clear the screen between moves (`system("cls")`).
- Inputs are validated to ensure they are within the 1-4 range.
- Variables and comments are in **Portuguese** (pt-br) as per the academic context.

## 📜 License
This project is open-source. Feel free to use, modify, or adapt it for educational purposes.
