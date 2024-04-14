#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {    
    //non-decreasing
    // if(strcmp(a, b) > 0)
    //     return 1;
    // else 
    //     return 0;
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    //non-increasing 
    if(strcmp(a, b) < 0)
        return 1;
    else
        return 0;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    //non-decreasing
    int a_map[27] = {0}, a_count = 0;
    int b_map[27] = {0}, b_count = 0;
    for(int i=0; i<strlen(a); i++){
        if(a_map[a[i] - 'a'] == 0){
            a_map[a[i] -'a']++;
            a_count++;
        }
        // else{
        //     a_count--;
        // }
    }
    for(int i=0; i<strlen(b); i++){
        if(b_map[b[i] - 'a'] == 0){
            b_map[b[i] -'a']++;
            b_count++;
        }
        // else{
        //     b_count--;
        // }
    }
    
    if(a_count > b_count)
        return 1;
    else if(a_count < b_count)
        return 0;
    else {
         return lexicographic_sort(a, b);
    }

}

int sort_by_length(const char* a, const char* b) {
    //non-decreasing
    if(strlen(a)>strlen(b)){ //front big swap
        return 1;
    }
    else if(strlen(a)<strlen(b))
        return 0;
    else{
        return lexicographic_sort(a, b);
    }
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for(int i = 0; i<len-1; i++){
        int swapped = 0;
        for(int j=0; j<len-1-i; j++){
            if(cmp_func(arr[j], arr[j+1]) > 0){
                swapped = 1;
                char* temp = arr[j];
                //printf("%s\n", temp);
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(swapped == 0) break;
    }
    //(*cmp_func)(arr[i], arr[i+1]);
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}