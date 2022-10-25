class Node {  
int row;  
int col;  
int value;  
Node next;  
Node(int r, int c, int val)   
{ row = r; col = c; this.value = val; }  
}  
public class Sparse{  
public static void main(String[] args)  
{  
/*Assume a 4x4 sparse matrix */  
int sparseMatrix[][] = {  
{0, 0, 1, 2},  
{3, 0, 0, 0},  
{0, 4, 5, 0},  
{0, 6, 0, 0}  
};  
Node start = null; /*Start with the empty list*/  
Node tail = null;  
int k = 0;  
for (int i = 0; i < 4; i++)  
for (int j = 0; j < 4; j++)  
{  
if (sparseMatrix[i][j] != 0) /*Pass only non-zero values*/  
{  
Node temp = new Node(i, j, sparseMatrix[i][j]);  
temp.next = null;  
if(start == null){  
start = temp;  
tail=temp;  
}  
else{  
tail.next = temp;  
tail = tail.next;  
}  
}  
}  
Node itr = start;  
while(start != null){  
System.out.println(start.row  + " " + start.col + " " + start.value);  
start = start.next;  
}  
}  
}  
