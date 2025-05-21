CC=gcc
CFLAGS=
MAIN_FILE=./zlock.c
OUTPUT_DIR=build
OUTPUT_FILE=zlock

#
# The default command
#
default: clean build

#
# Build the project
#
build:
	mkdir $(OUTPUT_DIR)
	$(CC) $(CFLAGS) $(MAIN_FILE) -o "$(OUTPUT_DIR)/$(OUTPUT_FILE)"

run: build
	cd $(OUTPUT_DIR)
	$(OUTPUT_FILE)

#
# Clean the output directory
#
clean:
	rm -rf "$(OUTPUT_DIR)/"


