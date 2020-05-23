FROM teeks99/boost-cpp-docker:gcc-9

# These commands copy your files into the specified directory in the image
# and set that as the working location
COPY . /usr/src/meddlers-server
WORKDIR /usr/src/meddlers-server

# This command compiles your app using GCC, adjust for your source code
RUN g++ -o meddlers-server main.cpp

# This command runs your application, comment out this line to compile only
CMD ["meddlers-server"]

LABEL Name=meddlers-server Version=0.0.1

EXPOSE 8080
