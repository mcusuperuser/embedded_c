@ECHO OFF
ECHO Generating Embedded C EPUB

REM "%ProgramFiles%\Pandoc\pandoc.exe" -f gfm -t epub -o embedded_c.epub ..\chapters\title.txt \
REM ..\chapters\preface.md \
REM ..\chapters\05.md \
REM ..\chapters\10.md \
REM ..\chapters\15.md \
REM ..\chapters\20.md \
REM ..\chapters\25.md \
REM ..\chapters\30.md \
REM ..\chapters\35.md

"%ProgramFiles%\Pandoc\pandoc.exe" -f markdown -t epub -s -o embedded_c.epub ..\chapters\metadata.yaml ..\chapters\preface.md ..\chapters\05.md ..\chapters\10.md ..\chapters\15.md ..\chapters\20.md ..\chapters\25.md ..\chapters\30.md ..\chapters\35.md