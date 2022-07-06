# Qt4-Cplusplus-Planets-of-the-solar-system

### Описание

Разработана база данных, работающая на основе контейнера. В качестве прототипа контейнера использовался vector из библиотеки STL. Для работы с контейнером предусмотрен итератор. В качестве элементов контейнера используются объекты классов. Класс: характеристики планеты солнечной системы.

Выбор данного контейнера объясняется простотой своей разработки и организации, а также возможностью произвольного доступа к своим элементам, чего нет у контейнера типа list. Контейнер list обладает только последовательным доступом.

Разработанная база данных создана с использованием C++ и библиотеки Qt4. Среда программирования Qt Creator.

База данных обеспечивает выполнение следующих операций:
- создание базы данных,
- объединение баз данных,
- добавления и удаления записей,
- редактирования записей,
- просмотра базы данных, 
- поиск данных (найти данные, удовлетворяющие заданному критерию),
- запись на диск,
- чтения с диска.

Интерфейсная часть программы содержит следующие компоненты:
- окно «ABOUT»,
- главное меню,
- всплывающее меню,
- строка состояния,
- панель инструментов,
- подсказки по командам меню и панели инструментов. 

### Инструкция пользователя

**1. Добавить новую планету или загрузить их из файла:**

![](https://raw.githubusercontent.com/sudlets/Qt4-Cplusplus-Planets-of-the-solar-system/main/Screenshots/Add%20Planet%201.png)

![](https://raw.githubusercontent.com/sudlets/Qt4-Cplusplus-Planets-of-the-solar-system/main/Screenshots/Add%20Planet%202.png)

**2. Сохранить планеты в файл:**

![](https://raw.githubusercontent.com/sudlets/Qt4-Cplusplus-Planets-of-the-solar-system/main/Screenshots/Save%20Planet%201.png)

**3. Информация о программе:**

![](https://raw.githubusercontent.com/sudlets/Qt4-Cplusplus-Planets-of-the-solar-system/main/Screenshots/Info.png)

**4. Удалить элемент:**

![](https://raw.githubusercontent.com/sudlets/Qt4-Cplusplus-Planets-of-the-solar-system/main/Screenshots/Delete.png)

**5. Добавить элементы из другого контейнера:**

![](https://raw.githubusercontent.com/sudlets/Qt4-Cplusplus-Planets-of-the-solar-system/main/Screenshots/Add%20Planet%203.png)

**6. Редактирование планеты:**

![](https://raw.githubusercontent.com/sudlets/Qt4-Cplusplus-Planets-of-the-solar-system/main/Screenshots/Edit%20Planet%201.png)

![](https://raw.githubusercontent.com/sudlets/Qt4-Cplusplus-Planets-of-the-solar-system/main/Screenshots/Edit%20Planet%202.png)

### Структура программы

Программа состоит из графического интерфейса и кода, который остается «за кадром». Интерфейс составляют: элемент отображения LineEdit, панель инструментов, главное меню и функциональные кнопки PushButton.

Фоновую часть составляют классы: контейнер VectPlanet, содержимое контейнера - класс планет Planet, и сама база данных Planets, которая хранит в себе данные и содержит методы обработки базы.

### Таблица идентификаторов

| Файлы  | Классы  | Методы класса  | Функция  | Назначение  |
| :------------: | :------------: | :------------: | :------------: | :------------: |
| Basevect.h  | VectPlanet  | VectPlanet ()  | Конструктор  | Контейнер  |
|   |   |  ~ VectPlanet () | Деструктор  |   |
|   |   | VectPlanet(const VectPlanet&)  | Конструктор копирования  |   |
|   |   |  VectPlanet(VectPlanet(const Planet\*, unsigned int)| Конструктор, который копирует планеты из указанного массива  |   |
|   |   | void add_planet ()  | Добавить элемент по умолчанию в конец  |   |
|   |   | void add_planet(const Planet&)  | Добавить указанную планету в конец  |   |
|   |   | void delete_planet(int) | Убрать элемент с указанным номером  |   |
|   |   | void new_size(int)  | Удаляем все планеты и устанавливаем новый размер контейнера  |   |
|   |   | void add_size(int)  | Добавляем указанный размер памяти к вектору с сохранением планет  |   |
|   |   | Planet& get_planet(const int&)  | Получить адрес указанной планеты  |   |
|   |   | get_size()  | Получить размер контейнера  |   |
|   |   | Iterator begin()  | Получить указатель на начало контейнера  |   |
|   |   | Iterator end()  | Получить указатель на фиктивный конец контейнера  |   |
|   |   | Planet& operator[] (const int&)  | Перегруженный оператор индексирования  |   |
|   | Iterator  | Iterator()  | Конструктор  | Итератор  |
|   |   | ~Iterator()  | Деструктор  |   |
|   |   | Planet& operator \* ()  | Перегруженный оператор разыменования  |   |
|   |   | Planet& operator ++ ()  | Перегруженный оператор инкремента  |   |
|   |   | Planet& operator -\- ()  | Перегруженный оператор декремента  |   |
|   |   | bool operator == (const Planet& it)  | Перегруженный оператор равенства  |   |
|   |   | bool operator != (const Planet& it)  | Перегруженный оператор неравенства  |   |
|   |   | friend ostream& operator<<  | Перегруженный оператор вывода в поток  |   |
|   |   | friend istream& operator>>  | Перегруженный оператор ввода в поток  |   |
| Planet.h  | Planet  | Planet ()  | Конструктор  | Класс  |
|   |   | Planet (string, int, int, string)  | Конструктор с параметрами  |   |
|   |   | Planet (const Planet &)  | Конструктор копирования  |   |
|   |   | ~ Planet()  | Деструктор  |   |
|   |   | string get_name(void)  | Получить имя объекта  |   |
|   |   | string get_Who_opening(void)  | Получить имя первооткрывателя  |   |
|   |   | int get_Year_of_opening(void)  | Получить год открытия  |   |
|   |   | int get_mass(void)  | Получить массу объекта  |   |
|   |   | void in_name(string)  | Ввести имя объекта  |   |
|   |   | void in_Who_opening(string)  | Ввести имя первооткрывателя  |   |
|   |   | void in_Year_of_opening(int)  | Установить год открытия  |   |
|   |   | void in_mass(int)  | Ввести массу объекта  |   |
|   |   | friend istream& operator>>  | Перегруженный оператор ввода в поток  |   |
| mainwindow.h  | MainWindow  | void on_add_item_clicked()  | Добавление новой планеты в контейнер  | Слоты  |
|   |   | void on_delete_item_clicked()  | Удаление планеты из контейнера  |   |
|   |   | void on_pushButton_SelectPlanet_clicked()  | Выбрать планету для просмотра и редактирования  |   |
|   |   | void on_pushButton_ConfChang_clicked()  | Применить изменения  |   |
|   |   | void on_pushButton_sizeVictor_clickd()  | Показать количество планет в контейнере  |   |
|   |   | void on_Author_triggered()  | Показать информацию о разработчике  |   |
|   |   | void on_action_triggered()  | Записать планеты из контейнера в файл  |   |
|   |   | void on_action_2_triggered()  | Записать планеты в контейнер из файла, старые планеты удаляются  |   |
|   |   | void on_Merge_in_file_triggered()  | Планеты из контейнера объединяются с планетами в файле  |   |
|   |   | void on_Merge_from_file_triggered()  | Планеты из файла объединяются с планетами в контейнере  |   |
|   |   | void on_pushButton_back_clicked()  | Показать предыдущую планету  |   |
|   |   | void on_pushButton_next_clicked()  | Показать следующую планету  |   |
|   |   |   |   |   |

### Поля классов

##### VectPlanet:
- Planet \* T; – начало вектора
- int size – размер списка

##### Planet:
- string name – имя объекта
- string Who_opening – имя первооткрывателя
- int mass - масса
- int Year_of_opening – год открытия

##### MainWindow:
- Ui::MainWindow \*ui
- QMenu \*Menu – меню
- QAction \*action – действие “Сохранить в файл”
- QAction \*action_2 – действие “Открыть из файла”
- QAction \*Merge_in_file – действие “Добавить в файл”
- QAction \*Merge_from_file – действие “Объединить из файла”
- QMenu \*about_of – меню
- QAction \*Author – действие “Информация об авторе”
- QLineEdit \* lineEdit_EnterPlanet– строка для ввода номера планеты
- QLineEdit \* lineEdit_Mass– строка для работы с массой планеты
- QLineEdit \* lineEdit_Mass_2– заблокированная строка с надписью «Идентификатор»
- QLineEdit \* lineEdit_Name– строка для работы с именем планеты
- QLineEdit \* lineEdit_Name_2– заблокированная строка с надписью «Имя»
- QLineEdit \* lineEdit_WhoOpen– строка для работы с первооткрывателем планеты
- QLineEdit \* lineEdit_WhoOpen_2– заблокированная строка с надписью «Кто открыл»
- QLineEdit \* lineEdit_YearOpen– строка для работы с годом открытия планеты
- QLineEdit \* lineEdit_YearOpen_2– заблокированная строка с надписью «Год открытия»
- QPushButton \* add_item– кнопка добавления новой планеты
- QPushButton \* delete_item– кнопка удаления планеты
- QPushButton \* pushButton_ConfChang– кнопка применения изменений
- QPushButton \* pushButton_SelectPlanet– кнопка выбора планеты
- QPushButton \* pushButton_back– кнопка для выбора предыдущей планеты
- QPushButton \* pushButton_next– кнопка для выбора следующей планеты
- QPushButton \* pushButton_sizeVictor– кнопка для показа количества планет 

