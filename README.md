# LampKeeper

A terminal-based exploration game where players navigate a mysterious dark 12x12 grid, uncovering hidden lamps and secrets.

---

## Tech Stack

![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS-lightgrey.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

---

## Features

- Procedurally generated 12x12 dark grid.
- Real-time terminal rendering with ANSI colors.
- Hidden lamps that illuminate surrounding cells.
- Simple yet engaging command interface.
- Score tracking and high‑score persistence.
- Cross‑platform support (Linux/macOS).

---

## Installation

1. **Prerequisites**
   - A C++17 compatible compiler (e.g., `g++` or `clang++`).
   - Make utility (optional, for convenience).
2. **Clone the repository**
   ```bash
   git clone https://github.com/brunorossani/lampkeeper.git
   cd lampkeeper
   ```
3. **Build the project**
   ```bash
   # Using make (if provided)
   make
   # Or compile manually
   g++ -std=c++17 -O2 -Wall lampkeeper.cpp -o lampkeeper
   ```
4. **Run the game**
   ```bash
   ./lampkeeper
   ```

---

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests.

---

## License

This project is licensed under the MIT License – see the [LICENSE](LICENSE) file for details.
