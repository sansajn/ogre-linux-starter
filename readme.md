# OGRE starter project

*OGRE 1.x* C++ starter template for easy prototyping on *Ubuntu 20.04 LTS* with [Scons](https://scons.org) build system. There are just three easy steps [setup](#1-setup), [clone](#2-clone) and [build & run](#3-build--run) and you are ready to start prototyping.

> if you are not yet familiar with *SCons* watch out [scons-starter](https://github.com/sansajn/scons-starter) tutorial


## 1. setup

Normally the easiest way to start with *OGRE* is from official package (`libogre-1.12-dev`), but I've found that it is broken in *Ubuntu 20.04 LTS* (user input is not working at all). Luckily for us the solution is dead simple. We are going to build the library by are own!

- install dependencies with

```bash
sudo apt install libxaw7-dev libsdl2-dev libgles2-mesa-dev libxt-dev libzzip-dev libfreetype-dev scons g++ pkg-config git
```

command.

> **tip**: you can skip `libgles2-mesa-dev` package if you do not need *OpenGL ES2/3* renderer support


- download source code from *OGRE* [repository](https://github.com/OGRECave/ogre) with

```bash
git clone https://github.com/OGRECave/ogre.git
```

command

- checkout newest 1.x version with 

```bash
cd ogre
git checkout -b v1.12.9 v1.12.9 
```

> currently the newest available 1.x version is 1.12.9

commands.


- configure *OGRE* with

```
mkdir build
cd build
cmake -DOGRE_BUILD_RENDERSYSTEM_GLES2=TRUE -DOGRE_BUILD_PLUGIN_ASSIMP=FALSE  ..
```

> **tip**: omit `-DOGRE_BUILD_RENDERSYSTEM_GLES2=TRUE` in case you do not need *OpenGL ES2/3* renderer support

> **note**: in case you have installed `libassimp-dev` package, building *OGRE* will fail with dependency issues (`No rule to make target 'Dependencies/lib/IrrXML.lib', needed by 'lib/Codec_Assimp.so.1.12.9'`), that is why  `-DOGRE_BUILD_PLUGIN_ASSIMP=FALSE` configuration option used

- build *OGRE* with

```bash
make -j4
```

command.

- install *OGRE* with

```bash
sudo make install
```

command.

> **note**: the library is installed in `/usr/local` directory


- configure dynamic linker run-time bindings with

```bash
sudo ldconfig
```

command, otherwise system can't see newly installed libraries and you will end up with *cannot open shared object file ...* complains after you try run *OGRE* application.


- create link for `libzzip.so.13` which is installed as `libzzip-0.so.13` in *Ubuntu 20.04 LTS* with

```bash
cd /usr/lib/x86_64-linux-gnu
sudo ln -s libzzip-0.so.13 libzzip.so.13
```

commands.

> **tip**: optionally you can also install *OGRE* documentation as `ogre-1.12-doc` and tools as `ogre-1.12-tools` packages 


## 2. clone 

Clone starter project repository with

```bash
git clone https://github.com/sansajn/ogre-linux-starter.git
```

command and delete `ogre-linux-starter/.git` directory after cloning finished.

## 3. build & run

To start a build process go to `ogre-linux-starter` and run `scons` with

```bash
cd ogre-linux-starter
scons
```

commands.

> use `-jN` option to speed up whole build process like `scons -j4` and `scons -c` for cleaning the project directory or `scons --help` for further help

Scons will create `./hello` as a result. So

```bash
./hello
```

will run the sample app. In my case I can now see

![image](hello_ogre.png "Hello OGRE screenshot.")

You are done, feel free to modify ...

> **tip**: there is great jump-in tutorial for *OGRE* [there](https://ogrecave.github.io/ogre/api/latest/tutorials.html)


Adam Hlavatovic
