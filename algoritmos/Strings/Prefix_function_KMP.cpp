/*
    Dado un string S de longitud n retorna un arreglo PI de longitud n, 
    donde el i-esimo termino es el la longitud del prefijo mas largo 
    que tambien es sufijo del substring de S formado hasta el i-esimo 
    termino desde el inicio de S.

    ejemplo:
    S: r a r a m e r a r a n t e
   PI: 0 0 1 2 0 0 1 2 3 4 0 0 0 

    O(n)
*/

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
