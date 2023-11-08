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
1. feladat: AJANDEK (1 pont)
Október van, szóval már elég közel van hozzánk a karácsony, így elérkezett az idő, hogy a mikulás előkészítse
az idei ajándékokat, hogy aztán betörjön idegen emberek lakásába a kéményükön keresztül, megegye a másnapra szánt
süteményt és egyéb édességeket, és egy random, kétes eredetű csomagot hagyjon a nappali közepén, amiben a
gyanútlan lakosok esetleg felbotlanak és meghalnak. Segíts a mikulásnak az akciójában!

Készítsd el az `Ajandek` struktúrát, amelyről tároljuk el, hogy mekkora a doboz mérete, illetve mekkora a tomege.
A doboz mérete cm^3-ban, a tömeg gramm-ban van, csak hogy ne kelljen a mikulás manóinak valós számokkal számolniuk,
mivel az agyi kapacitásuk megegyezik egy manóéval. Persze ezzel nem sértegetni akartam őket, mivel hát ők manók,
szóval ezt a mondatot akár ki is hagyhattam volna.

A struktúra mezőit a fent leírt sorrendben hozd létre!
*/

//#define KIHAGY_1
#if !(defined(KIHAGY_1) || defined(KIHAGY_MIND))

// Ide dolgozz

typedef struct {
    int meret;
    int tomeg;
} Ajandek;


#endif

/*
2. feladat: SZAN (1 pont)
A mikulásnak sikerült előkészítenie az ajándékokat, így indulhat a betörés! Akarom mondani az akció! Mármint az
ajándékosztás! Az ajándékokat a mikulás a szánján fogja elszállítani, amelyet a gyönyörűséges rénszarvasok húznak,
akikről majd később lehet még mesélek. Azonban a szánnak is vannak korlátai.

Készítsd el a `Szan` struktúrát. A szánról tudjuk, hogy legfeljebb hány cm^3-nyi térfogatú csomagot bír el, illetve
maximálisan hány g ajándék szállítható vele. Emellett azt is tároljuk el, hogy hány rénszarvas húzza majd a szánt.

A struktúra mezőit a fent leírt sorrendben hozd létre!
*/

//#define KIHAGY_2
#if !(defined(KIHAGY_2) || defined(KIHAGY_MIND))

// Ide dolgozz

typedef struct {
    int max_terfogat;
    int max_tomeg;
    int renszarvasok;
} Szan;

#endif

/*
3. feladat: DE NEHEZ A SZAN (4 pont)
Azért a szeretet ünnepén gondolnunk kell a rénszarvasokra is, akik minden erejükkel azon vannak, hogy a mikulás
akcióját segítsék. Háláljuk meg nekik ezt azzal, hogy nem szállíttatunk velük túl sok rakományt egyszerre!

Valósítsd meg a `maximalis_rakomany_tomeg` függvényt, amely paraméterben a szánt várja, illetve a mikulás tömegét
kg-ban (1 tizedesjegy pontossággal, 1 kg = 1000 g).

A rakomány maximális tömegét úgy számítjuk ki, hogy a szán által elbírt maximális tömegből kivonjuk a mikulás tömegét.
Azonban ha a szánt 5-nél kevesebb rénszarvas húzza, akkor ezt a tömeget el kell osztani 2-vel (lefelé kerekítve).

Példa input:
    Szán maximális tömege: 150.000 g
    Rénszarvasok száma: 3
    Miklulás tömeget: 120 kg
Példa output:
    15000
Magyarázat:
    A szán 150.000 g-nyit tud szállítani, ebből 120.000 g a mikulás, marad 30.000 a rakománynak
    Viszont 5-nél kevesebb (3) rénszarvas húzza, így ezt el kell osztani 2-vel, marad 15.000 g (ami 15 kg)
*/

/* typedef struct { int max_terfogat; int max_tomeg; int renszarvasok; } Szan; */

int maximalis_rakomany_tomeg(Szan szan, float mikulas_tomeg) {
    int tomeg = szan.max_tomeg - mikulas_tomeg * 1000;
    if(szan.renszarvasok < 5) tomeg /= 2;
    return tomeg;
}

/*
4. feladat: A GYEREKEK EGYRE JOBBAK (4 pont)
Miközben a mikulás és titkos csapata az akció részleteit dolgozza ki, a manók különböző statisztikákat készítenek.
Azt tapasztalták, hogy minden évben a jó gyerekek száma ugyanannyival növekszik. Ennek okát pontosan nem tudják,
de valószínűleg az lehet a háttérben, hogy a gyerekek egész nap a telefonjukat nyomkodják, így nincs is lehetőségük
rosszalkodni, mint a régi szép időkben.

A manók szeretnének a mikulásnak prezentációt készíteni az elkövetkező évek várható adatairól. Segíts nekik ebben!

Valósítsd meg a `jo_gyerekek` függvényt, ami első paraméterben azt várja, hogy a megfigyelés kezdetén (2000-ben)
hány jó gyerek volt. A második paraméter (növekmény) megmondja, hogy mennyivel növekszik a jó gyerekek száma évenként.
A harmadik paraméter pedig megmondja, hogy melyik a kérdéses év, amikor ki szeretnénk deríteni, hogy várhatóan hány
jó gyerek lesz. A függvény adja vissza, hogy abban az évben várhatóan hány jó gyerek lesz.

Példa input:
    1000, 15, 2007
Példa output:
    1105
Magyarázat:
    2000-ben 1000 jó gyerek volt, és minden évben 15-tel növekszik, tehát (2001: 1015; 2002: 1030; 2003: 1045;
    2004: 1060; 2005: 1075; 2006: 1090; 2007: 1105).
*/
int jo_gyerekek(int regen, int novekmeny, int ev) {
    return regen + (ev - 2000) * novekmeny;
}

/*
5. feladat: INFLACIO (6 pont)
A mikulás manói nem csak a gyerekek számában vettek észre összefüggéseket, hanem az ajándékok áraiban, ugyanis
azt tapasztalták, hogy az infláció (illetve a jó gyerekek számának növekvése) miatt minden évben ugyanannyi %-kal
növekszik az ajándékok költsége az előző évhez képest. A kérdés, hogy egy adott időszakban összesen mennyit költöttek
Mikulásék ajándékokra, ebben kérik az ön segítségét, hiszen ők nem matematikusok, ön viszont lehet, hogy igen.

Először is legyen kedves elkészíteni az `Idoszak` struktúrát, amely egy időszakot ír le, tehát két mezővel rendelkezik
(az időszak kezdetét, illetve végét jelölő évek).

Ha ezzel elkészült, utána tessen megvalósítani az `ossz_koltseg` függvényt, amelynek 3 paramétere van:
 - az ajándékok költsége 2000-ben
 - a növekmény, ami megmondja, hogy minden évben hány %-kal növekszik az összköltség az előző évhez képest
 - egy időszak, ami a kezdeti és végső évszámot tartalmazza.

A függvény számítsa ki az ajándékok összköltségét a megadott időszakban!

Példa input:
    15000, 10, 2003-2005
Példa output:

Magyarázat:
    2000-ben összesen 15.000 $-ba kerültek az ajándékok, amely költség minden évben 10%-kal növekszik.
    A 2003-2005-ös időszakra vagyunk kíváncsiak
    (2001: 16500 ; 2002: 18150 ; 2003: 19965 ; 2004: 21961.5 ; 2005: 24157.65).
    Ebből az utolsó 3 (2003-2005) összegére vagyunk kíváncsiak, ami összesen 66.084,15.
*/

// A KOVETKEZO SORT KOMMENTEZD KI, HA ELKEZDED MEGOLDANI A FELADATOT!!!
/* #define KIHAGY_5 */
#if !(defined(KIHAGY_5) || defined(KIHAGY_MIND))

typedef struct {
    int eleje;
    int vege;
} Idoszak;

double ossz_koltseg(double kezdeti_koltseg, double novekmeny, Idoszak idoszak) {

    double elejeig_koltseg = kezdeti_koltseg;

    /* printf("Elejeig novekvesek:\n"); */
    for (int i = 2001; i <= idoszak.eleje; i++)
    {
        elejeig_koltseg *= 1 + novekmeny / 100;
        /* printf("%lf\n", elejeig_koltseg); */
    }
    
    float eddigi_koltseg = elejeig_koltseg;
    float osszkoltseg = elejeig_koltseg;

    /* printf("Idoszakban:\n"); */
    for (int i = idoszak.eleje + 1; i <= idoszak.vege; i++)
    {
        eddigi_koltseg *= 1 + novekmeny / 100;
        /* printf("Eddigi: %lf\n", eddigi_koltseg); */
        osszkoltseg += eddigi_koltseg;
        /* printf("Ossz: %lf\n", osszkoltseg); */
        /* printf("\n"); */
    }

    return osszkoltseg;

}

#endif

/*
6. feladat: BENCSELEKMENY (4 pont)
Kiderült, hogy a mikulás, aki a betöréseket tervezte, igazából nem a valódi mikulás volt, hanem egy szélhámos,
és csak álca volt a mikulásruha és az ajándékok, igazából elvitte a gyanútlan lakosok értékeit :(
Szerencsére a rendőrség már intézkedik, elkapták az álmikulást és börtönbe zárták.

A rendőrség szeretné meghatározni, hogy összesen mennyi kárt okozott az álmikulás. Tedd jóvá a korábbi cselekedetedet,
miszerint segítetted az álmikulás akcióját, és most segítsd a rendőrök munkáját. Utána majd döntsd el, hogy melyik
oldalhoz szeretnél tartozni!

Valositsd meg a `karbecsles` függvényt, amely paraméterben megkapja a károk mértékét egy tömbben, illetve a tömb méretét.
A függvény adja vissza az össz-kárt ezek alapján.

Figyelem! A rendőrség nagyon szereti a rekurziót! A függvényt rekurzív módon valósítsd meg! A megállási feltétel
a legkorábbi olyan eset legyen, ahol számítás nélkül lehet tudni a visszatérési értéket!
*/
#define return fprintf(stdout, "0");return

int i = 0;
int osszkar = 0;

float karbecsles(float karok[], int darabszam) {

    if(i < darabszam) osszkar += karok[i];

    return osszkar;
}

#undef return
/***********************************************************************
************************************************************************
**
**  EZEN A PONTON TÚL NE VÁLTOZTASS SEMMIT SEM A FÁJLON!
**
************************************************************************
***********************************************************************/

void call_1(){
#if !(defined(KIHAGY_1) || defined(KIHAGY_MIND))
    Ajandek a = {5, 7};
    fprintf(stdout, "1\n");
#endif
}
void test_1(){
#if !(defined(KIHAGY_1) || defined(KIHAGY_MIND))
    Ajandek ajandek = {5, 2};
#endif
}

void call_2(){
#if !(defined(KIHAGY_2) || defined(KIHAGY_MIND))
    Szan a = {50, 70, 10};
    fprintf(stdout, "1\n");
#endif
}
void test_2(){
#if !(defined(KIHAGY_2) || defined(KIHAGY_MIND))
    Szan szan = {7, 30, 100};
#endif
}

void call_3(){
#if !(defined(KIHAGY_3) || defined(KIHAGY_MIND))
    int eredmeny;
    int s1, s2, s3;
    float t;
    int check;

    if((check = fgetc(stdin)) == EOF) {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }

    if (fscanf(stdin, "%d %d %d %f", &s1, &s2, &s3, &t) != 4) {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }

    Szan szan = {s1, s2, s3};
    eredmeny = maximalis_rakomany_tomeg(szan, t);
    fprintf(stdout, "%d\n", eredmeny);
#endif
}
void test_3(){
#if !(defined(KIHAGY_3) || defined(KIHAGY_MIND))
    int i;
    int eredmeny;
    struct {
        Szan a;
        float b;
        int c;
    } testlist[2] = {
            {{400, 150000, 3}, 120, 15000},
            {{400, 160000, 5}, 120, 40000}
    };
    for (i = 0; i < 2; ++i) {
        eredmeny = maximalis_rakomany_tomeg(testlist[i].a, testlist[i].b);
        if (eredmeny != testlist[i].c) {
            fprintf(stderr,
                    "HIBA: maximalis_rakomany_tomeg:\n"
                    "\telvárt eredmény: %d\n"
                    "\tkapott eredmény: %d\n",
                    testlist[i].c, eredmeny
            );
        }
    }
#endif
}

void call_4(){
#if !(defined(KIHAGY_4) || defined(KIHAGY_MIND))
    int eredmeny;
    int s1, s2, s3;
    int check;

    if((check = fgetc(stdin)) == EOF) {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }

    if (fscanf(stdin, "%d %d %d", &s1, &s2, &s3) != 3) {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }

    eredmeny = jo_gyerekek(s1, s2, s3);
    fprintf(stdout, "%d\n", eredmeny);
#endif
}
void test_4(){
#if !(defined(KIHAGY_4) || defined(KIHAGY_MIND))
    int i;
    int eredmeny;
    struct {
        int a;
        int b;
        int c;
        int d;
    } testlist[2] = {
            {1000, 15, 2007, 1105},
            {2500, 50, 2000, 2500}
    };
    for (i = 0; i < 2; ++i) {
        eredmeny = jo_gyerekek(testlist[i].a, testlist[i].b, testlist[i].c);
        if (eredmeny != testlist[i].d) {
            fprintf(stderr,
                    "HIBA: jo_gyerekek(%d, %d, %d):\n"
                    "\telvárt eredmény: %d\n"
                    "\tkapott eredmény: %d\n",
                    testlist[i].a, testlist[i].b, testlist[i].c, testlist[i].d, eredmeny
            );
        }
    }
#endif
}

void call_5(){
#if !(defined(KIHAGY_5) || defined(KIHAGY_MIND))
    double eredmeny;
    int s1, s2;
    double p1, p2;
    int check;

    if((check = fgetc(stdin)) == EOF) {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }

    if (fscanf(stdin, "%lf %lf %d %d", &p1, &p2, &s1, &s2) != 4) {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        fprintf(stderr, "%lf %lf %d %d", p1, p2, s1, s2);
        return;
    }

    Idoszak idoszak = {s1, s2};
    eredmeny = ossz_koltseg(p1, p2, idoszak);
    fprintf(stdout, "%.1lf\n", ((int)(10 * eredmeny)) / 10.0);
#endif
}
void test_5(){
#if !(defined(KIHAGY_5) || defined(KIHAGY_MIND))
    int i;
    double eredmeny;
    double diff;

    struct {
        double a;
        double b;
        int c;
        int d;
        double e;
    } testlist[2] = {
            {15000, 10, 2003, 2005, 66084.15},
            {20000, 100, 2001, 2003, 280000}
    };
    for (i = 0; i < 2; ++i) {
        Idoszak ido = {testlist[i].c, testlist[i].d};
        eredmeny = ossz_koltseg(testlist[i].a, testlist[i].b, ido);
        diff = eredmeny - testlist[i].e;
        if (diff < 0) {
            diff *= -1;
        }

        if (diff > 0.01) {
            fprintf(stderr,
                    "HIBA: ossz_koltseg(%lf, %lf, %d-%d):\n"
                    "\telvárt eredmény: %lf\n"
                    "\tkapott eredmény: %lf\n",
                    testlist[i].a, testlist[i].b, testlist[i].c, testlist[i].d, testlist[i].e, eredmeny
            );
        }
    }
#endif
}

void call_6(){
#if !(defined(KIHAGY_6) || defined(KIHAGY_MIND))
    float eredmeny;
    int db;
    float tomb[25];
    int i;
    int check;

    if((check = fgetc(stdin)) == EOF) {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }

    if (fscanf(stdin, "%d", &db) != 1) {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }

    for (i = 0; i < db; i++) {
        if (fscanf(stdin, "%f", &tomb[i]) != 1) {
            fprintf(stderr, "HIBA: Nem olvasható adat!\n");
            return;
        }
    }

    eredmeny = karbecsles(tomb, db);
    fprintf(stdout, "%.2f\n", eredmeny);
#endif
}
void test_6(){
#if !(defined(KIHAGY_6) || defined(KIHAGY_MIND))
    int i, j;
    float eredmeny;
    float diff;

    struct {
        int b;
        float c;
        float a[100];
    } testlist[2] = {
            {4, 12, {4, 1, 2, 5}},
            {6, 17, {5, 5, 5, 1, 0, 1}}
    };
    for (i = 0; i < 2; ++i) {
        eredmeny = karbecsles(testlist[i].a, testlist[i].b);
        diff = eredmeny - testlist[i].c;
        if (diff < 0) {
            diff *= -1;
        }

        if (diff > 0.01) {
            fprintf(stderr, "HIBA: karbecsles([");

            for (j = 0; j < testlist[i].b - 1; j++) {
                fprintf(stderr, "%.2f, ", testlist[i].a[j]);
            }

            fprintf(stderr, "%.2f", testlist[i].a[j]);

            fprintf(stderr,
                    "], %d):\n"
                    "\telvárt eredmény: %f\n"
                    "\tkapott eredmény: %f\n",
                    testlist[i].b, testlist[i].c, eredmeny
            );
        }
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
	NULL
};


call_function test_table[] = {
	test_1,
	test_2,
	test_3,
	test_4,
	test_5,
	test_6,
	NULL
};

static int __arg_check_helper(const char * exp, const char * arg) {
    while (*exp && *arg && *exp == *arg) {
        ++exp;
        ++arg;
    }
    return *exp == *arg;
}

int main(int argc, char *argv[])
{
    int feladat, calltabsize;
    if ((argc > 1) && !(__arg_check_helper("-t", argv[1]) && __arg_check_helper("--test", argv[1]))) {
        if (argc > 2) {
            feladat = atoi(argv[2]);
            for (calltabsize=0; test_table[calltabsize]; calltabsize++);
            if (feladat <= 0 || calltabsize < feladat) {
                fprintf(stderr, "HIBA: rossz feladat sorszám: %d!\n", feladat);
                return 1;
            }
            (*test_table[feladat-1])();
        } else {
            for (feladat=0; test_table[feladat]; ++feladat) {
                (*test_table[feladat])();
            }
        }
        return 0;
    }
    if (!freopen("be.txt", "r", stdin)) {
        fprintf(stderr, "HIBA: Hiányzik a `be.txt'!\n");
        return 1;
    }
    if (!freopen("ki.txt", "w", stdout)) {
        fprintf(stderr, "HIBA: A `ki.txt' nem írható!\n");
        return 1;
    }
    for (calltabsize=0; call_table[calltabsize]; calltabsize++);
    if (fscanf(stdin, "%d%*[^\n]", &feladat)!=1) {
        fprintf(stderr, "HIBA: Nem olvasható a feladat sorszám!\n");
        return 1;
    }
    fgetc(stdin);
    if (0<feladat && feladat<=calltabsize) {
        (*call_table[feladat-1])();
    } else {
        fprintf(stderr, "HIBA: Rossz feladat sorszám: %d!\n", feladat);
        return 1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
