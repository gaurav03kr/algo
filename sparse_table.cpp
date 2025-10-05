int st[LIM][22], lg[LIM];

int combine(int a, int b)
{
    return min(a, b);
}
//add all function for better understanding and readibility
void build(int n)
{
    lg[1] = 0;
    for (int i = 2; i < LIM; ++i)
        lg[i] = lg[i / 2] + 1;

    for (int i = 0; i < n; ++i)
        st[i][0] = arr[i];

    for (int j = 1; j < 22; ++j)
    {
        for (int i = 0; i + (1 << j) <= n; ++i)
            st[i][j] = combine(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
}

int query(int l, int r)
{
    int j = lg[r - l + 1];
    int ans = combine(st[l][j], st[r - (1 << j) + 1][j]);

    return ans;
}
Footer
