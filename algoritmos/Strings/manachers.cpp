/*
    Dado un string S de longitud n retorna dos arreglos de longitud n;  
    donde el i-esimo elemento del primer arreglo es el numero de palindromos
    con centro par centrados en el i-esimo par (el par: i, i-1), y donde el 
    el i-esimo elemento del segundo arreglo es el numero de palindromos 
    con centro impar centrados en el i-esimo elemento.
    NOTA: los caracteres solos no son tomados como palindromos 
    
    tiempo: O(n) 
*/ 

    vector<vector<int>> p(2,vector<int>(n,0));
    for(int z=0,l=0,r=0;z<2;z++,l=0,r=0)
        for(int i=0;i<n;i++)
        {
            if(i<r) p[z][i]=min(r-i+!z,p[z][l+r-i+!z]);
            int L=i-p[z][i], R=i+p[z][i]-!z;
            while(L-1>=0 && R+1<n && s[L-1]==s[R+1]) p[z][i]++,L--,R++;
            if(R>r) l=L,r=R;
        }
