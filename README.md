## AnyCodeToBmp
This program turns any code file (or any text file) into a BMP image file without losing any text information. It adds a BMP header to the head of the original file and keep all texts remain in the BMP file.

## Usage
Usage:
`bmp <any code or text file>`

---
Here is a simple `helloworld` cpp file

```
#include<iostream>
using namespace std;
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
```

save it to `hello.cpp` and then run

```
./bmp hello.cpp
```
on the `*nix OS` or

```
bmp.exe hello.cpp
```
on the `Windows OS` 

a file named `hello.cpp.bmp` will create, which looks like

![helloworld preview](https://github.com/KaitoHH/AnyCodeToBmp/raw/master/hello_prev.png)

**NOTE** This is *30x* larger version, click [here](https://github.com/KaitoHH/AnyCodeToBmp/raw/master/example/hello.cpp.bmp) to see the real file.

Use any text editor to open this bmp file

```
vim hello.cpp.bmp
```

![helloworld vim](https://github.com/KaitoHH/AnyCodeToBmp/raw/master/hello_vim.png)

You will find that the code is almost the same as the original one except the bmp header and some new lines.

**If you find any code that can generate a good-looking image, please send me your code, and I will post it here for everyone to watch :)**


