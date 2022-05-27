# Graph
This is an implementation of both the Undirected and Directed Graph from Algorithms 4e.
Everything is designed to be useable and efficient;
as such, there are no getters or setters for member data and users are expected to use best practices for C++20 as to avoid issue.
This code *does* make use of C++20 features, so it is a nonnegotiable requirement to running this.
Most major compilers already support the features used (concepts), and as such all one may need to do is update.
In either scenario, here is a breakdown of the code.

## Usage
To use the graph, one must use an ID class for the Vertex struct that is `Printable`, as defined in `include/Graph.hpp`.
This tests that a string can be constructed from the class, which is a necessity to ensure this graph can be output.
Altering the template to accept non-printable classes is a potential improvement that may be implemented in the future.

To use this project is quite simple. One simply has to include in their `CMakeLists.txt`:

    find_package(Graph 1.0.0 REQUIRED)
    # Add Targets
    target_link_libraries(Foo PRIVATE GRon::Graph)

## Requirements
* C++20
* CMake 3.12+

## Building
1. Download the source code

        git clone https://github.com/Macr0Nerd/Graph.git

2. Move into and make am output directory

        cd Graph
        mkdir out

3. Generate the makefiles

        cmake -DCMAKE_BUILD_TYPE=Release ..

5. Build & Install the project

        cmake --install .


## License
MIT License

Copyright (c) 2022 Gabriele A. Ron

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.