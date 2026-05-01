#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>

void crear_imagen_jpg(const char *filename, int width, int height) {
    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE *outfile = fopen(filename, "wb");
    if (!outfile) {
        printf("Error: No se pudo crear el archivo %s\n", filename);
        return;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);
    jpeg_stdio_dest(&cinfo, outfile);

    cinfo.image_width = width;
    cinfo.image_height = height;
    cinfo.input_components = 3;
    cinfo.in_color_space = JCS_RGB;

    jpeg_set_defaults(&cinfo);
    jpeg_set_quality(&cinfo, 90, TRUE);
    jpeg_start_compress(&cinfo, TRUE);

    unsigned char *buffer = malloc(width * height * 3);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double real = (x / (double)width) * 3.5 - 2.5;
            double imag = (y / (double)height) * 2.0 - 1.0;
            double zr = 0, zi = 0;
            int iter = 0;
            while (iter < 256 && zr*zr + zi*zi < 4) {
                double temp = zr*zr - zi*zi + real;
                zi = 2*zr*zi + imag;
                zr = temp;
                iter++;
            }
            int idx = (y * width + x) * 3;
            buffer[idx]   = iter % 256;
            buffer[idx+1] = (iter * 7) % 256;
            buffer[idx+2] = (iter * 13) % 256;
        }
    }

    JSAMPROW row[1];
    for (int y = 0; y < height; y++) {
        row[0] = &buffer[y * width * 3];
        jpeg_write_scanlines(&cinfo, row, 1);
    }

    jpeg_finish_compress(&cinfo);
    fclose(outfile);
    jpeg_destroy_compress(&cinfo);
    free(buffer);

    printf("Imagen JPG creada: %s (%dx%d)\n", filename, width, height);
}

int main() {
    printf("\n");
    printf("Generador de Imagenes JPG - Fractal Mandelbrot\n");
    printf("================================================\n\n");

    crear_imagen_jpg("output/mandelbrot.jpg", 800, 600);

    printf("\nProceso completado!\n");
    printf("La imagen esta en: output/mandelbrot.jpg\n\n");
    return 0;
}
