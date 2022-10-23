#include <stdio.h>
#include <stdlib.h>
struct node
{
  int item_no;
  int itm_val;
  int itm_wgt;
  float val_wgt;
  struct node *next;
} *start = NULL, *last = NULL;
void create_item(int item)
{
  struct node *newnode;
  for (int i = 0; i < item; i++)
  {
    newnode = (struct node *)malloc(1 * sizeof(struct node));
    newnode->item_no = i + 1;
    printf("Enter the Value of %d Item:- ", i + 1);
    scanf("%d", &newnode->itm_val);
    printf("Enter the Weight of %d Item:- ", i + 1);
    scanf("%d", &newnode->itm_wgt);
    newnode->val_wgt = ((float)newnode->itm_val) / ((float)newnode->itm_wgt);
    newnode->next = NULL;
    if (start == NULL)
        start = last = newnode;
    else
    {
       last->next = newnode;
       last = newnode;
    }
  }
}
void swap(struct node *t1, struct node *t2)
{
    int no, wt, va;
    float va_wt;
    no = t1->item_no;
    wt = t1->itm_wgt;
    va = t1->itm_val;
    va_wt = t1->val_wgt;
    t1->item_no = t2->item_no;
    t1->itm_wgt = t2->itm_wgt;
    t1->itm_val = t2->itm_val;
    t1->val_wgt = t2->val_wgt;
    t2->item_no = no;
    t2->itm_wgt = wt;
    t2->itm_val = va;
    t2->val_wgt = va_wt;
}
void descending()
{
    struct node *t1, *t2;
    t1 = start;
    while (t1)
    {
        t2 = t1;
        while (t2)
        {
            if (t1->val_wgt < t2->val_wgt)
                swap(t1, t2);
            t2 = t2->next;
        }
        t1 = t1->next;
    }
}
void display()
{
    struct node *temp;
    temp = start;
    printf("Wi\tVi\tVi/Wi\t\tItem\n");
    while (temp)
    {
        printf("%d\t%d\t%f\t%d\n", temp->itm_wgt, temp->itm_val, temp->val_wgt, temp->item_no);
        temp = temp->next;
    }
}
void solve_knapsack(int item, int cap)
{
    int weight = 0;
    float val = 0.0;
    int arr[item];
    for (int i = 0; i < item; i++)
         arr[i] = -1;
    struct node *temp;
    temp = start;
    for (int i = 0; i < item; i++)
    {
        if (temp->itm_wgt <= cap)
        {
            arr[i] = temp->item_no;
            cap = cap - temp->itm_wgt;
            val = val + (1 * temp->itm_val);
        }
        else if (temp->itm_wgt > cap && cap > 0)
        {
           arr[i] = temp->item_no;
           val = val + ((float)cap / (float)temp->itm_wgt) * temp->itm_val;
           cap = cap - temp->itm_wgt;
        }
        temp = temp->next;
    }
    printf("The Items Picked are:- ");
    for (int i = 0; i < item; i++)
    {
       if (arr[i] != -1)
           printf("%d ", arr[i]);
    }
    printf("\nThe Maximum Value is:- %f", val);
}
int main()
{
    int item, cap;
    printf("Enter the No of Items:- ");
    scanf("%d", &item);
    printf("Enter the Capacity of Bag:- ");
    scanf("%d", &cap);
    create_item(item);
    printf("\nItems Are:- \n");
    display();
    display();
    solve_knapsack(item, cap);
    return 0;
}
