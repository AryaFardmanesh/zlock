CC=gcc
CFLAGS= -O2
MAIN_FILE=./zlock.c
OUTPUT_DIR=build
OUTPUT_FILE=zlock
INSTALL_NAME=zlock
INSTALL_DIR=/usr/local/bin

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

#
# Install the Zlock
#
install: clean build
	@echo "Start to install Zlock."
	@echo "Will install in $(INSTALL_DIR)"
	install -m 755 $(OUTPUT_DIR)/$(OUTPUT_FILE) $(INSTALL_DIR)/$(INSTALL_NAME)
	@echo "Zlock installed successfully."

#
# Unstall the Zlock
#
uninstall:
	@echo Start to uninstall Zlock."
	rm -f $(INSTALL_DIR)/$(INSTALL_NAME)
	@echo "Zlock installed successfully."

