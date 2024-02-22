FROM gcc:latest
WORKDIR /app
COPY . /app
RUN gcc -o myapp Proiect.cpp -lstdc++
CMD ["./myapp"]