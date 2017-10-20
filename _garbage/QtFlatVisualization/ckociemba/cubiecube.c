#include "cubiecube.h"
#include "facecube.h"
#include <stdio.h>

cubiecube_t * get_moveCube()
{
    static cubiecube_t moveCube[6];
    static int moveCube_initialized = 0;
    static const corner_t     cpU[8]  = { UBR, URF, UFL, ULB, DFR, DLF, DBL, DRB };
    static const signed char  coU[8]  = { 0, 0, 0, 0, 0, 0, 0, 0 };
    static const edge_t       epU[12] = { UB, UR, UF, UL, DR, DF, DL, DB, FR, FL, BL, BR };
    static const signed char  eoU[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    static const corner_t     cpR[8]  = { DFR, UFL, ULB, URF, DRB, DLF, DBL, UBR };
    static const signed char  coR[8]  = { 2, 0, 0, 1, 1, 0, 0, 2 };
    static const edge_t       epR[12] = { FR, UF, UL, UB, BR, DF, DL, DB, DR, FL, BL, UR };
    static const signed char  eoR[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    static const corner_t     cpF[8]  = { UFL, DLF, ULB, UBR, URF, DFR, DBL, DRB };
    static const signed char  coF[8]  = { 1, 2, 0, 0, 2, 1, 0, 0 };
    static const edge_t       epF[12] = { UR, FL, UL, UB, DR, FR, DL, DB, UF, DF, BL, BR };
    static const signed char  eoF[12] = { 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0 };
    static const corner_t     cpD[8]  = { URF, UFL, ULB, UBR, DLF, DBL, DRB, DFR };
    static const signed char  coD[8]  = { 0, 0, 0, 0, 0, 0, 0, 0 };
    static const edge_t       epD[12] = { UR, UF, UL, UB, DF, DL, DB, DR, FR, FL, BL, BR };
    static const signed char  eoD[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    static const corner_t     cpL[8]  = { URF, ULB, DBL, UBR, DFR, UFL, DLF, DRB };
    static const signed char  coL[8]  = { 0, 1, 2, 0, 0, 2, 1, 0 };
    static const edge_t       epL[12] = { UR, UF, BL, UB, DR, DF, FL, DB, FR, UL, DL, BR };
    static const signed char  eoL[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    static const corner_t     cpB[8]  = { URF, UFL, UBR, DRB, DFR, DLF, ULB, DBL };
    static const signed char  coB[8]  = { 0, 0, 1, 2, 0, 0, 2, 1 };
    static const edge_t       epB[12] = { UR, UF, UL, BR, DR, DF, DL, BL, FR, FL, UB, DB };
    static const signed char  eoB[12] = { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1 };

    if (!moveCube_initialized) {
        memcpy(moveCube[0].cp, cpU, sizeof(cpU));
        memcpy(moveCube[0].co, coU, sizeof(coU));
        memcpy(moveCube[0].ep, epU, sizeof(epU));
        memcpy(moveCube[0].eo, eoU, sizeof(eoU));
        memcpy(moveCube[1].cp, cpR, sizeof(cpR));
        memcpy(moveCube[1].co, coR, sizeof(coR));
        memcpy(moveCube[1].ep, epR, sizeof(epR));
        memcpy(moveCube[1].eo, eoR, sizeof(eoR));
        memcpy(moveCube[2].cp, cpF, sizeof(cpF));
        memcpy(moveCube[2].co, coF, sizeof(coF));
        memcpy(moveCube[2].ep, epF, sizeof(epF));
        memcpy(moveCube[2].eo, eoF, sizeof(eoF));
        memcpy(moveCube[3].cp, cpD, sizeof(cpD));
        memcpy(moveCube[3].co, coD, sizeof(coD));
        memcpy(moveCube[3].ep, epD, sizeof(epD));
        memcpy(moveCube[3].eo, eoD, sizeof(eoD));
        memcpy(moveCube[4].cp, cpL, sizeof(cpL));
        memcpy(moveCube[4].co, coL, sizeof(coL));
        memcpy(moveCube[4].ep, epL, sizeof(epL));
        memcpy(moveCube[4].eo, eoL, sizeof(eoL));
        memcpy(moveCube[5].cp, cpB, sizeof(cpB));
        memcpy(moveCube[5].co, coB, sizeof(coB));
        memcpy(moveCube[5].ep, epB, sizeof(epB));
        memcpy(moveCube[5].eo, eoB, sizeof(eoB));
    }

    return moveCube;
}

cubiecube_t* get_cubiecube()
{
    cubiecube_t* result = (cubiecube_t *) calloc(1, sizeof(cubiecube_t));

    static const corner_t   cp[8]   = { URF, UFL, ULB, UBR, DFR, DLF, DBL, DRB };
    static const signed char       co[8]   = { 0, 0, 0, 0, 0, 0, 0, 0 };
    static const edge_t     ep[12]  = { UR, UF, UL, UB, DR, DF, DL, DB, FR, FL, BL, BR };
    static const signed char       eo[12]  = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    memcpy(result->cp, cp, sizeof(cp));
    memcpy(result->co, co, sizeof(co));
    memcpy(result->ep, ep, sizeof(ep));
    memcpy(result->eo, eo, sizeof(eo));
    
    return result;
}

int Cnk(int n, int k) {
    int i, j, s;
    if (n < k)
        return 0;
    if (k > n / 2)
        k = n - k;
    for (s = 1, i = n, j = 1; i != n - k; i--, j++) {
        s *= i;
        s /= j;
    }
    return s;
}

void rotateLeft_corner(corner_t* arr, int l, int r)
// Left rotation of all array elements between l and r
{
    corner_t temp = arr[l];
    for (int i = l; i < r; i++)
        arr[i] = arr[i + 1];
    arr[r] = temp;
}

void rotateRight_corner(corner_t* arr, int l, int r)
// Right rotation of all array elements between l and r
{
    corner_t temp = arr[r];
    for (int i = r; i > l; i--)
        arr[i] = arr[i - 1];
    arr[l] = temp;
}


void rotateLeft_edge(edge_t* arr, int l, int r)
// Left rotation of all array elements between l and r
{
    edge_t temp = arr[l];
    for (int i = l; i < r; i++)
        arr[i] = arr[i + 1];
    arr[r] = temp;
}

void rotateRight_edge(edge_t* arr, int l, int r)
// Right rotation of all array elements between l and r
{
    edge_t temp = arr[r];
    for (int i = r; i > l; i--)
        arr[i] = arr[i - 1];
    arr[l] = temp;
}

facecube_t* toFaceCube(cubiecube_t* cubiecube)
{
    facecube_t* fcRet = get_facecube();
    for(int i = 0; i < CORNER_COUNT; i++) {
        int j = cubiecube->cp[i];// cornercubie with index j is at
        // cornerposition with index i
        signed char ori = cubiecube->co[i];// Orientation of this cubie
        for (int n = 0; n < 3; n++)
            fcRet->f[cornerFacelet[i][(n + ori) % 3]] = cornerColor[j][n];
    }
    for(int i = 0; i < EDGE_COUNT; i++)
    {
        int j = cubiecube->ep[i];// edgecubie with index j is at edgeposition
        // with index i
        signed char ori = cubiecube->eo[i];// Orientation of this cubie
        for (int n = 0; n < 2; n++)
            fcRet->f[edgeFacelet[i][(n + ori) % 2]] = edgeColor[j][n];
    }
    return fcRet;
}

void cornerMultiply(cubiecube_t* cubiecube, cubiecube_t* b)
{
    corner_t cPerm[8] = {0};
    signed char cOri[8] = {0};
    for (int corn = 0; corn < CORNER_COUNT; corn++) {
        cPerm[corn] = cubiecube->cp[b->cp[corn]];

        signed char oriA = cubiecube->co[b->cp[corn]];
        signed char oriB = b->co[corn];
        signed char ori = 0;

        if (oriA < 3 && oriB < 3) // if both cubes are regular cubes...
        {
            ori = oriA + oriB; // just do an addition modulo 3 here
            if (ori >= 3)
                ori -= 3; // the composition is a regular cube

            // +++++++++++++++++++++not used in this implementation +++++++++++++++++++++++++++++++++++
        } else if (oriA < 3 && oriB >= 3) // if cube b is in a mirrored
        // state...
        {
            ori = oriA + oriB;
            if (ori >= 6)
                ori -= 3; // the composition is a mirrored cube
        } else if (oriA >= 3 && oriB < 3) // if cube a is an a mirrored
        // state...
        {
            ori = oriA - oriB;
            if (ori < 3)
                ori += 3; // the composition is a mirrored cube
        } else if (oriA >= 3 && oriB >= 3) // if both cubes are in mirrored
        // states...
        {
            ori = oriA - oriB;
            if (ori < 0)
                ori += 3; // the composition is a regular cube
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        }
        cOri[corn] = ori;
    }
    for(int c = 0; c < CORNER_COUNT; c++) {
        cubiecube->cp[c] = cPerm[c];
        cubiecube->co[c] = cOri[c];
    }
}

void edgeMultiply(cubiecube_t* cubiecube, cubiecube_t* b)
{
    edge_t ePerm[12] = {0};
    signed char eOri[12] = {0};

    for(int edge = 0; edge < EDGE_COUNT; edge++) {
        ePerm[edge] = cubiecube->ep[b->ep[edge]];
        eOri[edge] = (b->eo[edge] + cubiecube->eo[b->ep[edge]]) % 2;
    }
    for(int e = 0; e < EDGE_COUNT; e++) {
        cubiecube->ep[e] = ePerm[e];
        cubiecube->eo[e] = eOri[e];
    }
}

void multiply(cubiecube_t* cubiecube, cubiecube_t* b)
{
    cornerMultiply(cubiecube, b);
    edgeMultiply(cubiecube, b);
}

void invCubieCube(cubiecube_t* cubiecube, cubiecube_t* c)
{
    for (int edge = 0; edge < EDGE_COUNT; edge++)
        c->ep[cubiecube->ep[edge]] = edge;
    for (int edge = 0; edge < EDGE_COUNT; edge++)
        c->eo[edge] = cubiecube->eo[c->ep[edge]];
    for (int corn = 0; corn < CORNER_COUNT; corn++)
        c->cp[cubiecube->cp[corn]] = corn;
    for (int corn = 0; corn < CORNER_COUNT; corn++) {
        signed char ori = cubiecube->co[c->cp[corn]];
        if (ori >= 3)// Just for completeness. We do not invert mirrored
            // cubes in the program.
            c->co[corn] = ori;
        else {// the standard case
            c->co[corn] = -ori;
            if (c->co[corn] < 0)
                c->co[corn] += 3;
        }
    }
}

short getTwist(cubiecube_t* cubiecube)
{
    short ret = 0;
    for (int i = URF; i < DRB; i++)
        ret = (short) (3 * ret + cubiecube->co[i]);
    return ret;
}

void setTwist(cubiecube_t* cubiecube, short twist)
{
    int twistParity = 0;
    for (int i = DRB - 1; i >= URF; i--) {
        twistParity += cubiecube->co[i] = (signed char) (twist % 3);
        twist /= 3;
    }
    cubiecube->co[DRB] = (signed char) ((3 - twistParity % 3) % 3);
}

short getFlip(cubiecube_t* cubiecube)
{
    short ret = 0;
    for (int i = UR; i < BR; i++)
        ret = (short) (2 * ret + cubiecube->eo[i]);
    return ret;
}

void setFlip(cubiecube_t* cubiecube, short flip)
{
    int flipParity = 0;
    for (int i = BR - 1; i >= UR; i--) {
        flipParity += cubiecube->eo[i] = (signed char) (flip % 2);
        flip /= 2;
    }
    cubiecube->eo[BR] = (signed char) ((2 - flipParity % 2) % 2);
}

short cornerParity(cubiecube_t* cubiecube)
{
    int s = 0;
    for (int i = DRB; i >= URF + 1; i--)
        for (int j = i - 1; j >= URF; j--)
            if (cubiecube->cp[j] > cubiecube->cp[i])
                s++;
    return (short) (s % 2);
}

short edgeParity(cubiecube_t* cubiecube)
{
    int s = 0;
    for (int i = BR; i >= UR + 1; i--)
        for (int j = i - 1; j >= UR; j--)
            if (cubiecube->ep[j] > cubiecube->ep[i])
                s++;
    return (short) (s % 2);
}

short getFRtoBR(cubiecube_t* cubiecube)
{
    int a = 0, x = 0;
    edge_t edge4[4] = {0};
    // compute the index a < (12 choose 4) and the permutation array perm.
    for (int j = BR; j >= UR; j--)
        if (FR <= cubiecube->ep[j] && cubiecube->ep[j] <= BR) {
            a += Cnk(11 - j, x + 1);
            edge4[3 - x++] = cubiecube->ep[j];
        }

    int b = 0;
    for (int j = 3; j > 0; j--)// compute the index b < 4! for the
    // permutation in perm
    {
        int k = 0;
        while (edge4[j] != j + 8) {
            rotateLeft_edge(edge4, 0, j);
            k++;
        }
        b = (j + 1) * b + k;
    }
    return (short) (24 * a + b);
}
void setFRtoBR(cubiecube_t* cubiecube, short idx)
{
    int x;
    edge_t sliceEdge[4] = { FR, FL, BL, BR };
    edge_t otherEdge[8] = { UR, UF, UL, UB, DR, DF, DL, DB };
    int b = idx % 24; // Permutation
    int a = idx / 24; // Combination
    for (int e = 0; e < EDGE_COUNT; e++)
        cubiecube->ep[e] = DB;// Use UR to invalidate all edges

    for (int j = 1, k; j < 4; j++)// generate permutation from index b
    {
        k = b % (j + 1);
        b /= j + 1;
        while (k-- > 0)
            rotateRight_edge(sliceEdge, 0, j);
    }

    x = 3;// generate combination and set slice edges
    for (int j = UR; j <= BR; j++)
        if (a - Cnk(11 - j, x + 1) >= 0) {
            cubiecube->ep[j] = sliceEdge[3 - x];
            a -= Cnk(11 - j, x-- + 1);
        }
    x = 0; // set the remaining edges UR..DB
    for (int j = UR; j <= BR; j++)
        if (cubiecube->ep[j] == DB)
            cubiecube->ep[j] = otherEdge[x++];
}

short getURFtoDLF(cubiecube_t* cubiecube)
{
    int a = 0, x = 0;
    corner_t corner6[6] = {0};
    // compute the index a < (8 choose 6) and the corner permutation.
    for (int j = URF; j <= DRB; j++)
        if (cubiecube->cp[j] <= DLF) {
            a += Cnk(j, x + 1);
            corner6[x++] = cubiecube->cp[j];
        }

    int b = 0;
    for (int j = 5; j > 0; j--)// compute the index b < 6! for the
    // permutation in corner6
    {
        int k = 0;
        while (corner6[j] != j) {
            rotateLeft_corner(corner6, 0, j);
            k++;
        }
        b = (j + 1) * b + k;
    }
    return (short) (720 * a + b);
}

void setURFtoDLF(cubiecube_t* cubiecube, short idx)
{
    int x;
    corner_t corner6[6] = { URF, UFL, ULB, UBR, DFR, DLF };
    corner_t otherCorner[2] = { DBL, DRB };
    int b = idx % 720; // Permutation
    int a = idx / 720; // Combination
    for(int c = 0; c < CORNER_COUNT; c++)
        cubiecube->cp[c] = DRB;// Use DRB to invalidate all corners

    for (int j = 1, k; j < 6; j++)// generate permutation from index b
    {
        k = b % (j + 1);
        b /= j + 1;
        while (k-- > 0)
            rotateRight_corner(corner6, 0, j);
    }
    x = 5;// generate combination and set corners
    for (int j = DRB; j >= 0; j--)
        if (a - Cnk(j, x + 1) >= 0) {
            cubiecube->cp[j] = corner6[x];
            a -= Cnk(j, x-- + 1);
        }
    x = 0;
    for (int j = URF; j <= DRB; j++)
        if (cubiecube->cp[j] == DRB)
            cubiecube->cp[j] = otherCorner[x++];
}

int getURtoDF(cubiecube_t* cubiecube)
{
    int a = 0, x = 0;
    edge_t edge6[6] = {0};
    // compute the index a < (12 choose 6) and the edge permutation.
    for (int j = UR; j <= BR; j++)
        if (cubiecube->ep[j] <= DF) {
            a += Cnk(j, x + 1);
            edge6[x++] = cubiecube->ep[j];
        }

    int b = 0;
    for (int j = 5; j > 0; j--)// compute the index b < 6! for the
    // permutation in edge6
    {
        int k = 0;
        while (edge6[j] != j) {
            rotateLeft_edge(edge6, 0, j);
            k++;
        }
        b = (j + 1) * b + k;
    }
    return 720 * a + b;
}

void setURtoDF(cubiecube_t* cubiecube, int idx)
{
    int x;
    edge_t edge6[6] = { UR, UF, UL, UB, DR, DF };
    edge_t otherEdge[6] = { DL, DB, FR, FL, BL, BR };
    int b = idx % 720; // Permutation
    int a = idx / 720; // Combination

    for(int e = 0; e < EDGE_COUNT; e++)
        cubiecube->ep[e] = BR;// Use BR to invalidate all edges

    for (int j = 1, k; j < 6; j++)// generate permutation from index b
    {
        k = b % (j + 1);
        b /= j + 1;
        while (k-- > 0)
            rotateRight_edge(edge6, 0, j);
    }
    x = 5;// generate combination and set edges
    for (int j = BR; j >= 0; j--)
        if (a - Cnk(j, x + 1) >= 0) {
            cubiecube->ep[j] = edge6[x];
            a -= Cnk(j, x-- + 1);
        }
    x = 0; // set the remaining edges DL..BR
    for (int j = UR; j <= BR; j++)
        if (cubiecube->ep[j] == BR)
            cubiecube->ep[j] = otherEdge[x++];
}

short getURtoUL(cubiecube_t* cubiecube)
{
    int a = 0, x = 0;
    edge_t edge3[3] = {0};
    // compute the index a < (12 choose 3) and the edge permutation.
    for (int j = UR; j <= BR; j++)
        if (cubiecube->ep[j] <= UL) {
            a += Cnk(j, x + 1);
            edge3[x++] = cubiecube->ep[j];
        }

    int b = 0;
    for (int j = 2; j > 0; j--)// compute the index b < 3! for the
    // permutation in edge3
    {
        int k = 0;
        while (edge3[j] != j) {
            rotateLeft_edge(edge3, 0, j);
            k++;
        }
        b = (j + 1) * b + k;
    }
    return (short) (6 * a + b);
}

void setURtoUL(cubiecube_t* cubiecube, short idx)
{
    int x;
    edge_t edge3[3] = { UR, UF, UL };
    int b = idx % 6; // Permutation
    int a = idx / 6; // Combination
    for(int e = 0; e < EDGE_COUNT; e++) {
        cubiecube->ep[e] = BR;// Use BR to invalidate all edges
    }

    for (int j = 1, k; j < 3; j++) {// generate permutation from index b
        k = b % (j + 1);
        b /= j + 1;
        while (k-- > 0)
            rotateRight_edge(edge3, 0, j);
    }
    x = 2;// generate combination and set edges
    for (int j = BR; j >= 0; j--) {
        if (a - Cnk(j, x + 1) >= 0) {
            cubiecube->ep[j] = edge3[x];
            a -= Cnk(j, x-- + 1);
        }
    }
}

short getUBtoDF(cubiecube_t* cubiecube)
{
    int a = 0, x = 0;
    edge_t edge3[3] = {0};
    // compute the index a < (12 choose 3) and the edge permutation.
    for (int j = UR; j <= BR; j++)
        if (UB <= cubiecube->ep[j] && cubiecube->ep[j] <= DF) {
            a += Cnk(j, x + 1);
            edge3[x++] = cubiecube->ep[j];
        }

    int b = 0;
    for (int j = 2; j > 0; j--)// compute the index b < 3! for the
    // permutation in edge3
    {
        int k = 0;
        while (edge3[j] != UB + j) {
            rotateLeft_edge(edge3, 0, j);
            k++;
        }
        b = (j + 1) * b + k;
    }
    return (short) (6 * a + b);
}

void setUBtoDF(cubiecube_t* cubiecube, short idx)
{
    int x;
    edge_t edge3[3] = { UB, DR, DF };
    int b = idx % 6; // Permutation
    int a = idx / 6; // Combination
    for (int e = 0; e < EDGE_COUNT; e++)
        cubiecube->ep[e] = BR;// Use BR to invalidate all edges

    for (int j = 1, k; j < 3; j++)// generate permutation from index b
    {
        k = b % (j + 1);
        b /= j + 1;
        while (k-- > 0)
            rotateRight_edge(edge3, 0, j);
    }
    x = 2;// generate combination and set edges
    for (int j = BR; j >= 0; j--)
        if (a - Cnk(j, x + 1) >= 0) {
            cubiecube->ep[j] = edge3[x];
            a -= Cnk(j, x-- + 1);
        }
}

int getURFtoDLB(cubiecube_t* cubiecube)
{
    corner_t perm[8] = {0};
    int b = 0;
    for (int i = 0; i < 8; i++)
        perm[i] = cubiecube->cp[i];
    for (int j = 7; j > 0; j--)// compute the index b < 8! for the permutation in perm
    {
        int k = 0;
        while (perm[j] != j) {
            rotateLeft_corner(perm, 0, j);
            k++;
        }
        b = (j + 1) * b + k;
    }
    return b;
}

void setURFtoDLB(cubiecube_t* cubiecube, int idx)
{
    corner_t perm[8] = { URF, UFL, ULB, UBR, DFR, DLF, DBL, DRB };
    int k;
    for (int j = 1; j < 8; j++) {
        k = idx % (j + 1);
        idx /= j + 1;
        while (k-- > 0)
            rotateRight_corner(perm, 0, j);
    }
    int x = 7;// set corners
    for (int j = 7; j >= 0; j--)
        cubiecube->cp[j] = perm[x--];
}

int getURtoBR(cubiecube_t* cubiecube)
{
    edge_t perm[12] = {0};
    int b = 0;
    for (int i = 0; i < 12; i++)
        perm[i] = cubiecube->ep[i];
    for (int j = 11; j > 0; j--)// compute the index b < 12! for the permutation in perm
    {
        int k = 0;
        while (perm[j] != j) {
            rotateLeft_edge(perm, 0, j);
            k++;
        }
        b = (j + 1) * b + k;
    }
    return b;
}

void setURtoBR(cubiecube_t* cubiecube, int idx)
{
    edge_t perm[12] = { UR, UF, UL, UB, DR, DF, DL, DB, FR, FL, BL, BR };
    int k;
    for (int j = 1; j < 12; j++) {
        k = idx % (j + 1);
        idx /= j + 1;
        while (k-- > 0)
            rotateRight_edge(perm, 0, j);
    }
    int x = 11;// set edges
    for (int j = 11; j >= 0; j--)
        cubiecube->ep[j] = perm[x--];
}

int verify(cubiecube_t* cubiecube)
{
    int sum = 0;
    int edgeCount[12] = {0};
    for(int e = 0; e < EDGE_COUNT; e++)
        edgeCount[cubiecube->ep[e]]++;
    for (int i = 0; i < 12; i++)
        if (edgeCount[i] != 1)
            return -2;

    for (int i = 0; i < 12; i++)
        sum += cubiecube->eo[i];
    if (sum % 2 != 0)
        return -3;

    int cornerCount[8] = {0};
    for(int c = 0; c < CORNER_COUNT; c++)
        cornerCount[cubiecube->cp[c]]++;
    for (int i = 0; i < 8; i++)
        if (cornerCount[i] != 1)
            return -4;// missing corners

    sum = 0;
    for (int i = 0; i < 8; i++)
        sum += cubiecube->co[i];
    if (sum % 3 != 0)
        return -5;// twisted corner

    if ((edgeParity(cubiecube) ^ cornerParity(cubiecube)) != 0)
        return -6;// parity error

    return 0;// cube ok
}

int getURtoDF_standalone(short idx1, short idx2)
{
    cubiecube_t *a = get_cubiecube();
    cubiecube_t *b = get_cubiecube();
    setURtoUL(a, idx1);
    setUBtoDF(b, idx2);
    for (int i = 0; i < 8; i++) {
        if (a->ep[i] != BR) {
            if (b->ep[i] != BR) {// collision
                return -1;
            } else {
                b->ep[i] = a->ep[i];
            }
        }
    }
    int res = getURtoDF(b);
    free(a);
    free(b);
    return res;
}

void cornerToString(cubiecube_t* cubiecube, int index, char* result)
{
    corner_t corner = cubiecube->cp[index];
    switch (corner)
    {
    case URF: result[0] = 'U'; result[1] = 'R'; result[2] = 'F'; break;
    case UFL: result[0] = 'U'; result[1] = 'F'; result[2] = 'L'; break;
    case ULB: result[0] = 'U'; result[1] = 'L'; result[2] = 'B'; break;
    case UBR: result[0] = 'U'; result[1] = 'B'; result[2] = 'R'; break;
    case DFR: result[0] = 'D'; result[1] = 'F'; result[2] = 'R'; break;
    case DLF: result[0] = 'D'; result[1] = 'L'; result[2] = 'F'; break;
    case DBL: result[0] = 'D'; result[1] = 'B'; result[2] = 'L'; break;
    case DRB: result[0] = 'D'; result[1] = 'R'; result[2] = 'B'; break;
    }
    result[3] = '(';
    result[4] = (char)(cubiecube->co[index] + 48);
    result[5] = ')';
}

void edgeToString(cubiecube_t* cubiecube, int index, char* result)
{
    edge_t edge = cubiecube->ep[index];;
    switch (edge)
    {
    case UR: result[0] = 'U'; result[1] = 'R'; break;
    case UF: result[0] = 'U'; result[1] = 'F'; break;
    case UL: result[0] = 'U'; result[1] = 'L'; break;
    case UB: result[0] = 'U'; result[1] = 'B'; break;
    case DR: result[0] = 'D'; result[1] = 'R'; break;
    case DF: result[0] = 'D'; result[1] = 'F'; break;
    case DL: result[0] = 'D'; result[1] = 'L'; break;
    case DB: result[0] = 'D'; result[1] = 'B'; break;
    case FR: result[0] = 'F'; result[1] = 'R'; break;
    case FL: result[0] = 'F'; result[1] = 'L'; break;
    case BL: result[0] = 'B'; result[1] = 'L'; break;
    case BR: result[0] = 'B'; result[1] = 'R'; break;
    }
    result[2] = '(';
    result[3] = (char)(cubiecube->eo[index] + 48);
    result[4] = ')';
}

const int SIZE_CORNER_DESC = 6;
const int SIZE_EDGE_DESC = 5;

void cubiecubeToString(cubiecube_t* cubiecube, char* result)
{
    int index = 0;
    result[index++] = 'C';
    result[index++] = ':';
    result[index++] = ' ';
    char cornerDesc[SIZE_CORNER_DESC];
    for (int i = 0; i < CORNER_COUNT; i++)
    {
        cornerToString(cubiecube, i, cornerDesc);
        for (int j = 0; j < SIZE_CORNER_DESC; j++)
            result[index + j] = cornerDesc[j];
        index += SIZE_CORNER_DESC;
        result[index++] = ',';
    }
    // filling edges
    result[index++] = 'E';
    result[index++] = ':';
    result[index++] = ' ';
    char edgeDesc[SIZE_EDGE_DESC];
    for (int i = 0; i < EDGE_COUNT; i++)
    {
        edgeToString(cubiecube, i, edgeDesc);
        for (int j = 0; j < SIZE_CORNER_DESC; j++)
            result[index + j] = edgeDesc[j];
        index += SIZE_EDGE_DESC;
        result[index++] = ',';
    }
}

void insertChar(char* buffer, char c, int *index, int count)
{
    for (int i = 0; i < count; i++)
        buffer[*index + i] = c;
    *index += count;
}

void insertSpaceDashSpace(char* buffer, int *index)
{
    buffer[(*index)++] = ' ';
    buffer[(*index)++] = '-';
    buffer[(*index)++] = ' ';
}

void cubiecubeToString2(cubiecube_t* cubiecube, char** resultArray)
{
    int index;
    char* result;

    //line 0
    index = 0;
    result = resultArray[0] = malloc(50);
    insertChar(result, ' ', &index, 4);
    cornerToString(cubiecube, 2, result + index);
    index += SIZE_CORNER_DESC;
    insertSpaceDashSpace(result, &index);
    edgeToString(cubiecube, 3, result + index);
    index += SIZE_EDGE_DESC;
    insertSpaceDashSpace(result, &index);
    cornerToString(cubiecube, 3, result + index);
    index += SIZE_CORNER_DESC;
    result[index] = '\0';

    //line 1
    index = 0;
    result = resultArray[1] = malloc(50);
    insertChar(result, ' ', &index, 5);
    result[index++] = '/';
    insertChar(result, ' ', &index, 30);
    result[index++] = '/';
    result[index] = '\0';

    //line 2
    index = 0;
    result = resultArray[2] = malloc(50);
    insertChar(result, ' ', &index, 2);
    edgeToString(cubiecube, 2, result + index);
    index += SIZE_EDGE_DESC;
    insertChar(result, ' ', &index, 23);
    edgeToString(cubiecube, 0, result + index);
    index += SIZE_EDGE_DESC;
    result[index] = '\0';


    //line 3
    index = 0;
    result = resultArray[3] = malloc(50);
    insertChar(result, ' ', &index, 2);
    result[index++] = '/';
    insertChar(result, ' ', &index, 30);
    result[index++] = '/';
    result[index] = '\0';

    //line 4
    index = 0;
    result = resultArray[4] = malloc(50);
    cornerToString(cubiecube, 1, result + index);
    index += SIZE_CORNER_DESC;
    insertSpaceDashSpace(result, &index);
    edgeToString(cubiecube, 1, result + index);
    index += SIZE_EDGE_DESC;
    insertSpaceDashSpace(result, &index);
    cornerToString(cubiecube, 0, result + index);
    index += SIZE_CORNER_DESC;
    result[index] = '\0';

    //line 5
    index = 0;
    result = resultArray[5] = malloc(50);
    insertChar(result, ' ', &index, 1);
    result[index] = '\0';

    //line 6
    index = 0;
    result = resultArray[6] = malloc(50);
    insertChar(result, ' ', &index, 4);
    edgeToString(cubiecube, 10, result + index);
    index += SIZE_EDGE_DESC;
    insertChar(result, '-', &index, 18);
    edgeToString(cubiecube, 11, result + index);
    index += SIZE_EDGE_DESC;
    result[index] = '\0';

    //line 7
    index = 0;
    result = resultArray[7] = malloc(50);
    insertChar(result, ' ', &index, 4);
    result[index++] = '/';
    insertChar(result, ' ', &index, 30);
    result[index++] = '/';
    result[index] = '\0';

    //line 8
    index = 0;
    result = resultArray[8] = malloc(50);
    insertChar(result, ' ', &index, 3);
    result[index++] = '/';
    insertChar(result, ' ', &index, 30);
    result[index++] = '/';
    result[index] = '\0';


    //line 9
    index = 0;
    result = resultArray[9] = malloc(50);
    insertChar(result, ' ', &index, 2);
    result[index++] = '/';
    insertChar(result, ' ', &index, 30);
    result[index++] = '/';
    result[index] = '\0';

    //line 10
    index = 0;
    result = resultArray[10] = malloc(50);
    insertChar(result, ' ', &index, 1);
    edgeToString(cubiecube, 9, result + index);
    index += SIZE_EDGE_DESC;
    insertChar(result, '-', &index, 18);
    edgeToString(cubiecube, 8, result + index);
    index += SIZE_EDGE_DESC;
    result[index] = '\0';

    //line 11
    index = 0;
    result = resultArray[11] = malloc(50);
    insertChar(result, ' ', &index, 1);
    result[index] = '\0';


    //line 12
    index = 0;
    result = resultArray[12] = malloc(50);
    insertChar(result, ' ', &index, 4);
    cornerToString(cubiecube, 6, result + index);
    index += SIZE_CORNER_DESC;
    insertSpaceDashSpace(result, &index);
    edgeToString(cubiecube, 7, result + index);
    index += SIZE_EDGE_DESC;
    insertSpaceDashSpace(result, &index);
    cornerToString(cubiecube, 7, result + index);
    index += SIZE_CORNER_DESC;
    result[index] = '\0';

    //line 13
    index = 0;
    result = resultArray[13] = malloc(50);
    insertChar(result, ' ', &index, 5);
    result[index++] = '/';
    insertChar(result, ' ', &index, 30);
    result[index++] = '/';
    result[index] = '\0';

    //line 14
    index = 0;
    result = resultArray[14] = malloc(50);
    insertChar(result, ' ', &index, 2);
    edgeToString(cubiecube, 6, result + index);
    index += SIZE_EDGE_DESC;
    insertChar(result, ' ', &index, 23);
    edgeToString(cubiecube, 4, result + index);
    index += SIZE_EDGE_DESC;
    result[index] = '\0';


    //line 15
    index = 0;
    result = resultArray[15] = malloc(50);
    insertChar(result, ' ', &index, 2);
    result[index++] = '/';
    insertChar(result, ' ', &index, 30);
    result[index++] = '/';
    result[index] = '\0';

    //line 16
    index = 0;
    result = resultArray[16] = malloc(50);
    cornerToString(cubiecube, 5, result + index);
    index += SIZE_CORNER_DESC;
    insertSpaceDashSpace(result, &index);
    edgeToString(cubiecube, 5, result + index);
    index += SIZE_EDGE_DESC;
    insertSpaceDashSpace(result, &index);
    cornerToString(cubiecube, 4, result + index);
    index += SIZE_CORNER_DESC;
    result[index] = '\0';


    //    for (int i = 0; i < CORNER_COUNT; i++)
//    {
//        cornerToString(cubiecube->cp[i], cornerDesc);
//        for (int j = 0; j < SIZE_CORNER_DESC; j++)
//            result[index + j] = cornerDesc[j];
//        index += SIZE_CORNER_DESC;
//        result[index++] = '(';
//        result[index++] = (char)(cubiecube->co[i] + 48);
//        result[index++] = ')';
//        result[index++] = ',';
//    }
//    // filling edges
//    result[index++] = 'E';
//    result[index++] = ':';
//    result[index++] = ' ';
//    char edgeDesc[SIZE_EDGE_DESC];
//    for (int i = 0; i < EDGE_COUNT; i++)
//    {
//        edgeToString(cubiecube->ep[i], edgeDesc);
//        for (int j = 0; j < SIZE_CORNER_DESC; j++)
//            result[index + j] = edgeDesc[j];
//        index += SIZE_EDGE_DESC;
//        result[index++] = '(';
//        result[index++] = (char)(cubiecube->eo[i] + 48);
//        result[index++] = ')';
//        result[index++] = ',';
//    }
}
