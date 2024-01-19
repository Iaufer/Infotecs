FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y build-essential cmake

COPY . /app

WORKDIR /app

RUN cmake . && make

