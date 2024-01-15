```bash

Шаг 1: Скачивание исходного кода SQLite

git clone https://github.com/Iaufer/Infotecs.git


Шаг 2: Сборка локально

mkdir build
cd build
cmake ..
cmake --build .
ls


Шаг 3: Сборка с использованием Docker

docker build -t my_sqlite_builder .
docker run -it my_sqlite_builder


