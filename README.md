# Bin2Img
Reads pairs of bytes from a binary file specified in argv[1] and outputs a .ppm image generated from counting the number of each coordinate pair (which is then logged).
`main_golf.c` contains a golfed version of the same code.
## Usage
```zsh
$ cc -o main main.c
$ ./main ./main > out.ppm
```
To convert to png use imagemagick (or similar).
```zsh
$ convert out.ppm out.png
```
