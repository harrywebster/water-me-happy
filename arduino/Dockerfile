FROM ubuntu:20.04
ENV DEBIAN_FRONTEND noninteractive
COPY modules /modules
ENTRYPOINT cat /modules/$PROJECT/*.ino
