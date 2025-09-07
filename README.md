Para compilarlo hay dos opciones:

1- Cambiar en el Task.json de "lib\\*.a", a "src//*.c",

2- Mover los archivos que estan dentro de "src" a la carpeta de "include", luego dentro de esa carpeta ingresar el siguiente comando: gcc -shared -o NOMBRE.dll NOMBRE.c -Wl,--out-implib,NOMBRE.a
luego mover los archivos .a a la carpeta "lib", los .c devuelta a "src" y los .dll a la carpeta "bin".
