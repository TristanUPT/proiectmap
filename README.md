# Documentație Proiect Sincretic: Turnurile Hanoi
Implementarea soluției pentru problema Turnurilor Hanoi în limbajul de programare C++
## Descriere:
Se dau trei tije A, B, C și N discuri de diametre diferite, stivuite inițial pe tija A în ordinea descrescătoare a diametrelor, formând un con. Să se determine secvența de mutări ale discurilor de pe tija inițială A către tija finală C, folosind B ca tijă intermediară, având în vedere următoarele restricții:
- la fiecare mișcare se va muta un singur disc
- un disc se poate plasa doar asupra unui disc mai mare ca diametru.
  ## Structura Codului:
  #### Variabile Globale:
  -`vector<stack<int>> rods(3);`
  -`int moves = 0;`
  `rods`: Un vector de stive reprezentând cele trei tije ale Turnului din Hanoi.
`moves`: Un contor pentru numărul total de mutări efectuate.
### Funcție de Afișare a Tijelor:
`void displayTowers();`
Afișează starea actuală a tijelor în cadrul jocului.
### Funcție Turnul din Hanoi:
`void towerOfHanoi(int n, int source, int auxiliary, int destination);`
Implementarea recursivă a algoritmului Turnului din Hanoi.
### Funcție Joc Automatizat:
`void automatedGame(int n);`
Inițializează și gestionează jocul automatizat pentru un număr specific de discuri.
### Funcție Principală (main):
`Meniul principal care oferă opțiuni pentru a citi regulile, a juca manual sau a lăsa jocul să ruleze automat.`
#### Meniul Principal:
`Utilizatorul este întâmpinat cu opțiuni pentru citirea regulilor, joc manual sau joc automatizat.`
#### Reguli:
`Opțiunea 1 afișează regulile jocului Turnul din Hanoi.`
#### Joc Manual:
`Opțiunea 2 oferă utilizatorului posibilitatea de a juca manual cu diferite niveluri de dificultate sau număr personalizat de discuri.`
#### Joc Automatizat:
`Opțiunea 3 permite utilizatorului să observe cum jocul se desfășoară automat, alegând nivelul de dificultate sau numărul de discuri.`
#### Interacțiune cu Utilizatorul:
Se folosesc instrucțiuni `cout` și `cin` pentru a comunica cu utilizatorul, precum și pentru a colecta date de intrare.
## Exemplu de Utilizare:
```plaintext
Turnul din Hanoi minigame
1. Regulile jocului.
2. Joaca singur
3. Lasa minigame-ul sa joace pentru tine
Selecteaza o optiune:3

Selectati optiunea:
1. Dificultate predefinita
2. Numar personalizat de discuri
Alegeti optiunea:1

Selectati nivelul de dificultate:
1. Usor (3 discuri)
2. Normal (5 discuri)
3. Greu (8 discuri)
Alegeti nivelul de dificultate: 1

Turnul din Hanoi pentru 3 discuri:
-----------------------------------------------------
Tija C:
Tija B:
Tija A: 1 2 3
-----------------------------------------------------
Muta discul 1 din tija A la tija C
-----------------------------------------------------
Tija C: 1
Tija B:
Tija A: 2 3
-----------------------------------------------------
Muta discul 2 din tija A la tija B
-----------------------------------------------------
Tija C: 1
Tija B: 2
Tija A: 3
-----------------------------------------------------
Muta discul 1 din tija C la tija B
-----------------------------------------------------
Tija C:
Tija B: 1 2
Tija A: 3
-----------------------------------------------------
Muta discul 3 din tija A la tija C
-----------------------------------------------------
Tija C: 3
Tija B: 1 2
Tija A:
-----------------------------------------------------
Muta discul 1 din tija B la tija A
-----------------------------------------------------
Tija C: 3
Tija B: 2
Tija A: 1
-----------------------------------------------------
Muta discul 2 din tija B la tija C
-----------------------------------------------------
Tija C: 2 3
Tija B:
Tija A: 1
-----------------------------------------------------
Muta discul 1 din tija A la tija C
-----------------------------------------------------
Tija C: 1 2 3
Tija B:
Tija A:
-----------------------------------------------------
Jocul a luat sfarsit in 7 mutari.
```



## Utilizarea programului cu Docker
### Construirea și rularea într-un container Docker
- Construim imaginea docker:
```docker -build -t tristancv123/proiectmap .```
- Autentificarea in docker hub:
```docker login```
- Rularea in container Docker:
```docker run -it --rm tristancv123/proiectmap```

#### Conținutul Dockerfile
```plaintext
FROM gcc:latest
WORKDIR /app
COPY . /app
RUN gcc -o myapp Proiect.cpp -lstdc++
CMD ["./myapp"]
```

# Concluzie:
`Codul oferă o implementare funcțională și interactivă a jocului Turnul din Hanoi, permițând utilizatorului să experimenteze jocul manual sau să observe desfășurarea automată a acestuia.`




