FROM gcc:latest
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
EXPOSE 5000
RUN gcc server.c debug.c -o myapp
CMD ./myapp 5000