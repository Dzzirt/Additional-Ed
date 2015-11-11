cls
@cd %~dp0
@echo 12312312345.txt out.txt 1231234 cool
@echo.
@..\Debug\Var4.exe 12312312345.txt out.txt 1231234 cool
@echo.
@echo.
@echo mama.txt out.txt ma mama
@echo.
@..\Debug\Var4.exe mama.txt out.txt ma mama
@echo.
@echo.
@echo text.txt out.txt быстро 123
@echo.
@..\Debug\Var4.exe text.txt out.txt быстро 123
@echo.
@echo.
@fsutil file createnew big.txt 3147483648
@echo.
@echo big.txt out.txt 1 2
@echo.
@..\Debug\Var4.exe big.txt out.txt 1 2
@echo.
@echo.
@echo 12312312345.txt big.txt 1 2
@echo.
@..\Debug\Var4.exe 12312312345.txt big.txt 1 2
del big.txt
@echo.
@echo.
@echo empty.txt out.txt 1 2
@echo.
@..\Debug\Var4.exe empty.txt out.txt 1 2
@echo.
@echo.
@echo none.txt out.txt 1 2
@echo.
@..\Debug\Var4.exe none.txt out.txt 1 2
@echo.
@echo param count != 4
@echo.
@..\Debug\Var4.exe

