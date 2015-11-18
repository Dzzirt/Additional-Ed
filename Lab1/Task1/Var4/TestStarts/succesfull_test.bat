cls
@cd %~dp0

REM mama -> 123
..\Debug\replace.exe ../TestStarts/mama.txt ../TestStarts/output.txt mama 123
@IF NOT ERRORLEVEL 0 GOTO err
fc /B output.txt true_mama.txt
@IF NOT ERRORLEVEL 0 GOTO err

@ECHO OK
@EXIT /b

:err
@ECHO Failed
