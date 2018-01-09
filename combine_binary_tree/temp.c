//
//  temp.c
//  
//
//
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GATES	100

#define GATE_AND	1
#define GATE_OR		2
#define GATE_XOR	3
#define GATE_NOT	4
#define GATE_NAND	5
#define GATE_NOR	6

struct gate {
    int type;
    int op1, op2;
    int val;
};

struct gate gates[MAX_GATES];

/*
 sample circuit
 0: ^^ -4 -3
 1: || 0 -3
 2: || 0 -1
 3: ^^ 0 -1
 4: !& 2 -2
 5: && 4 1
 6: ^^ 5 3
 */

void get_tt (char *fname, int *tt) {
    char	s[1000];
    int	i, nrows = 0;
    
    FILE *f = fopen (fname, "r");
    if (!f) {
        perror (fname);
        exit (1);
    }
    
    /* skip past the first two lines */
    
    fgets (s, 1000, f);
    fgets (s, 1000, f);
    
    /* loop, getting rows of the truth table; actually we're just
     * getting the last 0-or-1 digit in the strings
     */
    for (;;) {
        char ch, *p;
        fgets (s, 1000, f);
        if (feof (f)) break;
        p = s + strlen (s);
        while (p != s && !(*p == '0' || *p == '1')) p--;
        if (*p == '0' || *p == '1') {
            tt[nrows++] = *p - '0';
        }
    }
    if (nrows != 16) {
        fprintf (stderr, "error: expecting 16 rows in the truth table!\n");
        exit (1);
    }
    fclose (f);
}

void print_circuit (int ngates) {
    int i;
    for (i=0; i<ngates; i++) {
        char ops[3];
        switch (gates[i].type) {
            case GATE_AND: strcpy (ops, "&&"); break;
            case GATE_OR: strcpy (ops, "||"); break;
            case GATE_NOT: strcpy (ops, "!!"); break;
            case GATE_XOR: strcpy (ops, "^^"); break;
            case GATE_NAND: strcpy (ops, "!&"); break;
            case GATE_NOR: strcpy (ops, "!|"); break;
            default:
                fprintf (stderr, "error(1): unknown gate type %d!\n", gates[i].type);
                exit (1);
        }
        printf ("%d: %s %d %d\n", i, ops, gates[i].op1, gates[i].op2);
    }
}

int get_circuit (char *fname) {
    int ngates = 0;
    FILE *f = fopen (fname, "r");
    if (!f) {
        perror (fname);
        return 1;
    }
    for (;;) {
        char s[1000], ops[10];
        int gateno, type;
        fgets (s, 1000, f);
        if (feof (f)) break;
        sscanf (s, "%d: %s %d %d", &gateno, ops, &gates[ngates].op1, &gates[ngates].op2);
        if (gateno != ngates) {
            fprintf (stderr, "gate #%d not in order; expecting %d!\n", gateno, ngates);
            return 1;
        }
        if (!strcmp (ops, "^^")) type = GATE_XOR; else
            if (!strcmp (ops, "&&")) type = GATE_AND; else
                if (!strcmp (ops, "!&")) type = GATE_NAND; else
                    if (!strcmp (ops, "!|")) type = GATE_NOR; else
                        if (!strcmp (ops, "||")) type = GATE_OR; else
                            if (!strcmp (ops, "!!")) type = GATE_NOT; else {
                                fprintf (stderr, "'%s' is an unknown gate\n", ops);
                                return 1;
                            }
        gates[ngates++].type = type;
    }
    fclose (f);
    return ngates;
}

int eval (int n, int a, int b, int c, int d) {
    if (n < 0) {
        switch (n) {
            case -4: return a;
            case -3: return b;
            case -2: return c;
            case -1: return d;
            default:
                fprintf (stderr, "error: unknown variable %d!\n", n);
                exit (1);
        }
    }
    switch (gates[n].type) {
        case GATE_XOR: return eval (gates[n].op1, a, b, c, d) ^ eval (gates[n].op2, a, b, c, d);
        case GATE_AND: return eval (gates[n].op1, a, b, c, d) && eval (gates[n].op2, a, b, c, d);
        case GATE_OR: return eval (gates[n].op1, a, b, c, d) || eval (gates[n].op2, a, b, c, d);
        case GATE_NOT: return ! eval (gates[n].op1, a, b, c, d);
        case GATE_NAND: return !(eval (gates[n].op1, a, b, c, d) && eval (gates[n].op2, a, b, c, d));
        case GATE_NOR: return !(eval (gates[n].op1, a, b, c, d) || eval (gates[n].op2, a, b, c, d));
        default:
            fprintf (stderr, "error(2): unknown gate type %d on gate %d!\n", gates[n].type, n);
            exit (1);
    }
    
}

int main (int argc, char **argv) {
    int tt[16];
    char s[1000];
    int i, ngates, ok;
    
    if (argc != 3) {
        fprintf (stderr, "Usage: %s <truth-table> <circuit>\n", argv[0]);
        return 0;
    }
    
    /* get the truth table */
    
    get_tt (argv[1], tt);
    
    /* get the circuit */
    
    ngates = get_circuit (argv[2]);
    printf ("your circuit:\n");
    print_circuit (ngates);
    int errors = 0;
    printf ("checking...\n-4 -3 -2 -1   | orig  yours\n");
    for (i=0; i<16; i++) {
        int a = !!(i & 8);
        int b = !!(i & 4);
        int c = !!(i & 2);
        int d = !!(i & 1);
        int x = eval (ngates-1, a, b, c, d);
        printf (" %d  %d  %d  %d   |  %d      %d", a, b, c, d, tt[i], x);
        if (x != tt[i]) {
            printf ("*");
            errors++;
        }
        printf ("\n");
    }
    if (errors)
        printf ("%d errors on rows marked with '*'\n", errors);
    else
        printf ("success!\n");
    return 0;
}
