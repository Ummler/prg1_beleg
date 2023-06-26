# Aufgabenstellung

## Allgemeine Aufgabenstellung

Es ist eine Bedienoberfläche basierend auf gtk+, libforms oder als CGI-Webanwendung zu realisieren, dabei ergibt sich die zu implementierende Variante aus Matrikelnummer modulo 3 plus 1.  

## Hinweise zu Lösung

Hinweise zur Lösung:
Alle Aufgaben sind modular zu lösen, das Programm ist sinnvoll in mehrere Module, bestehend aus c- und Headerfile aufzuteilen. Jeder Modul soll getrennt compilierbar sein.
Die Daten sind in Datei(-en) zu speichern und programmintern durch geeignete Datenstrukturen zu verwalten. Haben sich die Daten beim Programmlauf verändert, so sind sie beim Verlassen des Programms zu speichern. Das Programm erlaube in jedem Fall das Erfassen, Löschen, Suchen und Anzeigen der Datensätze, sowie eine sortierte tabellarische Auflistung der Daten.
Die Quelltexte sind sorgsam zu kommentieren. Dazu gehört auch die Urheberschaft im Kopf der Quelltexte.
Für alle verwalteten Daten sind Speicherbereiche in der erforderlichen Größe per malloc/free bereitzustellen.
Das Programm bestehe mindestens aus 3 C-Modulen bestehend aus c- und Headerfile.
Die Programme müssen auf den Rechnern in den Laboren der Fakultät vorgeführt und übersetzt werden können.

## Belegaufgabe 1 C

Programmieren Sie ein elektronisches Telfonverzeichnis.
Das Programm soll Datensätze, die Name, Vorname und Telefonnummer von Personen speichern, verwalten.
Es soll auch eine Suche nach der Telefonnummer ermöglichen, um die zugeordnete Person zu finden.


