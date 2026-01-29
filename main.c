#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  //Initialize variables
  FILE *file;
  unsigned int width = 5;
  unsigned int height = 5;

  //Pixel data type
  typedef struct {
    unsigned int r, g, b;
  } pixel;

  //Array of pixels for the image
  pixel image_data[10][10] = {
   {{255, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, },
   {{0, 255, 0}, {255, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, },
   {{0, 0, 255}, {0, 0, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, },
   {{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, },
   {{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, },
   {{0, 0, 0}, {0, 0, 0}, {0, 255, 0}, {0, 0, 0}, {0, 0, 0}, },
  };

  file = fopen("image.ppm", "w");

  //Check if file created successfully
  if(file == NULL) {
    perror("Failed to create image!\n");
    return EXIT_FAILURE;
  } else {
    printf("File created successfully!\n");
  }

  //Write the PPM headers to the file
  fprintf(file, "P3\n%d %d 255\n", width, height);

  //Write the image data to the file
  for(int i = 0; i<height; i++){
    for(int j = 0; j<width; j++){
      fprintf(file, "%d %d %d   ", image_data[i][j].r ,image_data[i][j].g, image_data[i][j].b);
    }
    fprintf(file, "\n");
  }

  //CLose the file
  fclose(file);

  return 0;
}
