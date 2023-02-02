FROM ubuntu:20.04 as builder

SHELL ["/bin/bash", "-c"]
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    openssh-client \
    git \
    ca-certificates \
    python3 \
    python3-pip \
    python3-dev \
    python-is-python3 \
    zip \
    curl \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/* && \
    pip3 install platformio==6.1.6 && \
    pio --version
