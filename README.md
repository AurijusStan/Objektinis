# Objektinio užduotis 1
  Programa skaičiuojanti galutinį studento rezultatą pagal pateiktus namų darbų ir egzamino rezultatus.

## Funkcionalumas
  - Meniu kuriame galima pasirinkti, ką atsitiktinai generuoti.
  - Duomenų įvedimas.
  - Galutinio balo skaičiavimas pagal vidurkį ir medianą.
  - Galima skaityti duomenis iš tam tikru formatu pateiktų teksto failų.

## Naudojimosi instrukcijos
  - Įjungti programą.
  - Sekti terminale matomus žingsnius.
  - Gauti rezultatus.

## Sistemos specifikacijos

- **CPU**: AMD Ryzen 5 5600H 3.30 GHz
- **RAM**: DDR4 16GB
- **HDD**: SSD 512GB

## Greičio testai (5 testų vidurkis) ms

#### Vector
| Failas | Skaitymo trukmė | Rūšiavimo trukmė | Skirstymo trukmė |
| :--- | ---- | ---- | ---- |
| stud1000 | 8 | 1 | 0 |
| stud10000 | 78 | 11 | 3 |
| stud100000 | 804 | 148 | 20 |
| stud1000000 | 8063 | 1941 | 288 |
| stud10000000 | 79864 | 24255 | 2373 |

#### List
| Failas | Skaitymo trukmė | Rūšiavimo trukmė | Skirstymo trukmė |
| :--- | ---- | ---- | ---- |
| stud1000 | 14 | 0 | 1 |
| stud10000 | 160 | 6 | 17 |
| stud100000 | 1160 | 78 | 144 |
| stud1000000 | 11753 | 1202 | 1570 |
| stud10000000 | 120384 | 18116 | 40532 |

#### Deque
| Failas | Skaitymo trukmė | Rūšiavimo trukmė | Skirstymo trukmė |
| :--- | ---- | ---- | ---- |
| stud1000 | 12 | 2 | 1 |
| stud10000 | 97 | 29 | 6 |
| stud100000 | 918 | 394 | 71 |
| stud1000000 | 9375 | 5177 | 937 |
| stud10000000 | 96751 | 69256 | 61005 |

