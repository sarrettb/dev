
# Building Redtangle Source
Redtangle can be fully built from source, including all of its dependencies. 

Clone the git repository:

    git clone https://github.com/sarrettb/dev.git


Update all of the git submodules to obtain the dependencies:

    git submodule update --init --recursive

Create the build spec using CMake:
    cmake ../.. -DSDL_STATIC=ON -DBUILD_SHARED_LIBS=OFF

Build the executable:

    cmake --build . 

Run the executable:

    ./src/Debug/redtangle.exe

Note: In order to see the icon, you must manually copy the file into the executable directory. This functionality is handled by the installer in the release version. 