echo "# EbrahimiHelen" >> README.md
git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/EbrahimiHelen/EbrahimiHelen.git
git push -u origin main
Advent of code 2024
Written in C++
Using CMake to built
cmake -Bbuild [-DAOC24_BUILD_TESTS=ON] [-DAOC24_BUILD_SOLUTIONS=ON]
cmake --build build
Execution: Run GTest: ./build/tests/AdventOfCode24_Test
Run Solutions from different days: ./build/tests/AdventOfCode24_Test
