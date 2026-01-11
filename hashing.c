#include <stdio.h>
#include <string.h>

int hastable[10];
int hashindex(int x){
    return x % 10;
}

void main(){
    for(int i=0; i<10; i++){
        hastable[i] = -1; 
    }
    char ch='y';
    while(ch=='y')
    {
        int n;
        printf("Enter a number to insert into the hash table: ");
        scanf("%d", &n);
        if(hastable[hashindex(n)]==-1){
            hastable[hashindex(n)] = n;
            printf("Inserted %d at index %d\n", n, hashindex(n));
        }
        else{
            printf("Collision occurred for %d at index %d\n", n, hashindex(n));
        }
        printf("Do you want to insert another number? (y/n): ");
        scanf(" %c", &ch);
    }
    printf("Final hash table contents:\n");
    for(int i=0; i<10; i++){
        if (hastable[i] == -1)
        {
            printf("Index %d: empty\n", i);
        }else{
            printf("Index %d: %d\n", i, hastable[i]);
        }
    } 
}