@ECHO OFF
ECHO Generating Embedded C EPUB

"%ProgramFiles%\Pandoc\pandoc.exe" -f markdown -t epub --toc -o embedded_c.epub --reference-links -s metadata.yaml complete.md