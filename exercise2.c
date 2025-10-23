/*
 * Exercise 2: Stack Implementation using Linked List
 * Assignment 7 - IPFCE 2025
 *
 * Implement all the stack functions declared in include/stack.h
 * The stack should be implemented using a linked list structure.
 *
 * Functions to implement:
 * - initialize: Create an empty stack
 * - push: Insert an item at the top of the stack
 * - pop: Remove and return the top item
 * - full: Check if stack is full (always false for linked list)
 * - empty: Check if stack is empty
 * - print: Print all items in the stack
 */

#include "include/stack.h"
#include <stdio.h>
#include <assert.h>

/* Create an empty stack */
void initialize(stack *s)
{
    /* pre-condition: true */

    s->head = NULL;

    assert(empty(s) == true);
    /* post-condition: stack is empty */
}

/* Insert item x at the top of stack s */
void push(int x, stack *s)
{
    /* pre-condition: true (linked list can always accept more items) */
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = x;
    new_node->next = s->head;
    s->head = new_node;

    assert(s->head->data == x);
    /* post-condition: x is added to top of stack */
}

/* Return (and remove) the top item of stack s */
int pop(stack *s)
{
    /* pre-condition: stack must not be empty */
    assert(empty(s) == false);

    int top = s->head->data;
    node *oldhead = s->head;
    s->head = s->head->next;
    free(oldhead);

    /* post-condition: top item is removed and returned */

    return top; // placeholder - replace with actual implementation
}

/* Test whether a stack can accept more pushes */
bool full(stack *s)
{
    /* pre-condition: true */
    /* post-condition: Returns true if stack is full, false otherwise */
    return false;
}

/* Test whether a stack can accept more pops */
bool empty(stack *s)
{
    /* pre-condition: true */
    if (s->head == NULL)
        return true;

    else
        return false;

    /* post-condition: returns true if stack is empty, false otherwise */
}

/* Print the contents of the stack */
void print(stack *s)
{
    /* pre-condition: true */
    node *current;
    current = s->head;
    while (current != NULL)
    {
        printf("%d \n", current->data);
        current = current->next;
    }
    /* post-condition: prints all items in the stack */
}
/*     HER ER VORES TEST FOR OPGAVE 2!!! \/ \/ \/
int main()
{
    stack mystack;

    initialize(&mystack);

    for (int i = 0; i <= 10; i++)
    {
        push(i, &mystack);
    }

    print(&mystack);

    for (int i = 0; i <= 10; i++)
    {

        int topnumber = pop(&mystack);
        int isempty = empty(&mystack);
        int isfull = full(&mystack);
        printf("is empty %d, is full %d, top number %d \n", isempty, isfull, topnumber);
    }
    return 0;
}
    */
