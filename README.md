

<p align="center">
  <img width="200" height="200" src="https://github.com/itasahobby/knocknock/assets/47305925/905a7e87-4ee6-49c2-b4c9-ccc285217924">
</p>

#  Knocknock

Knocknock is a simple program that prints the command line arguments and environment variables available to it. It can write its output to the standard output, a file, or a socket, depending on the selected output mode.

This tool is useful when you need to develop a cli tool and you do not know what is the interface needed and the codebase is so large that you don't feel like reading it.

## Compilation

The output destination is decided at compilation time. Therefore there are three possible targets:

### stdout

```
make knocknock_stdout
```

### file

```
make knocknock_file
```

### socket

```
make knocknock_socket
```
