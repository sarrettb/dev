
# Building Redtangle Source
Redtangle can be fully built from source, including all of its dependencies. 

Clone the git repository:

    git clone https://github.com/sarrettb/dev.git


Update all of the git submodules to obtain the dependencies:

    git submodule update --init --recursive

Create the build spec using CMake:

    cmake ../.. -DSDL_STATIC=ON

Build the executable:

    cmake --build . 