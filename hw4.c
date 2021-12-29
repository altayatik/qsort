// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTINT
int countInt(char * filename)
{
  FILE *flopn; //file

  double ctr = 0; //counter
  char a; //character

  flopn = fopen(filename,"r"); //fopen 

  if (flopn == NULL){ //if fopen fails
    return -1; //return -1
  }

  for (a = getc(flopn); a!=EOF; a=getc(flopn)){ //count the number of integers in file and look for ind chars
    if (a == '\n'){
      ctr++; //update counter
    }
  }

  fclose(flopn); //close if fopen succeeds
  
  return(ctr);
  
  // count the number of integers in the file
  // Please notice that if a file contains
  // 124 378 -56
  // There are three integers: 124, 378, -56
  // DO NOT count individual character '1', '2', '4' ...
  //
  // If fopen fails, return -1

  // remember to fclose if fopen succeeds
}
#endif

#ifdef TEST_READINT
bool readInt(char* filename, int * intArr, int size)
{
  FILE *flopn;
  
  int redo = 0;
  int ini;

  flopn = fopen(filename, "r");

  if (flopn == NULL){ //if fopen fails return false
    return false;
  }

  while(!feof(flopn)){ //check end of file
    if(fscanf(flopn, "%d", &ini)!=EOF){ //integer
      intArr[redo] = ini; //initialize array
      redo++; //update the loop
    }
    ftell(flopn);
  }
  
  if(redo != size){ //if the size is odd fail
    return false;
  }
  fclose(flopn); //if fopen succeeds fclose and return
  

  // if fopen fails, return false
  // read integers from the file.
  // 
  //
  // if the number of integers is different from size (too
  // few or too many) return false
  // 
  // if everything is fine, fclose and return true

  return true;
}
#endif

#ifdef TEST_COMPAREINT
int compareInt(const void *p1, const void *p2)
{
  return(*(int*)p1-*(int*)p2); //does what the comment says lol :D
  // needed by qsort
  //
  // return an integer less than, equal to, or greater than zero if
  // the first argument is considered to be respectively less than,
  // equal to, or greater than the second.
}
#endif

#ifdef TEST_WRITEINT
bool writeInt(char* filename, int * intArr, int size)
{
  FILE *flopn;

  int redo; //initialize the loop

  flopn = fopen(filename,"w");  //write integers to the file
  
  if (flopn == NULL){ //fail if fopen fails
    return false;
  }

  for (redo = 0; redo < size; redo++){ 
    fprintf(flopn,"%d\n", intArr[redo]); //integer per line
  }
  fclose(flopn); //close if success
  return true;
  // if fopen fails, return false
  // write integers to the file.
  // one integer per line
  // fclose and return true
}
#endif

