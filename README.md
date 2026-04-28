# mkxp-sunshine

This is a specialized fork of [mkxp-oneshot](https://github.com/elizagamedev/mkxp-oneshot) designed for OneShot: sunshine mod.
Target of sunshine mod - improve original game.

# xScripts.rxdata
./rpgscript.rb scripts/ [GameDir]

# Build
1.Install required packages
* Cmake
* C/C++ compiler
* Ruby (3 or higher)
* Boost
* SDL3
* pixman
* SDL3_image
* SDL3_ttf 
* SDL3_sound
* OpenAL 
* PhysFS
* sigc++-2.0
(Linux only!):
* GTK3
* libxfconf

2.build

* In project dir create build dir
* cmake -S . -B build
* cd build
* make -jn 
n - count of threads for compilation.
