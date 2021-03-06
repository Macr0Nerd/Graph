# Graph
This is an implementation of both the Undirected and Directed Graph from Algorithms 4e.
Everything is designed to be useable and efficient.

### Notes & Updates
This has been fixed, which has allowed the project to run on C++17 rather than C++20.
This library, as of 1.1.0, implements the stream insertion operator, allowing for any class that also implements this to be the ID class.
It also means it can be used in a wide variety of other ways.
Irregardless, this does not affect the API and `std::string` can still very easily be used as the template type.
Furthermore, this means that symbol graphs, as in Algorithms 4e, can easily be built by using a `Graph<int>`.

~~To use the graph, one must use an ID class for the Vertex struct that is `Printable`, as defined in `include/Graph.hpp`.
This tests that a string can be constructed from the class, which is a necessity to ensure this graph can be output.
Altering the template to accept non-printable classes is a potential improvement that may be implemented in the future.~~

## Usage
To use this project is quite simple. One simply has to include in their `CMakeLists.txt`:

    find_package(Graph 1.1.0 REQUIRED)
    # Add Targets
    target_link_libraries(Foo PRIVATE GRon::Graph)

Then, all that's necessary is to include `GRon/Graph/Graph.hpp`.

## Requirements
* C++17
* CMake 3.15+

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
