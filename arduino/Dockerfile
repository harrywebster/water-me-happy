FROM ubuntu:20.04
ENV DEBIAN_FRONTEND noninteractive

#ADD flatten.sh /bin/flatten

#RUN chmod 755 /bin/flatten
COPY modules /modules

ENTRYPOINT cat /modules/$PROJECT/*.ino
