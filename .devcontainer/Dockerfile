FROM amd64/ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    gdb \
    git \
    && rm -rf /var/lib/apt/lists/*
