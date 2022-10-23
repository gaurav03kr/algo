#include <iostream>
using namespace std;
class matchain
{
int *arr, size, **m, **s;
public:
matchain(int x = 0)
{
size = x;
arr = new int[size];
}
void input();
void create_2d_array();
void solve_mat_order();
void solve_paranthesis(int, int);
};
void matchain::input()
{
cout << "Enter the Matrix Array:- ";
for (int i = 0; i < size; i++)
cin >> arr[i];
cout << endl;
for (int i = 0; i < size - 1; i++)
{
cout << "The Matrix A" << i + 1 << " is:- "<< "(" << arr[i] << "X" << arr[i + 1] << ")" << endl;
}
}
void matchain::create_2d_array()
{
m = new int *[size];
s = new int *[size - 1];
for (int i = 0; i < size; i++)
    m[i] = new int[size];
for (int i = 0; i < size; i++)
s[i] = new int[size];
for (int i = 0; i < size; i++)
for (int j = 0; j < size; j++)
m[i][j] = -1;
for (int i = 0; i < size - 1; i++)
for (int j = 0; j < size; j++)
s[i][j] = -1;
}
void matchain::solve_mat_order()
{
create_2d_array();
for (int i = 0; i < size; i++)
m[i][i] = 0;
for (int l = 2; l < size; l++)
{
for (int i = 1; i < (size - l + 1); i++)
{
int j = i + l - 1;
m[i][j] = INT_MAX;
for (int k = i; k <= j - 1; k++)
{
 int q = m[i][k] + m[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]);

if (q < m[i][j])
{

m[i][j] = q;
s[i][j] = k;
}
}
}
}
}
void matchain::solve_paranthesis(int i, int j)
{
if (i == j)
{
cout << "A" << i;
return;
}
else
{
cout << "(";
solve_paranthesis(i, s[i][j]);
solve_paranthesis(s[i][j] + 1, j);
cout << ")";
}
}
int main()
{
int ch;
cout << "Enter the Value of Chain:- ";
cin >> ch;
matchain a(ch);
a.input();
a.solve_mat_order();
cout << endl<< "The Required Order is:- ";
a.solve_paranthesis(1, ch - 1);
return 0;
}
