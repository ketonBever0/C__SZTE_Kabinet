/***********************************************************************
 * A PROGRAMBAN NEM SZEREPELHETNEK AZ ALÁBBI SOROK:
 * #include <math.h>
 ***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***********************************************************************
************************************************************************
**  ETTŐL A PONTTÓL DOLGOZHATSZ A FELADATOKON
************************************************************************
***********************************************************************/

/*
1. feladat: BUSZLOPÁS (3 pont)
Mindigis szerettem volna buszt vezetni, mert a busz nagyon kék. Ahhoz, hogy valakiből buszvezető válhasson,
hosszú és nehéz út vezet. Namármost, nekem nincs arra időm, hogy ilyenekkel foglalkozzak, szóval inkább
úgy döntöttem, hogy ellopok egy buszt a buszállomásról.

Készítsd el a buszszerzes függvényt, amely paraméterben egy int pointert vár. A függvény olvasson be a standard
inputról egy egész számot, és tárolja el a pointer által mutatott értékben.

Nyilván csak pozitív járatok léteznek. A függvény visszatérési értéke mondja meg, hogy helyes adatot kaptunk-e.
Amennyiben a járat pozitív, akkor térjünk vissza 1-gyel, különben 0-val.
*/
int buszszerzes(int *jarat)
{

    scanf("%d", jarat);

    if (*jarat < 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/*
2. feladat: TANKOLÁS (4 pont)
A buszállomásra érve több szimpatikus buszt is láttam, ami megfelelő lenne a célra. Mindegyik csak úgy hívogatott.
Alapos számítások után a busz kiválasztott engem, mert a busz választja a sofőrt, és nem fordítva. Szóval odamentem
a kiválasztott buszhoz, és beszálltam. Nyilván ellenőriztem az üzemanyagszintet. Sajnos nem volt elég benne, így
a többi buszból átöntöttem a benzint.

Készítsd el a benzin függvényt, aminek három paramétere van, amelyek leírják 3 busznak a benzinmennyiségét.
A függvény készítsen egy float pointert, ami által mutatott értékbe tedd bele a három buszban lévő benzinmennyiségének
az összegét.
*/
float *benzin(float elsoBusz, float masodikBusz, float harmadikBusz)
{

    float *osszeg = malloc(sizeof(float));

    *osszeg = elsoBusz + masodikBusz + harmadikBusz;

    return osszeg;
}

/*
3. feladat: SOFŐRKÖDÉS (4 pont)
Kigurultam az utakra. Mármint nem szó szerint értem, mert én nem tudok gurulni, hanem a buszt kivezettem az útra.
Akkor azonban jött egy probléma. Az utasok azt hitték, hogy a busz, amit vezetek, az egy tényleges, menetrend
szerint közlekedő busz. Nyilván nem volt más választásam, muszáj volt elszállítanom az utasokat, mert különben
gyanús lesz nekik az eset és a végén még feljelentenek indokulatlanul. Már csak egy megálló volt hátra, amikor
hátranéztem, de nem láttam senkit. Vajon tényleg nincs már senki a buszon?

Készítsd el az utasok függvényt, amelynek 4 paramétere van:
  * egy megállókból álló tömb
  * a megállók darabszámát, azaz a tömb méretét
  * két pointert, amit kimeneti paraméterként használunk

A függvény módosítsa a két pointer által mutatott értékeket úgy, hogy abban rendre az összes leszálló ember száma,
illetve az összes felszálló ember száma legyen.

A függvény adjon vissza 1-et, amennyiben a busz kiürült, 0-t egyébként. A megállók nem feltétlenül sorrendben jönnek.
A buszon nem szállítunk kecskéket.
*/
typedef struct
{
    char nev[100];
    int leszallok;
    int felszallok;
} Megallo;

int utasok(Megallo *megallok, int megallokSzama, int *osszesLeszallok, int *osszesFelszallok)
{

    int buszonLevok = 0;


    for (int i = 0; i < megallokSzama; i++)
    {
        /* buszonLevok -= *megallok.leszallok; */
    }
    


}

/*
4. feladat: GAZDAGSÁG (4 pont)
Nem számítottam rá, de az akció során még pénzt is kerestem, ugyanis az utasok tőlem vásároltak jegyeket és
napijegyeket. Én egy random bevásárlólista darabjait adtam oda nekik, de nem nagyon voltak szomjasak, így
viszonylag könnyen meggyőzhetőek voltak, hogy ez így rendben van. Számoljuk össze, hogy mennyit kerestem
az út során!

Készítsd el a nyereseg függvényt, ami paraméterben várja az eladott jegyek, illetve az eladott napijegyek számát.
A függvény adjon vissza egy tömböt, amiben benne vannak az egyes vásárlások során elköltött összegek. A tömb elején
a jegyvásárlások vannak, utána a napijegy vásárlások.

Példa:
input: 5, 3
output: 600, 600, 600, 600, 600, 1300, 1300, 1300
magyarázat: 5 db jegyet vettek, így a tömb 5 db 600-assal indul, majd utána 3 db 1300-as következik, mivel 3 db
napijegyet vásároltak.
*/

#define JEGY_AR 600
#define NAPIJEGY_AR 1300

int *nyereseg(int jegyek, int napiJegyek)
{
}

/*
5. feladat: AUTÓS ÜLDÖZÉS (6 pont)
A rendőrség rájött a tettemre, és a nyomomba eredtek. Próbáltam menekülni, ahogy tudtam, de az előttem lévő
útszakaszra csapdákat állítottak, hogy megakadályozzanak ebben. Ki kell kerülnöm a csapdákat. A busz szenzorai
felmérték a területet, már csak olyan formába kell alakítani az adatokat, hogy megértsem, és aszerint tudjak
menekülni. Segíts kérlek! 👉👈

Készítsd el a csapda_atalakitas függvényt, ami első paraméterben egy tömböt vár, amelyben az előttem lévő
útszakasz csapdássága látható (0/1 értékek). A második paraméter megmondja, hogy hány sávos az útszakasz,
a harmadik pedig hogy milyen hosszú az útszakasz.
A tömbben az elemek úgy vannak az elemek, hogy először a hozzám legközelebb álló útszakasz sávjai egymás után,
utána az eggyel távolabbi, stb. A feladat, hogy átalakítsuk 2D-s tömbbé úgy, hogy az első index a sáv indexe legyen.

Példa:
-----------
| 1  1  1 |
| 0  0  1 |
| 0  1  0 |
| 1  1  0 |
| 0  0  1 |
| 1  0  0 |
|  (bus)  |
input: [1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0] (savok: 3, utszakaszok: 6)
output: [[1, 0, 0, 1, 0, 1], [1, 0, 1, 1, 0, 0], [1, 1, 0, 0, 1, 0]]
*/

int **csapda_atalakitas(int *csapdak, int savok, int utszakaszok)
{
}

/*
6. feladat: FÉNYMÁSOLÓ (4 pont)
A rendőrségnek sikerült megállítania a buszt. Nagyon ügyikék voltak. Kinyitottam az ajtót, rögtön letámadtak,
hogy letartóztassanak. Én meg így mondom nekik, hogy ácsika nagyfiúk, lassítsatok már. Aztán lassítottak, én
meg elmagyaráztam nekik, hogy igazából én nem is loptam el a buszt, mert az még most is az állomáson van.
Nem igazán akartak nekem hinni, azt mondták fixen hülyének nézem őket. Én meg mondom figyuka már kiscsibék,
eskü ott van, csak nézzétek meg az állomáson. Így végül magamra hagytak, mentem tovább, ők meg elindultak az
állomás fele.

És nem vicceltem, mielőtt elloptam a buszt, tényleg lemásoltam, és a másolat most ott van az állomáson.
A rendőrség megnyugodott, és onnantól kezdve békén hagytak.

Készítsd el a busz_masolas függvényt, amely paraméterben egy buszra mutató pointert vár, és lemásolja a buszt,
tehát egy másik busz pointert kell készíteni, ami egy teljes másolata (deep copy) az eredeti busznak.
*/
typedef struct
{
    char *megnevezes; // a tárgy megnevezése
    float szepseg;    // a tárgy szépsége (0-1)
} Targy;

typedef struct
{
    char rendszam[8];   // a busz rendszáma
    char *nev;          // a busz neve
    int *ulesTisztasag; // tiszták-e az ülések, 0-1 értékeket tároló tömb, minden ülésre
    int ulesekSzama;    // hány ülés van a buszban
    Targy vezetoTargya; // a vezető kedvenc tárgya, amit kirakott az ablakba
} Busz;

Busz *busz_masolas(Busz *busz)
{
}
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
    int p1 = -10000;
    int ertek;

    if (fgetc(stdin) == EOF)
    {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }

    ertek = buszszerzes(&p1);
    fprintf(stdout, "%d %d\n", p1, ertek);
#endif
}
void test_1()
{
#if !(defined(KIHAGY_1) || defined(KIHAGY_MIND))
    int eredmeny;
    int input = -1;
    eredmeny = buszszerzes(&input);

    fprintf(stdout, "jarat erteke: %d\n", input);
    fprintf(stdout, "visszateresi ertek: %d\n", eredmeny);
#endif
}

void call_2()
{
#if !(defined(KIHAGY_2) || defined(KIHAGY_MIND))
    float b1, b2, b3;
    float *eredmeny;

    if (fgetc(stdin) == EOF)
    {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }

    if (fscanf(stdin, "%f %f %f", &b1, &b2, &b3) != 3)
    {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }

    eredmeny = benzin(b1, b2, b3);
    fprintf(stdout, "%.3f\n", *eredmeny);
    free(eredmeny);
    fprintf(stdout, "memory ok\n");
#endif
}
void test_2()
{
#if !(defined(KIHAGY_2) || defined(KIHAGY_MIND))
    float *eredmeny;
    int i;

    struct
    {
        float a;
        float b;
        float c;
        float eredmeny;
    } testlist[2] = {
        {4, 5, 6, 15},
        {10, 20, 30.5f, 60.5f}};

    for (i = 0; i < 2; i++)
    {
        eredmeny = benzin(testlist[i].a, testlist[i].b, testlist[i].c);
        float diff = (*eredmeny - testlist[i].eredmeny);
        diff *= diff < 0 ? -1 : 1;
        if (diff > 0.001f)
        {
            fprintf(stdout, "HIBA: benzin(%f, %f, %f):\n"
                            "\telvárt eredmény: %f\n"
                            "\tkapott eredmény: %f\n",
                    testlist[i].a, testlist[i].b, testlist[i].c, testlist[i].eredmeny, *eredmeny);
        }

        free(eredmeny);
    }
#endif
}

void call_3()
{
#if !(defined(KIHAGY_3) || defined(KIHAGY_MIND))
    Megallo megallok[10];
    int megallokszam;
    int res2, res1, ret;
    int i;

    if (fgetc(stdin) == EOF)
    {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }

    if (fscanf(stdin, "%d", &megallokszam) != 1)
    {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }

    for (i = 0; i < megallokszam; i++)
    {
        fscanf(stdin, "%d %d %[^\n]s", &megallok[i].felszallok, &megallok[i].leszallok, megallok[i].nev);
    }

    ret = utasok(megallok, megallokszam, &res1, &res2);
    fprintf(stdout, "%d %d %d\n", res1, res2, ret);
#endif
}
void test_3()
{
#if !(defined(KIHAGY_3) || defined(KIHAGY_MIND))
    int eredmeny;
    int i;

    struct
    {
        Megallo megallok[10];
        int megallo_db;
        int p1;
        int p2;
        int p1ex;
        int p2ex;
        int rex;
    } testlist[2] = {
        {{{"UwU ter", 2, 5},
          {"Meow utca", 3, 4},
          {"cica utca", 4, 0}},
         3,
         -16322,
         -521512,
         9,
         9,
         1},

        {{{"UwU ter", 3, 12},
          {"Meow utca", 5, 5},
          {"cica utca", 2, 3}},
         3,
         -416344,
         -163262,
         10,
         20,
         0}};

    for (i = 0; i < 2; i++)
    {
        eredmeny = utasok(testlist[i].megallok, testlist[i].megallo_db, &testlist[i].p1, &testlist[i].p2);

        if (eredmeny != testlist[i].rex || testlist[i].p1 != testlist[i].p1ex || testlist[i].p2 != testlist[i].p2ex)
        {
            fprintf(stdout, "HIBA: utasok(...):\n"
                            "\telvárt eredmény: %d %d (%d)\n"
                            "\tkapott eredmény: %d %d (%d)\n",
                    testlist[i].p1ex, testlist[i].p2ex, testlist[i].rex, testlist[i].p1, testlist[i].p2, eredmeny);
        }
    }
#endif
}

void call_4()
{
#if !(defined(KIHAGY_4) || defined(KIHAGY_MIND))
    int p1, p2;
    int *res;

    if (fgetc(stdin) == EOF)
    {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }

    if (fscanf(stdin, "%d %d", &p1, &p2) != 2)
    {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }

    res = nyereseg(p1, p2);

    for (int i = 0; i < p1 + p2; i++)
    {
        fprintf(stdout, "%d ", res[i]);
    }
    fprintf(stdout, "\n");

    free(res);
    fprintf(stdout, "memory ok\n");
#endif
}
void test_4()
{
#if !(defined(KIHAGY_4) || defined(KIHAGY_MIND))
    int *eredmeny;
    int ok;
    int i, j;

    struct
    {
        int p1;
        int p2;
        int elvart[10];
    } testlist[2] = {
        {5, 2, {600, 600, 600, 600, 600, 1300, 1300}},
        {3, 1, {600, 600, 600, 1300}}};

    for (i = 0; i < 2; i++)
    {
        eredmeny = nyereseg(testlist[i].p1, testlist[i].p2);

        ok = 1;
        for (j = 0; j < testlist[i].p1 + testlist[i].p2; j++)
        {
            if (eredmeny[j] != testlist[i].elvart[j])
            {
                ok = 0;
                break;
            }
        }

        if (!ok)
        {
            fprintf(stdout, "HIBA: nyereseg(%d, %d):\n", testlist[i].p1, testlist[i].p2);
            fprintf(stdout, "\telvárt eredmény: [");

            for (j = 0; j < testlist[i].p1 + testlist[i].p2 - 1; j++)
            {
                fprintf(stdout, "%d, ", testlist[i].elvart[j]);
            }
            fprintf(stdout, "%d]\n", testlist[i].elvart[testlist[i].p1 + testlist[i].p2 - 1]);

            fprintf(stdout, "\tKapott eredmény: [");
            for (j = 0; j < testlist[i].p1 + testlist[i].p2 - 1; j++)
            {
                fprintf(stdout, "%d, ", eredmeny[j]);
            }

            fprintf(stdout, "%d]\n", eredmeny[testlist[i].p1 + testlist[i].p2 - 1]);
        }
    }

    free(eredmeny);
#endif
}

void call_5()
{
#if !(defined(KIHAGY_5) || defined(KIHAGY_MIND))
    int *p0, p1, p2;
    int **res;
    int i, j;

    if (fgetc(stdin) == EOF)
    {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }

    if (fscanf(stdin, "%d %d", &p1, &p2) != 2)
    {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }

    p0 = malloc(p1 * p2 * sizeof(int));
    for (i = 0; i < p1 * p2; i++)
    {
        fscanf(stdin, "%d", &p0[i]);
    }

    res = csapda_atalakitas(p0, p1, p2);

    for (i = 0; i < p1; i++)
    {
        for (j = 0; j < p2; j++)
        {
            fprintf(stdout, "%d ", res[i][j]);
        }
        fprintf(stdout, "\n");
    }

    for (i = 0; i < p1; i++)
    {
        free(res[i]);
    }

    free(res);
    free(p0);

    fprintf(stdout, "memory ok\n");
#endif
}
void test_5()
{
#if !(defined(KIHAGY_5) || defined(KIHAGY_MIND))
    int **eredmeny;
    int i, d1, d2, ok;

    struct
    {
        int savok;
        int szakaszok;
        int tomb[100];
    } testlist[2] = {
        {3, 6, {1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0}},
        {2, 4, {0, 1, 0, 1, 0, 1, 0, 1}}};

    for (i = 0; i < 2; i++)
    {
        eredmeny = csapda_atalakitas(testlist[i].tomb, testlist[i].savok, testlist[i].szakaszok);

        ok = 1;
        for (d1 = 0; d1 < testlist[i].savok; d1++)
        {
            for (d2 = 0; d2 < testlist[i].szakaszok; d2++)
            {
                if (eredmeny[d1][d2] != testlist[i].tomb[d2 * testlist[i].savok + d1])
                {
                    ok = 0;
                }
            }
        }

        if (!ok)
        {
            fprintf(stdout, "HIBA: csapda_atalakitas(...)!\n");
            fprintf(stdout, "Elvart: \n");
            for (d1 = 0; d1 < testlist[i].savok; d1++)
            {
                for (d2 = 0; d2 < testlist[i].szakaszok; d2++)
                {
                    fprintf(stdout, "%d ", testlist[i].tomb[d2 * testlist[i].savok + d1]);
                }
                fprintf(stdout, "\n");
            }

            fprintf(stdout, "\nKapott: \n");
            for (d1 = 0; d1 < testlist[i].savok; d1++)
            {
                for (d2 = 0; d2 < testlist[i].szakaszok; d2++)
                {
                    fprintf(stdout, "%d ", eredmeny[d1][d2]);
                }
                fprintf(stdout, "\n");
            }
        }

        for (d1 = 0; d1 < testlist[i].savok; d1++)
        {
            free(eredmeny[d1]);
        }
    }

    free(eredmeny);
#endif
}

void call_6()
{
#if !(defined(KIHAGY_6) || defined(KIHAGY_MIND))
    Busz eredeti;
    eredeti.nev = malloc(100);
    eredeti.vezetoTargya.megnevezes = malloc(100);
    eredeti.ulesTisztasag = malloc(1000 * sizeof(int));

    Busz *masolat;
    int i;

    if (fgetc(stdin) == EOF)
    {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }

    if (fscanf(stdin, "%s %[^\n] %d", eredeti.rendszam, eredeti.nev, &eredeti.ulesekSzama) != 3)
    {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }

    for (i = 0; i < eredeti.ulesekSzama; i++)
    {
        fscanf(stdin, "%d", &eredeti.ulesTisztasag[i]);
    }

    fscanf(stdin, "%s %f", eredeti.vezetoTargya.megnevezes, &eredeti.vezetoTargya.szepseg);

    masolat = busz_masolas(&eredeti);

    fprintf(stdout, "%s\n%s\n%d\n", masolat->rendszam, masolat->nev, masolat->ulesekSzama);
    for (i = 0; i < masolat->ulesekSzama; i++)
    {
        fprintf(stdout, "%d ", masolat->ulesTisztasag[i]);
    }
    fprintf(stdout, "\n");

    fprintf(stdout, "%s %.4f\n\n", masolat->vezetoTargya.megnevezes, masolat->vezetoTargya.szepseg);

    for (i = 0; i < 7; i++)
    {
        masolat->rendszam[i] = '@';
    }

    for (i = 0; masolat->nev[i] != 0; i++)
    {
        masolat->nev[i] = '@';
    }

    for (i = 0; i < masolat->ulesekSzama; i++)
    {
        masolat->ulesTisztasag[i] = -1;
    }

    masolat->ulesekSzama = -1;

    for (i = 0; masolat->vezetoTargya.megnevezes[i] != 0; i++)
    {
        masolat->vezetoTargya.megnevezes[i] = '@';
    }

    masolat->vezetoTargya.szepseg = -1;

    fprintf(stdout, "%s\n%s\n%d\n ", eredeti.rendszam, eredeti.nev, eredeti.ulesekSzama);
    for (i = 0; i < eredeti.ulesekSzama; i++)
    {
        fprintf(stdout, "%d ", eredeti.ulesTisztasag[i]);
    }
    fprintf(stdout, "\n");

    fprintf(stdout, "%s %.4f\n", eredeti.vezetoTargya.megnevezes, eredeti.vezetoTargya.szepseg);

    free(eredeti.nev);
    free(eredeti.vezetoTargya.megnevezes);
    free(eredeti.ulesTisztasag);
    free(masolat);

    fprintf(stdout, "memory ok\n");
#endif
}
void test_6()
{
#if !(defined(KIHAGY_6) || defined(KIHAGY_MIND))
    int i;
    int ok;
    int t1[] = {1, 0, 0, 1};
    Busz busz = {
        "AAA-111",
        "Mr. Bela",
        t1,
        4,
        {"polip", 0.88f}};

    Busz *megoldas;

    megoldas = busz_masolas(&busz);

    if (strcmp(busz.rendszam, megoldas->rendszam) != 0)
    {
        fprintf(stdout, "Hibas masolas: rendszam");
    }

    if (strcmp(busz.nev, megoldas->nev) != 0)
    {
        fprintf(stdout, "Hibas masolas: nev");
    }

    ok = 1;
    for (i = 0; i < busz.ulesekSzama; i++)
    {
        if (busz.ulesTisztasag[i] != megoldas->ulesTisztasag[i])
        {
            ok = 0;
        }
    }

    if (!ok)
    {
        fprintf(stdout, "Hibas masolas: ulesTisztasag");
    }

    if (busz.ulesekSzama != megoldas->ulesekSzama)
    {
        fprintf(stdout, "Hibas masolas: ulesekSzama");
    }

    if (busz.vezetoTargya.szepseg != megoldas->vezetoTargya.szepseg)
    {
        fprintf(stdout, "Hibas masolas: vezetoTargya.szepseg");
    }

    if (strcmp(busz.vezetoTargya.megnevezes, megoldas->vezetoTargya.megnevezes) != 0)
    {
        fprintf(stdout, "Hibas masolas: vezetoTargya.megnevezes");
    }

    // ----------

    megoldas->rendszam[0] = '#';
    megoldas->nev[0] = '#';
    megoldas->ulesekSzama = -1;
    megoldas->ulesTisztasag[0] = -1;
    megoldas->vezetoTargya.szepseg = -2;
    megoldas->vezetoTargya.megnevezes[0] = '#';

    if (busz.rendszam[0] == '#')
    {
        fprintf(stdout, "Nem fuggetlen: rendszam");
    }

    if (busz.nev[0] == '#')
    {
        fprintf(stdout, "Nem fuggetlen: nev");
    }

    if (busz.ulesekSzama == -1)
    {
        fprintf(stdout, "Nem fuggetlen: ulesekSzama");
    }

    if (busz.ulesTisztasag[0] == -1)
    {
        fprintf(stdout, "Nem fuggetlen: uletTisztasag");
    }

    if (busz.vezetoTargya.megnevezes[0] == '#')
    {
        fprintf(stdout, "Nem fuggetlen: vezetoTargya.megnevezes");
    }

    if (busz.vezetoTargya.szepseg == -2)
    {
        fprintf(stdout, "Nem fuggetlen: vezetoTargya.szepseg");
    }

#endif
}

typedef void (*call_function)();

call_function call_table[] = {
    call_1,
    call_2,
    call_3,
    call_4,
    call_5,
    call_6,
    NULL};

call_function test_table[] = {
    test_1,
    test_2,
    test_3,
    test_4,
    test_5,
    test_6,
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
