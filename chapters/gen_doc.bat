@ECHO OFF
ECHO Generating Embedded C EPUB

"%ProgramFiles%\Pandoc\pandoc.exe" -f markdown -t epub --toc --css=pandoc.css -o embedded_c.epub --reference-links -s metadata.yaml complete.md
"%ProgramFiles%\Pandoc\pandoc.exe" -f markdown -t html --toc --css=pandoc.css -o embedded_c.html --reference-links -s metadata.yaml complete.md
