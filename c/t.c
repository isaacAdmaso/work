/* fgets example */
#include <stdio.h>

int main()
{
   FILE * pFile;
   char mystring [32];

   pFile = fopen ("myfile.txt" , "r");
   if (pFile == NULL) perror ("Error opening file");
   else {
     if ( fgets (mystring, 32 , pFile) != NULL )
       fputs (mystring,stdout);
     fclose (pFile);
   }
   return 0;
}
