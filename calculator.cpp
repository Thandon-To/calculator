#include <stdio.h>
#include <string.h>

// 1. โครงสร้างข้อมูล (Struct)
struct Node {
    double data;
    char op;
    struct Node *next;
    struct Node *back;
};

// 2. ประกาศชื่อฟังก์ชัน (Prototypes)
void AddNode(struct Node **walk, double d, char o);
void ShowAll(struct Node *walk);
void ParseInput(char *input, struct Node **start);
void SolveLogic(struct Node **start);

// 3. ฟังก์ชันหลัก (Main)
int main() {
    struct Node *start = NULL;
    char input[100];

    printf("--- Group Calculator Project ---\n");
    printf("Input Expression: ");
    scanf("%s", input);

    ParseInput(input, &start);   
    printf("\n[Initial List]: ");
    ShowAll(start);              
    SolveLogic(&start);          

    return 0;
}

// --- งานคนที่ 2: Linked List ---
void AddNode(struct Node *walk, double d, char o) {
    struct Nodetemp = NULL;
    while (walk != NULL) {
        temp =walk;
        walk = &(*walk)->next;
    }
    walk = new struct Node;
    (walk)->data = d;
    (walk)->op = o;
    (walk)->next = NULL;
    (walk)->back = temp;
}

void ShowAll(struct Nodewalk) {
    while (walk != NULL) {
        if (walk->op != '=') printf("%.2f %c ", walk->data, walk->op);
        else printf("%.2f", walk->data);
        walk = walk->next;
    }
    printf("\n");
}
