# Woracle

Projet C++ minimal (C++20) initialisé pour développer un solveur Wordle en ligne de commande. L'ancienne dépendance à Qt a été retirée pour repartir de zéro.

## Prérequis

- CMake >= 3.10
- Compilateur C++20 (MSVC, GCC, Clang)

## Construction

```bash
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

Sous Windows avec plusieurs générateurs installés, vous pouvez préciser par exemple:
```bash
cmake -G "MinGW Makefiles" ..
```

## Exécution

Après compilation:
```bash
./woracle
```
Sous Windows (MSVC):
```bash
Release\\woracle.exe
```

## Structure
```
woracle/
├── CMakeLists.txt
├── src/
│   ├── main.cpp
│   ├── WordleSolver.h/.cpp
├── tests/
│   └── test_solver.cpp
└── README.md
```

## TODO (idées de démarrage)
- Améliorer la logique de filtrage pour les lettres dupliquées
- Ajouter une classe `WordleSolver` plus avancée (scoring)
- Implémenter le filtrage par feedback (g,y,b) plus strict
- Ajouter tests unitaires supplémentaires (couverture doublons)
- Support lecture d'un fichier de mots

## Licence
Voir fichier LICENSE.
