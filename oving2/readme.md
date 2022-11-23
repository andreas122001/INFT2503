# Oppgave 1

## a)

*i* og *j* vil ha verdiene 3 og 5, mens p og q vil ha verdier lik adressene til i og j, altså &i og &j.
p og q har egne adresser lik &p og &q.

```
i = 3, &i = 0x7a0a3ffcec
j = 5, &j = 0x7a0a3ffce8
p = 0x7a0a3ffcec, &p = 0x7a0a3ffce0
q = 0x7a0a3ffce8, &q = 0x7a0a3ffcd8
```

Som vi kan se i outputet er `p = &i` og `q = &j`

## b)
```
*p = 7;        // i settes til 7
*q += 4;       // j settes til 5 + 4 = 9
*q = *p + 1;   // j settes til 7 + 1 = 8
p = q;         // p settes til å peke på j
cout << *p << " " << *q << endl; // *p = *q = j = 8
```

Her vil begge verdiene bli 8, siden p peker på samme adresse som q, og q peker på j, som er 8.

# Oppgave 2

*line* peker på null-adressen, og adresser etter null-adressen er ikke allokert for teksten som skal kopieres.
Det som vi skje er at `strcpy()` vil prøve å overskive adresser på og etter 0x0 med teksten. Sannsynligvis vil en få en `segmentation fault`.

# Oppgave 3

```c++
char text[5];
char * pointer = text;
char search_for = 'e';     
cin >> text;                     // om input er for lang kan en få error.
while (*pointer != search_for) { // stopper ikke før *pointer = 'e', kan hende det aldri skjer.
  *pointer = search_for;
  pointer++;
}
```
Om det ikke finnes en 'e' i teksten vil programmet prøve å overskrive *alle* adresser også etter teksten med 'e', så lenge den ikke finner en 'e' i minnet.
Dette fordi stoppebetingelsen til while-loopen er at bokstaven som pointer peker på er 'e'.

I tillegg kan en få feil om input-teksten er lengre enn 4 bokstaver.

# Oppgave 4

Se kommentarene i [oppg4.cpp](oppg4.cpp).

# Oppgave 5
 
Se [oppg5.cpp](oppg5.cpp).

 ```c++
double number;
double *p = &number;
double &ref = number;

number = 5;
*p = 5;
ref = 5;
 ```

 # Oppgave 6

 Se [oppg6.cpp](oppg6.cpp).

