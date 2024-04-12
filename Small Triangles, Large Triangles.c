#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
    /**
    * Sort an array a of the length n
    */
    float p, area[n];
    
    //calculate the volume
    for(int i=0; i<n; i++){
        p = (tr[i].a + tr[i].b + tr[i].c)/2;
        // sqrt kinda messes things up so removing that
        area[i] = (p * (p-tr[i].a) * (p-tr[i].b) * (p-tr[i].c));
    }
    
    //bubble sort
    triangle temp;
    for(int i=0; i<n-1; i++){
        int swapped = 0;
        for(int j = 0; j<n-i-1; j++){
            if(area[j] > area[j+1]){
                swapped = 1;
                //swap the triangle lists
                temp = tr[j];
                tr[j] = tr[j+1];
                tr[j+1] = temp;

                int a_temp = area[j];
                area[j] = area[j+1];
                area[j+1] = a_temp;
            }
        }
        if(swapped == 0) break;
    }
}


int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}