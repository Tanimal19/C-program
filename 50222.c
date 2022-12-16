#include <stdio.h>
#include <stdlib.h>

typedef struct WAVheader
{
  char RIFF[4];
  int chunkSize;
  char wave[4];
  char format[4];
  int subChunkSize;
  short audioFormat;
  short numChannel;
  int sampleRate;
  int byteRate;
  short blockAlign;
  short bitsPerSample;
  char data[4];
  int dataSize;
} WAVHeader;

int main()
{
  char a[50], b[50];
  int time;
  scanf("%s%s", a, b);
  scanf("%d", &time);

  FILE *fa, *fb;

  fa = fopen(a, "rb");
  fb = fopen(b, "wb");

  WAVHeader buf;
  fread(&buf, sizeof(WAVHeader), 1, fa);
  fwrite(&buf, sizeof(WAVHeader), 1, fb);

  int size = sizeof(int) * time * buf.sampleRate / 2;
  int databuf[size];
  fread(databuf, sizeof(int), size/sizeof(int), fa);
  fwrite(databuf, sizeof(int), size/sizeof(int), fb);

  fclose(fa);
  fclose(fb);

  int chunksize = size + 36;
  fb = fopen(b, "rb+");

  fseek(fb, 4, SEEK_SET);
  fwrite(&chunksize, sizeof(int), 1, fb);
  fseek(fb, 40, SEEK_SET);
  fwrite(&size, sizeof(int), 1, fb);
  
  fclose(fb);
  return 0;
}