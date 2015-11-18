cls
@cd %~dp0

REM run without params
..\Debug\replace.exe
@IF NOT ERRORLEVEL 0 GOTO err

REM input file is not exist
..\Debug\replace.exe asdh output.txt 123 456
@IF NOT ERRORLEVEL 0 GOTO err
fc /B output.txt !0.txt

REM mama -> 123
..\Debug\replace.exe input.txt output.txt mama 123
@IF NOT ERRORLEVEL 0 GOTO err
fc /B output.txt true_mama.txt
@IF NOT ERRORLEVEL 0 GOTO err

@ECHO OK
@EXIT /b

:err
@ECHO Failed

