# The Lampkeeper
#### Description:

**The Lampkeeper** is a minimalist, terminal-based exploration game written entirely in C.  
It serves as my final project for CS50, combining randomness, matrix manipulation, state tracking, and a small visibility engine to create a simple but fully playable text-based experience.

The project is inspired by the charm of early computer games, where the entire world existed in ASCII characters and the player’s imagination filled in the rest. My goal was to see how much tension, atmosphere, and strategy I could create using only simple symbols and pure logic.

---

## 🌑 Core Concept

You play as the **Lampkeeper** (`*`), placed on a **12×12** board that starts almost completely dark.  
Your mission is to **reveal at least half of the map**. You do this by:
- moving around the board, and  
- lighting lamps scattered across it.

Visibility is intentionally limited. You can only see:
- tiles close to your character, and  
- tiles illuminated by lamps you step on.

This creates a small “fog-of-war” system where every move feels like exploration.

---

## 🕹️ Gameplay Mechanics

The controls are deliberately simple:

- `W`, `A`, `S`, `D` — Move up, left, down, right  
- Stepping on a lamp (`i`) lights it permanently  
- Breakable obstacles (`/`) can be destroyed if you still have **break credits**  
- Solid obstacles (`O`) act as walls  
- You can type **Quit** at any time to surrender  
- You win automatically when you reveal more than **50% of all tiles**

The game also includes a small emotional touch: if you decide to surrender, you receive one of three randomized farewell messages, each with a humorous tone.

---

## 🗺️ Map Generation

Each playthrough generates a completely new board.

### Random placement includes:
- **9 lamps** (`i`), each isolated from other objects  
- **40 solid obstacles** (`O`)  
- **20 breakable obstacles** (`/`)  
- The player character (`*`), positioned on a safe, empty tile  

The game uses `rand()` and `time(NULL)` to ensure randomness on every run.

I implemented a system to ensure lamps are not placed next to each other or too close to obstacles.  
This creates cleaner exploration paths and makes the map feel more intentional even though it's procedurally generated.

---

## 💡 Lamp System & Visibility Engine

The lighting mechanic is the heart of the game.

Whenever the player steps onto a lamp:

1. The lamp is marked as **lit**  
2. Its coordinates are saved into a **9×2 matrix**  
3. The lamp tile changes from `i` to `Y`  
4. The lamp permanently illuminates a **3×3 area** around it

Additionally, the player always has a **5×5 vision radius**, simulating real-time exploration.

### What this means in practice:
- The world feels dark and mysterious  
- Areas you illuminate stay visible forever  
- You gradually carve your own map  
- Your movement decisions matter more because you don’t know what’s ahead

---

## 🔧 Technical Breakdown

This project helped me apply many concepts from CS50, including:

### 1. Matrices & State Tracking
The game uses multiple 12×12 and 9×2 matrices to store:
- the board  
- visibility  
- lamp coordinates  
- player position  

### 2. Modular Design
The entire program is divided into small, reusable functions:
- `generateMap()`  
- `addLamps()`  
- `addObjects()`  
- `moveLamplighter()`  
- `printBoard()`  
- `saveLampCoordinate()`  
- and more…

Each function handles one task, making the code cleaner and easier to maintain.

### 3. Input Handling
Movement and surrender detection are processed character-by-character, allowing the game to:
- reject invalid input  
- detect the “Quit” command even if typed in mixed case  
- keep the game loop responsive

### 4. Randomization
Random map generation required:
- loop-based placement  
- collision checking  
- proximity validation  
- retrying logic until a valid configuration appeared  

### 5. Game Loop
A continuous loop tracks:
- player commands  
- victory condition  
- surrender condition  
- updated visibility  
- updated board state  

This includes redrawing the map on every move, giving the game an interactive feel even inside the terminal.

---

## 🎯 Design Philosophy

I chose to create a **terminal game** because I enjoy the minimalist aesthetic.  
Using only characters like `*`, `O`, `/`, and `i`, I wanted to create something that feels alive despite having no graphics.

This project allowed me to practice:

- procedural generation  
- stateful game loops  
- clean function architecture  
- debugging logic flow  
- expanding a simple concept into a complete, playable experience  
- writing code that’s easy to understand and extend

---

## 🏁 Final Thoughts

**The Lampkeeper** is small, simple, and intentionally minimal — but it contains a surprising amount of logic behind the scenes.

It started as an experiment in representing a world using only characters, but it grew into a full exploration game with lighting mechanics, obstacles, breakable elements, surrender detection, and randomized maps.

Thanks for checking out **The Lampkeeper** — and I see you in the dark. 💡✨


