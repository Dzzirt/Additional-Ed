cls
@cd C:\Users\Dzzirt\Documents\Additional-Ed\Lab1\Task2\solve\Debug

rem not digit params
solve.exe a b c
@IF NOT ERRORLEVEL 0 GOTO err

rem params != 4
solve.exe 
@IF NOT ERRORLEVEL 0 GOTO err


@ECHO.
@ECHO OK
@exit /B

:err
@ECHO.
@ECHO Failed