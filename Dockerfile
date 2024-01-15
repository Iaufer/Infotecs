FROM ubuntu:latest

# Установка необходимых пакетов
RUN apt-get update && \
    apt-get install -y build-essential cmake

# Копируем исходники проектра внутрь контейнера
COPY . /app

# Установка рабочей директории
WORKDIR /app

# Генерируем Makefile и компилируем библиотеку SQLite
RUN cmake . && make

