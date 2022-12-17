#include <stdio.h>
#include <stdlib.h>

int main()
{
  char str1[50], str2[50], str3[50];
  scanf("%s%s%s", str1, str2, str3);
  FILE *fa, *fb, *out;

  /* copy A to out */
  fa = fopen(str1, "rb");
  out = fopen(str3, "wb");

  char buf;
  while(fread(&buf, sizeof(char), 1, fa) > 0){
    fwrite(&buf, sizeof(char), 1, out);
  }

  fclose(fa);
  fclose(out);

  /* copy B's data to out */
  fb = fopen(str2, "rb");
  out = fopen(str3, "ab");

  fseek(fb, 44, SEEK_SET);
  while(fread(&buf, sizeof(char), 1, fb) > 0){
    fwrite(&buf, sizeof(char), 1, out);
  }

  fclose(fb);
  fclose(out);

  /* get A and B size */
  fa = fopen(str1, "rb");
  fb = fopen(str2, "rb");

  int A_size;
  fseek(fa, 40, SEEK_SET);
  fread(&A_size, sizeof(int), 1, fa);
  int B_size;
  fseek(fb, 40, SEEK_SET);
  fread(&B_size, sizeof(int), 1, fb);

  fclose(fa);
  fclose(fb);

  /* generate out */
  int dataSize = A_size + B_size;
  int chunkSize = dataSize + 36;

  out = fopen(str3, "rb+");

  fseek(out, 4, SEEK_SET);
  fwrite(&chunkSize, sizeof(int), 1, out);
  fseek(out, 40, SEEK_SET);
  fwrite(&dataSize, sizeof(int), 1, out);
  
  fclose(out);
  return 0;
}