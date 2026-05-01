# Docker-Contenedores

Proyecto de contenedores Docker para la materia Embedded IoT.

## Contenedores

### 1. contenedor-c-jpg
Programa en C que genera una imagen JPG del fractal Mandelbrot.

### 2. contenedor-python-png
Programa en Python que genera imagenes PNG con gradientes y circulos.

## Requisitos
- Docker Desktop instalado
- WSL 2 habilitado (Windows)

## Uso

### Contenedor C
```
cd contenedor-c-jpg
docker build -t generador-jpg .
docker run -ti --rm -v "${PWD}:/usr/src/app" generador-jpg
```

### Contenedor Python
```
cd contenedor-python-png
docker build -t generador-png .
docker run -ti --rm -v "${PWD}:/usr/src/app" generador-png
```

## Resultados
- contenedor-c-jpg/output/mandelbrot.jpg
- contenedor-python-png/output/gradiente.png
- contenedor-python-png/output/circulos.png

