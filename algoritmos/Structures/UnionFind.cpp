int padre[150005], fam[150005];

void init()
{
    for (int i = 0; i < 150005; i ++)
    {
        padre[i] = i;
        fam[i] = 1;
    }
}

int Find(int a)
{
    if (padre[a] == a)
    {
        return a;
    }
    return padre[a] = Find(padre[a]);
}

void unir(int a, int b)
{
    int A = Find(a);
    int B = Find(b);
    if (A != B)
    {
        padre[A] = padre[B];
        fam[B] += fam[A];
        fam[A] = 0;
    }
}