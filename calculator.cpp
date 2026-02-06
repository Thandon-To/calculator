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

// --- งานคนที่ 3: Input Parser ---
void ParseInput(char *input, struct Node **start) {
    char numStr[20];
    int j = 0;
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        // ถ้าเป็นตัวเลข 0-9 หรือจุดทศนิยม ให้เก็บใส่ string ชั่วคราว
        if ((input[i] >= '0' && input[i] <= '9') || input[i] == '.') {
            numStr[j++] = input[i];
            numStr[j] = '\0';
        } else {
            // ถ้าเจอเครื่องหมายคำนวณ ให้เอาตัวเลขก่อนหน้าใส่ Node
            double val;
            sscanf(numStr, "%lf", &val);
            AddNode(start, val, input[i]); // เรียกฟังก์ชันของคนที่ 2
            j = 0;
        }
    }
    // เก็บตัวเลขก้อนสุดท้าย (ที่ไม่มีเครื่องหมายต่อท้าย)
    if (j > 0) {
        double val;
        sscanf(numStr, "%lf", &val);
        AddNode(start, val, '=');
    }
}

// --- งานคนที่ 4: Logic Solver (คำนวณและยุบโหนด) ---
void DelNode(struct Node *now) {
    struct Node *del = now->next; // ตัวที่จะลบคือตัวถัดไป
    now->next = del->next;        // ข้ามหัวตัวที่จะลบ ไปชี้ตัวถัดไป
    if (del->next != NULL) {
        del->next->back = now;    // ให้ตัวนู้นชี้กลับมาหาเรา
    }
    now->op = del->op;            // ขโมยเครื่องหมายของตัวที่โดนลบมาใส่ตัวเรา
    delete del;                   // ลบตัวนั้นทิ้ง
}

void SolveLogic(struct Node **start) {
    struct Node *walk;
    printf("\n--- Calculation Process ---\n");

    // Loop 1: จัดการ คูณ หาร (*, /) ก่อน
    walk = *start;
    while (walk != NULL && walk->next != NULL) {
        char o = walk->op;
        if (o == '*' || o == '/') {
            double v1 = walk->data;
            double v2 = walk->next->data;
            
            if (o == '*') walk->data = v1 * v2;
            else if (o == '/') walk->data = v1 / v2;

            DelNode(walk); // ยุบโหนดหลังคำนวณเสร็จ
            printf("Step: "); ShowAll(*start); // โชว์สเต็ปการคิด
        } else {
            walk = walk->next;
        }
    }

    // Loop 2: จัดการ บวก ลบ (+, -) ทีหลัง
    walk = *start;
    while (walk != NULL && walk->next != NULL) {
        char o = walk->op;
        if (o == '+' || o == '-') {
            double v1 = walk->data;
            double v2 = walk->next->data;
            
            if (o == '+') walk->data = v1 + v2;
            else if (o == '-') walk->data = v1 - v2;

            DelNode(walk);
            printf("Step: "); ShowAll(*start);
        } else {
            walk = walk->next;
        }
    }
    printf("------------------------\n");
    printf("Final Answer = %.2f\n", (*start)->data);
}