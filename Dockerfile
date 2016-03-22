FROM alpine:3.3
RUN apk add --update gcc g++ cmake make
COPY . .
RUN g++ --version
RUN mkdir build && \
    cd build && \
    cmake .. && \
    make && \
    make test
