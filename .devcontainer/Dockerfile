FROM amd64/ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive
ENV QT_QPA_PLATFORM=xcb

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    gdb \
    libopencv-dev \
    qt6-base-dev \
    libgl1-mesa-dev \
    git \
    && rm -rf /var/lib/apt/lists/*
