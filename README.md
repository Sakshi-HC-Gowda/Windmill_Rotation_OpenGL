🌬️ Windmill Rotation – Computer Graphics Project (OpenGL)
📘 Overview

This project demonstrates a rotating windmill using OpenGL and FreeGLUT in C++.
The windmill rotates clockwise or anticlockwise using keyboard arrow keys and forms a simple animated 2D scene with sky, ground, sun, and clouds.

🖼️ Features

🌀 Animated rotation of windmill blades

⬅️➡️ Keyboard control for clockwise / anticlockwise rotation

⬆️⬇️ Start / Stop the rotation

☀️ Scenic background with sky, sun, and ground

🏗️ Broader windmill pole for realistic appearance

⚙️ Controls
Key	Action
⬅️ Left Arrow	Rotate Anticlockwise
➡️ Right Arrow	Rotate Clockwise
⬇️ Down Arrow	Stop Rotation
⬆️ Up Arrow	Start / Resume Rotation
🧩 Requirements

C++ Compiler (MinGW or MSYS2)

FreeGLUT library

OpenGL libraries (opengl32, glu32, freeglut)

🏗️ Installation (Windows)

Install MinGW-w64 → Add C:\MinGW\bin to PATH.

Download and extract FreeGLUT (32-bit or 64-bit).

Copy files to:

freeglut/include/GL   →  C:\MinGW\include\GL
freeglut/lib          →  C:\MinGW\lib
freeglut/bin          →  C:\Windows\System32


Save your code as windmill.cpp in your project folder.

▶️ Run the Program
g++ windmill.cpp -o windmill.exe -lfreeglut -lopengl32 -lglu32
./windmill.exe

🧠 Concepts Used

glBegin(GL_POLYGON) for drawing shapes

glTranslatef() and glRotatef() for transformations

glutKeyboardFunc() for user input handling

glutTimerFunc() for animation timing

Basic 2D graphics rendering using OpenGL pipeline

📸 Project Output Screenshot



🧑‍💻 Author

Sakshi H. C. Gowda
