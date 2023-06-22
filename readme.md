# Elektronisches Telefonverzeichnis

Dieses Programm ist ein einfaches elektronisches Telefonverzeichnis, das die Verwaltung von Kontaktdaten (Name, Vorname und Telefonnummer) ermöglicht.

## Angaben zum Autor

**Name**: Umlauft  
**Vorname**: Florian  
**E-Mail**: florian.umlauft@htw-dresden.de  
**Studiengang**: Informatik  
**Matrikelnummer**: 51345  
**s-Nummer**: s83747  
**Semester**: 4  
**Studiengruppe**: 21/041/62

## Dateistruktur

Das Projekt ist wie folgt strukturiert:

- `main.c`: Hauptprogrammdatei, verantwortlich für die Verarbeitung von Befehlszeilenargumenten und das Aufrufen entsprechender Funktionen.
- `contacts.c` und `contacts.h`: Enthalten die Struktur `Contact` und Funktionen zur Verwaltung von Kontakten.
- `search.c` und `search.h`: Enthalten Funktionen zur Durchführung von Such- und Sortieroperationen auf Kontakten.
- `utils.c` und `utils.h`: Enthalten Hilfsfunktionen, die von den anderen Modulen verwendet werden.
- `contacts.csv` ist die Datei, in der alle gespeicherten Kontakte kommasepariert gespeichert werden.
- `example_contacs.csv` ist eine Datei im selben Format wie `contacts.csv`. Diese Datei ist vorangig zu Testzwecken angedacht.

## Funktionsweise

Das Programm unterstützt die folgenden Befehle:

- `-n [Name] [Vorname] [Telefonnummer]`: Erstellt einen neuen Kontakt.
- `-o`: Sortiert und listet Kontakte auf. Es wird eine Abfrage zur Auswahl des Sortierparameters und der Sortierreihenfolge angezeigt.
- `-s [Argument]`: Sucht nach Kontakten, die das angegebene Argument enthalten. Dabei ist es auch möglich einen Namens- oder Telefonnummernanfang einzugeben, um alle darauf zutreffenden Ergebnisse gelistet angezeigt zu bekommen.
- `-k`: Löscht alle Kontakte.
- `-c`: Erstellt alle Kontakte, die in der Datei `example_contacts.csv` liegen. Diese Option ist vorangig zum Testen des Programmes angedacht.

## Struct Implementierung

Das Programm verwendet die `Contact`-Struktur, um Kontaktdaten zu speichern. Jeder `Contact` hat einen Namen, einen Vornamen und eine Telefonnummer, die als Zeichenketten (Arrays von `char`) gespeichert sind, sowie einen Zeiger auf den nächsten `Contact` in der Liste. Dies ermöglicht es, Kontakte in einer verketteten Liste zu speichern, was effiziente Einfüge- und Suchoperationen ermöglicht.

## Kompilieren und Ausführen

Zum Kompilieren des Programms navigieren Sie in der Konsole zum Verzeichnis des Programms und führen Sie den folgenden Befehl aus:

```C
gcc main.c contacts.c search.c utils.c -o phone
```

Dies erzeugt eine ausführbare Datei namens `phone`.

Um das Programm auszuführen, verwenden Sie den folgenden Befehl, gefolgt von den gewünschten Optionen und Argumenten:

```C
./phone [option] [arguments]
```

Zum Beispiel, um einen neuen Kontakt hinzuzufügen, würden Sie Folgendes eingeben:

```C
./phone -n Mustermann Max 1234567890
```
