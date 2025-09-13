mask |= (1<<n) // PRENDER BIT-N
mask ^= (1<<n) // FLIPPEAR BIT-N
mask &= ~(1<<n) // APAGAR BIT-N
if(mask&(1<<n)) // CHECKEAR BIT-N
T = mask&(-mask); // LSO
__builtin_ffs(mask); // INDICE DEL LSO
__builtin_ctz(S) // TRAILING ZEROS
// iterar sobre los subconjuntos del conjunto S
for(int sbset= S; sbset; subset= (sbset-1) & S)
for (int sbset=0;sbset=sbset-S&S;) // Increasing order