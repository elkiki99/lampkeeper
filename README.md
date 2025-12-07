# The Lampkeeper
#### Video Demo: <PASTE YOUR YOUTUBE URL HERE>
#### Description:

**The Lampkeeper** is a minimalist, terminal-based exploration game written entirely in C.  
It was built as my final project for CS50, inspired by old-school text interfaces and the charm of purely logic-driven games.

The objective is simple:  
You play as the **Lampkeeper** (`*`) and must reveal at least **half of the map** to win.  
The board begins almost completely dark, and visibility depends on two things:
- the player’s proximity, and  
- the lamps that have been lit around the map.

### 🕹️ Gameplay
- Move with **W, A, S, D**  
- Step on lamps (`i`) to light them permanently  
- Breakable obstacles (`/`) can be destroyed if you still have break credits  
- Solid obstacles (`O`) cannot be crossed  
- Type **“Quit”** to give up at any time  
- Win automatically when more than half of the board has been revealed

### 🔧 Technical Features
- 12×12 map dynamically generated with random obstacles and lamp placement  
- Fog-of-war visibility system  
- Storage of lamp coordinates in a 9×2 matrix  
- Clean modular structure with separate functions for:
  - map generation  
  - rendering  
  - movement  
  - lamp tracking  
  - surrender detection  
- Entirely self-contained C program — no external libraries needed

### 🎯 Purpose
I chose to build a game in the terminal because I enjoy the **minimalist aesthetic** and the challenge of expressing creativity with limited tools.  
This project helped me practice:
- arrays and matrices  
- randomization  
- state management  
- input handling  
- and building a full user experience with pure C logic

---

Thanks for checking out **The Lampkeeper**!
