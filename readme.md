# OGRE starter project

*OGRE 1.x* C++ starter template for easy prototyping on *Ubuntu 20.04 LTS* with [Scons](https://scons.org) build system. There are just three easy steps [setup](#1-setup), [clone](#2-clone) and [build & run](#3-build--run) and you are ready to start prototyping.

> optionally you can download *OGRE* sources, see [next step](#4-next-steps-optional) section for more info

## 1. setup

The easiest way to start with *OGRE* is from official package, command

```bash
sudo apt install g++ pkg-config scons libogre-1.12-dev
```
> you can also install *OGRE* documentation as `ogre-1.12-doc` and tools as `ogre-1.12-tools` package 

will do the magik for you.

One think needs to be done in *Ubuntu 20.04 LTS* before we can continue. Library files were installed to `/usr/lib/x86_64-linux-gnu/OGRE-1.12/` but *OGRE* is looking in `/usr/lib/x86_64-linux-gnu/OGRE/` directory. I think this will be fixed in some recent *OGRE* package update, but for now we can create link with 

```bash
cd /usr/lib/x86_64-linux-gnu
sudo ln -s OGRE-1.12/ OGRE
```

commands to get it working.

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

## 4. next steps (optional)

It is also good (but optional) to have *OGRE* [repository](https://github.com/OGRECave/ogre) cloned, because documentation refers to resource files there. Use

```bash
git clone https://github.com/OGRECave/ogre.git
```

command to clone *OGRE* repository. Resource files can be found in `ogre/Samples/Media` directory. Do not forget on samples in `ogre/Samples` and tutorial samples in `ogre/Samples/Tutorials` directories.

> there is great jump-in tutorial for *OGRE* [there](https://ogrecave.github.io/ogre/api/latest/tutorials.html)


Adam Hlavatovic
