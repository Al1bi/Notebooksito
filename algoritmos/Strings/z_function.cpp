/*
    Dado un string S de longitud n retorna un arreglo Z de longitud n, 
    donde el i-esimo termino del arreglo es la longitud del substring mas 
    largo que empieza en la i-esima posicion de S que ademas es igual a 
    un prefijo de S.
 
    ejemplo: 
    S: j o s e l i j o s e j
    Z: 0 0 0 0 0 0 4 0 0 0 1 

    tiempo: O(n)
*/


vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
