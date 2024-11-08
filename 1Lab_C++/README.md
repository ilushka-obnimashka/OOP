1. Создайте директорию для сборки (находясь в дирректории проекта 1lab-Cpp):
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
4. После успешной сборки проекта вы можете запустить ***все*** тесты с помощью следующей команды:
```sh
  ./Cb_test
```
*возможен запуск отдельной группы тестов:

```
test/
    ├── Constructor_Tests.cpp
    ├── Operator_Tests.cpp
    ├── Push_Pop_Front_Back_Tests.cpp
    ├── BufferState_Tests.cpp
    ├── Lineraize_Test.cpp
    └── Working_with_buffer_elements_Tests.cpp
```

```sh
  ./Cb_test  --gtest_filter=<Tests_name>.*
```


