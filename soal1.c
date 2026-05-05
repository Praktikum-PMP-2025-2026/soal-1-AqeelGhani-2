/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 3 - Struct and Dynamic Arrays
 *   Hari dan Tanggal    : Selasa, 5 Mei 2026
 *   Nama (NIM)          : Muhammad Aqeel Ghani (13224071)
 *   Nama File           : soal1.c
 *   Deskripsi           : Ritual Penyegelean (Periksa validitas string kurung dengan mengabaikan huruf kecil.)
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode{
    char element;
    struct StackNode *next;
} StackNode;

typedef struct Stack{
    StackNode *top;
}Stack;

void InitializeStack(Stack *stack){
    stack->top = NULL;
}

StackNode* CreateStackNode(char element){
    StackNode *newNode = malloc(sizeof(StackNode));

    newNode->element = element;
    newNode->next = NULL;
}

void AddNewNode(Stack *stack, char newElement){
    StackNode *newNode = CreateStackNode(newElement);
    if (stack->top == NULL) stack->top == newNode;
    else {
        newNode->next = stack->top;
        stack->top = newNode;
    }
}

void PopStack(Stack *stack){
    StackNode *temp = stack->top;
    stack->top = temp->next;
    free(temp);
    temp = NULL;
}

void CheckPair(Stack *stack, char newElement){
    if (stack->top == NULL) AddNewNode(stack, newElement);
    else if ((stack->top->element == '(' && newElement == ')')||(stack->top->element == '{' && newElement == '}')||(stack->top->element == '[' && newElement == ']')) PopStack(stack);
    else AddNewNode(stack, newElement);
}

int CheckInput(Stack *stack, char newElement){
    if (newElement == '(' || newElement == ')' || newElement == '{' || newElement == '}' || newElement == '[' || newElement == ']') return 1;
    else return 0;
}

int CheckValidity(Stack *stack){
    if (stack->top == NULL) printf("VALID");
    else printf("INVALID");
}

int main() {
    Stack stack;
    InitializeStack (&stack);
    char newElement = getchar();
    
    while (newElement != '\n' && newElement != '\0'){
        if (CheckInput(&stack, newElement)) CheckPair(&stack, newElement);
        newElement = getchar();
    }

    CheckValidity(&stack);

    return 0;
}

// Referensi
// https://www.geeksforgeeks.org/c/getchar-function-in-c/
