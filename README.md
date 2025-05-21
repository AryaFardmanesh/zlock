# Welcome to ZLock

zlock is a file encryption program that is specific to the Linux operating system. Using this program, you can easily encrypt a file that contains confidential information and restore that encrypted file if needed.

# Getting Started 🔥

To use it, simply run the following command:

```sh
zlock ./myfile.txt -o ./myfile.txt -p "password" -h xor
```

You can also use the following command to restore the file:

```sh
zlock ./myfile.txt -o ./myfile.txt -p "password" -h xor -r
```

# License ⚖️

This project is licensed under the MIT license. Feel free to edit it.
