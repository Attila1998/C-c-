#include <stdio.h>
#include <stdlib.h>
int main()
{
    int k = 4; // Number of disks
    towerOfHanoi(k, 'S', 'D', 'H');  // Source,Destination and Help are names of rods
    return 0;
}


void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);//meghivja eggyel kevesebb korongal a kezdo ruddal,seged ruddal es a vegso ruddal
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);//meghivja eggyel kevesebb koronggal a segito ruddal, vegso ruddal es a kezdo ruddal
}
