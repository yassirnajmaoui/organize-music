# organize-music
A quick and (very) unoptimized program i made to reorganize music folders

Let's pretend you have these files, which contain all your music.
Every file mp3 file is inside a directory for the album that is in a directory for the artist.
```

-- We are all astronauts
    |-- Autumn Time Vol. 3 (Album)
    |   |-- 23 Doves.mp3
    |   `-- cover.jpg
    |-- Lambo (Original Film Soundtrack) (Album)
    |   |-- 01 Ether.mp3
    |   |-- 08 Wolves.mp3
    |   |-- 09 Elysium.mp3
    |   `-- cover.jpg
    `-- Music for Dining in Space Vol 2 Compiled by DJ Darkhorse (Compile)
        |-- 12 Clear the Air.mp3
        `-- cover.jpg

```


Then this script will turn it into this:

```
|-- transfer
|   |-- We are all astronauts - Clear the Air.mp3
|   |-- We are all astronauts - Doves.mp3
|   |-- We are all astronauts - Elysium.mp3
|   |-- We are all astronauts - Ether.mp3
|   `-- We are all astronauts - Wolves.mp3
```
