/***********************************************************************
 * A PROGRAMBAN NEM SZEREPELHETNEK AZ ALÁBBI SOROK:
 * #include <string.h>
 * #include <math.h>
 ***********************************************************************/
#include <stdio.h>
#include <stdlib.h>

/***********************************************************************
************************************************************************
**  ETTŐL A PONTTÓL DOLGOZHATSZ A FELADATOKON
************************************************************************
***********************************************************************/

/*
1. feladat (5 pont)

Irj egy LEGO_lap nevu strukturat, ami az a_oldal es b_oldal nevu mezoiben egy
LEGO lap ket oldalat tarolja el. A LEGO lapok oldalhossza egesz szam.
Irj egy rendez fuggvenyt, amelynek elso parametere egy, a LEGO lapok
adatait tarolo tomb, masodik parametere pedig ezen tomb merete (elojeles egesz
szam). A fuggveny allitsa terulet szerint novekvo sorrendbe a
LEGO_lapok tomb elemeit. Amennyiben ket, vagy tobb lap terulete megegyezik,
akkor a rendezes tartsa meg az eredeti sorrendet. (Termeszetsen
az elemeket ilyenkor is a megfelelo sorrendbe kell allitani csak az azonos teruletu lapok
kozotti sorrend ne valtozzon az eredetihez kepest.)
void rendez(LEGO_lap LEGO_lapok[], int n);

*/
/****************************************************
 * A kovetkezo sor programba illesztese eseten      *
 * (// torlese a #define elol) a feladat nem okoz   *
 * forditasi hibat, de pontot sem fog erni.         *
 ****************************************************/
// #define KIHAGY_1

#if !(defined(KIHAGY_1) || defined(KIHAGY_MIND))

typedef struct LEGO_lap
{
    int a_oldal;
    int b_oldal;
} LEGO_lap;

int terulet(LEGO_lap lap)
{
    return lap.a_oldal * lap.b_oldal;
}

void rendez(LEGO_lap LEGO_lapok[], int n)
{

    printf("NEM rendezett:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", terulet(LEGO_lapok[i]));
    }

    int kicsi_index;
    LEGO_lap csere;


    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (terulet(LEGO_lapok[j]) > terulet(LEGO_lapok[i]))
            {
                csere = LEGO_lapok[j];
                LEGO_lapok[j] = LEGO_lapok[i];
                LEGO_lapok[i] = csere;
            }

        }
    }

    printf("Rendezett:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", terulet(LEGO_lapok[i]));
    }
}

#endif
/***********************************************************************
************************************************************************
**
**  EZEN A PONTON TÚL NE VÁLTOZTASS SEMMIT SEM A FÁJLON!
**
************************************************************************
***********************************************************************/

void call_1()
{
#if !(defined(KIHAGY_1) || defined(KIHAGY_MIND))
    int i, n;
    if (fscanf(stdin, "%d\n", &n) != 1)
    {
        fprintf(stderr, "HIBA: Nem olvasható adat (n)!\n");
        return;
    }
    if (n <= 0)
    {
        if (((LEGO_lap){.a_oldal = 1.5}).a_oldal != ((LEGO_lap){.a_oldal = 1}).a_oldal ||
            ((LEGO_lap){.b_oldal = 1.5}).b_oldal != ((LEGO_lap){.b_oldal = 1}).b_oldal)
        {
            fprintf(stdout, "typecheck FAIL!\n");
        }
        else
        {
            fprintf(stdout, "typecheck OK\n");
        }
        return;
    }
    LEGO_lap p[n];
    for (i = 0; i < n; ++i)
    {
        int a, b;
        if (fscanf(stdin, "%d;%d\n", &a, &b) != 2)
        {
            fprintf(stderr, "HIBA: Nem olvasható adat (LEGO_lap)!\n");
            return;
        }
        p[i].a_oldal = a;
        p[i].b_oldal = b;
    }
    rendez(p, n);
    for (i = 0; i < n; ++i)
    {
        fprintf(stdout, "%d %d\n", (int)(p[i].a_oldal), (int)(p[i].b_oldal));
    }
#endif
}
void test_1()
{
#if !(defined(KIHAGY_1) || defined(KIHAGY_MIND))
    int i, j;
    struct
    {
        LEGO_lap lapok[5];
        int n;
        LEGO_lap eredmeny[5];
    } testlist[1] = {
        {{
             {.a_oldal = 1, .b_oldal = 2011}, // 2011
             {.a_oldal = 399, .b_oldal = 5},  // 1995
             {.a_oldal = 2, .b_oldal = 1000}, // 2000
             {.a_oldal = 3, .b_oldal = 665},  // 1995
             {.a_oldal = 1, .b_oldal = 1989}, // 1989

         },
         5,
         {
             {.a_oldal = 1, .b_oldal = 1989}, // 1989
             {.a_oldal = 399, .b_oldal = 5},  // 1995
             {.a_oldal = 3, .b_oldal = 665},  // 1995
             {.a_oldal = 2, .b_oldal = 1000}, // 2000
             {.a_oldal = 1, .b_oldal = 2011}, // 2011
         }}};
    if (((LEGO_lap){.a_oldal = 1.5}).a_oldal != ((LEGO_lap){.a_oldal = 1}).a_oldal || ((LEGO_lap){.b_oldal = 1.5}).b_oldal != ((LEGO_lap){.b_oldal = 1}).b_oldal)
    {
        fprintf(stderr, "HIBA: az oldalhossz nem egész típusú!\n");
    }
    for (i = 0; i < 1; ++i)
    {
        rendez(testlist[i].lapok, testlist[i].n);
        for (j = 0; j < testlist[i].n; ++j)
        {
            if (testlist[i].lapok[j].a_oldal != testlist[i].eredmeny[j].a_oldal || testlist[i].lapok[j].b_oldal != testlist[i].eredmeny[j].b_oldal)
            {
                fprintf(stderr, "HIBA: rendez({...}, %d)\n", testlist[i].n);
                fprintf(stderr, "\telvárt eredmény:\n");
                for (j = 0; j < testlist[i].n; ++j)
                {
                    fprintf(stderr, "\t\t%d %d\n", testlist[i].eredmeny[j].a_oldal, testlist[i].eredmeny[j].b_oldal);
                }
                fprintf(stderr, "\tkapott eredmény:\n");
                for (j = 0; j < testlist[i].n; ++j)
                {
                    fprintf(stderr, "\t\t%d %d\n", testlist[i].lapok[j].a_oldal, testlist[i].lapok[j].b_oldal);
                }
                return;
            }
        }
    }
#endif
}

typedef void (*call_function)();

call_function call_table[] = {
    call_1,
    NULL};

call_function test_table[] = {
    test_1,
    NULL};

static int __arg_check_helper(const char *exp, const char *arg)
{
    while (*exp && *arg && *exp == *arg)
    {
        ++exp;
        ++arg;
    }
    return *exp == *arg;
}

int main(int argc, char *argv[])
{
    int feladat, calltabsize;
    if ((argc > 1) && !(__arg_check_helper("-t", argv[1]) && __arg_check_helper("--test", argv[1])))
    {
        if (argc > 2)
        {
            feladat = atoi(argv[2]);
            for (calltabsize = 0; test_table[calltabsize]; calltabsize++)
                ;
            if (feladat <= 0 || calltabsize < feladat)
            {
                fprintf(stderr, "HIBA: rossz feladat sorszám: %d!\n", feladat);
                return 1;
            }
            (*test_table[feladat - 1])();
        }
        else
        {
            for (feladat = 0; test_table[feladat]; ++feladat)
            {
                (*test_table[feladat])();
            }
        }
        return 0;
    }
    if (!freopen("be.txt", "r", stdin))
    {
        fprintf(stderr, "HIBA: Hiányzik a `be.txt'!\n");
        return 1;
    }
    if (!freopen("ki.txt", "w", stdout))
    {
        fprintf(stderr, "HIBA: A `ki.txt' nem írható!\n");
        return 1;
    }
    for (calltabsize = 0; call_table[calltabsize]; calltabsize++)
        ;
    if (fscanf(stdin, "%d%*[^\n]", &feladat) != 1)
    {
        fprintf(stderr, "HIBA: Nem olvasható a feladat sorszám!\n");
        return 1;
    }
    fgetc(stdin);
    if (0 < feladat && feladat <= calltabsize)
    {
        (*call_table[feladat - 1])();
    }
    else
    {
        fprintf(stderr, "HIBA: Rossz feladat sorszám: %d!\n", feladat);
        return 1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
