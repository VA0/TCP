### TCP Client - Server Example

**using SFML-2.5.1 library**

![Screenshot](screenshot.png =150x70)

Easy Setup:

    cmake -G "Visual Studio 16 2019" -B cmake_build .
	cmake --build cmake_build --config Release
	
Other way:

    cmake -G "Unix Makefiles" -B linux_build SFML-2.5.1
    cd linux_build
    make (to build SFML)
    move .so (or .dll on windows) libraries to main folder of project (TCP)
    make (to build TCP)
	
Added ready Windows Binaries/
