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
| stud1000 | 11 | 0 | 1 |
| stud10000 | 87 | 16 | 1 |
| stud100000 | 907 | 147 | 25 |
| stud1000000 | 8996 | 1911 | 292 |
| stud10000000 | 90697 | 25683 | 2911 |

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

## Skirstymas pagal skirtingas strategijas (3 testų vidurkis) ms

#### Vector
| Failas | 1 strategija | 2 strategija (originali) | 3 strategija |
| :--- | ---- | ---- | ---- |
| stud1000 | 0 | 1 | 1 |
| stud10000 | 3 | 1 | 6 |
| stud100000 | 28 | 25 | 31 |
| stud1000000 | 372 | 292 | 335 |
| stud10000000 | 5580 | 2911 | 3398 |

#### List
| Failas | 1 strategija | 2 strategija (originali) | 3 strategija |
| :--- | ---- | ---- | ---- |
| stud1000 | 1 | 1 | 1 |
| stud10000 | 20 | 17 | 10 |
| stud100000 | 242 | 144 | 149 |
| stud1000000 | 2628 | 1570 | 1806 |
| stud10000000 | 60549 | 40532 | 25499 |

#### Deque
| Failas | 1 strategija | 2 strategija (originali) | 3 strategija |
| :--- | ---- | ---- | ---- |
| stud1000 | 1 | 1 | 0 |
| stud10000 | 12 | 6 | 6 |
| stud100000 | 159 | 71 | 70 |
| stud1000000 | 1698 | 937 | 884 |
| stud10000000 | 102817 | 61005 | 52611 |
