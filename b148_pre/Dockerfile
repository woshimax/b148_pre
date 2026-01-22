FROM gcc:13-bookworm

# Install development tools
RUN apt-get update && apt-get install -y \
    make \
    gdb \
    valgrind \
    vim \
    && rm -rf /var/lib/apt/lists/*

# Create working directory
WORKDIR /workspace

# Copy project files
COPY . /workspace

# Default to bash shell for development
CMD ["/bin/bash"]