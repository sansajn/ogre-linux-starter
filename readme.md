# OGRE starter project

Ubuntu 20.04 LTS *OGRE 1.x* C++ starter project template with [Scons](https://scons.org) build system. Just clone, build (verify it is working) and start prototyping.

- [OGRE starter project](#ogre-starter-project)
	- [Setup](#setup)
	- [Sample](#sample)
	- [Resources (optional)](#resources-optional)

## Setup

The easiest way to get *OGRE* is from package, for the latest Ubuntu 20.04 LTS command

```bash
sudo apt install scons libogre-1.12-dev
```

> you can also install documentation as `ogre-1.12-doc` and tools as `ogre-1.12-tools` package 

will do the magick for you.

One think needs to be done in Ubuntu 20.04 LTS before we can continue. Library files were installed to `/usr/lib/x86_64-linux-gnu/OGRE-1.12/` but *OGRE* is looking in `/usr/lib/x86_64-linux-gnu/OGRE/` directory. I think this will be fixed in some recent *OGRE* package update, but for now we can create link with 

```bash
cd /usr/lib/x86_64-linux-gnu
sudo ln -s OGRE-1.12/ OGRE
```

commands to get it working.

## Sample

To compile the ptoject just run

```bash
scons
```

to start a build process.

> use `scons -j4` command to speed up whole build process, `scons -c` for cleaning the project directory or `scons --help` for further help

Scons will create `./hello` as a result. So

```bash
./hello
```

will run the sample app. In my case I can now see

![image](hello_ogre.png "Hello OGRE screenshot.")

You are done, feel free to modify ...

## Resources (optional)

It is also good (but optional) to have *OGRE* [repository](https://github.com/OGRECave/ogre) cloned, because documentation refers to resource files there. Use

```bash
git clone https://github.com/OGRECave/ogre.git
```

command to clone *OGRE* repository. Resource files can be found in `ogre/Samples/Media` directory. Do not forget on samples in `ogre/Samples` and tutorial samples in `ogre/Samples/Tutorials` directories.

> there is great jump-in tutorial for *OGRE* [there](https://ogrecave.github.io/ogre/api/latest/tutorials.html)


Adam Hlavatovic
