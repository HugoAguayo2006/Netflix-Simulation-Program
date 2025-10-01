# 🎬 Integrative Project - Streaming System in C++

This project implements a **streaming service model** in C++ using **Object-Oriented Programming (OOP)**.  
The system allows organizing and displaying movies and series, including information such as title, duration, genre, and average ratings. It also supports series with episodes and seasons.

---

## 🚀 Features

- Implementation of **classes and inheritance**:
  - `Video` (abstract base class).
  - `Movie` and `Series` (derived classes).
  - `Episode` (composition within `Series`).
- **Polymorphism** for displaying, visualizing, and rating content.
- **Operator overloading** (`<`, `==`) to compare video durations.
- **CSV file handling** for storing and updating ratings.
- **Video playback (MP4)** and **image display (PNG)** using `ShellExecute` (Windows).
- Use of standard C++ libraries:
  - `<fstream>` for file reading/writing.
  - `<vector>` for dynamic rating lists.
  - `<chrono>` and `<thread>` for time control in playback.
- Compatible with **Windows OS**.

---

## 📂 Project Structure

- **Main Classes**: `Video`, `Movie`, `Series`, `Episode`.
- **Support Files**:
  - `ratings.csv` → stores ratings.
  - Media resources: videos and images linked to the content.

---

## ⚙️ Requirements

- **C++ Compiler** supporting C++11 or later (e.g., g++, MSVC).
- **Windows OS** (uses `<windows.h>` library).
- Multimedia files (videos and images) placed in the correct paths specified in the code.

---

## 🖥️ Installation & Execution

1. Clone the repository:
   ```bash
   git clone https://github.com/username/integrative-project.git
   cd integrative-project
