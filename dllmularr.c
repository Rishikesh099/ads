#include <stdio.h>
#include <stdlib.h>

int next[20];
int prev[20];
int data[20];
int head = -1;
int tail = -1;

int getfreeindex() {
    for (int i = 0; i < 20; i++) {
        if (data[i] == -1) {
            return i;
        }
    }
    return -1;
}

void insertend(int x){
    int index, temp;
    index= getfreeindex();
    if(index == -1){
        printf("no free space to insert \n");
    }else{
        data[index]=x;
        next[index]=-1;
        if(head == -1){
            head = index;
            prev[index] = -1;
            tail = index;
        }else{
            temp=head;
            while(next[temp]!=-1){
                temp=next[temp];
            }
            next[temp]=index;
            prev[index]=temp;
            tail = index;
        }
    }
}

void insertbegin(int x){
    int index;
    index= getfreeindex();
    if(index == -1){
        printf("no free space to insert \n");
    }else{
        data[index]=x;
        prev[index]=-1;
        if(head == -1){
            head = index;
            next[index]=-1;
        }else{
            next[index]=head;
            prev[head]=index;
            head=index;
        }
    }
}

void deleteend()
{
    int temp;
    if(head==-1){
        printf("empty\n");
    }else{
        temp=head;
        while(next[temp]!=-1){
            temp=next[temp];
        }
        data[temp]=-1;
        next[temp]=-1;
        prev[temp]=-1;
        tail=prev[temp];
    }
}
void deletebegin()
{
    int temp;
    if(head==-1){
        printf("empty\n");
    }else{
        temp=head;
        head=next[head];
        if(head!=-1){
            prev[head]=-1;
        }
        data[temp]=-1;
        next[temp]=-1;
        prev[temp]=-1;
    }
}

void display()
{
    int temp;
    temp=head;
    if (temp==-1){
        printf("empty\n");
    }else{
        printf("data;\n");
        while(temp!=-1){
            if(data[temp]!=-1){
                printf("%d ", data[temp]);
            }
            temp=next[temp];
        }
        printf("\n");
    }
}

void fdisplay()
{
    int temp;
    temp=tail;
    if (temp==-1){
        printf("empty\n");
    }else{
        printf("data in reverse order:\n");
        while(temp!=-1){
            if(data[temp]!=-1){
                printf("%d ", data[temp]);
            }
            temp=prev[temp];
        }
        printf("\n");
    }
}

void main(){
    for(int i=0; i<20; i++){
        data[i]=-1;
        next[i]=-1;
        prev[i]=-1;
    }
    char ch='y';
    while(ch=='y'){
        int choice;
        printf("1.insertend \n2.insertbegin \n3.deleteend \n4.deletebegin \n5.display \n6.fdisplay \n7.exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                {
                    int val;
                    printf("Enter value to insert at end: ");
                    scanf("%d", &val);
                    insertend(val);
                    display();
                    break;
                }
            case 2:
                {
                    int val;
                    printf("Enter value to insert at beginning: ");
                    scanf("%d", &val);
                    insertbegin(val);
                    display();
                    break;
                }
            case 3:
                deleteend();
                display();
                break;
            case 4:
                deletebegin();
                display();
                break;
            case 5:
                display();
                break;
            case 6:
                fdisplay();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
        
    }
}