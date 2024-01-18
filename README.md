# RobotMotorsControl
Учебный репозиторий для обучения программированию

ОТЧЕТ по практической работе 4 курса "Linux для робототехников" 

В рамках практической работы 4 был создан репозиторий проекта # RobotMotorsControl. В качестве примера 
использован код hello_motor.cpp из известной книги по робототехнике) Проект предполагает Робота на Raspbery Pi 
управляющего 2 моторами ,
передающих момент вращения на 4 колеса, левый и правый борт попарно.
(Поскольку немного знаю Си++ (по работе с Arduino), делаю работу в нем.)
Затем репозиторий был склонирован командой git clone на локальный компьютер,
создана ветка develop командой git branch develop, доработан код для обмена по uart проверены команды 
git add, git commit, git push, git pull, объединены ветки командой git merge+git push.
Далее в ветке develop заменена строчка управления по uart на управление по uart, но с микросхемой FT245 в качестве интерфейса USB
и создан pool request, далее прошу Вас подтвердить работоспособность кода.

Примечание.
(Код был создан в vscode), однако не настроен тулчейн, при запуске сборки выдает ошибки следущего содержания:

 
 *  Executing task: C/C++: gcc build active file 

Starting build...
/usr/bin/gcc -fdiagnostics-color=always -g /home/den/Документы/vscode/RobotMotorsControl/hello_motor.cpp -o /home/den/Документы/vscode/RobotMotorsControl/hello_motor
/home/den/Документы/vscode/RobotMotorsControl/hello_motor.cpp:10:10: fatal error: pigpiod_if2.h: Нет такого файла или каталога
   10 | #include <pigpiod_if2.h>
      |          ^~~~~~~~~~~~~~~
compilation terminated.

Build finished with error(s).

 *  The terminal process terminated with exit code: -1. 
 *  Terminal will be reused by tasks, press any key to close it.

Библиотека pigpiod была установлена в папку vscode/library/, при этом в настройках Extensions/C/C++ переменная IncludePath="${workspaceFolder}/**
Прошу Вас помочь в настройке тулчейна C++ в vscode для Raspberry Pi
