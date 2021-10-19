# moonranger-rover-messages
This repository hosts the flight message definitions that will be used on MoonRanger rover.

## Important Notes

`moonranger_msgids.h` contains the system-wide message IDs for MoonRanger

`xxx_msg.h` is for message definition files that are used my multiple apps, e.g. `goal_msg.h`

`app_name_msgs.h` is for message definition files that are used solely by an app, e.g. `camera_if_msgs.h`




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
