# PicoVSCodeExp
Using VSCode to Compile a Full Project Structure

I wanted to demonstrate how a Pico SDK project of a fairly complex structure can still be fully supported by 
the VSCode extensions. This is to demonstrate on my [YouTube Channel](https://youtube.com/@drjonea).

The example just flashes an LED but it does so using the FreeRTOS Kernel. A very overengineered approach 
to the example but shows how a library like FreeRTOS Kernel can be included. FreeRTOS is included as a submodule
rather than hardcoded in the project. To use FreeRTOS Kernel I also need to do some configuration which I
call porting to my platform. So there is also some code in a "port" folder and the main program in the "src" folder.

This structure is beyond what the VSCode Pico extension can build, but the CMake Tool extension comes to
the rescue and can build this fine. Mean while the VSCode Pico extension can do the flashing of the Pico. 
