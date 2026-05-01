from PIL import Image, ImageDraw
import os

def crear_gradiente(filename, width, height):
    img = Image.new('RGB', (width, height))
    pixels = img.load()
    for y in range(height):
        for x in range(width):
            r = int((x / width) * 255)
            g = int((y / height) * 255)
            b = int(((x + y) / (width + height)) * 255)
            pixels[x, y] = (r, g, b)
    img.save(filename)
    print('Imagen gradiente creada: ' + filename)

def crear_circulos(filename, width, height):
    img = Image.new('RGB', (width, height), color=(10, 10, 30))
    draw = ImageDraw.Draw(img)
    cx, cy = width // 2, height // 2
    max_r = min(width, height) // 2
    for r in range(max_r, 0, -15):
        ratio = r / max_r
        color = (int(255 * ratio), int(100 * (1 - ratio)), int(255 * (1 - ratio)))
        draw.ellipse([cx - r, cy - r, cx + r, cy + r], outline=color, width=3)
    img.save(filename)
    print('Imagen circulos creada: ' + filename)

if __name__ == '__main__':
    print('')
    print('Generador de Imagenes PNG con Python')
    print('=====================================')
    print('')
    os.makedirs('output', exist_ok=True)
    crear_gradiente('output/gradiente.png', 800, 600)
    crear_circulos('output/circulos.png', 800, 600)
    print('')
    print('Proceso completado!')
    print('Las imagenes estan en: output/')
