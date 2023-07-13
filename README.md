# Knocknock

Knocknock is a simple program that prints the command line arguments and environment variables available to it. It can write its output to the standard output, a file, or a socket, depending on the selected output mode.

This tool is useful when you need to develop a cli tool and you do not know what is the interface used or the codebase is too large so you don't feel like checking it.

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
