
# Building Redtangle
Redtangle can be built from source including all of its dependencies via the terminal. 

To install gRPC, follow the instructions on their github page:

    https://github.com/grpc/grpc/blob/master/BUILDING.md. 
    
If using a Windows system, the following link can also be helpful: 

    https://sanoj.in/2020/05/07/working-with-grpc-in-windows.html. 

The rest of the dependencies are fully built from source via git submodules and CMake. Start by cloning the repo:

    git clone https://github.com/sarrettb/dev.git


Update all of the git submodules to obtain the dependencies:

    git submodule update --init --recursive

CMake is the build system used for this project, so ensure it is installed and up-to-date (3.15). If it is not you will need to install CMake 3.15 or better. 

    cmake --version 

Set the current directory to the redtangle-cpp folder:

    cd dev/projects/redtangle-cpp

Create the build folder:

    mkdir -p cmake/build 

Push the build directory:

    pushd cmake/build 


Create the build spec:
    
    cmake ../.. -DSDL_STATIC=ON -DBUILD_SHARED_LIBS=OFF

Build the executable:

    cmake --build . 

Run the executable:

    ./src/Debug/redtangle.exe

Note: In order to see the redtangle icon, you must manually copy the file into the executable directory. This functionality is handled by the installer in the release version. 