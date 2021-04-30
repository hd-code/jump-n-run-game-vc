# Visual Computing

Dies ist das Projekt für das Fach Visual Computing an der FH-Erfurt von Hannes Dröse.

Es ist ein Plattformer geschrieben in C++ mit dem SFML-Framework.

## Installation

Es muss lediglich das Git-Repository geklont werden. Danach lässt sich das Projekt mit Visual Studio öffnen und starten.

```sh
git clone https://github.com/hd-code/jump-n-run-game-vc.git
```

Das Projekt kann nur auf Windows mit Visual Studio gebaut und gestartet werden.

Dazu die Projektmappe `project.sln` mit Visual Studio öffnen. Die letzten Executables sind mit eingecheckt. das Projekt müsste sich also direkt ausführen lassen.

## Development

Dieses Projekt liegt auf 2 Git-Repos gleichzeitig. Einmal auf Github und zusätzlich noch auf dem Git-Server der FH Erfurt. Damit ein Push immer auf beide Repos erfolgt, müssen beide als remotes registriert sein.

```sh
# wenn noch nicht geschehen, Repo von Github clonen
git clone https://github.com/hd-code/vc.git

# in das Verzeichnis des Projektes wechseln
cd vc

# beide Git-Server als remote hinzufügen
git remote set-url --add --push origin https://github.com/hd-code/jump-n-run-game-vc.git
git remote set-url --add --push origin https://source.ai.fh-erfurt.de/ha9384dr/vc.git

# Überprüfen ob es geklappt hat
git remote -v
# => es sollten nun beide Repos für den push-Befehl hinterlegt sein
```