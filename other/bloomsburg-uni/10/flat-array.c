/* 
 * Date:    2-Oct-2014
 * Author:  Reuben Crimp
 * 
 * Bloomburg University 2014 programming contest
 * problem 10
*/

#include <stdio.h>
#include <stdlib.h>

#define EMPTY_NODE 0
#define MAX_SIZE 1000

int main (void)
{
   int tree[MAX_SIZE];
   int key, i;

   /* fill the array with 'empty' values */
   for (i = 0; i < MAX_SIZE; i++)
      tree[i] = EMPTY_NODE;

   /* read input */
   printf("Enter keys (0 to quit): ");
   while ( 1 == scanf("%d", &key)){
      if ( key == EMPTY_NODE ) break;

      i = 0; /* index to begin inserting */
      while ( EMPTY_NODE != tree[i] ) { /* while we haven't found an empty node */
         if ( key > tree[i] ) /* key is larger */
            i = 2 * (i + 1); /* move index to right child */
         else if ( key < tree[i] ) /* key is smaller */
            i = 2 * (i + 1)-1; /* move index to left child */
      }
      tree[i] = key;
   }

   /* print the array */
   printf("The keys in level order are: ");
   for ( i = 0; i < MAX_SIZE; i++ )
      if ( tree[i] != EMPTY_NODE )
         printf("%d ", tree[i]);
   printf("\n");

   return 0;
}

