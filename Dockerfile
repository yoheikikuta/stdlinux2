FROM ubuntu:18.04
LABEL maintainer="diracdiego@gmail.com"
LABEL version="1.0"

RUN apt update && apt install -y \
    build-essential \
	gdb \
    strace

WORKDIR /work

CMD ["/bin/bash"]
