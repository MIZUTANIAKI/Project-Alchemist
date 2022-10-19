@echo off
cd SaveDate
dir /b dat?.sav > ../list.tmp
cd ../
move list.tmp /temp