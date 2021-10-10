# moonranger-rover-flight
This repository hosts the flight software that will be used on MoonRanger rover.

## Build Instructions

**To build the repository:**
```
mkdir build
cd build
cmake ..
make 
```
(`make` will automatically call 'mission-all' and 'mission-install' targets which builds and installs the necessary files)

**To run cFS:**
```
cd build/exe/tx2i/
sudo ./core-tx2i
```
(it is necessary to `cd` to the directory the executable lives in (as shown) because the executable depends on files in the current directory for proper operation)