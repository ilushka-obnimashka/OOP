# Game of Life


## Содержание
- [Описание игры](#описание игры)
   - [Особенности реализации](#оссобенности реализации)
   - [Управление](#управление)
- [Техническое задание](#техническое задание)
- [Описание формата файла #Life 1.06](#Life 1.06)
- [Сборка проекта](#сборка проекта)
- [Запуск](#запуск)
  - [Опции запуска](#опции-запуска)
  - [Примеры запуска](#примеры-запуска)
  - [Интересные заготовки запуска](#Интересные заготовки запуска)

## Описание игры

Игра "Жизнь" (Game of Life) — это клеточный автомат, придуманный британским математиком Джоном Конвеем в 1970 году. Игра происходит на бесконечной двумерной сетке клеток, каждая из которых может находиться в одном из двух состояний: живая или мертвая. Состояние клеток изменяется в соответствии с простыми правилами, основанными на состоянии соседних клеток.

### Особенности реализации

Моя реализация игры "Жизнь" немного отклоняется от технического задания, но при этом использует графическую библиотеку `raylib` для создания визуально привлекательного и интерактивного представления вселенной. Вот основные особенности:

1. **Графическая визуализация**:
   - Использование библиотеки `raylib` позволяет создать красивое и интуитивно понятное графическое представление вселенной.
   - Пользователи могут наблюдать за изменением состояния клеток в реальном времени, что делает игру более увлекательной и наглядной.

2. **Дружелюбность к пользователю**:
   - Программа предоставляет ясные сообщения об ошибках формата файла и другие полезные подсказки.
   - Наличие справки и демонстрация ее при неправильном вводе обеспечивают максимальную дружелюбность к пользователю.

3. **Оффлайн и онлайн режимы**:
   - Программа умеет работать в онлайн и оффлайн режимах.
   - При запуске в онлайн режиме будет запущена графическая визуализация состояния вселенной.
   - При запуске в оффлайн режиме пользователь получит состояние его вселенной через нужное количество иттераций.
   (Подробнее см. [Техническое задание](#техническое задание))

4. **Документирование кода**:
   - В моем коде активно документированы все методы и классы, что облегчает понимание и поддержку программы.

Несмотря на некоторые отклонения от технического задания, моя реализация игры "Жизнь" с использованием графической библиотеки `raylib` обеспечивает визуально привлекательное и интерактивное представление вселенной. Программа предоставляет все необходимые функции и обеспечивает дружелюбность к пользователю, делая игру более увлекательной и наглядной.

### Управление
Во время симуляции игрок может :
1) Ставить симуляцию на паузу, нажатием клавиши клавиатуры "p". (симуляция возобновится после нажатия клавиши клавиатуры "enter").
2) Ускорять/замедлять процесс симуляции, нажатием клавиш клавиатуры "a/d".
3) Очищать поле симуляции, нажатием клавиши клавиатуры "c" (игра ставится на паузу и ожидает ввода состояния клеток).
4) Управлять состоянием клетки поля, посредством нажатия левой кнопки мыши на соответствующую клетку (игру нужно ставить на паузу).

## Техническое задание

### Требования к программе:

1. **Считывание вселенной из файла**:
    - Программа должна уметь считывать "вселенную" из файла .
    - Вселенная описывается:
        - (а) размером поля;
        - (б) правилом перехода клетки;
        - (в) состоянием ячеек.
    - Файл может подаваться программе при старте в качестве параметра входной строки.

2. **Инициализация поля**:
    - В случае, если файл не подан, начинать игру на произвольно инициализированном поле некоего фиксированного размера, красиво отображающегося на консоли.
    - Поле, инициализированное случайным образом малоинтересно, поэтому рекомендуется начинать игру на каких-нибудь заранее продуманных примерах.
    ***Изменено с согласия преподователя***:
    - красиво отображающегося на консоли : **изменено**. Игра использует графическую визуализацию состояния вселенной. Используется библиотека raylib (см. https://github.com/raysan5/raylib)
3. **Оффлайн режим**:
    - Программе подается входной файл, количество итераций, выходной файл.
    - Программа рассчитывает состояние поля после указанного количества итераций и сохраняет вселенную в указанный выходной файл.
    - Параметры командной строки:
        - `-i x` либо `--iterations=x`: Количество итераций.
        - `-o filename` либо `--output=filename`: Выходной файл.

4. **Команды после старта игры**:
    - `dump <filename>`: Сохранить вселенную в файл.
    - `tick <n=1>` (и сокращенно `t <n=1>`): Рассчитать `n` (по умолчанию 1) итераций и напечатать результат. На экране перед распечатанным полем должно отображаться имя вселенной, правило перехода и номер текущей итерации.
    - `exit`: Завершить игру.
    - `help`: Распечатать справку о командах.

   ***Изменено с согласия преподователя***:
   - `dump <filename>` : **не поддерживается**. При закрытии окна с отображением состояния вселенной, она всегда сохранится в файл ouput.txt.
   - `tick <n=1>`: **не поддерживается**. Игра постоянно отображает состояние вселенной на текущей иттерации. Номер текущей итерации также отображается. 
   - `exit` : **изменено**. Игра при онлайн режиме завершается при закрытии окна с отображением состояния вселенной.
   - `help` : **изменено**. Справка об игре будет получена при запуске с соответсвтующими опциями `./GameOfLife -h` или `./GameOfLife --help`. (Подробнее об опциях запуска: см в [Опции запуска](#опции-запуска))
      

5. **Поддержка разных правил перехода**:
    - Программа должна поддерживать расчет по разным правилам перехода состояний ячеек (см. [Описание формата файла #Life 1.06](#Life 1.06)).

6. **Замкнутое поле**:
    - Поле игры считать замкнутым (тороидальным). Таким образом, соседи сверху первого ряда поля - клетки последнего ряда и наоборот, аналогично для левого и правого краев вселенной.

7. **Архитектура программы**:
    - Программа должна быть разбита на классы.
    - Использование единственного God Object, хранящего состояние игры, рассчитывающего состояния и взаимодействующего с пользователем, не допускается.

8. **Использование стандартной библиотеки**:
    - Реализация программы подразумевает активное освоение стандартной библиотеки: файловых потоков, контейнеров, алгоритмов.

9. **Дружелюбность к пользователю**:
    - Реализация игры подразумевает "играбельность" и максимальную дружелюбность к пользователю: ясные сообщения об ошибках формата файла, и пр., наличие справки и демонстрация ее при неправильном вводе и т. д.


## Формат файла
Данная реализация игры поддерживает загрузку "вселенной" из файла следующего формата:

(оригинальный #Life 1.06 http://conwaylife.com/wiki/Life_1.06)

*в формат #Life 1.06 внесены правки в соответствии с техническим заданием*
```
1) #Life 1.06
2) #N My universe
3) #Size columns rows
4) #R Bx/Sy
5) 0 2
6) 1 0
7) 1 2
8) 2 1
9) 2 2
```
### Описание формата:

1. ***Строка 1***: Заголовок, указывающий формат файла.
2. ***Строка 2***: содержит комментарий с названием юниверса (произвольная строка).
3. ***Строка 3***: содержит размеры поля (количество столбцов <=100 , количество строк <=80).
4. ***Строка 4***: содержит комментарий со следующим правилом перехода:
   #R Bx/Sy , где x и y — последовательности разных цифр из набора {0...8}.
   Последовательность под буквой Б (рождение) содержит количество живых клеток,
   необходим для «рождения» клетки,
   под буквой S (выживание) — ячейки, необходимые для «выживания» клетки.
5. ***Строка 5-9***: координаты живых клеток.

***Важно*** : (x,y) - будут считаны, если x>=0, y>=0.
остальные координаты будут игнорироваться !!!




## Сборка проекта
1. Создайте директорию для сборки (находясь в дирректории проекта 2lab-Cpp):
```sh
   mkdir build
   cd build
```
2. Запустите CMake для конфигурации проекта:
```sh
   cmake ..
```
3. Соберите проект с помощью make:

***Используется утилита make, т.к. является стандартной частью большинства Unix-подобных операционных систем, включая Linux, BSD, macOS и другие.***

```sh
   make
```
4. После успешной сборки проекта вы можете игру и получить справку с помощью следующей команды:
```sh
  ./GameOfLife -h
```


## Запуск

### Опции запуска
- `--help`: Выводит справку.
- `-h`: Выводит справку.
- `--load <file>`: Загружает начальную конфигурацию вселенной из файла.
- `-l <file>`: Загружает начальную конфигурацию вселенной из файла.
- `-i <x>`: Указывает количество итераций для оффлайн режима.
- `--iterations=<x>`: Указывает количество итераций для оффлайн режима.
- `-o <filename>`: Указывает выходной файл для оффлайн режима.
- `--output=<filename>`: Указывает выходной файл для оффлайн режима.

### Примеры запуска
- `./GameOfLife -l input.txt -i 10 -o output.txt`: Запускает оффлайн режим, который запишет состояние вселенной из файла "input.txt" в файл "output.txt", после 10 итераций симуляции.
- `./GameOfLife --load=input.txt --iterations=10 --output=output.txt`: То же самое.
- `./GameOfLife` : Запускает онлайн режим симмуляции на случайно сгенерированной вселенной с #R B3/S23.
- `./GameOfLife -i 10 -o output.txt` : Запускает оффлайн режим, который запишет состояние случайно сгенерированной вселенной с #R B3/S23 в файл "output.txt" после 10 итераций симуляции.
- `./GameOfLife -h` : Выведет справку.

### Интересные заготовки запуска
- `./GameOfLife -l Planer.txt`
- `./GameOfLife -l Cover1.txt`
- `./GameOfLife -l Cover2.txt`
- `./GameOfLife -l "GosperGun + eater.txt"`