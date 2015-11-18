cls
@cd C:\Users\Dzzirt\Documents\Additional-Ed\Lab1\Task2\solve\Debug

@REM discr > 0
solve.exe 15 27 9
@IF NOT ERRORLEVEL 0 GOTO err

@REM discr < 0
solve.exe 2 3 4
@IF NOT ERRORLEVEL 0 GOTO err

@REM discr == 0
solve.exe 1 6 9
@IF NOT ERRORLEVEL 0 GOTO err



@ECHO.
@ECHO OK
@exit /B

:err
@ECHO Failed
