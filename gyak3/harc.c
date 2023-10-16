#include <stdio.h>

typedef struct
{
    int damage;
    int speed;
} WeaponType;

typedef struct
{
    char name[50];
    int hitpoints;
    WeaponType weapon;
} CharacterType;

WeaponType getWeapon()
{
    WeaponType weapon;
    printf("Choose weapon: damage speed\n");
    scanf("%d %d", &weapon.damage, &weapon.speed);
    return weapon;
}

CharacterType getCharacter()
{
    CharacterType character;
    printf("Choose character: name(max 50) hp\n");
    scanf("%s %d", &character.name, &character.hitpoints);

    return character;
}

void printWeapon(WeaponType w)
{
    printf("damage: %d, speed: %d\n", w.damage, w.speed);
}

void printCharacter(CharacterType c, WeaponType w)
{
    printf("Character: name: %s, hitpoints: %d\nWeapon: ", c.name, c.hitpoints);
    printWeapon(w);
}

int main()
{
    CharacterType characters[4];

    int characterNumber = 1;

    for (int i = 0; i < characterNumber; i++)
    {
        characters[i] = getCharacter();
        characters[i].weapon = getWeapon();
    }

    // CharacterType playerCharacter = getCharacter();
    // WeaponType playerWeapon = getWeapon();

    for (int i = 0; i < characterNumber; i++)
    {
        printf("Name: %s, HitPoints: %d\n", characters[i].name, characters[i].hitpoints);
        printWeapon(characters[i].weapon);
    }

    return 0;
}