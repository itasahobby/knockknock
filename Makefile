CC = gcc
CFLAGS = -Wall -Wextra
BINARY_NAME = knocknock

OUTPUT_FILENAME ?= $(BINARY_NAME).out
OUTPUT_IP ?= 127.0.0.1
OUTPUT_PORT ?= 1337

.PHONY: all clean

$(BINARY_NAME)_stdout: $(BINARY_NAME).c output_stdout.c
	$(CC) $(CFLAGS) -DOUTPUT_STDOUT $(BINARY_NAME).c -o $(BINARY_NAME)

$(BINARY_NAME)_file: $(BINARY_NAME).c output_file.c
	$(CC) $(CFLAGS) -DOUTPUT_FILE -DOUTPUT_FILE="\"$(OUTPUT_FILENAME)\"" $(BINARY_NAME).c -o $(BINARY_NAME)

$(BINARY_NAME)_socket: $(BINARY_NAME).c output_socket.c
	$(CC) $(CFLAGS) -DOUTPUT_SOCKET -DOUTPUT_IP="\"$(OUTPUT_IP)\"" -DOUTPUT_PORT=$(OUTPUT_PORT) $(BINARY_NAME).c -o $(BINARY_NAME)

clean:
	rm -f $(BINARY_NAME) $(OUTPUT_FILENAME)