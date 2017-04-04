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

![helloworld preview](https://https://github.com/KaitoHH/AnyCodeToBmp/raw/master/hello_prev.png)

![helloworld preview](https://https://github.com/KaitoHH/AnyCodeToBmp/raw/master/example/hello.cpp.bmp)

