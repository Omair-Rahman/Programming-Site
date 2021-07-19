/*
INPUT:
m: number of man, n: number of woman (must be at least as large as m)
L[i][]: the list of women in order of decreasing preference of man i
R[j][i]: the attractiveness of i to j.
OUTPUTS:
L2R[]: the mate of man i (always between 0 and n-1)
R2L[]: the mate of woman j (or -1 if single)
man priority
*/

int m, n, L[MAXM][MAXW], R[MAXW][MAXM], L2R[MAXM], R2L[MAXW], p[MAXM];

void stableMarriage() {
    int i, man, wom, hubby;
    SET(R2L); CLR(p);
    for(i = 0; i < m; i++ ) {
        man = i;
        while(man >= 0) {
            while(true) {
                wom = L[man][p[man]++];
                if(R2L[wom] < 0 || R[wom][man] > R[wom][R2L[wom]]) break;
            }
            hubby = R2L[wom];
            R2L[L2R[man] = wom] = man;
            man = hubby;
        }
    }
}


