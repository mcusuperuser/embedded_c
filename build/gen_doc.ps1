<#
.SYNOPSIS
    This script builds the documentation in the Embedded C GitHub repository.

.DESCRIPTION
    Use this script for generating HTML documentation and EPUB from the markdown files.

.NOTES
    Author:  Christopher Seidl
    Date:    October 15, 2018
#>
Write-Output "Switching directory to ..\chapters"
Push-Location ..\chapters
Write-Output "Removing previous builds"
Remove-Item .\all_chapters.md -ErrorAction SilentlyContinue
Remove-Item .\embedded_c.html -ErrorAction SilentlyContinue
Remove-Item .\embedded_c.epub -ErrorAction SilentlyContinue
Write-Output "Concatenating markdown files"
Get-Content .\*.md | Set-Content all_chapters.md
Write-Output "Generating HTML documentation"
&pandoc.exe -f markdown -t html -c epub.css -o embedded_c.html --reference-links -s -S all_chapters.md
Write-Output "Generating EPUB"
&pandoc.exe -f markdown -t epub -c epub.css -o embedded_c.epub --reference-links -s -S metadata.yaml all_chapters.md
Write-Output "Going back to build directory and done!"
Pop-Location