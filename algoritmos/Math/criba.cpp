int tam = 1000000;
vector < bool > criba(1000000, true);

void init()
{
    criba[0] = false;
    criba[1] = false;
    for (int i = 2; i <= sqrt(tam); i ++)
    {
        if (!criba[i]) continue;
        for (int j = 2; i*j <= tam; j ++)
        {
            criba[i*j] = false;
        }
    }
    return;
}